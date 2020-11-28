/***************************************************************
 * Name:      CalculadoraAntecipacaoMain.h
 * Purpose:   Defines Application Frame
 * Author:    Francisnei Lima (francisneibernardeslima@gmail.com)
 * Created:   2019-08-04
 * Copyright: Francisnei Lima ()
 * License:
 **************************************************************/

#ifndef CALCULADORAANTECIPACAOMAIN_H
#define CALCULADORAANTECIPACAOMAIN_H

//(*Headers(CalculadoraAntecipacaoFrame)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/spinctrl.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

void settaxa(wxString nome, double* var);

wxString fomatdecimal(double valor);

void filecheck(wxString nome);

class CalculadoraAntecipacaoFrame: public wxFrame
{
    public:

        CalculadoraAntecipacaoFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~CalculadoraAntecipacaoFrame();

    public:

        //(*Handlers(CalculadoraAntecipacaoFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnChoice1Select(wxCommandEvent& event);
        void Oncb_tipo_pgSelect(wxCommandEvent& event);
        void OnChoice2Select(wxCommandEvent& event);
        void Onbtn_calcClick(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void Onbtn_configClick(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnSetFocus(wxFocusEvent& event);
        void OnClose1(wxCloseEvent& event);
        //*)

        //(*Identifiers(CalculadoraAntecipacaoFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_CHOICE1;
        static const long ID_BUTTON1;
        static const long ID_CHOICE2;
        static const long ID_SPINCTRL1;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT14;
        static const long ID_BITMAPBUTTON1;
        static const long ID_CHECKBOX1;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT16;
        static const long ID_STATICTEXT17;
        static const long ID_STATICTEXT18;
        static const long ID_STATICLINE1;
        static const long ID_STATICBOX1;
        //*)

        //(*Declarations(CalculadoraAntecipacaoFrame)
        wxBitmapButton* btn_config;
        wxButton* btn_calc;
        wxCheckBox* rd_elo;
        wxChoice* cb_condicao;
        wxChoice* cb_frm_pg;
        wxSpinCtrl* txt_num_par;
        wxStaticBox* StaticBox1;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        wxStaticText* txt_aumento;
        wxStaticText* txt_parc_aum;
        wxStaticText* txt_perdas;
        wxStaticText* txt_tot_par_ant;
        wxStaticText* txt_tot_perda;
        wxStaticText* txt_valor_bruto;
        wxStaticText* txt_vlr_liquido;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* txt_vlr_total;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // CALCULADORAANTECIPACAOMAIN_H
