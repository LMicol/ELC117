# Q.1 Defina uma função addSuffix(suf,nomes) que retorne a lista de nomes com o sufixo suf adicionado.
def addSuffix(suf,nomes) : return [nome+suf for nome in nomes]

# Q.2 Escreva uma função countShorts(words), que receba uma lista de palavras e retorne a quantidade de palavras dessa lista que possuem menos de 5 caracteres.
def countShorts(words) : return len([x for x in words if len(x) < 5])

# Q.3 Defina uma função stripVowels(s) que receba uma string e retire suas vogais, conforme os exemplos abaixo:
def stripVowels(s): return ''.join([ x for x in s if x not in 'aeiouAEIOU'])

# Q.4 Defina uma função hideChars(s) que receba uma string, possivelmente contendo espaços, e que retorne outra string substituindo os demais caracteres por '-', mas mantendo os espaços.
def hideChars(s): return ''.join(['-' if x != ' ' else x for x in s ])

# Q.5 Defina uma função que receba um número n e retorne uma tabela de números de 1 a n e seus quadrados
def genTable(n): return [ (y, y*y) for y in range(n+1) if y != 0]

# Q.6 Defina uma função que receba uma lista de palavras e retorne uma string contendo o primeiro e o último caracter de cada palavra da lista.
def genCode(l1) : return ''.join([x[0] + x[-1] for x in l1])

# Q.7 Defina uma função myZip(l1,l2) que reproduza o comportamento da função zip do Python:
def myZip(l1,l2): return [(l1[x], l2[x]) for x in range(len(l1 if(len(l1)<len(l2)) else l2))]

# Q.8 Escreva uma função enumerate(words) que numere cada palavra da lista recebida:
def enumerate(words) : return [(x, words[x]) for x in range(len(words))]

# Q.9 Escreva uma função isBin(s) que verifique se a string recebida representa um número binário.
def isBin(s) : return len([ x for x in s if x in '01']) == len(s)

# Q.10 Escreva uma função bin2dec(digits), que receba uma lista de dígitos representando um número binário e retorne seu equivalente em decimal.
def bin2dec(digits) : return sum([2**y for y in list(range(len(digits)-1, -1, -1)) if list(reversed(digits))[y] == 1])
