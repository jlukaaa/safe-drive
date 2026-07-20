import math

def povrsina(oblik):

    def izracunaj(*args):
        if oblik == "kvadrat":
            a = args[0]
            return a * a
        
        elif oblik == "pravougaonik":
            a,b = args[0], args[1]
            return a * b
        
        elif oblik == "krug":
            r = args[0]
            return (r ** 2) * math.pi
        
        else:
            return "Nepoznat oblik!"
        
    return izracunaj

povrsina_kvadrata = povrsina("kvadrat")
povrsina_pravougaonika = povrsina("pravougaonik")
povrsina_kruga = povrsina("krug")   

print("Površina kvadrata stranice 4 je:", povrsina_kvadrata(4))
print("Površina pravougaonika stranica 3 i 5 je:", povrsina_pravougaonika(3, 5))
print("Površina kruga poluprečnika 3 je:", round(povrsina_kruga(3), 2))