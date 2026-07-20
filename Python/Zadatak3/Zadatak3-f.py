def okreni_rjecnik(rjecnik):

    novi_rjecnik = {}

    for kljuc, vrijednost in rjecnik.items():
        novi_rjecnik[vrijednost] = kljuc

    return novi_rjecnik

og_rijecnik = {
    "Marko" : "BanjaLuka",
    "Milos" : "Beograd",
    "Marija" : "Zagreb",
    "Nikola" : "Sarajevo"
}

okrenuti = okreni_rjecnik(og_rijecnik)

print("Originalni rijecnik: ")
print(og_rijecnik)

print("\nNovi rijecnik: ")
print(okrenuti)
