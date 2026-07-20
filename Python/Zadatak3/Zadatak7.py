stare_cijene = {
    "mlijeko" : 1.50,
    "hleb" : 1.10,
    "kafa" : 4.50,
    "cokolada" : 2.20
}

nove_cijene_pdv = {proizvod: round(cijena * 1.17, 2) for proizvod, cijena in stare_cijene.items()}
print("Cijene bez PDV-a:")
print(stare_cijene)

print("\nNove cijene sa uračunatim PDV-om (17%):")
print(nove_cijene_pdv)