valorEmprestimo = float(input("Informe o valor do empréstimo: "))
nParcelas = int(input("Informe quantidade de parcelas: "))
salario = float(input("Informe o seu salario: "))

if valorEmprestimo / nParcelas <= salario * 0.30:
    print(f"Imprestimo foi aprovado!!")
else:
    print(f"Imprestimo não foi aprovado T.T")