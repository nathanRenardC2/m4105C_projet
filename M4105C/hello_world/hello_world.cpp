// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp: public wxApp
{
public:
	virtual bool OnInit();
};

class MyFrame: public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	void OnHello(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnEnCours(wxCommandEvent& event);
	void OnResize(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
};

enum	// énumération. Elle gère la numérotation automatiquement 
{
	ID_Hello = 1,
	ID_About,	// ID_Truc a pour valeur 2 
	ID_EnCours,	// ID_Machin a pour valeur 3 
	ID_PlusLarge,
	ID_MoinsLarge
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	MyFrame *frame = new MyFrame( wxT("Hello World"), wxPoint(50, 50), wxSize(450, 340) );
	frame->Center();
	frame->Show(true);
	return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	wxMenu *menuFile = new wxMenu ;
	menuFile->Append(ID_Hello, wxT("Hello...\tCtrl-H"), "Afficher 'Hello world!'") ;
	Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello) ;

	menuFile->Append(ID_PlusLarge, wxT("Plus large\tCtrl-="));
	Bind(wxEVT_MENU, &MyFrame::OnResize, this, ID_PlusLarge);
	
	menuFile->Append(ID_MoinsLarge, wxT("Moins large\tCtrl--"));
	Bind(wxEVT_MENU, &MyFrame::OnResize, this, ID_MoinsLarge);

	menuFile->AppendSeparator();

	menuFile->Append(ID_About, wxT("About\tCtrl-A"));
	Bind(wxEVT_MENU, &MyFrame::OnAbout, this, ID_About);

	menuFile->Append(wxID_EXIT) ;
	Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT) ;


	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(ID_EnCours, wxT("En cours\tCtrl-C"));
	Bind(wxEVT_MENU, &MyFrame::OnEnCours, this, ID_EnCours);

	wxMenuBar *menuBar = new wxMenuBar ;
	menuBar->Append( menuFile, wxT("File" )) ;
	menuBar->Append(menuHelp, wxT("Help"));
	SetMenuBar(menuBar) ;
	
	wxStatusBar *statusBar = CreateStatusBar();
	SetStatusText(wxT("Je baise ta grand-mère"));
	SetStatusBar(statusBar);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage(wxT("Hello world from wxWidgets!"));
}

void MyFrame::OnAbout(wxCommandEvent& event) {
	wxLogMessage(wxT("Auteur : Gabriel Pacotte - 2022"));
}

void MyFrame::OnEnCours(wxCommandEvent& event) {
	wxLogMessage(wxT("En construction"));
}

void MyFrame::OnResize(wxCommandEvent& event) {
	int width = 0;
	int height = 0;
	GetSize(&width, &height);
	
	if(event.GetId() == ID_PlusLarge && width < 1900) {
		SetSize(width+100, height+100);
	} else if(event.GetId() == ID_MoinsLarge && width > 400) {
		SetSize(width-100, height-100);
	}
}

void MyFrame::OnExit(wxCommandEvent& event)
{
	Close( true );
}

