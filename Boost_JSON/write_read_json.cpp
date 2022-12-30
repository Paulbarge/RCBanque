#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>
#include <iostream>


#ifdef _WIN32
#include <SDKDDKVer.h>
#endif 

#include "../RCBanque/Clients.hpp" 

using namespace std;

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;




ptree get_a_ptree_from_a_customer(client &customer) {
    ptree pt;
    ptree account_numbers;

    pt.put("numero_client", customer.numeroClientGet());
    pt.put("Nom", customer.nomGet());
    pt.put("Prenom", customer.prenomGet());
    pt.put("dateNaissance", customer.dateNaissanceGet());
   // pt.put("numeroAdresse", customer.numeroAdresseGet());
   // pt.put("adresse", customer.adresseGet());
    pt.put("tel", customer.telGet());
    pt.put("compte_courant", customer.comptecourantGet());
    pt.put("compte_epargne", customer.compteepargneGet());
    pt.put("interet", customer.interetGet());

    return pt;
}

client get_a_customer_from_a_ptree(ptree& pt) {

    int numero_client = pt.get<int>("numero_client");

    string Nom = pt.get<string>("Nom");
    string Prenom = pt.get<string>("Prenom");
    int dateNaissance = pt.get<int>("dateNaissance");

    //int numeroAdresse = pt.get<int>("numeroAdresse");
    //string adresse = pt.get<string>("adresse"); 
    int tel = pt.get<int>("tel", 0);

    int compte_courant = pt.get<int>("compte_courant", 0);
    int compte_epargne = pt.get<int>("compte_epargne", 0);
    int interet = pt.get<int>("interet", 0);



    client customer(numero_client,Nom,Prenom,dateNaissance,tel,compte_courant,compte_epargne,interet);

    return customer;
}


int main(int argc, char** argv) {
    ptree pt_write;
    ptree pt_accounts;

    try {
        client customer1(1001, "Barge","Paul",13092003,0652270107,200,300,3);

        client customer2(1002, "simon", "bernard", 12042001,0624522701, 1200, 300, 5);
 

        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer1) });
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer2) });
        pt_write.add_child("Customers", pt_accounts);

        ofstream file_out("bdd.json");
        write_json(file_out, pt_write);
        file_out.close();

        ifstream file_in("bdd.json");
        read_json(file_in, pt_write);
        file_in.close();

        for (ptree::value_type& customer : pt_write.get_child("Customers")) {
            auto custom = get_a_customer_from_a_ptree(customer.second);

             cout << custom << std::endl;
        }
    }
    catch (std::exception& e) {
        // Other errors
    }
}
