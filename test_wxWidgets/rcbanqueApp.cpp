#include "rcbanqueApp.h"
#include "mainFrame.h"
#include "inscriptionFrame.h"
#include "clients.hpp"
#include <string>

client* actualClient;
//definitiion onInit
bool rcBanqueApp::OnInit()
{
	//on cr�er un objet mainFrame
	MainFrame* frame = new MainFrame();
	//on l'affiche
	frame->Show();
	//indique que l'application peut continuer 
	return true;
}

IMPLEMENT_APP(rcBanqueApp);
