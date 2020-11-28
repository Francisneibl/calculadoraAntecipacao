/***************************************************************
 * Name:      CalculadoraAntecipacaoApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Francisnei Lima (francisneibernardeslima@gmail.com)
 * Created:   2019-08-04
 * Copyright: Francisnei Lima ()
 * License:
 **************************************************************/

#include "CalculadoraAntecipacaoApp.h"

//(*AppHeaders
#include "CalculadoraAntecipacaoMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(CalculadoraAntecipacaoApp);

bool CalculadoraAntecipacaoApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	CalculadoraAntecipacaoFrame* Frame = new CalculadoraAntecipacaoFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
