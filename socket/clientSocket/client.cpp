// SocketsClient.cpp : définit le point d'entrée de l'application.
//

#include "client.h"




#include <iostream>
#include <boost/asio.hpp>




using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;


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



void verifErreur(boost::system::error_code error, string message) {
    if (!error) {
        cout << "Message : " << message << " --> envoye" << endl;
    }
    else {
        cout << "send failed: " << error.message() << endl;
    }
}

void nouveauMsg(string message) {

    boost::asio::io_service io_service;
    //socket creation
    tcp::socket socket(io_service);
    //connection
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    boost::system::error_code error;

    boost::asio::write(socket, boost::asio::buffer(message), error);

}


int main() {


    boost::asio::io_service io_service;
    //socket creation
    tcp::socket socket(io_service);
    //connection
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    boost::system::error_code error;





    const string msg = "Hello from Client!\n";
    boost::asio::write(socket, boost::asio::buffer(msg), error);
    verifErreur(error, msg);



    string msg2 = "Hello c'est moi\n";
    boost::asio::write(socket, boost::asio::buffer(msg2), error);
    verifErreur(error, msg2);



    msg2 = "Hello c'est moi2\n";
    boost::asio::write(socket, boost::asio::buffer(msg2), error);
    verifErreur(error, msg2);
    msg2 = "Hello c'est moi3\n";
    boost::asio::write(socket, boost::asio::buffer(msg2), error);
    verifErreur(error, msg2);


    msg2 = "Hello c'est moi4\n";
    boost::asio::write(socket, boost::asio::buffer(msg2), error);
    verifErreur(error, msg2);



    // getting response from server
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
    if (error) {
        cout << "fermeture ok" << endl;
    }
    else {
        cout << "pb fermeture" << endl;
    }



    getchar();
    getchar();
    return 0;
}








//using namespace std;
//#include <iostream>
//#include <boost/asio.hpp>
//
//using namespace boost::asio;
//using ip::tcp;
//using std::string;
//using std::cout;
//using std::endl;
//
//
//class newClient {
//private:
//    string nameClient;
//
//public:
//    void setNameClient(string);
//    string getNameClient();
//};
//
//void newClient::setNameClient(string name) {
//    this->nameClient = name;
//}
//
//string newClient::getNameClient() {
//    return this->nameClient+"\n";
//}
//
//
//int main() {
//    cout << "### Fenetre client ###\n" << endl;
//
//    
//    newClient client1;
//
//    client1.setNameClient("Baptiste");
//    cout << "Nom client1 : " << client1.getNameClient() << endl;
//
//    boost::asio::io_service io_service;
//    //socket creation
//    tcp::socket socket(io_service);
//
//    tcp::resolver resolver(io_service);
//    boost::asio::connect(socket, resolver.resolve({ "127.0.0.1", "1234" }));
//
//    //connection
//    //socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
//    // request/message from client
//
//    boost::system::error_code error;
//
//    const string msg = "Hello from Client!\n";
//    cout << "msg vaut : " << msg << endl;
//    
//    boost::asio::write(socket, boost::asio::buffer(msg), error);
//
//    /*boost::asio::write(socket, boost::asio::buffer(msg), error);*/
//
//    const string msg2 = (string)client1.getNameClient();
//    cout << "msg2 vaut : " << msg2 << endl;
//    boost::asio::write(socket, boost::asio::buffer(msg2), error);
//    
//    if (!error) {
//        cout << "Client sent hello message!" << endl;
//        cout << "Je suis le client" << endl;
//    }
//    else {
//        cout << "send failed: " << error.message() << endl;
//    }
//    // getting response from server
//    boost::asio::streambuf receive_buffer;
//    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
//    if (error && error != boost::asio::error::eof) {
//        cout << "receive failed: " << error.message() << endl;
//    }
//    else {
//        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
//        cout << data << endl;
//    }
//    getchar();
//    return 0;
//}