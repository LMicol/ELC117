#include "window.h"

UserInterface::UserInterface() {
  {
    w = new Fl_Double_Window(385, 405, "Sorteador");
    w->box(FL_EMBOSSED_BOX);
    w->user_data((void*)(this));
    { // Fl_Int_Input* inputPARTICIPANTES
      inputPARTICIPANTES = new Fl_Int_Input(100, 200, 180, 25, "Participantes");
      inputPARTICIPANTES->type(2);
      inputPARTICIPANTES->labelsize(13);
      inputPARTICIPANTES->align(Fl_Align(FL_ALIGN_LEFT));
    }
    {
      btnRESET = new Fl_Button(285, 200, 80, 25, "Reset");
    }
    { // Fl_Box* boxRESULTS
      boxRESULTS = new Fl_Box(190, 255, 0, 80, "");
      boxRESULTS->box(FL_BORDER_BOX);
      boxRESULTS->labelsize(15);
      boxRESULTS->align(Fl_Align(FL_ALIGN_TOP));
    }
    { // Fl_Box* boxRESULTS_
      boxRESULTS_ =  new Fl_Box(20, 255, 265+80, 80, "");
      boxRESULTS_ -> box(FL_BORDER_BOX);
      boxRESULTS_ -> labelsize(40);
    }
    { // Fl_Button* btnSORTEAR
      btnSORTEAR = new Fl_Button(20, 350, 265+80, 40, "Sortear");
    }
    {
      myimage = new Fl_PNG_Image("logo.png");
  	  boxImg = new Fl_Box(148, 45, 100, 100);
  	  boxImg->image(myimage);
  	  boxImg->redraw();
    }
    { // bool que define se ira sortear ou pegar o proximo da lista
      bool sorteado = false;
    }
    // Fl_Double_Window* w
    w->end();
  }
}

