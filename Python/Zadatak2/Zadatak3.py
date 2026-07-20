tekst = "Pajton"

niz_ascii = []

for karakter in tekst:
    ascii_vrijednosti = ord(karakter)

    niz_ascii.append(ascii_vrijednosti)


print("Originalan string:", tekst)
print("Niz ASCII vrijednosti", niz_ascii)