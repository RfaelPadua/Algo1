valorHora = float(input("Informe o valor da hora de trabalho: "))
hora = int(input("Informe quantas horas trabalhadas no mês: "))

salario = valorHora*hora
salario += salario*0.1

print(f"O valor a ser pago para o funcionario é R$ {salario: .2f}")