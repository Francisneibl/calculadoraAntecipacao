#include "configuracoes.h"
#include "CalculadoraAntecipacaoMain.h"
#include <wx/file.h>
#include <wx/msgdlg.h>

void validar (wxTextCtrl *campo);

//(*InternalHeaders(configuracoes)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(configuracoes)
const long configuracoes::ID_TEXTCTRL1 = wxNewId();
const long configuracoes::ID_TEXTCTRL2 = wxNewId();
const long configuracoes::ID_TEXTCTRL3 = wxNewId();
const long configuracoes::ID_TEXTCTRL4 = wxNewId();
const long configuracoes::ID_TEXTCTRL5 = wxNewId();
const long configuracoes::ID_BUTTON1 = wxNewId();
const long configuracoes::ID_BUTTON2 = wxNewId();
const long configuracoes::ID_STATICTEXT1 = wxNewId();
const long configuracoes::ID_STATICTEXT2 = wxNewId();
const long configuracoes::ID_STATICTEXT3 = wxNewId();
const long configuracoes::ID_STATICTEXT4 = wxNewId();
const long configuracoes::ID_STATICTEXT5 = wxNewId();
const long configuracoes::ID_STATICTEXT6 = wxNewId();
const long configuracoes::ID_STATICTEXT7 = wxNewId();
const long configuracoes::ID_TEXTCTRL6 = wxNewId();
const long configuracoes::ID_TEXTCTRL7 = wxNewId();
const long configuracoes::ID_TEXTCTRL8 = wxNewId();
const long configuracoes::ID_TEXTCTRL9 = wxNewId();
const long configuracoes::ID_TEXTCTRL10 = wxNewId();
const long configuracoes::ID_STATICBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(configuracoes,wxDialog)
	//(*EventTable(configuracoes)
	//*)
END_EVENT_TABLE()

configuracoes::configuracoes(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(configuracoes)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(451,256));
	txt_deb = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(136,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	txt_cred = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(136,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	txt_6x = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(136,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	txt_12x = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(136,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	txt_ant = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(136,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	btn_cancelar = new wxButton(this, ID_BUTTON1, _("CANCELAR"), wxPoint(136,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	btn_ok = new wxButton(this, ID_BUTTON2, _("OK"), wxPoint(248,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("DEFINIR VALOR DE TAXAS"), wxPoint(120,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("TAXA DE DEBITO"), wxPoint(45,65), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("TAXA CREDITO A VISTA"), wxPoint(10,92), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("TAXA CREDITO 6X"), wxPoint(35,116), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("TAXA CREDITO 12X"), wxPoint(32,140), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("TAXA ANTECIPACAO"), wxPoint(20,165), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, wxEmptyString, wxPoint(96,40), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	txt_ant_elo = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(264,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	txt_12x_elo = new wxTextCtrl(this, ID_TEXTCTRL7, wxEmptyString, wxPoint(264,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	txt_6x_elo = new wxTextCtrl(this, ID_TEXTCTRL8, wxEmptyString, wxPoint(264,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	txt_cred_elo = new wxTextCtrl(this, ID_TEXTCTRL9, wxEmptyString, wxPoint(264,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	txt_deb_elo = new wxTextCtrl(this, ID_TEXTCTRL10, wxEmptyString, wxPoint(264,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("ELO"), wxPoint(248,40), wxSize(176,152), 0, _T("ID_STATICBOX1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&configuracoes::Onbtn_cancelarClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&configuracoes::Onbtn_okClick);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&configuracoes::OnInit);
	//*)
}

configuracoes::~configuracoes()
{
	//(*Destroy(configuracoes)
	//*)
}

void configuracoes::Onbtn_cancelarClick(wxCommandEvent& event)
{
    Close();
}

void configuracoes::Onbtn_okClick(wxCommandEvent& event)
{
    getlabels(txt_deb,"TAXA_DEB.TXT");

    getlabels(txt_cred,"TAXA_CRED.TXT");

    getlabels(txt_6x,"TAXA_6X.txt");

    getlabels(txt_12x,"TAXA_12X.TXT");

    getlabels(txt_ant,"TAXA_ANT.TXT");


    getlabels(txt_deb_elo,"TAXA_DEB_ELO.TXT");
    getlabels(txt_cred_elo,"TAXA_CRED_ELO.TXT");
    getlabels(txt_6x_elo,"TAXA_6X_ELO.TXT");
    getlabels(txt_12x_elo,"TAXA_12X_ELO.TXT");
    getlabels(txt_ant_elo,"TAXA_ANT_ELO.TXT");


    Close();
}

void configuracoes::OnInit(wxInitDialogEvent& event){

    setlabels(txt_deb,"TAXA_DEB.TXT");

    setlabels(txt_cred,"TAXA_CRED.TXT");

    setlabels(txt_6x,"TAXA_6X.TXT");

    setlabels(txt_12x,"TAXA_12X.TXT");

    setlabels(txt_ant,"TAXA_ANT.TXT");


    setlabels(txt_deb_elo,"TAXA_DEB_ELO.TXT");
    setlabels(txt_cred_elo,"TAXA_CRED_ELO.TXT");
    setlabels(txt_6x_elo,"TAXA_6X_ELO.TXT");
    setlabels(txt_12x_elo,"TAXA_12X_ELO.TXT");
    setlabels(txt_ant_elo,"TAXA_ANT_ELO.TXT");
}


void setlabels(wxTextCtrl *campo,wxString texto){
    wxFile arquivo;
    wxString valor;

    arquivo.Open(texto,wxFile::read,wxS_DEFAULT);
    arquivo.ReadAll(&valor);
    campo->SetValue(valor);
    arquivo.Close();
}

void getlabels(wxTextCtrl * campo,wxString texto){

    wxFile filetx;
    wxString valor;
    int n = -1;

    valor = campo->GetValue();
    n = valor.Find(",");

    if(n!=-1){
        valor.replace(n,1,".");
    }


    if(!campo->GetValue().IsNull()){
        filetx.Open(texto,wxFile::write,wxS_DEFAULT);
        filetx.Write(valor);
        filetx.Close();
    }
}


void validar (wxTextCtrl *campo){
    if(campo->GetValue().IsWord()){
        wxMessageBox("Por Favor apenas numeros","ERROR",wxCENTRE,NULL,wxDefaultCoord);
    }

}
