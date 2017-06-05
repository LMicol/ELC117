#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <FL/fl_ask.H>
#include <sstream>
#include "window.h"

/// Devido ao erro de compilação por causa da falta de reconhecimento da função std::to_string com o comando
/// de compilação $ fltk-config --compile t7\ -\ sorteador.cpp, utilizei  uma classe secundária que compensa
/// e implementa a mesma função da biblioteca std, logo abaixo:
namespace patch
{
  template < typename T > std::string to_string( const T& n )
  {
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
  }
}

class SorteadorView : public UserInterface {
private:
  std::vector<int> Participantes;
  int sorteados;
  int ja_sorteados;

  void sorteia_participantes(int n){
    for(int i=1; i<=n; i++){
	  this->Participantes.push_back(i);
	}
	std::random_shuffle (this->Participantes.begin(), this->Participantes.end());
    this->sorteados = n;
    this->ja_sorteados = 1;
  }

public:
  SorteadorView() {
    btnSORTEAR -> callback((Fl_Callback*) cbBtnSortear, (void*)(this));
    btnRESET -> callback((Fl_Callback*) cbBtnReset, (void*)(this));
  }

  static void cbBtnSortear (Fl_Widget* btn, void* userdata){
    SorteadorView* gui = static_cast<SorteadorView*>(userdata);
    try{
      int NdeParticipantes = std::stoi(gui->inputPARTICIPANTES->value());
      if(NdeParticipantes <= 0){
        fl_alert("DIGITE UM NÚMERO MAIOR DO QUE 0 ANTES DE CONTINUAR");
      }else if(gui->Participantes.empty()){
        if(gui->sorteados != 0){
          gui->sorteia_participantes(NdeParticipantes);
        }else if(gui->sorteados == 0){
          gui->boxRESULTS_->label("");
          gui->boxRESULTS->copy_label("");
          fl_alert("TODOS OS PARTICIAPNTES JÁ FORAM SORTEADOS");
        }
      }else {
        int win = gui->Participantes.back();
        gui->Participantes.pop_back();
        gui->boxRESULTS_->copy_label(patch::to_string(win).c_str());
        std::string ganhador_atual = patch::to_string(gui->ja_sorteados).c_str();
        ganhador_atual += "º Ganhador";
        gui->boxRESULTS->copy_label(ganhador_atual.c_str());
        gui->ja_sorteados++;
        gui->sorteados--;
      }
    }catch (std::invalid_argument&){
      fl_alert("DIGITE O NÚMERO DE PARTICIPANTES ANTES DE CONTINUAR");
    }
  }

  static void cbBtnReset(Fl_Widget* btn, void* userdata) {
	SorteadorView* gui = static_cast<SorteadorView*>(userdata);
    gui->boxRESULTS->label("------------------------------------");
    gui->boxRESULTS_->label("--");
    gui->inputPARTICIPANTES->value("");
    gui->Participantes.clear();
    gui->sorteados = 1;
  }


  void show() { // Mostra janela
    w->show();
  }
};


int main() {
  srand((unsigned)time(NULL));
  SorteadorView gui;
  gui.show();
  return Fl::run();
}
