
<h1> std::chrono </h1>

<h2> Utilidades e aplicações: </h2>

<p>
Esta biblioteca utiliza classes e funções de manipulação de tempo e pode ser dividida em três tipos principais :
 durações, relógios e pontos de tempo.
Todas trabalham com a escala de tempo, porém cada uma tem sua finalidade específica.
</p>

<h3>Duração</h3>
<p>
Como o próprio nome já diz, é um espaço de tempo, um intervalo entre dois eventos.
Possuímos apenas uma classe de duração:
  <li>duration : generaliza qualquer tipo de duração temporal (sgundos, minutos, horas...)</li>
</p>

<h3>Relógios</h3>
<p>
É um ponto de partida, uma marca onde a partir desse ponto contamamos uma duração específica, seja essa de 
qualquer medida como segundos ou horas. Em c++ possuímos três tipos de relógios:
</p>

 <li>system_clock : Relógio padrão do sistema</li>
 <li>steady_clock : Relógio monotônico(cresce ou decresce) que nunca será ajustado</li>
 <li>high_resolution_clock : Relógio de alta precisão</li>
		

<h3>Pontos de Tempo</h3>
<p>
É uma duração de tempo a partir de um determinado relógio, ou seja, uma duração com um referêncial de partida.
Para esse caso também possuímos apenas uma classe:
</p>

 <li>time_point : Um ponto de tempo</li>

<h3>Arquivo exemplo</h3>

<p>
Neste arquivo [Chrono1.c] (https://github.com/LMicol/ELC117/blob/master/extras/std-chrono/chrono1.cpp)
temos uma demonstração de uso da biblioteca. Esse exemplo mostra como pegar a hora atual do sistema e como
contar o tempo de execução de um programa.
</p>
