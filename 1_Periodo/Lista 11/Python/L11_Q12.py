vetor = []
i, j = 0, 0
while i <= 100:
    if j % 7 == 0:
        j+=1
        continue
    vetor.append(j)
    i+=1
    j+=1

print(vetor)