#include "clients.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//constructeur 
client::client(int numC, string name1, string name2, int date, int numAd, string ad, int numTel) {
    this->numeroClient = numC;
    this->nom = name1;
    this->prenom = name2;
    this->dateNaissance = date;
    this->numeroAdresse = numAd;
    this->adresse = ad;
    this->tel = numTel;

}
int client::numeroClientGet() {
    return(numeroClient);
}

string client::nomGet() {
    return(nom);
}
string client::prenomGet() {
    return(prenom);
}
int client::dateNaissanceGet() {
    return(dateNaissance);
}
int client::numeroAdresseGet() {
    return(numeroAdresse);
}
string client::adresseGet() {
    return(adresse);
}
int client::telGet() {
    return(tel);
}


//setter
void client::numeroClientSet(int value) {
    numeroClient = value;
}
void client::nomSet(string value) {
    nom = value;
}
void client::prenomSet(string value) {
    prenom = value;
}
void client::dateNaissanceSet(int value) {
    dateNaissance = value;
}
void client::numeroAdresseSet(int value) {
    numeroAdresse = value;
}
void client::adresseSet(string value) {
    adresse = value;
}
void client::telSet(int value) {
    tel = value;
}



