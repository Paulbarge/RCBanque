#include "epargneFrame.h"
#include "inscriptionFrame.h"
#include "clients.hpp"
#include <string>

EpargneFrame::EpargneFrame() :wxFrame(NULL, wxID_ANY, _T("RCBanque")) {
    wxBoxSizer* mainsizer = new wxBoxSizer(wxVERTICAL);
        //solde
        wxStaticBoxSizer* soldeEpargneBox = new wxStaticBoxSizer(wxVERTICAL, this, _T("Solde compte épargne :"));
            soldeEpargne = new wxStaticText(this, wxID_ANY, _T(""));
            soldeEpargneBox->Add(soldeEpargne, 0, wxALL | wxALIGN_CENTER, 50);
        mainsizer->Add(soldeEpargneBox, 0, wxALL | wxEXPAND, 10);

        //historique
        wxStaticBoxSizer* historiqueEpargneBox = new wxStaticBoxSizer(wxVERTICAL, this, _T("Historique transactions :"));
            //code liste transaction
            //.....
            //.....
        mainsizer->Add(historiqueEpargneBox, 0, wxALL | wxEXPAND, 10);
    //affectation main sizer
    SetSizer(mainsizer);
    mainsizer->SetSizeHints(this);
}

EpargneFrame::~EpargneFrame() {
    //Destructeur
}

void EpargneFrame::setSolde(client* client) {
    m_solde << client->compteepargneGet();
    soldeEpargne->SetLabel(m_solde);
}
