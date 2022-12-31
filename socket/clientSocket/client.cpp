// SocketsClient.cpp : définit le point d'entrée de l'application.
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


void  envoiReception(tcp::socket& socket, string message) {
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

    boost::asio::io_service io_service;
    //socket creation
    tcp::socket socket(io_service);

    while (true) {
        string message;

        cout << "Entrez un mot : " << endl;
        cin >> message;

        envoiReception(socket, message);
    }
}



bool momentInterets() {
    cout << "Hehe les interets" << endl;
    cout << "timestamp : " << time(NULL) << endl;

    while (true) {
        cout << "\n#####  Hehe  #####" << endl;
        Sleep(2000);



    }
}



int main() {


    //boost::asio::io_service io_service;
    ////socket creation
    //tcp::socket socket(io_service);
    //
    //envoiUnique(socket, "Test");


    std::thread leTraitement(fonctionnementComplet, socket);
    //std::thread nouveauxInterets(momentInterets);

    leTraitement.join();
    //nouveauxInterets.join();


    fonctionnementComplet();

    while (true) {



        /*string message;

        cout << "Entrez un mot : " << endl;
        cin >> message;

        envoiReception(socket, message);

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

        socket.close(error);*/


    }




    getchar();
    getchar();
    return 0;
}
