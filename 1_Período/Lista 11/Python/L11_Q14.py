print("Informe a primeira lista de 10 elementos: ")
listaNumeros1 = [int(input()) for i in range(10)]
print("Informe a segunda lista de 10 elementos: ")
listaNumeros2 = [int(input()) for i in range(10)]
listaFinal = list(set(listaNumeros1) | set(listaNumeros2))

print(listaFinal)