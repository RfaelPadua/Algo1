numero = int(input("Informe um numero: "))

if numero % 10 == 0:
    print("É divisivel por 10.")
elif numero % 5 == 0:
    print("É divisivel por 5.")
elif numero % 2 == 0:
    print("É divisivel por 2.")
else:
    print("Não é divisivel nem por 10, 5 ou 2.")