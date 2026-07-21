def ukloni_duplikate(lista):
    return list(dict.fromkeys(lista))

def podijeli_skup(pocetni_skup):
    skup_brojeva = set()
    skup_ostalih = set()
    for clan in pocetni_skup:
        if isinstance(clan, (int, float)) and not isinstance(clan, bool):
            skup_brojeva.add(clan)
        else:
            skup_ostalih.add(clan)
    return skup_brojeva, skup_ostalih

def okreni_rjecnik(rjecnik):
    return {vrijednost: kljuc for kljuc, vrijednost in rjecnik.items()}

def razdvoji_rjecnik(rjecnik):
    return set(rjecnik.keys()), list(rjecnik.values())

def je_palindrom(tekst):
    cist_tekst = tekst.lower().replace(" ", "")
    return cist_tekst == cist_tekst[::-1]

def string_u_ascii_niz(tekst):
    return [ord(karakter) for karakter in tekst]

def podijeli_string(tekst, znak):
    return [rijec.strip() for rijec in tekst.split(znak)]

def brojevi_zbir_cifara_djeljiv_sa_5():
    return [x for x in range(1, 101) if sum(int(cifra) for cifra in str(x)) % 5 == 0]

def dodaj_pdv_na_cijene(rjecnik_cijena, pdv_stopa=0.17):
    koeficijent = 1 + pdv_stopa
    return {proizvod: round(cijena * koeficijent, 2) for proizvod, cijena in rjecnik_cijena.items()}