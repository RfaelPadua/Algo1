print("Informe 10 valores: ")
numeros = [int(input()) for i in range(10)]

for i in range(len(numeros)):
    if numeros[i] < 0:
        numeros[i] = 0

print(numeros)