#ifndef DEPOTFRAME_H_INCLUDED
#define DEPOTFRAME_H_INCLUDED

//include classique
#include "wx/wx.h"
#include "clients.hpp"
//Definition de notre classe mainFrame
class DepotFrame : public wxFrame
{
public:
	//constructeur
	DepotFrame();
	//destructeur
	~DepotFrame();

	void setSolde(client* client);
private:
	wxString m_solde;//Solde a afficher
	wxStaticText* soldeDepot;//pointeur sur notre solde pour le mettre à jour
};

#endif