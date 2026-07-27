from abc import ABC, abstractmethod
import os

class IotUredjaj:

    def __init__(self, sn: str, id_na_claudu : str):
        self.sn = sn
        self.id_na_cloudu = id_na_claudu

    def __str__(self):
        return f"{self.sn} , {self.id_na_cloudu}"
    

    @classmethod
    def iz_stringa(cls, tekst):
        dio = tekst.split(",")
        sn = dio[0].strip()
        id_na_claudu = dio[1].split()
        return cls(sn, id_na_claudu)
    
    @staticmethod
    def validiraj_sn(sn):
        return isinstance(sn, str) and sn.startswith("SN-")
    
    
    def upisi(uredjaj):
        fajl_putanja = os.getenv("IOT_FILE_PATH")

        if not fajl_putanja:
            raise ValueError("Varijabla nije postavljena!")
        
        with open(fajl_putanja, "a", encoding="utf-8") as f:
            f.write(str(uredjaj) + "\n")

        print(f"Uredjaj {uredjaj.sn} uspjesno upisan u fajl: {fajl_putanja}")

        
        
if __name__ == '__main__':

    os.environ["IOT_FILE_PATH"] = "uredjaji.txt"

    sn_test = "SN-12345"
    

    if IotUredjaj.validiraj_sn(sn_test):
        print(f"Serijski broj {sn_test} je validan!")

    u1 = IotUredjaj("SN-12345", "cloude-id-001")

    print("Ispis u1: ", u1)

    u2 = IotUredjaj.iz_stringa("SN-67689 , cloude-id-002")
    print("Ispis u2: ", u2)

    try:
        u1.upisi()
        u2.upisi()

    except ValueError as e:
        print(f"Greska je : {e}")



