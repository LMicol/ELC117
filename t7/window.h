#ifndef window_h
#define window_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

class UserInterface {
public:
  UserInterface();
protected:
  Fl_Double_Window *w;              // Janela
  Fl_Int_Input *inputPARTICIPANTES; // n� de participantes
  Fl_Button *btnRESET;              // bot�o reset
  Fl_Box *boxRESULTS;               // n�mero do ganhador
  Fl_Box *boxRESULTS_;              // bot�o do ganhador
  Fl_Button *btnSORTEAR;            // bot�o sortear
  Fl_Box *boxImg;                   // caixa da imagem
  Fl_PNG_Image* myimage;            // a pr�pria imagem
};

#endif
