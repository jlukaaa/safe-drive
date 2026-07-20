skup = {1,2,3, "jabuka", True, (1,2), 42, "RT-RK", False}

skup_brojeva = set()
skup_ostalih = set()

for clan in skup:

    if isinstance(clan, (int, float)) and not isinstance(clan, bool):
        skup_brojeva.add(clan)
    else:
        skup_ostalih.add(clan)

print("Pocetni skup je:", skup)
print("Skup sa brojevima je: ", skup_brojeva)
print("Skup ostalih je: ", skup_ostalih)

