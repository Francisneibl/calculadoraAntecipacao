/***************************************************************
 * Name:      CalculadoraAntecipacaoMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Francisnei Lima (francisneibernardeslima@gmail.com)
 * Created:   2019-08-04
 * Copyright: Francisnei Lima ()
 * License:  FreeWare
 **************************************************************/
#include<locale>
#include "CalculadoraAntecipacaoMain.h"
#include <wx/msgdlg.h>
#include <wx/file.h>
#include "configuracoes.h"
#include "password.h"
#include "aumento.h"

#define TX_DEBITO 1.76
#define TX_CRED 2.77
#define TX_CRED_6X 3.04
#define TX_CRED_12X 3.29
#define TX_ANTEC 2.59

// ESCOPO DE FUNCOES
void calccredito(int form_pag, int num_parc);
void antecipacao (int num_parc);
wxString forma (wxString valor);

//  VARIAVEIS GLOBAIS
double valor_tot = 0, res=0, taxa_deb = 0, taxa_cred, taxa_6x,taxa_12x, taxa_ant, aumentoTot;
/*
double TX_DEBITO = 1.76;
double TX_CRED = 2.77;
double TX_CRED_6X 3.04;
double TX_CRED_12X 3.29;
double TX_ANTEC 2.59; */

//(*InternalHeaders(CalculadoraAntecipacaoFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/image.h>
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

//(*IdInit(CalculadoraAntecipacaoFrame)
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT1 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_TEXTCTRL1 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_CHOICE1 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_BUTTON1 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_CHOICE2 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_SPINCTRL1 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_TEXTCTRL5 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT2 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT3 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT4 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT5 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT6 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT7 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT8 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT9 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT10 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT11 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT12 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT13 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT14 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_BITMAPBUTTON1 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_CHECKBOX1 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT15 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT16 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT17 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICTEXT18 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICLINE1 = wxNewId();
const long CalculadoraAntecipacaoFrame::ID_STATICBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CalculadoraAntecipacaoFrame,wxFrame)
    //(*EventTable(CalculadoraAntecipacaoFrame)
    //*)
END_EVENT_TABLE()

CalculadoraAntecipacaoFrame::CalculadoraAntecipacaoFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(CalculadoraAntecipacaoFrame)
    Create(parent, id, _("Calculadora de Antecipacao"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(304,610));
    SetMinSize(wxSize(320,640));
    SetMaxSize(wxSize(320,640));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("icon-mao.png"))));
    	SetIcon(FrameIcon);
    }
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("VALOR TOTAL"), wxPoint(10,20), wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    txt_vlr_total = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(88,16), wxSize(118,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    cb_frm_pg = new wxChoice(this, ID_CHOICE1, wxPoint(152,64), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    cb_frm_pg->SetSelection( cb_frm_pg->Append(_("DEBITO")) );
    cb_frm_pg->Append(_("CREDITO"));
    btn_calc = new wxButton(this, ID_BUTTON1, _("SIMULAR"), wxPoint(208,16), wxSize(88,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    cb_condicao = new wxChoice(this, ID_CHOICE2, wxPoint(152,96), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    cb_condicao->SetSelection( cb_condicao->Append(_("A VISTA")) );
    cb_condicao->Append(_("PARCELADO"));
    txt_num_par = new wxSpinCtrl(this, ID_SPINCTRL1, _T("2"), wxPoint(152,128), wxSize(40,21), 0, 2, 12, 2, _T("ID_SPINCTRL1"));
    txt_num_par->SetValue(_T("2"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(8,224), wxSize(288,240), wxTE_NO_VSCROLL|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl2->Disable();
    TextCtrl2->SetFocus();
    TextCtrl2->SetForegroundColour(wxColour(255,0,0));
    wxFont TextCtrl2Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    TextCtrl2->SetFont(TextCtrl2Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("FORMA DE PAGAMENTO"), wxPoint(16,64), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("CONDICAO"), wxPoint(88,96), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("PARCELAS"), wxPoint(88,128), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("VALOR BRUTO:"), wxPoint(72,160), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("VALOR LIQUIDO:"), wxPoint(64,192), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("TOTAL PARCELAS ANTECIPADAS:"), wxPoint(17,472), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("TOTAL PERDA COM ANTECIPACAO:"), wxPoint(3,496), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    txt_tot_par_ant = new wxStaticText(this, ID_STATICTEXT9, _("R$ 0,00"), wxPoint(200,472), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    wxFont txt_tot_par_antFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    txt_tot_par_ant->SetFont(txt_tot_par_antFont);
    txt_tot_perda = new wxStaticText(this, ID_STATICTEXT10, _("R$ 0,00"), wxPoint(200,496), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    wxFont txt_tot_perdaFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    txt_tot_perda->SetFont(txt_tot_perdaFont);
    txt_valor_bruto = new wxStaticText(this, ID_STATICTEXT11, _("R$ 0,00"), wxPoint(152,160), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    wxFont txt_valor_brutoFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    txt_valor_bruto->SetFont(txt_valor_brutoFont);
    txt_vlr_liquido = new wxStaticText(this, ID_STATICTEXT12, _("R$ 0,00"), wxPoint(152,192), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    wxFont txt_vlr_liquidoFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    txt_vlr_liquido->SetFont(txt_vlr_liquidoFont);
    StaticText9 = new wxStaticText(this, ID_STATICTEXT13, _("TOTAL PERDAS NA VENDA:"), wxPoint(48,520), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    txt_perdas = new wxStaticText(this, ID_STATICTEXT14, _("R$ 0,00"), wxPoint(200,520), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    txt_perdas->SetForegroundColour(wxColour(253,39,28));
    wxFont txt_perdasFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    txt_perdas->SetFont(txt_perdasFont);
    btn_config = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("maintenance_filled_50px.png"))), wxPoint(8,96), wxSize(56,56), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    rd_elo = new wxCheckBox(this, ID_CHECKBOX1, _("ELO\?"), wxPoint(216,128), wxSize(64,13), 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    rd_elo->SetValue(false);
    wxFont rd_eloFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    rd_elo->SetFont(rd_eloFont);
    StaticText10 = new wxStaticText(this, ID_STATICTEXT15, _("ACONSELHA-SE COBRAR:"), wxPoint(48,556), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    StaticText11 = new wxStaticText(this, ID_STATICTEXT16, _("VALOR PARCELAS:"), wxPoint(82,578), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    txt_aumento = new wxStaticText(this, ID_STATICTEXT17, _("R$ 0,00"), wxPoint(192,552), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    txt_aumento->SetForegroundColour(wxColour(0,176,0));
    wxFont txt_aumentoFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    txt_aumento->SetFont(txt_aumentoFont);
    txt_parc_aum = new wxStaticText(this, ID_STATICTEXT18, _("R$ 0,00"), wxPoint(192,576), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    txt_parc_aum->SetForegroundColour(wxColour(0,176,0));
    wxFont txt_parc_aumFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    txt_parc_aum->SetFont(txt_parc_aumFont);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(8,544), wxSize(288,0), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, wxEmptyString, wxPoint(8,536), wxSize(288,64), 0, _T("ID_STATICBOX1"));
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculadoraAntecipacaoFrame::Onbtn_calcClick);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculadoraAntecipacaoFrame::Onbtn_configClick);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&CalculadoraAntecipacaoFrame::OnClose1);
    Connect(wxEVT_PAINT,(wxObjectEventFunction)&CalculadoraAntecipacaoFrame::OnPaint);
    //*)
}

CalculadoraAntecipacaoFrame::~CalculadoraAntecipacaoFrame()
{
    //(*Destroy(CalculadoraAntecipacaoFrame)
    //*)
}

void CalculadoraAntecipacaoFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CalculadoraAntecipacaoFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}


void CalculadoraAntecipacaoFrame::Onbtn_calcClick(wxCommandEvent& event)
{
    if(rd_elo->GetValue()){
        //wxMessageBox("Selecionado elo","",wxCENTRE,NULL,wxDefaultCoord);
        settaxa("TAXA_DEB_ELO.TXT",&taxa_deb);
        settaxa("TAXA_CRED_ELO.TXT",&taxa_cred);
        settaxa("TAXA_6X_ELO.TXT",&taxa_6x);
        settaxa("TAXA_12X_ELO.TXT",&taxa_12x);
        settaxa("TAXA_ANT_ELO.TXT",&taxa_ant);
    }else{
        settaxa("TAXA_DEB.TXT",&taxa_deb);
        settaxa("TAXA_CRED.TXT",&taxa_cred);
        settaxa("TAXA_6X.TXT",&taxa_6x);
        settaxa("TAXA_12X.TXT",&taxa_12x);
        settaxa("TAXA_ANT.TXT",&taxa_ant);
    }

    int condicao, form_pag,num_parc;
    float tot_parc = 0, tot_perdas = 0,perd_tot;

    TextCtrl2->Clear();

    condicao = cb_frm_pg->GetCurrentSelection();
    form_pag = cb_condicao->GetCurrentSelection();
    num_parc = txt_num_par->GetValue();

    wxString valor;
    valor = txt_vlr_total->GetValue();
    valor = forma(valor);
    //txt_vlr_total->GetValue().ToDouble(&valor_tot);
    valor.ToDouble(&valor_tot);

    if(condicao == 0){
        res = (float) valor_tot-((valor_tot*taxa_deb)/100);
        perd_tot = (float)valor_tot-res;
    }else{
        //wxString tex;
        calccredito(form_pag,num_parc);
        perd_tot = (float)valor_tot-res;
        if(form_pag==1){
            float parcela = (float) res/num_parc;
            for(int c=1;c<=num_parc;c++){

                //float taxa = (float) c*taxa_ant;
                float vlr_parc = parcela-((taxa_ant*parcela)/100);
                parcela = vlr_parc;
                tot_parc = tot_parc + vlr_parc;
                //tex = fomatdecimal(vlr_parc);
                TextCtrl2->SetValue(TextCtrl2->GetValue()+wxString::FromDouble(c)+"ª Parcela --> "+fomatdecimal(vlr_parc)+"\n");
            }
            tot_perdas = res-tot_parc;
            perd_tot = valor_tot-tot_parc;
        }
    }

    txt_valor_bruto->SetLabel(fomatdecimal(valor_tot));
    txt_vlr_liquido->SetLabel(fomatdecimal(res));
    txt_tot_par_ant->SetLabel(fomatdecimal(tot_parc));
    txt_tot_perda->SetLabel(fomatdecimal(tot_perdas));
    txt_perdas->SetLabel(fomatdecimal(perd_tot));

    txt_aumento->SetLabel(fomatdecimal(aumentoMoney(valor_tot,perd_tot)));

    if(cb_frm_pg->GetSelection() && cb_condicao->GetSelection()){
        aumentoTot = aumentoMoney(valor_tot,perd_tot);
        txt_parc_aum->SetLabel(fomatdecimal(parcAumento(aumentoTot,num_parc)));
    }else{
        //
    }

}


void calccredito(int form_pag, int num_parc){

    if(form_pag == 0){
        res = (float) valor_tot-((valor_tot*taxa_cred)/100);
    }else{
        if(num_parc<=6){
            res = (float) valor_tot-((valor_tot*taxa_6x)/100);
        }else{
            res = (float) valor_tot-((valor_tot*taxa_12x)/100);
        }
    }
}

void CalculadoraAntecipacaoFrame::Onbtn_configClick(wxCommandEvent& event)
{

    password * dpassword = new password(NULL,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    dpassword->ShowModal();
}

void settaxa(wxString nome, double* var)
{
    wxFile taxa;
    wxString taxas;
    taxa.Open(nome,wxFile::read,wxS_DEFAULT);
    taxa.ReadAll(&taxas);
    taxas.ToDouble(var);
}

wxString fomatdecimal(double valor)
{
    wxString texto;
    texto = wxString::FromDouble(valor,2);
    int tam = texto.Length();
    int pos = tam-6;

    if(tam>=7){
        texto.replace(pos,0,".");
    }

    return "R$ "+texto;
}

void filecheck(wxString nome){

    wxFile teet;

    if(!wxFile::Exists(nome)) {
        teet.Create(nome,1,wxS_DEFAULT);
    }
}

void CalculadoraAntecipacaoFrame::OnPaint(wxPaintEvent& event)
{
    filecheck("TAXA_CRED.TXT");
    filecheck("TAXA_DEB.TXT");
    filecheck("TAXA_6X.TXT");
    filecheck("TAXA_12X.TXT");
    filecheck("TAXA_ANT.TXT");

    filecheck("TAXA_DEB_ELO.TXT");
    filecheck("TAXA_CRED_ELO.TXT");
    filecheck("TAXA_6X_ELO.TXT");
    filecheck("TAXA_12X_ELO.TXT");
    filecheck("TAXA_ANT_ELO.TXT");

}

wxString forma (wxString valor){


    int n = -1;

    //valor = campo->GetValue();
    n = valor.Find(",");

    if(n!=-1){
        valor.replace(n,1,".");
    }

    return valor;

}

void CalculadoraAntecipacaoFrame::OnClose1(wxCloseEvent& event)
{
    exit(0);
}
