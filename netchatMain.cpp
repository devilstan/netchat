﻿/***************************************************************
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
const long netchatFrame::ID_BUTTON2 = wxNewId();
const long netchatFrame::ID_RICHTEXTCTRL1 = wxNewId();
const long netchatFrame::ID_CHECKLISTBOX1 = wxNewId();
const long netchatFrame::ID_TEXTCTRL2 = wxNewId();
const long netchatFrame::ID_STATICTEXT3 = wxNewId();
const long netchatFrame::ID_COLOURPICKERCTRL1 = wxNewId();
const long netchatFrame::ID_PANEL1 = wxNewId();
const long netchatFrame::idMenuQuit = wxNewId();
const long netchatFrame::idMenuAbout = wxNewId();
const long netchatFrame::ID_STATUSBAR1 = wxNewId();
const long netchatFrame::ID_TIMER1 = wxNewId();
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
    wxBoxSizer* BoxSizer5;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
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
    TextCtrl6_username = new wxTextCtrl(Panel1, ID_TEXTCTRL6, _("hello"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    StaticBoxSizer2->Add(TextCtrl6_username, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("passwd"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticBoxSizer2->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl7_passwd = new wxTextCtrl(Panel1, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    StaticBoxSizer2->Add(TextCtrl7_passwd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3_logon = new wxButton(Panel1, ID_BUTTON3, _("登入"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer2->Add(Button3_logon, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Server"));
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("127.0.0.1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticBoxSizer1->Add(TextCtrl3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2_logout = new wxButton(Panel1, ID_BUTTON2, _("logout"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2_logout->Disable();
    StaticBoxSizer1->Add(Button2_logout, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    RichTextCtrl1 = new wxRichTextCtrl(Panel1, ID_RICHTEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(284,350), wxRE_MULTILINE|wxRE_READONLY, wxDefaultValidator, _T("ID_RICHTEXTCTRL1"));
    wxRichTextAttr rchtxtAttr_1;
    BoxSizer3->Add(RichTextCtrl1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckListBox1_usetlist = new wxCheckListBox(Panel1, ID_CHECKLISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, wxLB_MULTIPLE, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
    BoxSizer3->Add(CheckListBox1_usetlist, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(188,66), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl2->Disable();
    BoxSizer4->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("color"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer5->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ColourPickerCtrl1 = new wxColourPickerCtrl(Panel1, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
    BoxSizer5->Add(ColourPickerCtrl1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(BoxSizer5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
    Timer1.SetOwner(this, ID_TIMER1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&netchatFrame::OnButton3_logonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&netchatFrame::OnButton2_logoutClick);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&netchatFrame::OnTextCtrl2TextEnter);
    Connect(ID_COLOURPICKERCTRL1,wxEVT_COMMAND_COLOURPICKER_CHANGED,(wxObjectEventFunction)&netchatFrame::OnColourPickerCtrl1ColourChanged);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&netchatFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&netchatFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&netchatFrame::OnTimer1Trigger);
    //*)
    Connect(ID_SOCKET, wxEVT_SOCKET, (wxObjectEventFunction)&netchatFrame::OnSocketEvent );
    m_pSocket =  NULL;
    m_pPackage = new MsgPackage();
    m_ver = 20130909;
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

void netchatFrame::OnButton3_logonClick(wxCommandEvent& event)
{
	wxString user_tmp = TextCtrl6_username->GetValue();
	wxString user_trim = user_tmp.Trim();
	if ( user_trim.empty() ) {
		wxMessageBox(_("OH oh！！Mr. Blank, I can NOT allow you to login for some mystery reason."));
	}
	else {
		Button3_logon->Enable(false);
		TextCtrl3->Enable(false);
		TextCtrl6_username->Enable(false);
		TextCtrl7_passwd->Enable(false);
		wxIPV4address addr;
		addr.Hostname( TextCtrl3->GetValue() );
		addr.Service(3000);

		m_pSocket =  new wxSocketClient();

		m_pSocket->SetEventHandler(*this, ID_SOCKET);
		m_pSocket->SetNotify(wxSOCKET_CONNECTION|wxSOCKET_INPUT_FLAG|wxSOCKET_LOST_FLAG);
		m_pSocket->Notify(true);
		//m_pPackage->clear_m_nsock_id()
		//m_pPackage->set_m_login_flag(false);
		m_pPackage->set_m_susername( wxStringToString( TextCtrl6_username->GetValue() ) );
		m_pPackage->set_ver( m_ver );
		m_pSocket->Connect(addr, false);
		m_pSocket->WaitOnConnect(5);
		if ( !m_pSocket->IsConnected() ) {
			wxMessageBox(_("not!"));
			Button3_logon->Enable();
			TextCtrl3->Enable();
			TextCtrl6_username->Enable();
			TextCtrl7_passwd->Enable();
		}else{
			//Button2_logout->Enable(false);
			//Button2_logout->Hide();
			Button3_logon->Enable(false);
			TextCtrl3->Enable(false);
			TextCtrl6_username->Enable(false);
			TextCtrl7_passwd->Enable(false);
			//m_pPackage->Clear();
		}
		UpdateWindowUI();
	}
}

void netchatFrame::OnSocketEvent(wxSocketEvent& event)
{
	wxSocketBase* sock = event.GetSocket();

	switch ( event.GetSocketEvent() )
	{
		case wxSOCKET_INPUT:
			break;
		case wxSOCKET_LOST:
			(*RichTextCtrl1) << _("server's DOWN!!!!!! bye bye.") << _("\n");
			break;
		default:
			break;
	}
	
	wxString colour_str;
	wxColour colour_custom;
	switch ( event.GetSocketEvent() )
	{
		//接收處理
		case wxSOCKET_INPUT:
		{
			MsgPackage package_r = ReadPackage( sock );
			//(*m_pPackage) = package_r;	//接收封包副本
			switch ( package_r.handle() )
			{
				case 0x00: //未登入
					switch ( package_r.m_login_stage() )
					{
						case 0:
							(*RichTextCtrl1) << StringTowxString(package_r.m_susername()) + _(": login stage(0x00) = ") << package_r.m_login_stage() << _("\n");
							(*RichTextCtrl1) << StringTowxString(package_r.msg()) << _("\n");
							break;
						case 1:
							(*RichTextCtrl1) << StringTowxString(package_r.m_susername()) + _(": login stage(0x00) = ") << package_r.m_login_stage() << _("\n");
							m_pPackage->set_m_susername( wxStringToString( TextCtrl6_username->GetValue() ) );
							m_pPackage->set_m_nsock_id( package_r.m_nsock_id() );
							m_pPackage->set_m_login_stage(2);
							SendPackage( m_pSocket, m_pPackage );
							break;
						case 2:
							(*RichTextCtrl1) << StringTowxString(package_r.m_susername()) + _(": login stage(0x00) = ") << package_r.m_login_stage() << _("\n");
							(*RichTextCtrl1) << _("hey dude, 這世界上的 ") + TextCtrl6_username->GetValue() + _(" 只有一個...ㄎㄎ") << _("\n");
							break;
						case 3:
							(*RichTextCtrl1) << StringTowxString(package_r.m_susername()) + _(": login stage(0x00) = ") << package_r.m_login_stage() << _("\n");
							if ( package_r.m_login_flag() ) {
								m_pPackage->set_m_login_flag(true);
								m_pPackage->set_m_update_user_flag( true );
								m_pPackage->set_m_login_stage(4);
								SendPackage( m_pSocket, m_pPackage );
							}
							else {
								(*RichTextCtrl1) << _("沒收到登入旗標啦!");
							}
							break;
						case 4:
							(*RichTextCtrl1) << StringTowxString(package_r.m_susername()) + _(": login stage(0x00) = ") << package_r.m_login_stage() << _("\n");
							break;
						case 5:
							//RichTextCtrl1->SetDefaultStyle(wxTextAttr(*wxRED));
							(*RichTextCtrl1) << StringTowxString(package_r.m_susername()) + _(": login stage(0x00) = ") << package_r.m_login_stage() << _("\n");
							(*RichTextCtrl1) << _("login stage = ") << package_r.m_login_stage() << _("\n");
							(*RichTextCtrl1) << _("update user list: ") << (package_r.m_update_user_flag()?_("true"):_("false")) << _("\n");
							CheckListBox1_usetlist->Clear();//清除全部
							for ( int i = 0; i < package_r.m_user_list_size(); i++ ) {
								if ( StringTowxString(package_r.m_user_list(i)) != TextCtrl6_username->GetValue() ) {
									CheckListBox1_usetlist->Append( StringTowxString(package_r.m_user_list(i)) );
								}
							}
							m_pPackage->set_m_login_stage(6);
							m_pPackage->clear_m_update_user_flag();
							m_pPackage->set_handle( 0x69 );
							(*RichTextCtrl1) << _("login successful.") << _("\n");
							(*RichTextCtrl1) << _("User: ") + StringTowxString(m_pPackage->m_susername()) <<_("\n");
							(*RichTextCtrl1) << _("password: ") + StringTowxString(m_pPackage->m_spassword()) <<_("\n");
							(*RichTextCtrl1) << _("login stage: ") << m_pPackage->m_login_stage() <<_("\n");
							(*RichTextCtrl1) << _("login flag: ") << (m_pPackage->m_login_flag()?_("true"):_("false")) <<_("\n");
							(*RichTextCtrl1) << _("Update user flag: ") << (m_pPackage->m_update_user_flag()?_("true"):_("false")) <<_("\n");
							(*RichTextCtrl1) << _("handle code: ") << m_pPackage->handle() <<_("\n");
							(*RichTextCtrl1) << _("error code: ") << m_pPackage->m_err_code() <<_("\n");
							Timer1.Start(2000, true);
							break;
						case 6:
							(*RichTextCtrl1) << StringTowxString(package_r.m_susername()) + _(": login stage(0x00) = ") << package_r.m_login_stage() << _("\n");
							break;
						default:
							(*RichTextCtrl1) << StringTowxString(package_r.m_susername()) + _(": login stage(0x00) = ") << package_r.m_login_stage() << _("\n");
							break;
					}
					break;
				case 0x69: //已登入
					colour_str = StringTowxString( package_r.colour() );
					colour_custom.Set( colour_str );
					RichTextCtrl1->BeginTextColour( colour_custom );
					RichTextCtrl1->WriteText(_("[ ") + StringTowxString(package_r.m_susername()) + _(" ]:"));
					RichTextCtrl1->Newline();
					RichTextCtrl1->WriteText(StringTowxString(package_r.msg()));
					RichTextCtrl1->BeginLeftIndent(30);
					RichTextCtrl1->Newline();
					RichTextCtrl1->EndRightIndent();
					RichTextCtrl1->EndTextColour();
					RichTextCtrl1->ScrollIntoView(RichTextCtrl1->GetCaretPosition(),WXK_PAGEDOWN);
					RequestUserAttention();
					break;
				case 0x31: //其他使用者登入
					//(*RichTextCtrl1) << StringTowxString(package_r.m_susername()) + _(": 有人登入了") << _("\n");
					if ( package_r.m_user_list_size() == 1 ) {
						CheckListBox1_usetlist->Append( StringTowxString(package_r.m_user_list( 0 )) );
					}
					break;
				case 0x13: //其他使用者登出
					//(*RichTextCtrl1) << StringTowxString(package_r.m_susername()) + _(": 有人登出了") << _("\n");
					for ( size_t i = 0; i < CheckListBox1_usetlist->GetCount(); i++ ) {
						if ( package_r.m_user_list_size() == 1 ) {
							if ( CheckListBox1_usetlist->GetString(i) == StringTowxString( package_r.m_user_list(0) ) ) {
								CheckListBox1_usetlist->Delete( i );
							}
						}
						else {
							(*RichTextCtrl1) << _("刪除列表應該只有一人才對...") << _("\n");
						}
					}
					break;
				default:
					break;
			}
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
	if ( !TextCtrl2->GetValue().IsEmpty() ) {
		//設定傳送字串
		m_pPackage->set_msg( wxStringToString( TextCtrl2->GetValue() ) );
		//宣告傳送序列資料buffer
		std::string mubuffer;
		//結構序列化
		m_pPackage->SerializeToString( &mubuffer );
		//傳送
		m_pSocket->Write( mubuffer.c_str(), m_pPackage->ByteSize() );
	}
}

void netchatFrame::OnTextCtrl2TextEnter(wxCommandEvent& event)
{
//	(*RichTextCtrl1) << _(">>") << _("\n");
//	(*RichTextCtrl1) << _("Sock ID = ") << static_cast<long>(m_pPackage->m_nsock_id()) << _("\n");
//	(*RichTextCtrl1) << _("Server idx = ") << m_pPackage->m_nindex() << _("\n");
//	(*RichTextCtrl1) << _("username = ") << StringTowxString( m_pPackage->m_susername() ) << _("\n");
//	(*RichTextCtrl1) << _("passwd = ") << StringTowxString( m_pPackage->m_spassword() ) << _("\n");
//	(*RichTextCtrl1) << _("login result = ") << (int)m_pPackage->m_login_flag() << _("\n");
//	(*RichTextCtrl1) << _("login stage = ") << m_pPackage->m_login_stage() << _("\n");
//	(*RichTextCtrl1) << _("Err code = ") << m_pPackage->m_err_code() << _("\n");
//	(*RichTextCtrl1) << _("update_user_flag = ") << m_pPackage->m_update_user_flag() << _("\n");
	if ( !TextCtrl2->GetValue().IsEmpty() ) {
		//RichTextCtrl1->Freeze();
		RichTextCtrl1->BeginTextColour( m_colour );
		RichTextCtrl1->WriteText(_("[ ") + TextCtrl6_username->GetValue() + _(" ]:"));
		
		RichTextCtrl1->Newline();
		RichTextCtrl1->WriteText(TextCtrl2->GetValue());
		RichTextCtrl1->BeginLeftIndent(30);
		RichTextCtrl1->Newline();
		RichTextCtrl1->EndLeftIndent();
		RichTextCtrl1->EndTextColour();
		RichTextCtrl1->ScrollIntoView(RichTextCtrl1->GetCaretPosition(),WXK_PAGEDOWN);
		//RichTextCtrl1->ShowPosition( RichTextCtrl1->GetLastPosition() );
		//RichTextCtrl1->Thaw();
		
		//(*RichTextCtrl1) << TextCtrl6_username->GetValue() + _(":") << _("\n");
		//(*RichTextCtrl1) << TextCtrl2->GetValue() << _("\n") ;
		m_pPackage->clear_m_starget_user();
		for ( size_t i = 0; i < CheckListBox1_usetlist->GetCount(); i++ ) {
			if ( CheckListBox1_usetlist->IsChecked(i) ) {
				wxString user_tmp = CheckListBox1_usetlist->GetString(i);
				m_pPackage->add_m_starget_user( wxStringToString( user_tmp ) );
			}
		}
		wxString colour_tmp = m_colour.GetAsString();
		m_pPackage->set_colour( wxStringToString( colour_tmp ) );
		m_pPackage->set_m_susername( wxStringToString( TextCtrl6_username->GetValue() ) );
		m_pPackage->set_msg( wxStringToString( TextCtrl2->GetValue() ) );
		SendPackage( m_pSocket, m_pPackage );
		TextCtrl2->Clear();
	}
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



//void netchatFrame::OnButton3Click(wxCommandEvent& event)
//{
//	if ( shownflg ) {
//		StaticBoxSizer2->Show(false);
//		shownflg = false;
//	}else {
//		StaticBoxSizer2->Show(true);
//		shownflg = true;
//	}
//	BoxSizer2->RecalcSizes();
//}

void netchatFrame::OnButton2_logoutClick(wxCommandEvent& event)
{
	if ( m_pSocket->Close() ) {

		Timer1.Start(3000, true);

	}
	//UpdateWindowUI();
}

void netchatFrame::OnTimer1Trigger(wxTimerEvent& event)
{
	TextCtrl2->Enable();
}

void netchatFrame::OnColourPickerCtrl1ColourChanged(wxColourPickerEvent& event)
{
	m_colour = ColourPickerCtrl1->GetColour();
}

void netchatFrame::showtext(wxTextCtrl* tc, wxString s)
{
	// HACK: Under Windows (using wxTE_RICH2) we have trouble ensuring that the last
    // entered line is really at the bottom of the screen. We jump through some
    // hoops to get this working.
 
    // Count number of newlines (i.e lines)
//    int lines = 0;
//    const char* cstr = s.c_str();
//    for( ; *cstr ; ++cstr )
//        if( *cstr == '\n' )
//            ++lines;
 
    // Dance...
    tc->Freeze();                 // Freeze the window to prevent scrollbar jumping
    tc->AppendText( s );          // Add the text
    tc->ScrollLines( 2 + 1 ); // Scroll down correct number of lines + one (the extra line is important for some cases!)
    tc->ShowPosition( tc->GetLastPosition() ); // Ensure the last line is shown at the very bottom of the window
    tc->Thaw();                   // Allow the window to redraw
}

