#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring> 


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

void add_customer1(client& customer) {
    ptree pt_in;
    ptree pt_accounts;
    ptree pt_write;
    //on recuper les client deja present dans le json 
    ifstream file_in("C:/Users/Administrateur/source/repos/RCBanque/Boost_JSON/bdd1.json");
    read_json(file_in, pt_in);
    file_in.close();
    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto custom = get_a_customer_from_a_ptree(customer.second);
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(custom) });
        
    }
    // on ajoute le nouveau client au ptree
    pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer) });
   

    pt_write.add_child("Customers", pt_accounts);

   
    // on ecrit dans le json
    ofstream file_out("C:/Users/Administrateur/source/repos/RCBanque/Boost_JSON/bdd1.json");
    write_json(file_out, pt_write);
    file_out.close();
}
void add_customer2(client& customer) {
    ptree pt_in;
    ptree pt_accounts;
    ptree pt_write;
    //on recuper les client deja present dans le json 
    ifstream file_in("C:/Users/Administrateur/source/repos/RCBanque/Boost_JSON/bdd2.json");
    read_json(file_in, pt_in);
    file_in.close();
    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto custom = get_a_customer_from_a_ptree(customer.second);
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(custom) });

    }
    // on ajoute le nouveau client au ptree
    pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer) });


    pt_write.add_child("Customers", pt_accounts);


    // on ecrit dans le json
    ofstream file_out("C:/Users/Administrateur/source/repos/RCBanque/Boost_JSON/bdd2.json");
    write_json(file_out, pt_write);
    file_out.close();
}
void add_customer3(client& customer) {
    ptree pt_in;
    ptree pt_accounts;
    ptree pt_write;
    //on recuper les client deja present dans le json 
    ifstream file_in("C:/Users/Administrateur/source/repos/RCBanque/Boost_JSON/bdd3.json");
    read_json(file_in, pt_in);
    file_in.close();
    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto custom = get_a_customer_from_a_ptree(customer.second);
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(custom) });

    }
    // on ajoute le nouveau client au ptree
    pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer) });


    pt_write.add_child("Customers", pt_accounts);


    // on ecrit dans le json
    ofstream file_out("C:/Users/Administrateur/source/repos/RCBanque/Boost_JSON/bdd3.json");
    write_json(file_out, pt_write);
    file_out.close();
}

vector<client> json_to_vector1() {
    std::vector<client> cust;
    ptree pt_in;

    //on recuper les client deja present dans le json 
    ifstream file_in("C:/Users/Administrateur/source/repos/RCBanque/Boost_JSON/bdd1.json");
    read_json(file_in, pt_in);
    file_in.close();

    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto customer_f_ptree = get_a_customer_from_a_ptree(customer.second);
        cust.push_back(customer_f_ptree);

    }
    return cust;
}
vector<client> json_to_vector2() {
    std::vector<client> cust;
    ptree pt_in;

    //on recuper les client deja present dans le json 
    ifstream file_in("C:/Users/Administrateur/source/repos/RCBanque/Boost_JSON/bdd2.json");
    read_json(file_in, pt_in);
    file_in.close();

    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto customer_f_ptree = get_a_customer_from_a_ptree(customer.second);
        cust.push_back(customer_f_ptree);

    }
    return cust;
}
vector<client> json_to_vector3() {
    std::vector<client> cust;
    ptree pt_in;

    //on recuper les client deja present dans le json 
    ifstream file_in("C:/Users/Administrateur/source/repos/RCBanque/Boost_JSON/bdd3.json");
    read_json(file_in, pt_in);
    file_in.close();

    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto customer_f_ptree = get_a_customer_from_a_ptree(customer.second);
        cust.push_back(customer_f_ptree);

    }
    return cust;
}


vector<string> separationvirement(string enter) {
    string delimiter = "/";
    string token = enter.substr(0, enter.find(delimiter));
    int nbvir = atoi(token.c_str());
    int i = 0;
    vector<string> sortie;
    while (i!=nbvir){
        string delimiter2 = "/";
        string token2 = enter.substr(0, enter.find(delimiter2));
        sortie.push_back()
    }
}
int numagence(string enter) {
    string delimiter = ",";
    string token = enter.substr(0, enter.find(delimiter)); 
    int sortie = atoi(token.c_str());
    sortie = sortie % 1000;
    return sortie;
}

int numclient(string enter) {
    string delimiter = ",";
    string token = enter.substr(0, enter.find(delimiter));
    int sortie = atoi(token.c_str());
    return sortie;
}

int sommevirement(string enter) {
    string delimiter = ",";
    string token = enter.substr(enter.find(delimiter)+1,enter.length());
    int sortie = atoi(token.c_str());
    return sortie;
}


client virement(client customer, string enter) {
    int vir = sommevirement(enter);
    int solde = customer.comptecourantGet();
    int total = solde + vir;
    customer.comptecourantSet(total);
    return customer;
}

 




int main(int argc, char** argv) {
    ptree pt_write;
    ptree pt_accounts;
    ptree pt_test;

    try {
        client customer1(1003, "bonjour","bochu",13092003,0652270107,200,300,3);
        
        

        string a = "2003,211";

        virement(customer1, a);

        cout << customer1 << endl;
        



        /*
        add_customer2(customer1);
        add_customer3(customer1);

        
        vector<client> ca = json_to_vector2();
        vector<client> cb = json_to_vector3();

       
        for (int i = 0; i < 2; i++) {
            cout << ca[i] << endl;
        }
        for (int i = 0; i < 2; i++) {
            cout << cb[i] << endl;
        }*/

        int n = numagence(a);
        int b = numclient(a);
        int w = sommevirement(a);
        cout << n << std::endl;
        cout << b << std::endl;
        cout << w << std::endl;


    }

    catch (std::exception& e) {
        // Other errors
    }
}
