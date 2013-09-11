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
#include <wx/notebook.h>
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
        void OnKeyDown(wxKeyEvent& event);
        void OnNotebook1PageChanged(wxNotebookEvent& event);
        //*)
        
        //­­¨î·Æ¹«¨Æ¥ó		
		void OnEnterNotebook1() {
			//CaptureMouse();
		}
		void OnLeaveNotebook1() {
			//ReleaseMouse();
		}
		void OnMoveNotebook1( wxMouseEvent& event ) {
			wxPoint pos = event.GetPosition();
			wxString x,y;
			x << pos.x;
			y << pos.y;
			StatusBar1->SetStatusText(x,0);
			StatusBar1->SetStatusText(y,1);
			if ( m_Restricted.Contains(pos) ) {
					WarpPointer(43, 496);
			} 
			else {
				//if ( HasCapture() )
					//ReleaseMouse();
			}
		}

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
        static const long ID_PANEL2;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_BUTTON8;
        static const long ID_BUTTON9;
        static const long ID_BUTTON10;
        static const long ID_BUTTON11;
        static const long ID_BUTTON12;
        static const long ID_BUTTON13;
        static const long ID_BUTTON14;
        static const long ID_BUTTON15;
        static const long ID_BUTTON16;
        static const long ID_BUTTON17;
        static const long ID_BUTTON1;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_PANEL3;
        static const long ID_NOTEBOOK1;
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
        wxBoxSizer* BoxSizer6;
        wxButton* Button4;
        wxNotebook* Notebook1;
        wxStaticText* StaticText2;
        wxTextCtrl* TextCtrl6_username;
        wxRichTextCtrl* RichTextCtrl1;
        wxTextCtrl* TextCtrl7_passwd;
        wxButton* Button1;
        wxButton* Button14;
        wxCheckListBox* CheckListBox1_usetlist;
        wxButton* Button2_logout;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxColourPickerCtrl* ColourPickerCtrl1;
        wxBoxSizer* BoxSizer2;
        wxStaticText* StaticText3;
        wxButton* Button2;
        wxButton* Button3_logon;
        wxPanel* Panel3;
        wxButton* Button6;
        wxButton* Button10;
        wxButton* Button11;
        wxButton* Button5;
        wxButton* Button3;
        wxButton* Button7;
        wxStatusBar* StatusBar1;
        wxButton* Button9;
        wxTextCtrl* TextCtrl2;
        wxBoxSizer* BoxSizer1;
        wxTextCtrl* TextCtrl1;
        wxPanel* Panel2;
        wxButton* Button15;
        wxButton* Button13;
        wxTextCtrl* TextCtrl3;
        wxButton* Button8;
        wxTimer Timer1;
        wxButton* Button12;
        //*)

        wxSocketClient* m_pSocket;
        MsgPackage *m_pPackage;
        wxColour m_colour;
        wxRect m_Restricted;
        wxPoint m_Last;
        size_t m_ver;

        DECLARE_EVENT_TABLE()
};

#endif // NETCHATMAIN_H
