premio = float(780000)

ganhador1 = premio * 0.46
ganhador2 = premio * 0.32
ganhador3 = premio - ganhador2 - ganhador1

ganhador1 = f'R${ganhador1:_.2f}'
ganhador1 = ganhador1.replace('.',',').replace('_','.')

print(f"Primeiro ganhador: {ganhador1}")

ganhador2 = f'R${ganhador2:_.2f}'
ganhador2 = ganhador2.replace('.',',').replace('_','.')

print(f"Segundo ganhador: {ganhador2}")

ganhador3 = f'R${ganhador3:_.2f}'
ganhador3 = ganhador3.replace('.',',').replace('_','.')

print(f"Terceiro ganhador: {ganhador3}")