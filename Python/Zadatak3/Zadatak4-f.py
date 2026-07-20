def razdvoji_rjecnik(rjecnik):

    skup_kljuceva = set(rjecnik.keys())

    lista_vrijednosti = list(rjecnik.values())

    return skup_kljuceva, lista_vrijednosti

rijecnik = {
    "proizvod" : "laptop",
    "cijena" : 1200,
    "brend" : "HP",
    "dostupno" : True
}

kljucevi, vrijednosti = razdvoji_rjecnik(rijecnik)
print("Pocetni rijecnik: ", rijecnik)
print("Skup kljuceva: ", kljucevi)
print("Lista vrijednosti: ", vrijednosti)
