// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include "MyThresholdDialog.hpp"
#include "MyRotateDialog.hpp"
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MyHistogram.hpp"

class MyApp: public wxApp
{
public:
	virtual bool OnInit();
};

class MyPanel: public wxPanel
{
public:
    MyPanel( wxWindow *parent ) ;
    ~MyPanel() ;
	void OnPaint(wxPaintEvent &WXUNUSED(event));
	void OpenImage(wxString fileName);
	void MirrorImage(bool horizontal);
	void BlurImage();
	void RotateImage(int idRotation);
	void NegateImage();
	void DesaturateImage();
	void ThresholdImage();
	void ApplyThreshold(const int value);
	void PosterizeImage();
	void AboutImage();
	void ContrastImage();
	
private:
	MyImage *m_image ;		// used to load and process the image
	wxBitmap m_bitmap ;	// used to display the image
	int m_width;
	int m_height;
};

class MyFrame: public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	void OnOpenImage(wxCommandEvent& event);
	void OnSaveImage(wxCommandEvent& event);
	void OnHello(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnEnCours(wxCommandEvent& event);
	void OnResize(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnProcessImage(wxCommandEvent& event);
	void OnThresholdImage(wxCommandEvent& event);
	
	MyPanel *m_panel; // the panel inside the main frame
};

enum	// énumération. Elle gère la numérotation automatiquement 
{
	ID_Hello = 1,
	ID_About,	// ID_Truc a pour valeur 2 
	ID_EnCours,	// ID_Machin a pour valeur 3 
	ID_PlusLarge,
	ID_MoinsLarge,
	ID_Open,
	ID_Save,
	ID_Mirror_Horizontal,
	ID_Mirror_Vertical,
	ID_Blur,
	ID_Rotate,
	ID_Negatif,
	ID_Desaturate,
	ID_Threshold,
	ID_Posterize,
	ID_Contrast
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	wxInitAllImageHandlers();
	MyFrame *frame = new MyFrame( wxT("Image viewer 2022"), wxPoint(50, 50), wxSize(450, 340) );
	frame->Center();
	frame->Show(true);
	return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	m_panel = new MyPanel(this);
	
	wxMenu *menuFile = new wxMenu ;
	
	menuFile->Append(ID_Open, wxT("Open\tCtrl-O"), "Ouvrir une image") ;
	Bind(wxEVT_MENU, &MyFrame::OnOpenImage, this, ID_Open) ;
	
	menuFile->Append(ID_Save, wxT("Save\tCtrl-O"), "Sauvegarder l'image") ;
	Bind(wxEVT_MENU, &MyFrame::OnSaveImage, this, ID_Save) ;
	
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

	wxMenu* menuProcess = new wxMenu;
	menuProcess->Append(ID_Mirror_Horizontal, wxT("Horizontal Mirror\tCtrl-M"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Mirror_Horizontal);
	
	menuProcess->Append(ID_Mirror_Vertical, wxT("Vertical Mirror\tCtrl-V"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Mirror_Vertical);
	
	menuProcess->Append(ID_Blur, wxT("Blur\tCtrl-B"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Blur);
	
	menuProcess->Append(ID_Rotate, wxT("Rotate\tCtrl-R"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Rotate);
	
	menuProcess->Append(ID_Negatif, wxT("Negatif\tCtrl-N"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Negatif);
	
	menuProcess->Append(ID_Desaturate, wxT("Desaturate\tCtrl-D"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Desaturate);
	
	menuProcess->Append(ID_Threshold, wxT("Threshold\tCtrl-T"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Threshold);
	
	menuProcess->Append(ID_Posterize, wxT("Posterize\tCtrl-T"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Posterize);
	
	menuProcess->Append(ID_Contrast, wxT("Contrast\tCtrl-C"));
	Bind(wxEVT_MENU, &MyFrame::OnProcessImage, this, ID_Contrast);
	
	Bind(MON_EVENEMENT, &MyFrame::OnThresholdImage, this) ;
	
	wxMenuBar *menuBar = new wxMenuBar ;
	menuBar->Append( menuFile, wxT("File" )) ;
	menuBar->Append(menuHelp, wxT("Help"));
	menuBar->Append(menuProcess, wxT("Process"));
	SetMenuBar(menuBar) ;
	
	wxStatusBar *statusBar = CreateStatusBar();
	SetStatusText(wxT("Image viewer 2022"));
	SetStatusBar(statusBar);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage(wxT("Hello world from wxWidgets!"));
}

void MyFrame::OnAbout(wxCommandEvent& event) {
	m_panel->AboutImage();
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

MyPanel::MyPanel(wxWindow *parent) : wxPanel(parent) {
	Bind(wxEVT_PAINT, &MyPanel::OnPaint, this) ;
	m_image = nullptr;
	m_width = 0;
	m_height = 0;
}

MyPanel::~MyPanel() {
	delete m_image;
}

void MyPanel::AboutImage() {
	if(m_image) {
		wxLogMessage(wxT("Hello world from wxWidgets!"));
		unsigned int colorCount = m_image->countColors();
		wxLogMessage(wxT("Colors count: " + std::to_string(colorCount)));
	}
}

void MyFrame::OnOpenImage(wxCommandEvent& event) {
	wxString filename = wxFileSelector(wxT("Choose an image to open"), "", "", "", "PNG images (*.png)|*.png|JPG images (*.jpg)|*.jpg");
	if(!filename.empty()) {
		m_panel->OpenImage(filename);
	} 
}

void MyPanel::OpenImage(wxString fileName) {
	if(m_image) {
		delete m_image;
	}
	m_image = new MyImage(fileName);
	m_width = m_image->GetWidth();
	m_height = m_image->GetHeight();
	GetParent()->SetSize(m_width, m_height);
	Refresh();
}

void MyPanel::OnPaint(wxPaintEvent &WXUNUSED(event)) {
	if(m_image != nullptr) {
		m_bitmap = wxBitmap(*m_image);
		wxPaintDC dc(this);
		dc.DrawBitmap(m_bitmap, 0, 0);
	}
}

void MyFrame::OnSaveImage(wxCommandEvent& event) {
	
}

void MyPanel::MirrorImage(bool horizontal) {
	if(m_image) {
		m_image->Mirror(horizontal);
		Refresh();
	}
}

void MyPanel::BlurImage() {
	if(m_image) {
		*m_image = m_image->Blur(5);
		Refresh();
	}
}

void MyPanel::RotateImage(int idRotation) {
	if(m_image) {
		MyRotateDialog *dlg = new MyRotateDialog(this, -1, wxDefaultPosition, wxSize(260,250)) ;
		if(dlg->ShowModal() == wxID_OK) {
			idRotation = dlg->RadioBox1->GetSelection();
			switch(idRotation) {
			case 0:
				m_image = m_image->Rotate90();
				break;
			case 2:
				m_image = m_image->RotateM90();
				m_image = m_image->RotateM90();
				m_image = m_image->RotateM90();
				break;
			case 1:
				*m_image = m_image->Rotate180();
				break;
			}
		}
		
		delete dlg;
		
		Refresh();
	}
}

void MyPanel::NegateImage() {
	m_image->Negative();
	Refresh();
}

void MyPanel::DesaturateImage() {
	m_image->Desaturate();
	Refresh();
}

/*void MyPanel::ThresholdImage() {
	MyThresholdDialog *dlg = new MyThresholdDialog(this, -1, wxT("Threshold"), wxDefaultPosition, wxSize(250,140)) ;
	dlg->ShowModal() ;
	m_image->Threshold(dlg->m_threshold->GetValue());
	delete dlg;
	Refresh();
}*/

wxDEFINE_EVENT(MON_EVENEMENT, wxCommandEvent);

void MyFrame::OnThresholdImage(wxCommandEvent& event) {
	std::cout << "HIHI" << std::endl;
	m_panel->ApplyThreshold(event.GetInt());
}

void MyPanel::ThresholdImage() {
	MyImage* copy = new MyImage(*m_image);
	MyThresholdDialog *dlg = new MyThresholdDialog(this, -1, wxT("Threshold"), wxDefaultPosition, wxSize(250,140));
	
	if(dlg->ShowModal() == wxID_CANCEL) {
		*m_image = *copy;
	}
	
	delete copy;
}

void MyPanel::ApplyThreshold(const int value) {
	m_image->Threshold(value);
}

void MyPanel::PosterizeImage() {
	m_image->Posterize();
	Refresh();
}

void MyPanel::ContrastImage() {
	MyHistogram* hist = new MyHistogram(*m_image);
	int imin = 0, imax = 0;
	hist->GetDynamic(&imin, &imax);
	m_image->EnhenceContrast(imin, imax);
	Refresh();
}

void MyFrame::OnProcessImage(wxCommandEvent& event) {
	int id = event.GetId();
	switch(id) {
		case ID_Mirror_Horizontal:
			m_panel->MirrorImage(true);
			break;
		case ID_Mirror_Vertical:
			m_panel->MirrorImage(false);
			break;
		case ID_Blur:
			m_panel->BlurImage();
			break;
		case ID_Rotate:
			m_panel->RotateImage(id);
			break;
		case ID_Negatif:
			m_panel->NegateImage();
			break;
		case ID_Desaturate:
			m_panel->DesaturateImage();
			break;
		case ID_Threshold: 
			m_panel->ThresholdImage();
			break;
		case ID_Posterize:
			m_panel->PosterizeImage();
			break;
		case ID_Contrast:
			m_panel->ContrastImage();
			break;
	}
}