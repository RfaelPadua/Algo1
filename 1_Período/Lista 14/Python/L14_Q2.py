palavra = input("Informe um palavra: ")

for i in range(len(palavra)):
    if i % 2 != 0:
        print(palavra[i], end = "")