rijec = "Anavolimilovana".lower()

obrnuta_rijec = rijec[::-1]

if rijec == obrnuta_rijec:
    print("String je palindrom!")
else:
    print("String nije palindrom!")
