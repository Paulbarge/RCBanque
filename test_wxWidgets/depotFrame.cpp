#include "depotFrame.h"
#include "inscriptionFrame.h"
#include "clients.hpp"
#include <string>

DepotFrame::DepotFrame() :wxFrame(NULL, wxID_ANY, _T("RCBanque")) {
    wxBoxSizer* mainsizer = new wxBoxSizer(wxVERTICAL);
        //solde
        wxStaticBoxSizer* soldeDepotBox = new wxStaticBoxSizer(wxVERTICAL,this, _T("Solde compte dépôt :"));
            soldeDepot = new wxStaticText(this,wxID_ANY, _T(""));
            soldeDepotBox->Add(soldeDepot, 0, wxALL |wxALIGN_CENTER, 50);
        mainsizer->Add(soldeDepotBox, 0, wxALL | wxEXPAND, 10);

        //historique
        wxStaticBoxSizer* historiqueDepotBox = new wxStaticBoxSizer(wxVERTICAL, this, _T("Historique transactions :"));
        
        mainsizer->Add(historiqueDepotBox, 0, wxALL | wxEXPAND, 10);
    //affectation main sizer
    SetSizer(mainsizer);
    mainsizer->SetSizeHints(this);
}

DepotFrame::~DepotFrame() {
    //Destructeur
}

void DepotFrame::setSolde(client* client) {
    m_solde << client->comptecourantGet();
    soldeDepot->SetLabel(m_solde);
}