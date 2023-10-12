numeros = [float(input("Informe um numero real: ")) for i in range(10)]
cont = 0

for numero in numeros:
    if numero % 2 == 0:
        cont +=1

print(f'Ha {cont} numeros pares')
