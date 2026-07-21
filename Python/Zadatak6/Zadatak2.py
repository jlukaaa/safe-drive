from abc import ABC, abstractmethod

class Razlomak:
    def __init__(self, brojilac, imenilac):
        if imenilac == 0:
            raise TypeError("Imenilac ne smije biti nula!")
        
        self.brojilac = brojilac
        self.imenilac = imenilac

    def __str__(self):
        return f"{self.brojilac} / {self.imenilac}"
    
    def __mul__(self, drugi):
        
        if isinstance(drugi, Razlomak):

            novi_brojilac = self.brojilac * drugi.brojilac
            novi_imenilac = self.imenilac * drugi.imenilac
            return Razlomak(novi_brojilac, novi_imenilac)
        
        elif isinstance(drugi, int):

            return Razlomak(self.brojilac * drugi, self.imenilac)
        
    
    def __add__(self, drugi):

        if isinstance(drugi, Razlomak):

            novi_brojilac = (self.brojilac * drugi.imenilac) + (drugi.brojilac * self.imenilac)
            novi_imenilac = self.imenilac * drugi.imenilac
            return Razlomak(novi_brojilac, novi_imenilac)
        
        elif isinstance(drugi, int):

            novi_brojilac = self.brojilac + (drugi * self.imenilac)
            return Razlomak(novi_brojilac, self.imenilac)
        
    
if __name__ == '__main__':

    r1 = Razlomak(10, 2)
    r2 = Razlomak(3, 4)

    print("Razlomak r1: ", r1)
    print("Razlomak r2: ", r2)

    mnozenje = r1 * r2
    print(f"\nMnozenje: {r1} * {r2} = {mnozenje}")

    sabiranje = r1 + r2
    print(f"\Sabiranje: {r1} + {r2} = {sabiranje}")

