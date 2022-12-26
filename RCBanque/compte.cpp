#include <iostream>
#include <string>
#include "compte.hpp"

using namespace std;

//constructeur
compte::compte(string type, float fonds, float interet) {
    this->typeCompte = type;
    this->fonds = fonds;
    this->interet = interet;
}

//getters
const int compte::getFonds() {
    return this->fonds;
}

const string compte::getTypeCompte() {
    return this->typeCompte;
}

const int compte::getInteret() {
    return this->interet;
}

//fonction ajoutant les intérêts
void compte::addInteret() {
    float fonds = this->getFonds();
    float interet = this->getInteret();
    this->fonds += fonds * interet / 100;
};