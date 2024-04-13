import os
import random

while(True):
    os.system('cls')
    menu = 0
    print("1. Gerar dígitos verificadores.")
    print("2. Validar CPF.")
    print("3. Gerar um CPF.")
    print("4. Gerar N CPFs.")
    print("0. Para sair do programa.")
    menu = int(input())

    if menu == 1:
        CPFstring = input("Informe os 9 primeiros digitos do CPF: ")
        CPF = []
        for char in CPFstring:
            numero = int(char)
            CPF.append(numero)
        if len(CPF) != 9:
            print("\nDigitar exatamente 9 digitos.\n\nPrecione enter para continuar. ")
            input()
            continue

        soma = 0
        for i in range(10, 12):
            for j in range(len(CPF)):
                soma += CPF[j] * (i - j)
            
            soma %= 11
            if soma > 9:
                CPF.append(0)
            else:
                CPF.append(11 - soma)
            soma = 0

        for numero in CPF:
            print(numero, end = ' ')

        print('\n')
        print("\nPrecione enter para continuar. ")
        input()
    elif menu == 2:
        CPFstring = input("Informe CPF: ")
        CPF = []
        for char in CPFstring:
            numero = int(char)
            CPF.append(numero)

        if len(CPF) != 11:
            print("\nDigitar exatamente 11 digitos.\n\nPrecione enter para continuar. ")
            input()
            continue
        cont = 0
        soma = 0
        for i in range(10, 12):
            for j in range(i-1):
                soma += CPF[j] * (i - j)
            soma %= 11
            if (11 - soma) != CPF[i - 1]:
                cont = 1
            soma = 0
        if cont == 1:
            print("CPF Invalido.\n\nPrecione enter para continuar. ")
            input()
            continue 
        print("CPF Valido.")

        print("\nPrecione enter para continuar. ")
        input()
        
    elif menu == 3:
        CPF = [random.randint(0,9) for i in range(9)]

        soma = 0
        for i in range(10, 12):
            for j in range(len(CPF)):
                soma += CPF[j] * (i - j)
            
            soma %= 11
            if soma > 9:
                CPF.append(0)
            else:
                CPF.append(11 - soma)
            soma = 0

        for numero in CPF:
            print(numero, end = '')

        print('\n')
        print("\nPrecione enter para continuar. ")
        input()
    elif menu == 4:
        n = int(input("Informe N: "))
        for i in range(n):
            CPF = [random.randint(0,9) for i in range(9)]

            soma = 0
            for i in range(10, 12):
                for j in range(len(CPF)):
                    soma += CPF[j] * (i - j)
                
                soma %= 11
                if 11 - soma > 9:
                    CPF.append(0)
                else:
                    CPF.append(11 - soma)
                soma = 0

            for numero in CPF:
                print(numero, end = '')
            print()
        print("Precione enter para continuar. ")
        input()
    else:
        break
    
os.system('cls')