matriz = []


for i in range(3):
    linha = []
    for j in range(3):
        linha.append(int(input(f'A{i}x{j} = ')))
    matriz.append(linha)

for linha in matriz:
    print(linha)

soma = 0
for i in range(3):
    soma += matriz[i][i]
    

print(soma)