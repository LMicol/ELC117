# Parte 1 do trabalho de Paradigmas:

# Q.1: faz a soma dos quadrados de x e y
def somaQuad(x,y): return (x*x) + (y*y)


# Q.2: l1 e l2 sendo duas listas
def hasEqHeads(l1,l2): return l1[0] == l2[0]


# Q.3: coloca "Sr." antes de cada nome em uma lista
def senhores(s):
    def senhores_aux(s): return "Sr." + s
    return list(map(senhores_aux, s));


# Q.4: conta o número de espaços de uma string          
def space(s):
    def space_aux(x): return x == " "
    return len(list(filter(space_aux, s)))


# Q.5: executa a função correspondente para cada valor dentro da lista de numeros
def eq(ln):
    def eq_aux(n): return ((3*n)*2) + (2/n) + 1
    return list(map(eq_aux, ln))  


# Q.6: remove valores positivos da lista passada       
def negativos(n):
    def negativos_aux(num):return num < 0
    return list(filter(negativos_aux, n)) 


# Q.7: verifica os numeros entre 0 e 100 da lista de numeros
def entre1e100(n):
    def entre1e100_aux(num):return num > 0 and num < 101
    return list(filter((entre1e100_aux),n))


# Q.8: confere quais são os valores pares da lista         
def pares(n):
    def pares_aux(num):return num%2 == 0
    return list(filter(pares_aux, n)) 


# Q.9: c = char que tem que procurar, s = string, retorna se o char c esta presente na String s
def charFound(c,s):
    def charFound_aux(x): return x == c
    return len(list(filter(charFound_aux, s))) > 0
    

# Q.10: s é uma string qualquer que recebe a adição de <B> e </B>
def html(s): return "<B>" + s + "</B>"


