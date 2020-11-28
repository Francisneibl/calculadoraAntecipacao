#include "trocasenha.h"

//(*InternalHeaders(trocasenha)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(trocasenha)
const long trocasenha::ID_STATICTEXT1 = wxNewId();
const long trocasenha::ID_STATICTEXT2 = wxNewId();
const long trocasenha::ID_STATICTEXT3 = wxNewId();
const long trocasenha::ID_TEXTCTRL1 = wxNewId();
const long trocasenha::ID_TEXTCTRL2 = wxNewId();
const long trocasenha::ID_TEXTCTRL3 = wxNewId();
const long trocasenha::ID_BUTTON1 = wxNewId();
const long trocasenha::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(trocasenha,wxDialog)
	//(*EventTable(trocasenha)
	//*)
END_EVENT_TABLE()

trocasenha::trocasenha(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(trocasenha)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(379,98));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("DIGITE A SENHA ANTIGA"), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("DIGITE A NOVA SENHA"), wxPoint(24,40), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("CONFIRMAR NOVA SENHA"), wxPoint(8,64), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	txt_old_senha = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(152,16), wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	txt_new_senha = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(152,40), wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	txt_new_senha_c = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(152,64), wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	btn_ok = new wxButton(this, ID_BUTTON1, _("Ok"), wxPoint(280,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	btn_cancelar = new wxButton(this, ID_BUTTON2, _("CANCELAR"), wxPoint(280,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&trocasenha::Onbtn_okClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&trocasenha::Onbtn_cancelarClick);
	//*)
}

trocasenha::~trocasenha()
{
	//(*Destroy(trocasenha)
	//*)
}


void trocasenha::Onbtn_okClick(wxCommandEvent& event)
{
    wxFile arquivo;
    wxString senhaold;

    arquivo.Open("PASSWORD.TXT",wxFile::read,wxS_DEFAULT);

    arquivo.ReadAll(&senhaold);
    arquivo.Close();

    if(senhaold == txt_old_senha->GetValue()){

        if(txt_new_senha->GetValue() == txt_new_senha_c->GetValue()){
                if(txt_new_senha_c->GetValue().IsNull()){
                    wxMessageBox("Campo de senha em branco!","ERRO",wxCENTRE,NULL,wxDefaultCoord);
                }else{
                    arquivo.Open("PASSWORD.TXT",wxFile::write,wxS_DEFAULT);
                    arquivo.Flush();
                    arquivo.Write(txt_new_senha->GetValue());
                    arquivo.Close();
                    wxMessageBox("Senha alterada com sucesso!!!","",wxCENTRE,NULL,wxDefaultCoord);
                    Close();
                }
        }else{
            wxMessageBox("Confirmação de senha incorreta!!!","",wxCENTRE,NULL,wxDefaultCoord);
        }

    }else{
        wxMessageBox("Senha incorreta!!!","",wxCENTRE,NULL,wxDefaultCoord);
    }

}

void trocasenha::Onbtn_cancelarClick(wxCommandEvent& event)
{
    Close();
}
