salario = float(input("Informe o salario: "))

if salario <= 280:
    print(f"O salario depois do reajuste é de R${salario + salario * 0.2: .2f}")
elif salario <= 700:
    print(f"O salario depois do reajuste é de R${salario + salario * 0.15: .2f}")
elif salario <= 1500:
    print(f"O salario depois do reajuste é de R${salario + salario * 0.1: .2f}")
else:
    print(f"O salario depois do reajuste é de R${salario + salario * 0.05: .2f}")