#include "MyImage.hpp"
#include <iostream>
using namespace std;


MyImage::MyImage(const wxString& fileName)
: wxImage(fileName) 
{
}

MyImage::MyImage(wxImage image)
: wxImage(image) 
{
}

 

MyImage::MyImage(int largeur, int hauteur)
: wxImage(largeur, hauteur) 
{
}

MyImage::MyImage()
: wxImage() 
{
}

void MyImage::Negative() {
	unsigned char* data = GetData();
	int longueur = GetHeight() * GetWidth() * 3;
	for(int i=0; i<longueur; i++) {
		data[i] = 255 - data[i];
	}
}

void MyImage::Desaturate() {
	unsigned char* data = GetData();
	int longueur = GetHeight() * GetWidth() * 3;
	for(int i=0; i<longueur; i+=3) {
		int valeur = data[i] * 0.2126 + data[i+1] * 0.7152 + data[i+2] * 0.0722;
		data[i] = valeur;
		data[i+1] = valeur;
		data[i+2] = valeur;
	}
}

void MyImage::Threshold(int seuil) {
	Desaturate();
	unsigned char* data = GetData();
	int longueur = GetHeight() * GetWidth() * 3;
	for(int i=0; i<longueur; i+=3) {
		if(data[i] <= seuil) {
			data[i] = 0;
			data[i+1] = 0;
			data[i+2] = 0;
		} else {
			data[i] = 255;
			data[i+1] = 255;
			data[i+2] = 255;
		}
	}
}

void MyImage::Mirror(bool horizontally) {
	unsigned char* data = GetData();
	
	if(horizontally) {
		for(int j=0; j<GetHeight(); j++) {
			for(int i=0; i<GetWidth()/2; i++) {
				int pixel = (j*GetWidth()+i) * 3;
				int symPixel = (j*GetWidth()+GetWidth()-i)*3;
				
				unsigned char temp = data[symPixel];
				data[symPixel] = data[pixel-3];
				data[pixel-3] = temp;
				
				temp = data[symPixel+1];
				data[symPixel+1] = data[pixel-2];
				data[pixel-2] = temp;
				
				temp = data[symPixel+2];
				data[symPixel+2] = data[pixel-1];
				data[pixel-1] = temp;
			}
		}
	} else {
		for(int j=0; j<GetHeight()/2; j++) {
			for(int i=0; i<GetWidth(); i++) {
				int pixel = (j*GetWidth()+i)*3;
				int symPixel = ((GetHeight()-1-j)*GetWidth() + i)*3;
				
				unsigned char temp = data[symPixel];
				data[symPixel] = data[pixel];
				data[pixel] = temp;
				
				temp = data[symPixel+1];
				data[symPixel+1] = data[pixel+1];
				data[pixel+1] = temp;
				
				temp = data[symPixel+2];
				data[symPixel+2] = data[pixel+2];
				data[pixel+2] = temp;
			}
		}
	}	
}

MyImage* MyImage::Rotate90(){
    unsigned int sizeX = this->GetWidth();
    unsigned int sizeY = this->GetHeight();
    unsigned char* data = this->GetData();
    MyImage* newImage = new MyImage(this->GetHeight(), this->GetWidth());
    unsigned char* newdata = newImage->GetData();
    for(unsigned int x=0; x< sizeX; x++){
        for(unsigned int y=0; y<sizeY; y++){
            int pixel = (y*sizeX+x)*3;
            int destination = (x*sizeY+(sizeY-y-1))*3; 
            newdata[destination] = data[pixel] ;
            newdata[destination+1] = data[pixel+1];
            newdata[destination+2] = data[pixel+2];
        }
    }
    return newImage;
}

MyImage* MyImage::RotateM90(){
    unsigned int sizeX = this->GetWidth();
    unsigned int sizeY = this->GetHeight();
    unsigned char* data = this->GetData();
    MyImage* newImage = new MyImage(this->GetHeight(), this->GetWidth());
    unsigned char* newdata = newImage->GetData();
    for(unsigned int x=0; x< sizeX; x++){
        for(unsigned int y=0; y<sizeY; y++){
            int pixel = (y*sizeX+x)*3;
            int destination = (x*sizeY+(sizeY-y-1))*3; 
            newdata[destination] = data[pixel] ;
            newdata[destination+1] = data[pixel+1];
            newdata[destination+2] = data[pixel+2];
        }
    }
    return newImage;
}

void MyImage::Posterize() {
	unsigned char* data = GetData();
	long taille = GetWidth() * GetHeight() * 3;
	for(int i=0; i<taille; i++) {
		if(data[i] > 127) {
			data[i] = 255;
		} else {
			data[i] = 0;
		}
	}
}

unsigned int MyImage::countColors() {
	bool* colors = (bool*)malloc(256*256*256 * sizeof(bool));
	for(unsigned int i=0; i<(256*256*256); i++) {
		colors[i] = false;
	}
	
	unsigned int longueur = GetWidth() * GetHeight() * 3;
	unsigned char* data = GetData();
	for(unsigned int i=0; i<longueur; i+=3) {
		unsigned int red = data[i];
		unsigned int green = data[i+1];
		unsigned int blue = data[i+2];
		
		unsigned int color = blue + (green << 8) + (red << 16);
		colors[color] = true;
	}
	
	unsigned int count = 0;
	for(unsigned int i=0; i<(256*256*256*sizeof(bool)); i++) {
		if(colors[i]) {
			count++;
		}
	}
	
	free(colors);
	
	return count;
}

void MyImage::EnhenceContrast(int imin, int imax) {	
	int d = (255 * imin) / (imin - imax);
	int f = 255 / (imax - imin);
	
	unsigned char* data = GetData();
	int size = GetWidth() * GetHeight() * 3;
	for(int i=0; i<size; i++) {
		if(f * data[i] + d > 255) {
			data[i] = 255;
		}
		if(f * data[i] + d < 0) {
			data[i] = 0;
		} else {
			data[i] = f * data[i] + d;
		}
		
	}
}