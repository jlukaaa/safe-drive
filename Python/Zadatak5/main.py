import os

from strukture.obrada_podataka import (
    ukloni_duplikate, 
    podijeli_skup, 
    okreni_rjecnik, 
    razdvoji_rjecnik, 
    je_palindrom, 
    string_u_ascii_niz, 
    podijeli_string,
    brojevi_zbir_cifara_djeljiv_sa_5,
    dodaj_pdv_na_cijene
)
from matematika.matematika import fabrika_povrsina
from sistem.sistem import (
    zamijeni_brojeve_ascii_karakterom, 
    upravljaj_korisnickim_fajlom
)

if __name__ == '__main__':
    print("=== TESTIRANJE PAKETA 'strukture' ===")
    print("1. Bez duplikata:", ukloni_duplikate([1, 2, 2, 3]))
    print("2. Podjela skupa:", podijeli_skup({1, "a", True, 2.5}))
    print("3. Okrenut rječnik:", okreni_rjecnik({"a": 1, "b": 2}))
    print("4. Razdvojen rječnik:", razdvoji_rjecnik({"a": 1, "b": 2}))
    print("5. Je palindrom 'Kajak':", je_palindrom("Kajak"))
    print("6. String u ASCII niz:", string_u_ascii_niz("Python"))
    print("7. Podijeljen string:", podijeli_string("a,b,c", ","))
    print("8. Brojevi djeljivi sa 5 (zbir cifara):", brojevi_zbir_cifara_djeljiv_sa_5())
    print("9. Cijene sa PDV-om:", dodaj_pdv_na_cijene({"hleb": 1.0, "kafa": 4.0}))

    print("\n=== TESTIRANJE PAKETA 'matematika' ===")
    povrsina_kruga = fabrika_povrsina("krug")
    print("Površina kruga (r=3):", round(povrsina_kruga(3), 2))

    print("\n=== TESTIRANJE PAKETA 'sistem' ===")
    try:
        print("ASCII zamjena (ispravno):", zamijeni_brojeve_ascii_karakterom([65, 97]))
 
    except ValueError as e:
        print("Uhvaćena greška:", e)

    os.environ['USER_NAME'] = 'marko_kraljevic'
    os.environ['USER_PASS'] = 'MojaSigurnaLozinka123'
    try:
        upravljaj_korisnickim_fajlom()
    except ValueError as e:
        print("Uhvaćena greška pri radu sa fajlom:", e)