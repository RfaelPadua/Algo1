numeros = [float(input("Informe um numero real: ")) for i in range(5)]
cont = 0
codigo = 0
while codigo < 1 or codigo > 2:
    codigo = int(input('Informe o codigo: '))

if codigo == 1:
    print(numeros)
else:
    numeros.reverse()
    print(numeros)
