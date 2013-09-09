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
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
#include <wx/panel.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/clrpicker.h>
#include <wx/statusbr.h>
//*)

#include <wx/socket.h>
#include "proto/MsgPackage.pb.h"

class netchatFrame: public wxFrame
{
    public:

        netchatFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~netchatFrame();

    private:

        //(*Handlers(netchatFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrl2TextEnter(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton3_logonClick(wxCommandEvent& event);
        void OnButton2_logoutClick(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnColourPickerCtrl1ColourChanged(wxColourPickerEvent& event);
        //*)

        void OnSocketEvent(wxSocketEvent& event);
        void SendPackage( wxSocketClient* socketclient, MsgPackage* package_tmp );
        MsgPackage ReadPackage(wxSocketBase* sock);
        std::string wxStringToString( const wxString& );
        wxString StringTowxString( const std::string& );
        void showtext(wxTextCtrl* tc, wxString s);

        //(*Identifiers(netchatFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL7;
        static const long ID_BUTTON3;
        static const long ID_TEXTCTRL3;
        static const long ID_BUTTON2;
        static const long ID_RICHTEXTCTRL1;
        static const long ID_CHECKLISTBOX1;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_COLOURPICKERCTRL1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        static const long ID_SOCKET;

        //(*Declarations(netchatFrame)
        wxStaticBoxSizer* StaticBoxSizer2;
        wxStaticText* StaticText2;
        wxTextCtrl* TextCtrl6_username;
        wxRichTextCtrl* RichTextCtrl1;
        wxTextCtrl* TextCtrl7_passwd;
        wxCheckListBox* CheckListBox1_usetlist;
        wxButton* Button2_logout;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxColourPickerCtrl* ColourPickerCtrl1;
        wxBoxSizer* BoxSizer2;
        wxStaticText* StaticText3;
        wxButton* Button3_logon;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl2;
        wxBoxSizer* BoxSizer1;
        wxTextCtrl* TextCtrl3;
        wxTimer Timer1;
        //*)

        wxSocketClient* m_pSocket;
        MsgPackage *m_pPackage;
        wxColour m_colour;
        size_t m_ver;

        DECLARE_EVENT_TABLE()
};

#endif // NETCHATMAIN_H
