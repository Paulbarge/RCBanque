#ifndef INSCRIPTIONFRAME_H_INCLUDED
#define INSCRIPTIONFRAME_H_INCLUDED

//include classique
#include "wx/wx.h"
#include <vector>
//Definition de notre classe mainFrame
class InscriptionFrame : public wxFrame
{
public:
	//constructeur
	InscriptionFrame();
	//destructeur
	~InscriptionFrame();
	void setFramePtn(InscriptionFrame* frame);
private:
	InscriptionFrame* m_frame; //pointeru sur notre frame
	wxTextCtrl* m_nom, *m_prenom,* m_date,* m_tel,*m_fond;//pointeurs sur les valeurs à recpupérer
	wxRadioBox* m_radioBox; //pointeur sur la radio box
	//identifiants boutons
	static const int ID_BTN_VALIDER, ID_BTN_ANNULER;

	//event bouttons click
	void OnButtonValiderClicked(wxCommandEvent& event);
	void OnButtonAnnulerClicked(wxCommandEvent& event);

	//tabble des evenements
	DECLARE_EVENT_TABLE();
};

#endif