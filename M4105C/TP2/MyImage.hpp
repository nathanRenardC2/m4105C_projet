#ifndef MYIMAGE_HPP
#define MYIMAGE_HPP
#include <wx/wx.h>

class MyImage : public wxImage
{
public:
	
	MyImage(const wxString& fileName);
	MyImage(wxImage image);

	MyImage(int largeur, int hauteur);
	MyImage();
	
	void Negative();
	void Desaturate();
	void Threshold(int seuil);
	void Mirror(bool horizontally = true);
	MyImage* Rotate90();
	MyImage* RotateM90();
	void Posterize();
	unsigned int countColors();
	void EnhenceContrast(int imin, int imax);
};

#endif // MYIMAGE_HPP
