#include "password.h"
#include "configuracoes.h"

//(*InternalHeaders(password)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(password)
const long password::ID_TEXTCTRL1 = wxNewId();
const long password::ID_STATICTEXT1 = wxNewId();
const long password::ID_STATICTEXT2 = wxNewId();
const long password::ID_BUTTON1 = wxNewId();
const long password::ID_BUTTON2 = wxNewId();
const long password::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(password,wxDialog)
	//(*EventTable(password)
	//*)
END_EVENT_TABLE()

password::password(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(password)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(400,155));
	Move(wxDefaultPosition);
	txt_password = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(88,40), wxSize(296,21), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	txt_msg = new wxStaticText(this, ID_STATICTEXT1, _("SENHA:"), wxPoint(40,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	txt_title = new wxStaticText(this, ID_STATICTEXT2, _("Acesso Gerencial"), wxPoint(136,8), wxSize(208,13), 0, _T("ID_STATICTEXT2"));
	wxFont txt_titleFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	txt_title->SetFont(txt_titleFont);
	btn_ok = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(120,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	btn_cancelar = new wxButton(this, ID_BUTTON2, _("CANCELAR"), wxPoint(224,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	txt_troca = new wxButton(this, ID_BUTTON3, _("TROCAR SENHA"), wxPoint(8,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&password::Onbtn_okClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&password::Onbtn_cancelarClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&password::Ontxt_trocaClick);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&password::OnInit);
	//*)
}

password::~password()
{
	//(*Destroy(password)
	//*)
}


void password::OnInit(wxInitDialogEvent& event)
{

    wxFile passwordFile;

    if(passcheck("PASSWORD.TXT")){
    //////
    }else{
        txt_title->SetLabel("DIGITE A PRIMEIRA SENHA");
        passwordFile.Create("PASSWORD.TXT",1,wxS_DEFAULT);
    }

}


bool passcheck(wxString nome){
    wxFile arquivo;

    if(arquivo.Exists(nome)){
        return 1;
    }else{
        return 0;
    }
}


void password::Onbtn_okClick(wxCommandEvent& event)
{
    wxFile arquivo;
    wxString senha, senha2;

    arquivo.Open("PASSWORD.TXT",wxFile::read,wxS_DEFAULT);
    arquivo.ReadAll(&senha2);
    arquivo.Close();


    if(senha2.IsNull()){
        txt_title->SetLabel("DIGITE A PRIMEIRA SENHA");
        arquivo.Open("PASSWORD.TXT",wxFile::write,wxS_DEFAULT);
        arquivo.Write(txt_password->GetValue());
        arquivo.Close();
    }

    arquivo.Open("PASSWORD.TXT",wxFile::read,wxS_DEFAULT);
    arquivo.ReadAll(&senha);

    if(senha == txt_password->GetValue()){
        //wxMessageBox("Senha correta","senha",wxCENTRE,NULL,wxDefaultCoord);
        Close();
        configuracoes * disconfig = new configuracoes(NULL,wxID_ANY,wxDefaultPosition,wxDefaultSize);
        disconfig->ShowModal();
        arquivo.Close();

    }else{
        wxMessageBox("Senha incorreta","senha",wxCENTRE,NULL,wxDefaultCoord);
    }

}

void password::Ontxt_trocaClick(wxCommandEvent& event)
{
   trocasenha * dtrocasenha = new trocasenha(NULL,wxID_ANY,wxDefaultPosition,wxDefaultSize);
   dtrocasenha->ShowModal();
}

void password::Onbtn_cancelarClick(wxCommandEvent& event)
{
    Close();
}
