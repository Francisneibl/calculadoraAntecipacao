#ifndef CONFIGURACOES_H
#define CONFIGURACOES_H



//(*Headers(configuracoes)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

void setlabels(wxTextCtrl *campo,wxString texto);
void getlabels(wxTextCtrl * campo,wxString texto);

class configuracoes: public wxDialog
{
	public:

		configuracoes(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~configuracoes();

		//(*Declarations(configuracoes)
		wxButton* btn_cancelar;
		wxButton* btn_ok;
		wxStaticBox* StaticBox1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxTextCtrl* txt_12x;
		wxTextCtrl* txt_12x_elo;
		wxTextCtrl* txt_6x;
		wxTextCtrl* txt_6x_elo;
		wxTextCtrl* txt_ant;
		wxTextCtrl* txt_ant_elo;
		wxTextCtrl* txt_cred;
		wxTextCtrl* txt_cred_elo;
		wxTextCtrl* txt_deb;
		wxTextCtrl* txt_deb_elo;
		//*)

	protected:

		//(*Identifiers(configuracoes)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL5;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL6;
		static const long ID_TEXTCTRL7;
		static const long ID_TEXTCTRL8;
		static const long ID_TEXTCTRL9;
		static const long ID_TEXTCTRL10;
		static const long ID_STATICBOX1;
		//*)

	private:

		//(*Handlers(configuracoes)
		void Onbtn_cancelarClick(wxCommandEvent& event);
		void Onbtn_okClick(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
