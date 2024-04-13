numero = int(input("Informe um numero inteiro positivo: "))

if numero <= 0:
    print("Numero invalido")
else:
    for i in range(2 , numero//2):
        if numero % i == 0:
            print("O numero não é primo")
            break
    else:
        print("O numero é primo")