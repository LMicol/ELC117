#!/usr/bin/env python3
import itertools
import random

'''
   Programacao funcional para gerar SVG:
   - gera uma lista de coordenadas de retangulos
   - define uma lista de estilos (cores), em qualquer quantidade
   - aplica os estilos aos retangulos, gerando uma lista com todos os dados para o SVG
   - coloca os dados no formato SVG, concatenando strings
'''

def svgRect(rs):
   (((x,y),w,h),style) = rs
   return "<rect x='%.3f' y='%.3f' width='%.2f' height='%.2f' style='%s'/>\n" % (x,y,w,h,style)

def svgImage(w, h, rs):
   return "<svg width='%.2f' height='%.2f' xmlns='http://www.w3.org/2000/svg'>\n" % (w,h) + \
          ''.join(map(svgRect, rs)) + "</svg>"

def applyStyles(rects, styles):
   return list(zip(rects, itertools.cycle(styles)))

# Q.1 : Função de geração dos Retângulos
def genRects(n, w, h):
   return [((x,0.0),w,h) for x in range(n*50) if x % 50 == 0]
"""
   Professora, para um efeito mais bonito, apague o genRects
   acima e retire o cometário do genRects abaixo, repita o mesmo
   processo na main() 

def genRects(n, w, h):
   return [((x,y),w,h) for x in range(n*50) if x % 50 == 0 for y in range(n*50) if y % 100 == 0]
"""

# Q.2 : Styles gera tonalidades de verde e azul aleatórias
def styles(n): 
   if(n >= 255 or n <= 0) : return ["fill:rgb(255,255,255)","fill:rgb(0,0,0)"]
   x = random.randrange(0, n)
   return ["fill:rgb" + "(" + str(int(x/random.randrange(1, 20))) + "," + str(int(x*random.randrange(2, 5))) + "," + str(int(x*random.randrange(1, 3))) + ")", "fill:rgb" + "(" + str(int(x/random.randrange(1, 20))) + "," + str(int(x*random.randrange(1, 5))) + "," + str(int(x*random.randrange(3, 6))) + ")"]


def writeFile(fname, contents):
   f = open(fname, 'w')
   f.write(contents)
   f.close()
   
def main():
   maxWidth = 1000
   maxHeight = 100
   rects = genRects(10,50,50)
   estilos = styles(random.randrange(1, 254)) # se passar de 255 ou for menor que 0 fica xadrez preto e branco, por isso o random controlado
   rectstyles = applyStyles(rects, estilos)
   writeFile("mycolors.svg", svgImage(maxWidth, maxHeight, rectstyles))

'''
def main():
   maxWidth = 1370
   maxHeight = 650
   rects = genRects(50,50,50)
   estilos = styles(random.randrange(1, 254)) # se passar de 255 ou for menor que 0 fica xadrez preto e branco, por isso o random controlado
   rectstyles = applyStyles(rects, estilos)
   writeFile("mycolors.svg", svgImage(maxWidth, maxHeight, rectstyles))
'''
