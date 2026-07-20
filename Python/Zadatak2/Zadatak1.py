niz = [65, "tekst", 97, 400, 72, -5, True]
print("Originalni niz: ", niz)
for i in range(len(niz)):
    clan = niz[i]

    if isinstance(clan, int) and not isinstance(clan, bool):
        if 0 <= clan <= 255:
            niz[i] = chr(clan)
      

print("Novi niz:")
print(niz)



