#include "Clients.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// constructeur
client::client(int numC, string name1, string name2, int date, int numAd, string ad, int numTel, int courant, int epargne, int interet)
{
    this->numeroClient = numC;
    this->nom = name1;
    this->prenom = name2;
    this->dateNaissance = date;
    this->numeroAdresse = numAd;
    this->adresse = ad;
    this->tel = numTel;
    this->compte_courant = courant;
    this->compte_epargne = epargne;
    this->interet = interet;
}
int client::numeroClientGet()
{
    return (numeroClient);
}

string client::nomGet()
{
    return (nom);
}
string client::prenomGet()
{
    return (prenom);
}
int client::dateNaissanceGet()
{
    return (dateNaissance);
}
int client::numeroAdresseGet()
{
    return (numeroAdresse);
}
string client::adresseGet()
{
    return (adresse);
}
int client::telGet()
{
    return (tel);
}
int client::comptecourantGet()
{
    return (compte_courant);
}
int client::compteepargneGet()
{
    return (compte_epargne);
}
int client::interetGet()
{
    return (interet);
}
// fonction ajoutant les intérêts
void client::addInteret()
{
    compte_epargne += compte_epargne * interet / 100;
};
// setter
void client::numeroClientSet(int value)
{
    numeroClient = value;
}
void client::nomSet(string value)
{
    nom = value;
}
void client::prenomSet(string value)
{
    prenom = value;
}
void client::dateNaissanceSet(int value)
{
    dateNaissance = value;
}
void client::numeroAdresseSet(int value)
{
    numeroAdresse = value;
}
void client::adresseSet(string value)
{
    adresse = value;
}
void client::telSet(int value)
{
    tel = value;
}
void client::comptecourantSet(int value)
{
    compte_courant = value;
}
void client::compteepargneSet(int value)
{
    compte_epargne = value;
}