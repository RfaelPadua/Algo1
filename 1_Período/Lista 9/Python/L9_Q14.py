numeros = []
somaNumeros = 0
maiorNumero = float('-inf')
menorNumero = float('inf')
qntNumerosPares = 0
somaNumerosPares = 0


while True:
    numero = int(input("Numero: "))
    if numero == 0:
        break
    if numero > maiorNumero:
        maiorNumero = numero
    if numero < menorNumero:
        menorNumero = numero

    numeros.append(numero)

qntNumeros = len(numeros)

for i in range(qntNumeros):
    somaNumeros += numeros[i]

for i in range(qntNumeros):
    if numeros[i] % 2 == 0:
        qntNumerosPares += 1
        somaNumerosPares += numeros[i]



mediaNumeros = somaNumeros / qntNumeros
mediaNumerosPares = somaNumerosPares / qntNumerosPares


print("\nA soma dos numeros digitados é: ", somaNumeros)
print("A quantidade de numeros digitados é: ", qntNumeros)
print("A média dos numeros digitados é: ", mediaNumeros)
print("O maior numero digitado é: ", maiorNumero)
print("O menor numero digitado é: ", menorNumero)
print("A media dos numeros pares é: ", mediaNumerosPares)