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

#include <google/protobuf/message.h>

bool shownflg = true;

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
const long netchatFrame::ID_STATICTEXT1 = wxNewId();
const long netchatFrame::ID_TEXTCTRL6 = wxNewId();
const long netchatFrame::ID_STATICTEXT2 = wxNewId();
const long netchatFrame::ID_TEXTCTRL7 = wxNewId();
const long netchatFrame::ID_BUTTON3 = wxNewId();
const long netchatFrame::ID_TEXTCTRL3 = wxNewId();
const long netchatFrame::ID_TEXTCTRL4 = wxNewId();
const long netchatFrame::ID_TEXTCTRL5 = wxNewId();
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
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("ICQQ CLIENT"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("請輸入帳號密碼"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("username"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticBoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl6_username = new wxTextCtrl(Panel1, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    StaticBoxSizer2->Add(TextCtrl6_username, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("passed"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticBoxSizer2->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl7_passwd = new wxTextCtrl(Panel1, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    StaticBoxSizer2->Add(TextCtrl7_passwd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("登入"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer2->Add(Button3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Label"));
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("172.16.132.141"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticBoxSizer1->Add(TextCtrl3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, _("000448"), wxDefaultPosition, wxSize(54,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    StaticBoxSizer1->Add(TextCtrl4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl5 = new wxTextCtrl(Panel1, ID_TEXTCTRL5, _("001123"), wxDefaultPosition, wxSize(46,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    StaticBoxSizer1->Add(TextCtrl5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&netchatFrame::OnButton3Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&netchatFrame::OnButton2Click1);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&netchatFrame::OnTextCtrl2TextEnter);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&netchatFrame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&netchatFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&netchatFrame::OnAbout);
    //*)
    Connect(ID_SOCKET, wxEVT_SOCKET, (wxObjectEventFunction)&netchatFrame::OnSocketEvent );
    m_pSocket =  NULL;
    m_pPackage = new MsgPackage();
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
	Button2->Enable(false);
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
		Button2->Enable();
	}else{
		Button2->Enable(false);
		TextCtrl3->Enable(false);
		TextCtrl4->Enable(false);
		std::string temp_username = std::string( TextCtrl4->GetValue().mb_str(wxConvUTF8) );
		m_pPackage->set_m_susername( temp_username );
		SendPackage( m_pSocket, m_pPackage );
		//m_pSocket->Write( TextCtrl4->GetValue().mb_str(wxConvUTF8), strlen(TextCtrl4->GetValue().mb_str(wxConvUTF8)) );
	}
}

void netchatFrame::OnSocketEvent(wxSocketEvent& event)
{
	wxSocketBase* sock = event.GetSocket();

	switch ( event.GetSocketEvent() )
	{
		case wxSOCKET_INPUT:
			//(*TextCtrl1) << _("server input.") << _("\n");
			break;
		case wxSOCKET_LOST:
			(*TextCtrl1) << _("server's DOWN!!!!!! bye bye.") << _("\n");
			break;
		default:
			break;
	}

	switch ( event.GetSocketEvent() )
	{
		case wxSOCKET_INPUT:
		{
			MsgPackage package_read = ReadPackage( sock );
			wxString str_read_user = wxString::FromUTF8( package_read.m_susername().c_str() );  
			wxString str_read_msg = wxString::FromUTF8( package_read.msg().c_str() );  
            *TextCtrl1 << str_read_user << _("\n") << str_read_msg << _("\n");
            RequestUserAttention();
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
	//宣告傳送序列資料buffer
	std::string mubuffer;
	//結構序列化
	m_pPackage->SerializeToString( &mubuffer );
	//傳送
	m_pSocket->Write( mubuffer.c_str(), m_pPackage->ByteSize() );
//	if ( !TextCtrl2->GetLineText(0).IsEmpty() ) {
//		wxString lstr = TextCtrl4->GetValue() + _(",") + TextCtrl5->GetValue() + _(":") + TextCtrl2->GetLineText(0);
//		*TextCtrl1 << TextCtrl4->GetValue() + _(":") << _("\n") << TextCtrl2->GetLineText(0) << _("\n");
//		if ( m_pSocket != NULL ) {
//			if ( m_pSocket->IsConnected() ) {
//				m_pSocket->Write( lstr.mb_str(wxConvUTF8), strlen(lstr.mb_str(wxConvUTF8)) );
//			}
//		}
//		TextCtrl2->Clear();
//	}
}

void netchatFrame::OnTextCtrl2TextEnter(wxCommandEvent& event)
{
	if ( !TextCtrl2->GetLineText(0).IsEmpty() ) {
		std::string msgbuf = std::string( TextCtrl2->GetValue().mb_str(wxConvUTF8) );
		m_pPackage->set_msg( msgbuf );
		SendPackage( m_pSocket, m_pPackage );
		//m_pPackage->SerializeToString( &sendbuffer );
		//m_pSocket->Write( sendbuffer.c_str(), m_pPackage->ByteSize() );
		TextCtrl2->Clear();
	}
//	if ( !TextCtrl2->GetLineText(0).IsEmpty() ) {
//		wxString lstr = TextCtrl4->GetValue() + _(",") + TextCtrl5->GetValue() + _(":") + TextCtrl2->GetLineText(0);
//		*TextCtrl1 << TextCtrl4->GetValue() + _(":") << _("\n") << TextCtrl2->GetLineText(0) << _("\n");
//		if ( m_pSocket != NULL ) {
//			if ( m_pSocket->IsConnected() ) {
//				m_pSocket->Write( lstr.mb_str(wxConvUTF8), strlen(lstr.mb_str(wxConvUTF8)) );
//			}
//		}
//		TextCtrl2->Clear();
//	}
}

void netchatFrame::SendPackage( wxSocketClient* socketclient, MsgPackage* package_tmp )
{
	std::string sbuffer;
	package_tmp->SerializeToString( &sbuffer );
	socketclient->Write( sbuffer.c_str(), package_tmp->ByteSize() );
}

MsgPackage netchatFrame::ReadPackage( wxSocketBase* sock )
{
	unsigned char buf[4096] = {0};
	sock->Read(buf, sizeof(buf));
	std::string myread((const char*)buf);
	MsgPackage package_tmp;
	package_tmp.ParseFromString(myread);
	return package_tmp;
}

std::string netchatFrame::wxStringToString(const wxString& s)
{
	std::string str_tmp = std::string( s.mb_str(wxConvUTF8) );
	return str_tmp;
}

wxString netchatFrame::StringTowxString(const std::string& s)
{
	wxString wxstr_tmp = wxString::FromUTF8( s.c_str() );
	return wxstr_tmp;
}


void netchatFrame::OnButton3Click(wxCommandEvent& event)
{
	if ( shownflg ) {
		StaticBoxSizer2->Show(false);
		shownflg = false;
	}else {
		StaticBoxSizer2->Show(true);
		shownflg = true;
	}
	BoxSizer2->RecalcSizes();
}
