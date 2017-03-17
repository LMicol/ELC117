# Parte 1 do trabalho de Paradigmas:

# Q.1: faz a soma dos quadrados de x e y
def somaQuad(x,y): return (x*x) + (y*y)


# Q.2: l1 e l2 sendo duas listas
def hasEqHeads(l1,l2): return l1[0] == l2[0]


# Q.3: coloca "sr." antes de cada nome em uma lista
list(map(senhores, sua_lista_nomes))      # utilizar no terminal para chamar a função
def senhores(s):  return "Sr." + s


# Q.4:
len(list(filter(space, sua_string)))    # utilizar no terminal para chamar a função
def space(s): return s == " "


# Q.5:
list(map(eq, sua_lista_numeros))    # utilizar no terminal para chamar a função
def eq(n): return ((3*n)*2) + (2/n) + 1


# Q.6:
list(filter(negativos, sua_lista_numeros))  # utilizar no terminal para chamar a função
def negativos(n): return n < 0


# Q.7:
list(filter((entre1e100), sua_lista_numeros))   # utilizar no terminal para chamar a função
def entre1e100(n): return n > 0 & n < 101


# Q.8:
list(filter((pares), sua_lista_numeros))    # utilizar no terminal para chamar a função
def pares(n): return n%2 == 0


# Q.9: c = char que tem que procurar, s = string
def charFound(c,s): return (s.count(c)) > 0
    

# Q.10: s é uma string qualquer
def html(s): return "<B> " + s + " </B>"



