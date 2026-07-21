import os

def zamijeni_brojeve_ascii_karakterom(lista):
    nova_lista = lista.copy()
    for i in range(len(nova_lista)):
        clan = nova_lista[i]
        if isinstance(clan, int) and not isinstance(clan, bool):
            if 32 <= clan <= 126:
                nova_lista[i] = chr(clan)
            else:
                raise ValueError(f"Broj {clan} nije u opsegu printabilnih ASCII karaktera (32-126)!")
    return nova_lista

def upravljaj_korisnickim_fajlom():
    username = os.getenv('USER_NAME')
    password = os.getenv('USER_PASS')

    if not username or not password:
        raise ValueError("Environment varijable 'USER_NAME' ili 'USER_PASS' nisu postavljene!")
    
    filename = f"{username}.txt"

    if os.path.exists(filename):
        with open(filename, 'r', encoding='utf-8') as f:
            tren_sadrzaj = f.read()

        if tren_sadrzaj == password:
            print(f"Fajl '{filename}' već postoji i lozinka je ista. Ništa se ne mijenja.")
        else:
            with open(filename, 'w', encoding='utf-8') as f:
                f.write(password)
            print(f"Fajl '{filename}' postoji, ali se lozinka razlikovala. Uspješno je promijenjena!")
    else:
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(password)
        print(f"Kreiran je novi fajl '{filename}' sa postavljenom lozinkom!")