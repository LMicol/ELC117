/// Lucas Micol - Paradigmas de Programação - 2017/1 - Trabalho 6
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

#define PI 3.14159265358979323846

/**
                        Programa dos biscoitos:
        Esse programa simula a criação e vendas de biscoitos feitos de diversas
formas, os biscoitos tem quatro formatos e são divididos em faixa de forma, tamanho
e preço final. Tabela de valores:
                            P (3cm² - 6cm²)      M (6cm² - 9cm²)     G (9cm² - 15cm²)
            Triângulos:         R$  0,50            R$  1,00            R$  1,65
            Círculos  :         R$  0,50            R$  1,00            R$  1,65
            Retângulo :         R$  0,50            R$  1,00            R$  1,65

        Considerando que cada biscoito vendido custa 65% do seu valor final para ser produzido,
o programa gera o valor final de produção, quantos biscoitos serão feitos e o lucro.
*/

class Biscoito { /// Classe geral para todos biscoitos
protected:
    std::string tipo;
    float area;
    float preco;
public:
    void set_Preco(float novoPreco){
        this->preco = novoPreco;
    }
    float get_Preco(){
        return this->preco;
    }
    float get_area(){
        return this->area;
    }
    std::string get_Tipo(){
        return this->tipo;
    }
};

/// Presupondo que o triângulo seja um triângulo retângulo
class BiscoitoTriangular : public Biscoito{
private:
    float lados;
public:
    BiscoitoTriangular(float lado){
        this->tipo = "Triangulo";
        this->lados = lado;
        this->area = ((lado*lado)/2);
    }
};

/// Pode ser retangulo ou quadrado
class BiscoitoRetangular : public Biscoito{
private:
    float lado;
    float altura;
public:
    BiscoitoRetangular(float altura, float lado){
        this->tipo = "Retangulo||Quadrado";
        this->lado = lado;
        this->altura = altura;
        this->area = (lado*altura);
    }
};

/// Circulos redondinhos
class BiscoitoRedondo : public Biscoito{
private:
    float raio;
public:
    BiscoitoRedondo(float raio){
        this->tipo = "Redondo";
        this->raio = raio;
        this->area = PI*(raio*raio);
    }
};

/// Aux de ordenação do vetor
bool cmpTamanho(Biscoito &a, Biscoito &b) {
  return a.get_area() > b.get_area();
}

main(){
    int biscs = 0;
    std::vector<Biscoito> biscoitos; // Guarda todos os biscoitos

    std::cout << "Quantos biscoitos serao feitos?  ";
    std::cin >> biscs;
    std::cout << "Criando um sistema aleatorio de producao de biscoitos..." << std::endl;

    // Gera valores aleatorios para os tamanhos e para as formas
    unsigned seed = static_cast<int> (std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distributionQuadrado(19, 35);
    std::uniform_int_distribution<int> distributionTriangulo(15, 43);
    std::uniform_int_distribution<int> distributionRedondo(10, 20);
    std::uniform_int_distribution<int> distributionSwitch(0, 2);

    for(int i = 0; i < biscs; i ++){
        int s = distributionSwitch(generator);
        switch (s)
        {
            case 0:
            {
                BiscoitoTriangular b( (((float)distributionTriangulo(generator)) / 10) + 1 );
                biscoitos.push_back(b);
                break;
            }
            case 1:
            {
                BiscoitoRedondo b( ((float)distributionRedondo(generator)) / 10 );
                biscoitos.push_back(b);
                break;
            }
            case 2:
            {
                BiscoitoRetangular b( ((float)distributionQuadrado(generator)) / 10, ((float)distributionQuadrado(generator)) / 10 );
                biscoitos.push_back(b);
                break;
            }
        }
    }
    std::cout << "      Foram Produzidos " << biscs << " Biscoistos " << std::endl << std::endl;

    // Ordena o vetor por tamanho dos biscoitos
    std::sort(biscoitos.begin(), biscoitos.end(), cmpTamanho);

    std::cout << "      Biscoitos em ordem de tamanho : " << std::endl ;

    // Variavei que gravam todos os dados importantes para os prints posteeriores
    int contTri = 0, contQuad = 0, contCir = 0;
    int contP = 0, contM = 0, contG = 0;
    float lucroP = 0, lucroM = 0, lucroG = 0;
    float lucro = 0;

    std::vector<Biscoito>::iterator it;
    /**
            Itera o vetor buscando cada biscoito e descobrindo o seu tamanho, colocando seu preço,
        calculando o lucro e calculando as quantidades de cada forma e tamanho.
    */
    for (it = biscoitos.begin(); it != biscoitos.end(); it++) {

        std::string s = it->get_Tipo();
        std::cout << s << "  ";
        if(s == "Redondo"){
            contCir++;
        }else if (s == "Triangulo"){
            contTri++;
        }else if (s == "Retangulo||Quadrado"){
            contQuad++;
        }

        float area = it->get_area();
        std::cout << area << "cm² " << std::endl;

        if(area >= 3 && area< 6){
            contP++;
            it->set_Preco(0.5);
            lucroP = lucroP + (0.5 * 0.35);
        }else if(area >= 6 && area < 9){
            contM++;
            it->set_Preco(1);
            lucroM = lucroM + (1 * 0.35);
        }else if(area >=9 && area <= 15){
            contG++;
            it->set_Preco(1.65);
            lucroG = lucroG + (1.65 * 0.35);
        }
    }

    lucro = lucroP + lucroM + lucroG;

    std::cout << std::endl << "  Com esse esquema de producao os estudantes terao feito:" << std::endl << std::endl;
    std::cout << "Biscoitos Retangulos||Quadrados: " << contQuad << std::endl ;
    std::cout << "Biscoitos Redondos: " << contCir << std::endl ;
    std::cout << "Biscoitos Triangulares: " << contTri << std::endl << std::endl ;
    std::cout << "Biscoitos P: " << contP << std::endl ;
    std::cout << "Biscoitos M: " << contM << std::endl ;
    std::cout << "Biscoitos G: " << contG << std::endl << std::endl;

    std::cout << "O valor de cada biscoito é 65% custo de produção + 35% lucro, sendo assim, o lucro final desses biscoitos foi de : ";
    std::cout << "R$ " << lucro << std::endl ;

    std::cout << "E o valor respectivo do lucro de cada tamanho foi: " << std::endl;
    std::cout << "Tamanho P: " << lucroP << std::endl ;
    std::cout << "Tamanho M: " << lucroM << std::endl ;
    std::cout << "Tamanho G: " << lucroG << std::endl ;

}
