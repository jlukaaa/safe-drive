def podijeli_skup(pocetni_skup):
    skup_brojeva = set()
    skup_ostalih = set()

    for clan in pocetni_skup:

        if isinstance(clan, (int, float)) and not isinstance(clan, bool):
            skup_brojeva.add(clan)
        else:
            skup_ostalih.add(clan)

    return skup_brojeva, skup_ostalih   
    
skup = {1,2,3, "jabuka", True, (1,2), 42, "RT-RK", False}

brojevi, ostalo = podijeli_skup(skup)
print("Pocetni skup je:", skup)
print("Skup sa brojevima je: ", brojevi)
print("Skup ostalih je: ", ostalo)

