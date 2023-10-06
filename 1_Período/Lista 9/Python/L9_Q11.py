n =  float(input("Informe N: "))
i, j = 0, 0
while j < n:
    if i % 2 != 0:
        print(i, end = " ")
        j+=1
    
    i+=1

print()

i, j = 1, 0

while j < n:
    print(i, end=' ')
    i +=2
    j+=1