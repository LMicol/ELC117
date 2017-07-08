/**
 *  Lucas Micol - Paradigmas de Programa��o - 2017/1
 *  Extra sobre as fun��es e utiliza��es da biblioteca Chrono em C++
*/
#include <iostream>   // Saidas b�sicas
#include <chrono>     // Fun��es de tempo
#include <ctime>      // Auxiliares de algumas fun��es do Chrono
#include <thread>     // Utilizado apenas no Sleep

main(){
    std::chrono::time_point<std::chrono::system_clock> inicio, fim;
    // Declara as duas vari�veis de tempo

    inicio = std::chrono::system_clock::now();
    // Pega o tempo do sistema antes da execu��o do programa

    std::cout << "Isso vai demorar tres segundos..." << std::endl << std::endl;
    // "Seu programa aqui"
    std::this_thread::sleep_for(std::chrono::seconds(3));
    // Nesse caso uso um thread para simular um programa que demora 3 segundos para ser executado

    fim = std::chrono::system_clock::now();
    // Pega o tempo ap�s a execu��o do programa

    int t = std::chrono::duration_cast<std::chrono::seconds>(fim-inicio).count();
    // Calcula a difer�nca de tempo em segundos do fim do programa com o inicio para descobrir o tempo de execu��o
    std::time_t relogio = std::chrono::system_clock::to_time_t(fim);
    // Usando o define time_t, da biblioteca ctime.h, o relogio recebe os dados do horario de t�rmino do programa.

    std::cout << "Hor�rio de t�rmino:  " << std::ctime(&relogio) << std::endl;
    // Printa o tempo de acordo com o valor resultante de relogio
    std::cout << "Tempo de processamento:  " << t << " segundo(s)" << std::endl;
}
