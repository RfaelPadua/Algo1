idade = int(input("Informe a idade: "))

print()

if idade < 16:
    print(f"Não pode vota.")
elif idade < 18 or idade >= 64:
    print(f"Facultativo")
else:
    print(f"Obrigatório")

print()