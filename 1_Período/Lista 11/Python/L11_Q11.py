print("Informe um vetor com 10 numeros positivos: ")
numeros = [int(input()) for i in range(10)]

for numero in numeros:
    print(f"Os divisores de {numero}:", end = " ")
    for i in range(1, (numero // 2)+1):
        if numero % i == 0:
            print(i, end = ' ')
    print()