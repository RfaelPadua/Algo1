idade = int(input("Informe a sua idade: "))

if idade < 16:
    print(f"Não pode nem votar e nem dirigir.")
elif idade < 18:
    print(f"Pode votar, mas não pode dirigir.")
else:
    print(f"Pode votar e dirigir.")