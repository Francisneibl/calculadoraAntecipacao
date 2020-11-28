#ifndef PASSWORD_H
#define PASSWORD_H

//(*Headers(password)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include <wx/file.h>
#include <wx/msgdlg.h>
#include "trocasenha.h"
bool passcheck(wxString nome);

class password: public wxDialog

{
	public:

		password(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~password();

		//(*Declarations(password)
		wxButton* btn_cancelar;
		wxButton* btn_ok;
		wxButton* txt_troca;
		wxStaticText* txt_msg;
		wxStaticText* txt_title;
		wxTextCtrl* txt_password;
		//*)

		//(*Identifiers(password)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

		//(*Handlers(password)
		void OnInit(wxInitDialogEvent& event);
		void Onbtn_okClick(wxCommandEvent& event);
		void Ontxt_trocaClick(wxCommandEvent& event);
		void Onbtn_cancelarClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
