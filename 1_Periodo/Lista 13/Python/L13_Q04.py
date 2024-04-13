matriz = []

for i in range(10):
    print(f"Informe as notas do {i+1}º aluno: ")
    linha = [float(input()) for i in range(3)]

melhorProva1, melhorProva2, melhorProva3 = 0, 0, 0

for linha in matriz:
    prova = linha.index(max(linha))
    if prova == 0:
        melhorProva1+=1
    elif prova == 1:
        melhorProva2+=1
    else:
        melhorProva3+=1

print(f"{melhorProva1} alunos foi melhor na prova 1")
print(f"{melhorProva2} alunos foi melhor na prova 2")
print(f"{melhorProva3} alunos foi melhor na prova 3")