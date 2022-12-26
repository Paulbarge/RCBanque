using namespace std;

class compte //création de l'objet compte
{
private:
    string typeCompte; //permet de ranger le compte (epargne, debit ...)
    float fonds; //argent sur le compte
    float interet; //interet pour le type de compte
public:
    compte(string, float, float); //constructeur
    const int getFonds(); //getters
    const string getTypeCompte();
    const int getInteret();
    void addInteret(); //fonction ajoutant les intérêts
};

