// TestSockets2.cpp : définit le point d'entrée de l'application.
//

#include "serveur.h"

//importing libraries
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <time.h>

//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;
using std::string;


class newClient {
private:
    string nameClient;

public:
    void setNameClient(string);
    string getNameClient();
};

void newClient::setNameClient(string name) {
    this->nameClient = name;
}

string newClient::getNameClient() {
    return this->nameClient + "\n";
}


string read_(tcp::socket& socket) {
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, "\n");
    string data = boost::asio::buffer_cast<const char*>(buf.data());
    return data;
}


void verifErreur(boost::system::error_code error, string message) {
    if (!error) {
        cout << "Message : " << message << " --> envoye" << endl;
    }
    else {
        cout << "send failed: " << error.message() << endl;
    }
}

bool momentInterets(time_t& ancienneHeure) {
    if ((ancienneHeure + 3600) < time(NULL)) {
        ancienneHeure = time(NULL);
        // utiliser méthode des intérêts
        return true;
    }
    else {
        return false;
    }
}




int main()
{

    string msg;

    time_t prochainsInterets = time(NULL);
    //std::thread nouveauxInterets()...


    while (true)
    {


        boost::asio::io_service io_service;

        // listen for new connection
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1234));

        // socket creation
        /*auto socket = std::make_unique<tcp::socket>(io_service);*/
        tcp::socket socket(io_service);

        // waiting for connection
        acceptor.accept(socket); //acceptor.accept(*socket);




        string message = read_(socket); //string message = read_(*socket);
        cout << message << endl;

        const string msgRenvoi = "message recu\n";
        boost::system::error_code error;
        boost::asio::write(socket, boost::asio::buffer(msgRenvoi), error);

        verifErreur(error, msgRenvoi);

        newClient client1;
        client1.setNameClient("ClemenceServeur");
        const string msg3 = (string)client1.getNameClient();
        cout << "msg3 vaut : " << msg3 << endl;

        boost::asio::write(socket, boost::asio::buffer(msg3), error);
        verifErreur(error, msg3);

        client1.setNameClient("ClemenceServeur2");

        boost::asio::write(socket, boost::asio::buffer((string)client1.getNameClient()), error);

        verifErreur(error, (string)client1.getNameClient());


        cout << "encore dans la boucle" << endl;


    }

    cout << "sortie de boucle" << endl;
    return 0;
}
