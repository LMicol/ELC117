/**
 *  Lucas Micol - Paradigmas de Programação - 2017/1
 *  Extra sobre as funções e utilizações da biblioteca Chrono em C++
*/
#include <iostream>   // Saidas básicas
#include <chrono>     // Funções de tempo
#include <ctime>      // Auxiliares de algumas funções do Chrono
#include <thread>     // Utilizado apenas no Sleep

main(){
    std::chrono::time_point<std::chrono::system_clock> inicio, fim;
    // Declara as duas variáveis de tempo

    inicio = std::chrono::system_clock::now();
    // Pega o tempo do sistema antes da execução do programa

    std::cout << "Isso vai demorar tres segundos..." << std::endl << std::endl;
    // "Seu programa aqui"
    std::this_thread::sleep_for(std::chrono::seconds(3));
    // Nesse caso uso um thread para simular um programa que demora 3 segundos para ser executado

    fim = std::chrono::system_clock::now();
    // Pega o tempo após a execução do programa

    int t = std::chrono::duration_cast<std::chrono::seconds>(fim-inicio).count();
    // Calcula a diferênca de tempo em segundos do fim do programa com o inicio para descobrir o tempo de execução
    std::time_t relogio = std::chrono::system_clock::to_time_t(fim);
    // Usando o define time_t, da biblioteca ctime.h, o relogio recebe os dados do horario de término do programa.

    std::cout << "Horário de término:  " << std::ctime(&relogio) << std::endl;
    // Printa o tempo de acordo com o valor resultante de relogio
    std::cout << "Tempo de processamento:  " << t << " segundo(s)" << std::endl;
}
