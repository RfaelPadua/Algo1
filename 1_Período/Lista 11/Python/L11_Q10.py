print("Informe o primeiro vetor de 10 numeros inteiros: ")
vetor1 = [int(input()) for i in range(10)]

print("Informe o segundo vetor de 10 numeros inteiros: ")
vetor2 = [int(input()) for i in range(10)]

vetor3 = []
for i in range(10):
    vetor3.append(vetor1[i] + vetor2[i])

print(vetor3)