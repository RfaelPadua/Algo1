matriz = []
soma = 0
x = 3
for i in range(x):
    linha = [float(input()) for j in range(x)]
    matriz.append(linha)

for i in range(x):
    for j in range(x):
        if i != j and i + j != x - 1:
                soma += matriz[i][j]

print(soma)