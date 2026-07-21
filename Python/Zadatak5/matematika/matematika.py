import math

def fabrika_povrsina(oblik):
    def izracunaj(*args):
        if oblik == "kvadrat":
            return args[0] ** 2
        elif oblik == "pravougaonik":
            return args[0] * args[1]
        elif oblik == "krug":
            return (args[0] ** 2) * math.pi
        else:
            raise ValueError(f"Nepoznat oblik: {oblik}")
    return izracunaj