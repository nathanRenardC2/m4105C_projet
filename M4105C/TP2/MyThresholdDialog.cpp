#include "MyThresholdDialog.hpp"

MyThresholdDialog::MyThresholdDialog( 
	wxWindow* parent, wxWindowID id, const wxString& title, 
	const wxPoint& pos, const wxSize& size, long style ) 
: wxDialog( parent, id, title, pos, size, style )
{
	m_threshold = new wxSlider( this, wxID_ANY, 128, 0, 255, wxPoint(10,10), wxSize(220,50), wxSL_HORIZONTAL|wxSL_LABELS );
	m_okButton = new wxButton( this, wxID_OK, wxT("OK"), wxPoint(120,60), wxSize(100,30), 0 );
	m_cancelButton = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxPoint(10,60), wxSize(100,30), 0 );

	m_threshold->Bind( wxEVT_SCROLL_THUMBTRACK, &MyThresholdDialog::OnScroll, this );
}

MyThresholdDialog::~MyThresholdDialog() {
	m_threshold->Unbind( wxEVT_SCROLL_THUMBTRACK, &MyThresholdDialog::OnScroll, this );
}

void MyThresholdDialog::OnScroll( wxScrollEvent& event )
{
    wxCommandEvent outEvent(MON_EVENEMENT) ;	// création d'un événement propre 
    outEvent.SetInt(m_threshold->GetValue()) ;	// stockage de la valeur du seuil dans l'événement
    wxPostEvent(GetParent(), outEvent);		// poste le message au wxPanel
}

