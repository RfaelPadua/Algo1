matriz = []
soma = 0

for i in range(5):
    linha = [float(input()) for i in range(5)]
    matriz.append(linha)

for i in range(5):
    for j in range(5):
        if j > i:
            soma += matriz[i][j]

print(soma)