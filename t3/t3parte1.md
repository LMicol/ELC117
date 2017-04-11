1.Mostre o trace comentado das consultas:
   ?- avo(joao,Y).

[trace]  ?- avo(joao,Y).                // Chama avo
   Call: (8) avo(joao, _2328) ? creep   // Chama avo para joao que ira chamar a função pai
   Call: (9) pai(joao, _2560) ? creep   // Chama pai para joao e procura resposta
   Exit: (9) pai(joao, jose) ? creep    // Encontrou a resposta jose e retorna
   Call: (9) pai(jose, _2328) ? creep   // Chama pela segunda vez pai passando a resposta achada anteriormente
   Fail: (9) pai(jose, _2328) ? creep   // Não acha respostas
   Fail: (8) avo(joao, _2328) ? creep   // Retorna o erro
false.


   ?- avo(roberto,Y).

[trace]  ?- avo(roberto,Y).                 // Chama avo
   Call: (8) avo(roberto, _2328) ? creep    // Chama avo com argumento roberto
   Call: (9) pai(roberto, _2542) ? creep    // Chama pai passando roberto
   Exit: (9) pai(roberto, joao) ? creep     // Encontra uma resposta pra pai roberto = joao, e retorna
   Call: (9) pai(joao, _2328) ? creep       // Chama novamente pai passando a resposta encontrada anteriormente
   Exit: (9) pai(joao, jose) ? creep        // Encontra uma resposta para pai(joão) = jose
   Exit: (8) avo(roberto, jose) ? creep     // Econtra uma resposta para avo(roberto) = jose
Y = jose ;                                  // Resposta printada
   Redo: (9) pai(roberto, _2542) ? creep    // Verifica outra possibilidade de respostapara pai(roberto)
   Exit: (9) pai(roberto, julio) ? creep    // Acha julio como resposta para pai(roberto)
   Call: (9) pai(julio, _2328) ? creep      // Chama pai(julho)
   Exit: (9) pai(julio, marcos) ? creep     // Encontra marcos de resposta para pai(julio)
   Exit: (8) avo(roberto, marcos) ? creep   // Retorna a resposta para avo(roberto) = marcos
Y = marcos ;                                // Printa Outra possibilidade de Resposta
   Redo: (9) pai(julio, _2328) ? creep      // Retorna para a chamada de pai(julio)
   Exit: (9) pai(julio, mario) ? creep      // encontra mais uma resposta = mario
   Exit: (8) avo(roberto, mario) ? creep    // Retorna para avo(roberto) mais uma resposta = mario
Y = mario.                                  // Printa a última possibilidade


2. Mostre o trace comentado das consultas:
   ?- azulejos(120,A).

[trace]  ?- |    azulejos(120,A).              // Chama a função azulejos passando o valor 120
   Call: (8) azulejos(120, _2328) ? creep      // Inicia a função azulejos com o valor 120 e o endereço de A
   Call: (9) 120>0 ? creep                     // Verifica se a constante 120 é > 0
   Exit: (9) 120>0 ? creep                     // Devolve true
   Call: (9) _2552 is floor(sqrt(120)) ? creep // Chama a função floor(sqrt(120)) que tira a raiz de 120 e arredonda para baixo
   Exit: (9) 10 is floor(sqrt(120)) ? creep    // Retorna o valor 10
   Call: (9) _2564 is 120-10*10 ? creep        // Associa no endereço a operação matemática
   Exit: (9) 20 is 120-10*10 ? creep           // Retorna o valor 20 para a operação acima
   Call: (9) azulejos(20, _2566) ? creep       // Chama novamente a função azulejos com o valor retornado acima
   Call: (10) 20>0 ? creep                     // Verifica de 20 é maior que 0
   Exit: (10) 20>0 ? creep                     // Retorna true
   Call: (10) _2572 is floor(sqrt(20)) ? creep // Executa novamente a função de raíz e arredondamento
   Exit: (10) 4 is floor(sqrt(20)) ? creep     // Retorna o valor 4 para a função anterior
   Call: (10) _2584 is 20-4*4 ? creep          // Atribui a função para o endereço
   Exit: (10) 4 is 20-4*4 ? creep              // Acha a resposta da função atribuida acima
   Call: (10) azulejos(4, _2586) ? creep       // Chama novamente a função azulejo, com o valor 4 achado antes
   Call: (11) 4>0 ? creep                      // Verifica se 4 é maior que 0
   Exit: (11) 4>0 ? creep                      // Retorna true
   Call: (11) _2592 is floor(sqrt(4)) ? creep  // Chama a função para fazer a raiz de 4
   Exit: (11) 2 is floor(sqrt(4)) ? creep      // Retorna o valor 2 como resposta
   Call: (11) _2604 is 4-2*2 ? creep           // Atribui a equação no endereço
   Exit: (11) 0 is 4-2*2 ? creep               // Retorna 0 como resposta da equação
   Call: (11) azulejos(0, _2606) ? creep       // Chama a função azulejos
   Exit: (11) azulejos(0, 0) ? creep           // Retorna por causa da declaração que quando azulejo(0) return 0
   Call: (11) _2610 is 1+0 ? creep             // Associa no endereço a soma de 1+0
   Exit: (11) 1 is 1+0 ? creep                 // Retorna o resultado 1 para a chamada anterior da função azulejo
   Exit: (10) azulejos(4, 1) ? creep           // Recebe a resposta do último retorno
   Call: (10) _2616 is 1+1 ? creep             // Atriubui e Executa a soma do retorno anterior com um
   Exit: (10) 2 is 1+1 ? creep                 // Retorna o valor 2 para a chamada anterior da função
   Exit: (9) azulejos(20, 2) ? creep           // Recebe o valor 2
   Call: (9) _2328 is 1+2 ? creep              // Soma o retorno com um e salva
   Exit: (9) 3 is 1+2 ? creep                  // Retorna a resposta para a chamada anterior da função
   Exit: (8) azulejos(120, 3) ? creep          // Libera a resposta para a primeira chamada da função
A = 3 ;                                        // Printa a resposta


3. Mostre o trace comentado das consultas:

   A declaração função sumQuads está no t3parte2.pl
   ?- sumQuads([1,2,3],Q).

[trace]  ?- sumQuads([1,2,3],Q).                 // Chama a sumQuads
   Call: (8) sumQuads([1, 2, 3], _2346) ? creep  // Chama a sumQuads passando a lista e uma posição de memória
   Call: (9) [1, 2, 3]=[_2588|_2590] ? creep     // Separa em [H|T]
   Exit: (9) [1, 2, 3]=[1, 2, 3] ? creep         // Salva H e T
   Call: (9) sumQuads([2, 3], _2610) ? creep     // Chama sumQuads passando T
   Call: (10) [2, 3]=[_2594|_2596] ? creep       // Separa T em [H1|T1]
   Exit: (10) [2, 3]=[2, 3] ? creep              // Salva H1 e T1
   Call: (10) sumQuads([3], _2616) ? creep       // Chama sumQuads passando T1
   Call: (11) [3]=[_2600|_2602] ? creep          // Tenta separar T1 em [H2|T2], mas não existe continuação da lista então...
   Exit: (11) [3]=[3] ? creep                    // Salva H2 como o próprio T1 e T2 como um lista vazia
   Call: (11) sumQuads([], _2622) ? creep        // Chama sumQuads com a lista vazia
   Exit: (11) sumQuads([], 0) ? creep            // Por causa da condição sumQuads([], 0), retorna 0
   Call: (11) _2632 is 3*3+0 ? creep             // Atribui a Equação a uma variável
   Exit: (11) 9 is 3*3+0 ? creep                 // Retorna 9 como resposta
   Exit: (10) sumQuads([3], 9) ? creep           // Recebe o 9 na chamada anterior
   Call: (10) _2644 is 2*2+9 ? creep             // Atribui a equação a uma variável
   Exit: (10) 13 is 2*2+9 ? creep                // Encontra o resultado 13 e retorna
   Exit: (9) sumQuads([2, 3], 13) ? creep        // Recebe o 13 na chamada anterior
   Call: (9) _2346 is 1*1+13 ? creep             // Executa a função e salva na variável
   Exit: (9) 14 is 1*1+13 ? creep                // Encontra a resposta 14 e retorna
   Exit: (8) sumQuads([1, 2, 3], 14) ? creep     // Salva a resposta para para a primeira chamada de sumQuads em Q
Q = 14 .                                         // Printa a resposta, 14.

