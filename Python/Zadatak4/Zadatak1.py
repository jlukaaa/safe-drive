import os
os.environ['USER_NAME'] = 'marko_kraljevic'
os.environ['USER_PASS'] = 'MojaSigurnaLozinka123'

def upravljaj_fajlom():

    username = os.getenv('USER_NAME')
    password = os.getenv('USER_PASS')

    if not username or not password:
        print("Greska. Varijable nisu postavljene!")
        return
    
    filename = f"{username}.txt"

    if os.path.exists(filename):
        with open(filename, 'r', encoding='utf-8') as f:
            tren_sadrzaj = f.read()

        if tren_sadrzaj == password:
            print("Fajl vec postoji i lozinka je ista. Nista se ne mijenja")
        else:
            with open (filename, 'w', encoding='utf-8') as f:
                f.write(password)
            print("Fajl postoji ali se lozinka razlikuje. Uspjesno je promjenjena!")

    else:

        with open (filename, 'w', encoding='utf-8') as f:
            f.write(password)
        print("Kreiran je novi fajl sa postavljenom lozinkom!")


if __name__ == '__main__':
    upravljaj_fajlom()
