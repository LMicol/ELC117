#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cstdlib>

class Player {
  std::string name;
  int pontos;
public:
  Player(std::string name, int ponto) {
    this->name = name;
    this->pontos = ponto;
  }
  std::string getName() {
    return this->name;
  }
  int getPoints(){
    return  this->pontos;
  }
  void addPoints(int maisPontos){
    this->pontos += maisPontos;
  }
};


class Point_per_A{
  std::string jogador;
  std::string atividade;
  int pontos;
public:
  Point_per_A(std::string jogador, std::string atividade, int pontos){
    this->jogador = jogador;
    this->atividade = atividade;
    this->pontos = pontos;
  }
  std::string getName(){
    return this->jogador;
  }
  std::string getAtividade(){
    return this->atividade;
  }
  int getPoints(){
    return this->pontos;
  }
};


bool cmpPoints(Point_per_A& p1, Point_per_A& p2) {
   return p1.getPoints() > p2.getPoints();
}

bool cmpPointsPlayer(Player& p1, Player& p2) {
   return p1.getPoints() > p2.getPoints();
}

bool cmpNamePlayer(Player& p1, Player& p2) {
   return p1.getName() < p2.getName();
}


int main() {
  //arquivo a ser lido
  std::ifstream data("data.csv");

  std::string line;
  std::string cell[3];

  std::vector<Point_per_A> v;   // Duas classes uma salva as atividades, pontos e jogador
  std::vector<Player> Players;  // A outra só os pontos e o jogador

  while (std::getline(data, line)) {
    // Lê linha a linha e salva no vetor cell
    std::stringstream linestream(line);
    std::getline(linestream, cell[0], ',');
    std::getline(linestream, cell[1], ',');
    std::getline(linestream, cell[2], ',');

    // Salva cada linha lida na primeira struct onde é apresentado pontos por atividades
    Point_per_A p1 = Point_per_A(cell[0], cell[1], strtol(cell[2].c_str(),0,10));
    v.push_back(p1);

    // Salva no segundo vetor onde temos que salvar cada pontuação e não pode haver jogadores repetidos
    bool temNoVetor = false;
    std::vector<Player>::iterator it;
    // Verifica se o jogador existe no vetor
    for (it = Players.begin(); it != Players.end(); it++){
      std::string aux = it->getName();
      if (aux == cell[0]){
        // Se tiver no vetor, acrescenta pontos ao jogador existente
        it->addPoints(strtol(cell[2].c_str(),0,10));
        temNoVetor = true;
      }
    }
    // Se não, cria um novo jogador e entrega a ele seus pontos
    if(temNoVetor == false) {
      Player p2 = Player(cell[0], strtol(cell[2].c_str(),0,10));
      Players.push_back(p2);
    }
  }
  // primeiro sort e primeiro print
  std::sort(v.begin(), v.end(), cmpPoints);
  std::vector<Point_per_A>::iterator itt;
  for (itt = v.begin(); itt != v.end(); itt++){
    std::cout<< itt->getName() << " ";
    std::cout<< itt->getAtividade() << " ";
    std::cout<< itt->getPoints() << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl << std::endl;

  // segundo sort e print
  std::sort(Players.begin(), Players.end(), cmpNamePlayer);
  std::vector<Player>::iterator it;
  for (it = Players.begin(); it != Players.end(); it++){
    std::cout << it->getName() << " ";
    std::cout << it->getPoints() << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl << std::endl;

  // Ultimo sort e ultimo print
  std::sort(Players.begin(), Players.end(), cmpPointsPlayer);
  for (it = Players.begin(); it != Players.end(); it++){
    std::cout << it->getName() << " ";
    std::cout << it->getPoints() << " ";
    std::cout << std::endl;
  }
}
