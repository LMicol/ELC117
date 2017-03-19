# Parte 2 do trabalho de Paradigmas:

# Q.1 : escreve sr. no inicio de cada string da lista
def func1(lista_de_nomes):  return list(map(lambda s: "Sr." + s, lista_de_nomes))

# Q.2 : faz a equação para cada valor da lista
def func2(lista_de_numeros):  return list(map((lambda n: ((3*n*2)+(2/n)+1)), lista_de_numeros))

# Q.3 : retorna uma lista que contem os nomes que terminam com "a"
def func3(lista_de_nomes):  return list(filter(lambda ult: ult[-1:] == "a", lista_de_nomes))

# Q.4 : retorna uma lista das pessoas que nasceram depois de 1970
def func4(idades):  return list(filter(lambda num: num < 2017 - 1970, idades))

# Q.5 : o retorno da função será o new_numbers que é um vetor com os numeros de numbers * 2
def func5(numbers):  return list(map(lambda num: num * 2, numbers)) 
