#ifndef EPARGNEFRAME_H_INCLUDED
#define EPARGNEFRAME_H_INCLUDED

//include classique
#include "wx/wx.h"
#include "clients.hpp"
//Definition de notre classe mainFrame
class EpargneFrame : public wxFrame
{
public:
	//constructeur
	EpargneFrame();
	//destructeur
	~EpargneFrame();

	void setSolde(client* client);
private:
	wxString m_solde;//Solde a afficher
	wxStaticText* soldeEpargne;//pointeur sur notre solde pour le mettre à jour
};

#endif