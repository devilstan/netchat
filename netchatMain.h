/***************************************************************
 * Name:      netchatMain.h
 * Purpose:   Defines Application Frame
 * Author:    devilstan (devilstan@gmail.com)
 * Created:   2013-08-13
 * Copyright: devilstan ()
 * License:
 **************************************************************/

#ifndef NETCHATMAIN_H
#define NETCHATMAIN_H

//(*Headers(netchatFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include <wx/socket.h>

class netchatFrame: public wxFrame
{
    public:

        netchatFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~netchatFrame();

    private:

        //(*Handlers(netchatFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrl2TextEnter(wxCommandEvent& event);
        //*)

        void OnSocketEvent(wxSocketEvent& event);

        //(*Identifiers(netchatFrame)
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        static const long ID_SOCKET;

        //(*Declarations(netchatFrame)
        wxTextCtrl* TextCtrl4;
        wxButton* Button1;
        wxPanel* Panel1;
        wxButton* Button2;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl5;
        wxTextCtrl* TextCtrl3;
        //*)

        wxSocketClient* m_pSocket;

        DECLARE_EVENT_TABLE()
};

#endif // NETCHATMAIN_H
