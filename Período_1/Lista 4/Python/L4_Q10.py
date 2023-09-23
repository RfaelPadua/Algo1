salario = float(input("Informe o seu salario: "))
tempoDeTrabalho = int (input("Informe o tempo de trabalho na empresa: "))

if tempoDeTrabalho >= 5:
    salario += salario * 0.20
else:
    salario += salario * 0.10

print(salario)