/***************************************************************
 * Name:      netchatMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    devilstan (devilstan@gmail.com)
 * Created:   2013-08-13
 * Copyright: devilstan ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "netchatMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(netchatFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)



//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(netchatFrame)
const long netchatFrame::ID_TEXTCTRL3 = wxNewId();
const long netchatFrame::ID_TEXTCTRL4 = wxNewId();
const long netchatFrame::ID_BUTTON2 = wxNewId();
const long netchatFrame::ID_TEXTCTRL1 = wxNewId();
const long netchatFrame::ID_TEXTCTRL2 = wxNewId();
const long netchatFrame::ID_BUTTON1 = wxNewId();
const long netchatFrame::ID_PANEL1 = wxNewId();
const long netchatFrame::idMenuQuit = wxNewId();
const long netchatFrame::idMenuAbout = wxNewId();
const long netchatFrame::ID_STATUSBAR1 = wxNewId();
//*)

const long netchatFrame::ID_SOCKET = wxNewId();

BEGIN_EVENT_TABLE(netchatFrame,wxFrame)
    //(*EventTable(netchatFrame)
    //*)
END_EVENT_TABLE()

netchatFrame::netchatFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(netchatFrame)
    wxBoxSizer* BoxSizer4;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, id, _("ICQQ CLIENT"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Label"));
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("127.0.0.1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticBoxSizer1->Add(TextCtrl3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, _("000448"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    StaticBoxSizer1->Add(TextCtrl4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("LOG IN"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer1->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(332,291), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer3->Add(TextCtrl1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(188,66), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer4->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("send"), wxDefaultPosition, wxSize(75,64), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer4->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&netchatFrame::OnButton2Click1);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&netchatFrame::OnTextCtrl2TextEnter);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&netchatFrame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&netchatFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&netchatFrame::OnAbout);
    //*)
    Connect(ID_SOCKET, wxEVT_SOCKET, (wxObjectEventFunction)&netchatFrame::OnSocketEvent );
}

netchatFrame::~netchatFrame()
{
    //(*Destroy(netchatFrame)
    //*)
}

void netchatFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void netchatFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void netchatFrame::OnButton2Click1(wxCommandEvent& event)
{
	wxIPV4address addr;
	addr.Hostname( TextCtrl3->GetValue() );
	addr.Service(3000);

	m_pSocket =  new wxSocketClient();

	m_pSocket->SetEventHandler(*this, ID_SOCKET);
	m_pSocket->SetNotify(wxSOCKET_CONNECTION|wxSOCKET_INPUT_FLAG|wxSOCKET_LOST_FLAG);
	m_pSocket->Notify(true);
	m_pSocket->Connect(addr, false);
	m_pSocket->WaitOnConnect(20);
	if ( !m_pSocket->IsConnected() ) {
		wxMessageBox(_("not!"));
	}
}

void netchatFrame::OnSocketEvent(wxSocketEvent& event)
{
	wxSocketBase* sock = event.GetSocket();

	switch ( event.GetSocketEvent() )
	{
		case wxSOCKET_INPUT:
			(*TextCtrl1) << _("server input.") << _("\n");
			break;
		case wxSOCKET_LOST:
			(*TextCtrl1) << _("server disconnected.") << _("\n");
			break;
		default:
			break;
	}

	switch ( event.GetSocketEvent() )
	{
		case wxSOCKET_INPUT:
		{
			char buf[4096] = {0};
			sock->Read(buf, sizeof(buf));
            wxString str_read = wxString::FromUTF8(buf);  //收信陣列數值→字串
            *TextCtrl1 << str_read << _("\n");
            RequestUserAttention();
			//sock->Write(buf, sizeof(buf));
			//sock->Destroy();
			break;
		}
		case wxSOCKET_OUTPUT:
			break;
		case wxSOCKET_CONNECTION:
			break;
		case wxSOCKET_LOST:
		{
			sock->Destroy();
			break;
		}
		default:;
	}
}



void netchatFrame::OnButton1Click(wxCommandEvent& event)
{
//	wxString str(_("FQ"));
	wxString lstr = TextCtrl4->GetValue() + TextCtrl2->GetLineText(0);
	*TextCtrl1 << TextCtrl4->GetValue() << _("\n") << lstr << _("\n");
	//wxMessageBox(lstr);
	//*TextCtrl1 << static_cast<int>(lstr.Len());
	m_pSocket->Write( lstr.mb_str(wxConvUTF8), strlen(lstr.mb_str(wxConvUTF8)) );
//	m_pSocket->Write( str.mb_str(), 5 );
	TextCtrl2->Clear();
}

void netchatFrame::OnTextCtrl2TextEnter(wxCommandEvent& event)
{
//	wxString str(_("FQ"));
	wxString lstr = TextCtrl4->GetValue() + TextCtrl2->GetLineText(0);
	*TextCtrl1 << TextCtrl4->GetValue() << _("\n") << lstr << _("\n");
	//wxMessageBox(lstr);
	//*TextCtrl1 << static_cast<int>(lstr.Len());
	m_pSocket->Write( lstr.mb_str(wxConvUTF8), strlen(lstr.mb_str(wxConvUTF8)) );
//	m_pSocket->Write( str.mb_str(), 5 );
	TextCtrl2->Clear();
}
