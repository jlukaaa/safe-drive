from abc import ABC, abstractmethod

class Adder(ABC):

    @abstractmethod
    def add(self, x, y):
        pass


class ListAdder(Adder):

    def add(self, x, y):

        return x + y
    
class DictAdder(Adder):

    def add(self, x, y):

        return x | y
    

if __name__ == '__main__':
    
    lista_adder = ListAdder()
    l1 = [1, 2, 3]
    l2 = [4, 5, 6]
    
    rez = lista_adder.add(l1, l2)
    print ("Spojene liste: ", rez)

    dict_adder = DictAdder()
    d1 = {"a" : 1, "b" : 2}
    d2 = {"c" : 3, "d" : 4}

    rez_dict = dict_adder.add(d1, d2)
    print("Spojeni rjecnici: ", rez_dict)