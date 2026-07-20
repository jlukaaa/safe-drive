og_rijecnik = {
    "Marko" : "BanjaLuka",
    "Milos" : "Beograd",
    "Marija" : "Zagreb",
    "Nikola" : "Sarajevo"
}

okrenuti = {}

for kljuc, vrijednost in og_rijecnik.items():
    okrenuti[vrijednost] = kljuc

print("Originalni rijecnik: ")
print(og_rijecnik)

print("\nNovi rijecnik: ")
print(okrenuti)
