cont = 0
for i in range(6):
    if input(f"Na {i + 1}ª partida venceu (V) ou perdeu (P): ") == 'V':
        cont +=1

if cont > 4:
    print("3")
elif cont > 2:
    print("2")
elif cont > 0:
    print("1")
else:
    print("0")