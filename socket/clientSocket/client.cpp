// SocketsClient.cpp�: d�finit le point d'entr�e de l'application.
//

#include "client.h"


#include <iostream>
#include <string>
#include <boost/asio.hpp>



using namespace std;
using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;



void verifErreur(boost::system::error_code error, string message) {
    if (!error) {
        cout << "Message : " << message << " --> envoye" << endl;
    }
    else {
        cout << "send failed: " << error.message() << endl;
    }
}

void envoiUnique(tcp::socket& socket, string message) {


    //connection
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    boost::system::error_code error;
    const string msg = message + "\n";

    boost::asio::write(socket, boost::asio::buffer(msg), error);
    verifErreur(error, message);

    socket.close(error);

}


//void  envoiReception(tcp::socket& socket, string message) {
void  envoiReception(string message) {

    boost::asio::io_service io_service;
    //socket creation
    tcp::socket socket(io_service);

    //connection
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    boost::system::error_code error;
    const string msg = message + "\n";

    boost::asio::write(socket, boost::asio::buffer(msg), error);
    verifErreur(error, message);

    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
    if (error && error != boost::asio::error::eof) {
        cout << "receive failed: " << error.message() << endl;
    }
    else {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        cout << data << endl;
    }

    socket.close(error);
}


void fonctionnementComplet(/*tcp::socket& socket*/) {

    //boost::asio::io_service io_service;
    ////socket creation
    //tcp::socket socket(io_service);

    while (true) {
        string message;

        cout << "Entrez un mot : " << endl;
        cin >> message;

        /*envoiReception(socket, message);*/
        envoiReception(message);
    }
}


bool momentInterets() {
    cout << "Hehe les interets" << endl;
    cout << "timestamp : " << time(NULL) << endl;

    while (true) {
        //cout << "\n#####  Hehe  #####" << endl;
        Sleep(20000);

        cout << "\n" << endl;
        envoiReception("11111,2000");
        cout << "\n" << endl;

    }
}



int main() {


    //boost::asio::io_service io_service;
    ////socket creation
    //tcp::socket socket(io_service);
    //
    //envoiUnique(socket, "Test");


    /*std::thread leTraitement(fonctionnementComplet, socket);*/
    std::thread leTraitement(fonctionnementComplet);
    std::thread nouveauxInterets(momentInterets);

    leTraitement.join();
    nouveauxInterets.join();


    //fonctionnementComplet();



    return 0;
}



