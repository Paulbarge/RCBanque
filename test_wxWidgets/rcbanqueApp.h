#ifndef RCBANQUEAPP_H_INCLUDED
#define RCBANQUEAPP_H_INCLUDED

#include "wx/wx.h"
#include "Clients.hpp"


class rcBanqueApp : public wxApp
{
public:
	virtual bool OnInit();
};

DECLARE_APP(rcBanqueApp);


#endif
