import abc
from math import sqrt, tan, pi

class Shapes(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def perimeter(self):
        pass
    @abc.abstractmethod
    def area(self):
        pass

class Square(Shapes):
    def __init__(self, side):
        self.a = side
    def perimeter(self):
        return self.a*4
    def area(self):
        return self.a**2

class Rectangle(Shapes):
    def __init__(self, lenth,width):
        self.l = lenth
        self.b = width
    def perimeter(self):
        return 2*(self.l+self.b)
    def area(self):
        return self.l*self.b

class Triangle(Shapes):
    def __init__(self, x, y, z):
        self.a = x
        self.b = y
        self.c = z
    def perimeter(self):
        return self.a+self.b+self.c
    def area(self):
        s = (self.a + self.b + self.c)/2  
        return sqrt(s*(s-self.a)*(s-self.b)*(s-self.c))

class Pantagon(Shapes):
    def __init__(self, side):
        self.a = side
    def perimeter(self):
        return f'{self.a*5:.2f}'
    def area(self):
        return (5/2)*(self.a)*(self.a/(2*tan(pi/5)))


if __name__=="__main__":
    p = Pantagon(13);
    print ('Perimete: ',p.perimeter())
    print ('Area: ',p.area())