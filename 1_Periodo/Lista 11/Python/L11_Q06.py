numeros = [float(input("Informe um numero real: ")) for i in range(10)]
numerosRepetidos = []
for numero in numeros:
    if numeros.count(numero) > 1:
        numerosRepetidos.append(numero)
numerosRepetidos = list(set(numerosRepetidos))
print(numerosRepetidos)