#include "inscriptionFrame.h"
#include "clients.hpp"
#include <string>

//on affecte les identifiants aux boutons
const int InscriptionFrame::ID_BTN_VALIDER = wxNewId();
const int InscriptionFrame::ID_BTN_ANNULER = wxNewId();
//Definition de la table des evenements
BEGIN_EVENT_TABLE(InscriptionFrame, wxFrame)
    EVT_BUTTON(ID_BTN_VALIDER, InscriptionFrame::OnButtonValiderClicked)
    EVT_BUTTON(ID_BTN_ANNULER, InscriptionFrame::OnButtonAnnulerClicked)
END_EVENT_TABLE()

InscriptionFrame::InscriptionFrame() :wxFrame(NULL, wxID_ANY, _T("RCBanque")) {
    // Création du panel d'affichage
    wxPanel* panelAffichage = new wxPanel(this, -1);

    // Création du wxBoxSizer intermédiaire
    wxBoxSizer* sizer_intermed = new wxBoxSizer(wxVERTICAL);

        // Création du wxStaticBoxSizer pour le cadre
        wxStaticBoxSizer* cadre = new wxStaticBoxSizer(wxVERTICAL, panelAffichage, _T("Création d'un utilisateur : "));
            // Création du wxFlexGridSizer
            wxFlexGridSizer* grille = new wxFlexGridSizer(6, 2, 5, 5);

                // wxStaticText pour le nom
                wxStaticText* labelNom = new wxStaticText(panelAffichage, -1, _T("Nom :"));
                grille->Add(labelNom, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
                // wxTextCtrl pour le nom
                m_nom = new wxTextCtrl(panelAffichage, -1, _T(""));
                grille->Add(m_nom, 0, wxEXPAND);

                // wxStaticText pour le prénom
                wxStaticText* labelPrenom = new wxStaticText(panelAffichage, -1, _T("Prénom :"));
                grille->Add(labelPrenom, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
                // wxTextCtrl pour le prénom
                m_prenom = new wxTextCtrl(panelAffichage, -1, _T(""));
                grille->Add(m_prenom, 0, wxEXPAND);

                // wxStaticText pour la date de naissance
                wxStaticText* labelDate = new wxStaticText(panelAffichage, -1, _T("Date de naissance :"));
                grille->Add(labelDate, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
                // wxTextCtrl pour la date de naissance
                m_date = new wxTextCtrl(panelAffichage, -1, _T(""));
                grille->Add(m_date, 0, wxEXPAND);

                // wxStaticText pour le tel
                wxStaticText* labelTel = new wxStaticText(panelAffichage, -1, _T("Tel :"));
                grille->Add(labelTel, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
                // wxTextCtrl pour le tel
                m_tel = new wxTextCtrl(panelAffichage, -1, _T(""));
                grille->Add(m_tel, 0, wxEXPAND);

                // wxStaticText pour les sous
                wxStaticText* labelFond = new wxStaticText(panelAffichage, -1, _T("Fonds (en €) souhaités :"));
                grille->Add(labelFond, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
                // wxTextCtrl pour les sous
                m_fond = new wxTextCtrl(panelAffichage, -1, _T(""));
                grille->Add(m_fond, 0, wxEXPAND);

                //wxStaticText pour banque
                wxStaticText* labelBanque = new wxStaticText(panelAffichage, -1, _T("Banque d'inscription :"));
                grille->Add(labelBanque, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_RIGHT);
                //radio box pour banque
                wxArrayString choices;
                choices.Add("RCBanque");
                choices.Add("LilloisBanque");
                choices.Add("BanqueParis");
                m_radioBox = new wxRadioBox(panelAffichage, wxID_ANY, _T("Banque désirée :"), wxDefaultPosition, wxDefaultSize, choices, 3, wxRA_VERTICAL);
                grille->Add(m_radioBox, 0, wxEXPAND);

            // Ajout de la grille au wxStaticBoxSizer
            cadre->Add(grille, 1, wxALL | wxEXPAND, 5);
            // La deuxième colonne est extensible
            grille->AddGrowableCol(1);      
        // Ajout du wxStaticBoxSizer au sizer intermédiaire
        sizer_intermed->Add(cadre, 1, wxALL | wxEXPAND, 5);


        // Création du wxBoxSizer pour les boutons
        wxBoxSizer* sizer_boutons = new wxBoxSizer(wxHORIZONTAL);
            // Création du bouton "Valider"
            wxButton* btnValider = new wxButton(panelAffichage, ID_BTN_VALIDER, _T("Valider"));
            sizer_boutons->Add(btnValider, 0);

            // Ajout d'un espace entre les deux boutons
            sizer_boutons->AddSpacer(5);

            // Création du bouton "Annuler"
            wxButton* btnAnnuler = new wxButton(panelAffichage, ID_BTN_ANNULER, _T("Annuler"));
            sizer_boutons->Add(btnAnnuler, 0);
        // Ajout du sizer des boutons au sizer intermédiaire
        sizer_intermed->Add(sizer_boutons, 0, wxALIGN_RIGHT | wxALL, 5);

    // Affectation du sizer intermédiaire au wxPanel
    panelAffichage->SetSizer(sizer_intermed);
    sizer_intermed->SetSizeHints(this);
}

InscriptionFrame::~InscriptionFrame() {
    //Destructeur
}

void InscriptionFrame::setFramePtn(InscriptionFrame* frame) {
    m_frame = frame;
}


void InscriptionFrame::OnButtonValiderClicked(wxCommandEvent& event) {
    wxString s_nom = m_nom->GetValue();
    wxString s_prenom = m_prenom->GetValue();
    wxString s_date = m_date->GetValue();
    wxString s_tel = m_tel->GetValue();
    wxString s_fond = m_fond->GetValue();

    if (s_nom=="" || s_prenom == "" || s_date == "" || s_tel == "" || s_fond == "") {
        wxMessageBox(_T("Veuillez remplir tous les champs correctement svp."));
    }
    else {
        client* newClient = new client(0, m_nom->GetValue().ToStdString(), m_prenom->GetValue().ToStdString(), wxAtoi(m_date->GetValue()), wxAtoi(m_tel->GetValue()), wxAtoi(m_fond->GetValue()), 0, 2);
        //code PAUL on assigne touts les pointeurs
        // 
        // 
        // 
        // 
        // 
        // 
        // 
        //on ferme la fenetre
        m_frame->Destroy();
    }
}

void InscriptionFrame::OnButtonAnnulerClicked(wxCommandEvent& event) {
    //code annulation
    m_frame->Destroy();
}