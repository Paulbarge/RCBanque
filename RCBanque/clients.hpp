using namespace std;

class client {
private:
    int numeroClient;//premet d'identifier le client 
    //inforation du client
    string nom;
    string prenom;
    int dateNaissance;
    int numeroAdresse;
    string adresse;
    int tel;





public:
    //constructeur 
    client(int, string, string, int, int, string, int);

    //getter
    int numeroClientGet();
    string nomGet();
    string prenomGet();
    int dateNaissanceGet();
    int numeroAdresseGet();
    string adresseGet();
    int telGet();


    //setter
    void numeroClientSet(int value);
    void nomSet(string value);
    void prenomSet(string value);
    void dateNaissanceSet(int value);
    void numeroAdresseSet(int value);
    void adresseSet(string value);
    void telSet(int value);



};

