numeros = []
numerosPrimos = []
numeros.append(int(input("Informe um numero: ")))
numeros.append(int(input("Informe um numero: ")))

numeros.sort()

cont = False

for i in range(numeros[0]+1,numeros[1]):
    for j in range(2, i//2 + 1):
        if i % j == 0:
            cont = True
            break
    if cont == False:
        numerosPrimos.append(i)
    
    cont = False

print(numerosPrimos)