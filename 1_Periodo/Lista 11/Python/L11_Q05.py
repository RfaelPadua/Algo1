numeros = [int(input("Informe um numero: ")) for i in range(10)]
maiorNumero = float('-inf')
posicaoMaiorNumero = 0
menorNumero = float('inf')
posicaoMenorNumero = 0

for numero in numeros:
    if numero > maiorNumero:
        maiorNumero = numero
        posicaoMaiorNumero = numeros.index(numero)
    if numero < menorNumero:
        menorNumero = numero
        posicaoMenorNumero = numeros.index(numero)

print(f'O menor numero é {menorNumero} na posição {posicaoMenorNumero}')
print(f'O maior numero é {maiorNumero} na posição {maiorNumero}')