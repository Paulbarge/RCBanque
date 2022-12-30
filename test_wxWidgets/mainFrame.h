#ifndef MAINFRAME_H_INCLUDED
#define MAINFRAME_H_INCLUDED

//include classique
#include "wx/wx.h"
#include "clients.hpp"
#include <vector>
//Definition de notre classe mainFrame
class MainFrame : public wxFrame
{
public:
	//constructeur
	MainFrame();
	//destructeur
	~MainFrame();
private:
	client* actualClient; //stocck le client actuel
	vector< client* > clientsTbl; //stock la totalité des profils
	//pointeur vers les montants d'argents
	wxStaticText* soldeDepot, *epargneMtn;
	//identifiants boutons
	static const int ID_BTN_DEPOT, ID_BTN_EPARGNE, ID_BTN_VIREMENT, ID_BTN_PROFIL;

	//event bouttons click
	void OnButtonDepotClicked(wxCommandEvent& event);
	void OnButtonEpargneClicked(wxCommandEvent& event);
	void OnButtonVirementClicked(wxCommandEvent& event);
	void OnButtonProfilClicked(wxCommandEvent& event);

	//tabble des evenements
	DECLARE_EVENT_TABLE();
};

#endif