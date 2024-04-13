matriz = []

for i in range(3):
    linha = [int(input("")) for i in range(3)]
    matriz.append(linha)
soma = []
for linha in matriz:
    soma.append(sum(linha))
print(soma)