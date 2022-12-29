#include "Clients.hpp"
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
//version const
int  client::numeroClientGet1()const
{
    return (numeroClient);
}

string  client::nomGet1()const
{
    return (nom);
}
string client::prenomGet1() const
{
    return (prenom);
}
int  client::dateNaissanceGet1()const
{
    return (dateNaissance);
}
int  client::numeroAdresseGet1()const
{
    return (numeroAdresse);
}
string  client::adresseGet1()const
{
    return (adresse);
}
int  client::telGet1() const
{
    return (tel);
}
int  client::comptecourantGet1()const
{
    return (compte_courant);
}
int  client::compteepargneGet1()const
{
    return (compte_epargne);
}
int  client::interetGet1() const
{
    return (interet);
}
std::ostream& operator<<(std::ostream& os,const client& customer) {
    os << "numero_client" << customer.numeroClientGet1() << std::endl;
    os << "Nom" << customer.nomGet1() << std::endl;
    os << "Prenom" << customer.prenomGet1() << std::endl;
    os << "dateNaissance" << customer.dateNaissanceGet1() << std::endl;
    os << "numeroAdresse" << customer.numeroAdresseGet1() << std::endl;
    os << "adresse" << customer.adresseGet1() << std::endl;
    os << "tel" << customer.telGet1() << std::endl;
    os << "compte_courant" << customer.comptecourantGet1() << std::endl;
    os << "compte_epargne" << customer.compteepargneGet1() << std::endl;
    os << "interet" << customer.interetGet1() << std::endl;
    return os;
}