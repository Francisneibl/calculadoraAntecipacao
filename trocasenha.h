#ifndef TROCASENHA_H
#define TROCASENHA_H

//(*Headers(trocasenha)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include <wx/file.h>
#include <wx/msgdlg.h>

class trocasenha: public wxDialog
{
	public:

		trocasenha(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~trocasenha();

		//(*Declarations(trocasenha)
		wxButton* btn_cancelar;
		wxButton* btn_ok;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* txt_new_senha;
		wxTextCtrl* txt_new_senha_c;
		wxTextCtrl* txt_old_senha;
		//*)

		//(*Identifiers(trocasenha)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

		//(*Handlers(trocasenha)
		void Onbtn_okClick(wxCommandEvent& event);
		void Onbtn_cancelarClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
