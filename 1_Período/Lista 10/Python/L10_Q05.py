# receba o tamanho do quadrado
tamanho = int(input("Informe o tamanho do quadrado: "))

# Desenhar a base superior

print("*" * tamanho)

# Desenhar os lados do quadrado
for i in range(tamanho - 2):
    print('*' + ' ' * (tamanho - 2) + '*')

# Desenhar a base inferior
print("*" * tamanho)
