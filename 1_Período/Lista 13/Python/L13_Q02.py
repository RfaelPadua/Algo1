matriz = []

for i in range(1, 11):
    linha = []
    for j in range(1, 11):
        if i < j:
            linha.append(2*i + 7*j - 2)
        elif i == j:
            linha.append(3*i*i - 1)
        else:
            linha.append(4*i**3 + 5*j**2 + 1)
    matriz.append(linha)


for linha in matriz:
    for numero in linha:
        print(f"{numero:5d}", end = ' ')
    print()