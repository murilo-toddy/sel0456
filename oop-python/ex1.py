# Polimorfismo

class Classe1:
    def __init__(self, name):
        self.name = name
    def __repr__(self):
        return "Classe1 {}".format(self.name)

class Classe2:
    def __init__(self, name):
        self.name = name
    def __repr__(self):
        return "Classe2 {}".format(self.name)

def Repr(obj):
    print(obj.__repr__())

Repr(a)

Repr(b)
