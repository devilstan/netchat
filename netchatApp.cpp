/***************************************************************
 * Name:      netchatApp.cpp
 * Purpose:   Code for Application Class
 * Author:    devilstan (devilstan@gmail.com)
 * Created:   2013-08-13
 * Copyright: devilstan ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "netchatApp.h"

//(*AppHeaders
#include "netchatMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(netchatApp);

bool netchatApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	netchatFrame* Frame = new netchatFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
