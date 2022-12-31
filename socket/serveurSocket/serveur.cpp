// TestSockets2.cpp : définit le point d'entrée de l'application.
//

#include "serveur.h"

//importing libraries
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <time.h>
#include <thread>
#include <stdio.h>
#include <vector>
#include <string>


using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;
using std::string;



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

bool isSynchro(string enter) {
    string delimiter = ",";
    string token = enter.substr(0, enter.find(delimiter));
    if (token == "11111") {
        return 1;
    }
    else {
        return 0;
    }
}

int numagence(string enter) {
    string delimiter = ",";
    string token = enter.substr(0, enter.find(delimiter));
    int sortie = atoi(token.c_str());
    sortie = sortie / 1000;
    return sortie;
}


bool momentInterets(time_t& ancienneHeure) {
    cout << "Hehe les interets" << endl;
    cout << "timestamp : " << time(NULL) << endl;

    while (true) {
        /*cout << "Hehe" << endl;
        Sleep(2000);*/


        if ((ancienneHeure + 2) < time(NULL)) {
            ancienneHeure = time(NULL);
            cout << "Changement d'heure !" << endl;
            // utiliser méthode des intérêts
            return true;
        }
        else {
            return false;
        }
    }
}


void traitement(int nbModifsAgence1, string* tabAgence1, int nbModifsAgence2, string* tabAgence2, int nbModifsAgence3, string* tabAgence3) {
    while (true) {
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

        if (isSynchro(message)) {
            if (numagence(message) == 1) {
                tabAgence1[nbModifsAgence1] = message;
                nbModifsAgence1 += 1;
                cout << "Contenu ajouté à l'agence 1" << endl;
            }
            else if (numagence(message) == 2) {
                tabAgence1[nbModifsAgence2] = message;
                nbModifsAgence2 += 1;
                cout << "Contenu ajouté à l'agence 2" << endl;
            }
            else if (numagence(message) == 3) {
                tabAgence1[nbModifsAgence3] = message;
                nbModifsAgence3 += 1;
                cout << "Contenu ajouté à l'agence 3" << endl;
            }
        }



        string message2 = "Voila votre message : " + message;

        const string msgRenvoi = "message recu\n";
        boost::system::error_code error;
        boost::asio::write(socket, boost::asio::buffer(msgRenvoi), error);
        boost::asio::write(socket, boost::asio::buffer(message2), error);

        verifErreur(error, msgRenvoi);
    }
}



string prepaSynchro(const std::vector<string>& tabAgence) {
    string retourSynchro = std::to_string(tabAgence.size());
    for (int i = 0; i < tabAgence.size(); i++) {
        retourSynchro += "/";
        retourSynchro += tabAgence[i]; // a voir si fonctionne avec \n, normalement pb réglé
    }
    retourSynchro += "\n";
    return retourSynchro;
}


int main()
{



    int nbModifsAgence1 = 0;
    std::vector<string> tabAgence1;

    int nbModifsAgence2 = 0;
    std::vector<string> tabAgence2;

    int nbModifsAgence3 = 0;
    std::vector<string> tabAgence3;


    string msg;




    time_t prochainsInterets = time(NULL);
    //std::thread nouveauxInterets()...

    /*std::thread nouveauxInterets(momentInterets, std::ref(prochainsInterets));
    std::thread leTraitement(traitement, nbModifsAgence1, std::ref(tabAgence1), nbModifsAgence2, std::ref(tabAgence2), nbModifsAgence3, std::ref(tabAgence3));

    nouveauxInterets.join();
    leTraitement.join();*/

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

        boost::system::error_code error;


        string message = read_(socket); //string message = read_(*socket);
        cout << message << endl;

        if (isSynchro(message)) {
            message.erase(0, 6);
            string retourSynchro;
            cout << "on synchronise" << endl;

            if (numagence(message) == 1) {
                //retourSynchro = std::to_string(tabAgence1.size());
                //for (int i = 0; i < tabAgence1.size(); i++) {
                //    retourSynchro += "/";
                //    retourSynchro += tabAgence1[i]; // a voir si fonctionne avec \n, normalement pb réglé
                //}
                //retourSynchro += "\n";
                retourSynchro = prepaSynchro(tabAgence1);
                cout << "le retour synchro : " << retourSynchro << endl;
                boost::asio::write(socket, boost::asio::buffer(retourSynchro), error);
                tabAgence1.clear();
            }
            else if (numagence(message) == 2) {
                retourSynchro = prepaSynchro(tabAgence2);
                cout << "le retour synchro : " << retourSynchro << endl;
                boost::asio::write(socket, boost::asio::buffer(retourSynchro), error);
                tabAgence2.clear();
            }
            else if (numagence(message) == 3) {
                retourSynchro = prepaSynchro(tabAgence3);
                cout << "le retour synchro : " << retourSynchro << endl;
                boost::asio::write(socket, boost::asio::buffer(retourSynchro), error);
                tabAgence3.clear();
            }


        }
        else {
            if (numagence(message) == 1) {
                message.erase(message.end() - 1);
                tabAgence1.push_back(message);
                nbModifsAgence1 += 1;
                cout << "Contenu ajoute a l'agence 1" << endl;
            }
            else if (numagence(message) == 2) {
                message.erase(message.end() - 1);
                tabAgence2.push_back(message);
                nbModifsAgence2 += 1;
                cout << "Contenu ajoute a l'agence 2" << endl;
            }
            else if (numagence(message) == 3) {
                message.erase(message.end() - 1);
                tabAgence3.push_back(message);
                nbModifsAgence3 += 1;
                cout << "Contenu ajoute a l'agence 3" << endl;
            }
        }

        string message2 = "Voila votre message : " + message;

        const string msgRenvoi = "message recu\n";
        //boost::system::error_code error;
        boost::asio::write(socket, boost::asio::buffer(msgRenvoi), error);
        boost::asio::write(socket, boost::asio::buffer(message2), error);

        //verifErreur(error, msgRenvoi);

        /*newClient client1;
        client1.setNameClient("ClemenceServeur");
        const string msg3 = (string)client1.getNameClient();

        boost::asio::write(socket, boost::asio::buffer(msg3), error);
        verifErreur(error, msg3);*/




        cout << "encore dans la boucle" << endl;


    }

    cout << "sortie de boucle" << endl;
    return 0;
}
