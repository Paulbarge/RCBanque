#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

#include "../RCBanque/Clients.hpp" 

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;


enum class Account_type { Checking, Savings };

struct Account {
    int number;
    Account_type account_type;
};

ptree get_a_ptree_from_a_customer(client &customer) {
    ptree pt;
    ptree account_numbers;

    pt.put("numero_client", customer.numeroClientGet());
    pt.put("Nom", customer.nomGet());
    pt.put("Prenom", customer.prenomGet());
    pt.put("dateNaissance", customer.dateNaissanceGet());
    pt.put("numeroAdresse", customer.numeroAdresseGet());
    pt.put("adresse", customer.adresseGet());
    pt.put("tel", customer.telGet());

   
    /*
    for (auto& account_number : customer.account_numbers_) {
        ptree dummy_tree;
        //   dummy_tree.put(account_number.first, account_number.second);
        dummy_tree.put_value(account_number);
        account_numbers.push_back({ "", dummy_tree });
    }
    pt.add_child("Account_numbers", account_numbers);*/

    return pt;
}

client get_a_customer_from_a_ptree(ptree& pt) {

    int numero_client = pt.get<int>("numero_client");

    std::string Nom = pt.get<std::string>("Nom");
    std::string Prenom = pt.get<std::string>("Prenom");
    std::string dateNaissance = pt.get<std::string>("dateNaissance");

    int numeroAdresse = pt.get<int>("numeroAdresse");
    std::string adresse = pt.get<std::string>("adresse"); 
    const int tel = pt.get<int>("tel", 0);

    /*
    for (ptree::value_type& account_number : pt.get_child("Account_numbers")) {
        account_numbers.push_back(account_number.second.get_value<int>());
    }*/

    client customer(numero_client,Nom,Prenom,dateNaissance,numeroAdresse,adresse,tel);

    return customer;
}


int main(int argc, char** argv) {
    ptree pt_write;
    ptree pt_accounts;

    try {
        Customer customer1(1001, "Tartempion1",
            //    { {"Epargne", 10000}, {"Courant", 10001} });
            { 10000, 10001 });

        Customer customer2(1002, "Tartempion2",
            //      { {"Epargne", 10002}, {"Courant", 10003} });
            { 10002, 10003 });

        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer1) });
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer2) });
        pt_write.add_child("Customers", pt_accounts);

        std::ofstream file_out("example_write_read.json");
        write_json(file_out, pt_write);
        file_out.close();

        std::ifstream file_in("example_write_read.json");
        read_json(file_in, pt_write);
        file_in.close();

        for (ptree::value_type& customer : pt_write.get_child("Customers")) {
            auto custom = get_a_customer_from_a_ptree(customer.second);

            std::cout << custom << std::endl;
        }
    }
    catch (std::exception& e) {
        // Other errors
    }
}
