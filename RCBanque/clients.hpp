using namespace std;
#include <iostream>
#include <iomanip>
#include <string>



class client
{
private:
    int numeroClient; // premet d'identifier le client
    // inforation du client
    string nom;
    string prenom;
    int dateNaissance;
    int numeroAdresse;
    string adresse;
    int tel;
    // a l'inscription on choisie la somme de chaque compte
    int compte_courant;
    int compte_epargne;
    int interet;

public:
    // constructeur
    client(int, string, string, int, int, string, int, int, int, int);

    // getter
    int numeroClientGet();
    string nomGet();
    string prenomGet();
    int dateNaissanceGet();
    int numeroAdresseGet();
    string adresseGet();
    int telGet();
    int comptecourantGet();
    int compteepargneGet();
    int interetGet();

    // fonction ajoutant les intérêts
    void addInteret();

    // setter
    void numeroClientSet(int value);
    void nomSet(string value);
    void prenomSet(string value);
    void dateNaissanceSet(int value);
    void numeroAdresseSet(int value);
    void adresseSet(string value);
    void telSet(int value);
    void comptecourantSet(int value);
    void compteepargneSet(int value);

    // surcharge operateur
    friend std::ostream& operator<<(std::ostream& os, const client& customer);
};
