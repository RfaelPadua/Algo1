numeros = []
for i in range(6):
    numeros.append(int(input("Informe um numero inteiro: ")))

for numero in reversed(numeros):
    print(numero, end = ' ')