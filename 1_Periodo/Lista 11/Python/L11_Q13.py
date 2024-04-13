numeros = [int(input("Informe um numero: ")) for i in range(6)]
numerosPares = []
numerosImpares = []

for numero in numeros:
    if numero % 2 == 0:
        numerosPares.append(numero)
    else:
        numerosImpares.append(numero)

print("\nNumeros Pares: ")
print(numerosPares)

print("A soma dos números pares digitados: ")
print(sum(numerosPares))

print("Numeros ímpares: ")
print(numerosImpares)

print("A quantidade e números ímpares digitados: ")
print(len(numerosImpares))