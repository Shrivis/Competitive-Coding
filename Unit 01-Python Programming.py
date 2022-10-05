https://www.onlinegdb.com/online_python_compiler
https://www.programiz.com/python-programming/online-compiler/
counter = 1000
miles = 1000.0
name = "Krishna"

a = b = c = 5
a,b,c = 7,8,10.5    # Multi value assignment

# Type conversions
# Process of converting one data type to another data type:
# Implicit type conversion:

num_int = 123
num_flo = 1.23
num_new = num_int + num_flo
num_new

type(num_int)
type(num_flo)
type(num_new)

# Explicit type conversion:
# Converting any data type of an element into another data type.

num_int = 123
num_str = "456"
num_str
type(num_str)
num_str = int(num_str)
type(num_str)
num_str

num_sum = num_int + num_str
num_sum
type(num_sum)

# String methods

string1 = "python is is awesome"
string1.upper()

substring = "is"
string1.count(substring)

substring = "python"
string1.count(substring)

text = "let it be let it be let it be"
text.find("let")
text.find("it")
text.find("be")

sen = "Python Programming is full of fun"
sen.index("is full")
sen.index("g is")

name = "Monica"
name.isalpha()
name.isdigit()

string = "THIS SHOULD ALL BE LOWERCASE"
string.swapcase()

song = "cold, cold heart"
song.replace("cold","hot")
song.replace("cold","hot",1)

song = "cold, cold heart"
song.replace("cold","hot")
song.replace("cold","hot",0)

song = "cold, cold heart, cold heart"
song.replace("cold","hot")
song.replace("cold","hot",2)

song = "cold, cold heart, cold heart, cold heart"
song.replace("cold","hot")
song.replace("cold","hot",0)

song = "light, light heart cold siva venkat ranga cold hello cold"
print(song)

song2=song.replace("cold","hot",1)
print(song2)

song3=song.replace("cold","hot",2)
print(song3)

grocery = "Milk, Butter, Jam, Bread"
grocery.split()

grocery = "Milk, Butter, Jam, Bread"
grocery.split(",",1)

grocery = "Milk, Butter, Jam, Bread"
grocery.split(",",2)

grocery = "Milk, Butter, Jam, Bread"
grocery.split(",",3)

grocery = "Milk, Butter, Jam, Bread"
grocery.split(",",4)

# Simple output 

print("This Sentence is Output to the Screen")

a = 5

print(a)

print(1,2,3,4)
print(1,2,3,4, sep='*')
print(1,2,3,4, sep='*', end='%')

# Output formatting with “format” 

print("I love {0} and {1}".format("bread", "butter"))
print("I love {1} and {0}".format("bread", "butter"))

x = 12.3456789
print("The value of x is %3.2f" %x)
print("The value of x is %3.4f" %x)
print("The value of x is %3.6f" %x)

# Simple input: Input function

#Reading input without a prompt
num = input()
num

#Reading input with a prompt
num = input('Enter a number: ')

# Type casting 
num = int(num)
num
num

# Mutable vs immutable objects 

# Lists: Create and access
# List of floats

num_list = [11.22, 33.44, 55.66, 77.88]
num_list

mix_list = [11.22, 22.33, 1, 2, "Python Beginner", 100, 'Hello']
mix_list

# Empty list
nodata_list = []
nodata_list

# List creation
# List of numbers
numbers = [11, 22, 33, 44, 55, 66]

print(numbers[0])
print(numbers[1])
print(numbers[2])
print(numbers[3])

my_list = ['hello', 'world', 'hi', 'bye']

print(my_list[1])
print(my_list[-1])
print(my_list[-3])

# Lists: Modify and slice
nlist = [1, 2, 3, 4, 5, 6, 7, 8, 9]
nlist[0:3]
nlist[:2]
nlist[3:]
nlist[:]

thislist = ["apple", "banana", "cherry"]
thislist
thislist[1] = "blackberry"
thislist

# Sets: Create and operations
thisset = {"apple", "banana", "cherry"}
thisset.add("orange")
thisset
thisset.update(["orange","mango","grapes"])
thisset

#  Deletion using del, remove, pop, clear methods
thisset.remove("grapes")
thisset
thisset.discard("mango")
thisset
thisset.pop()
thisset

thisset.clear()
thisset

del thisset

# Sets: Operators and methods
A = {1,2,3,4,5}
B = {4,5,6,7,8}
print(A | B)
print(A & B)
A.union(B)
B.intersection(A)

(A - B)
(B - A)
A.symmetric_difference(B)

# Tuples: Create and access
# Tuples are used to store multiple items in a single variable.

# Tuple is one of 4 built-in data types in Python used to store collections of data, 
# the other 3 are List, Set, and Dictionary, all with different qualities and usage.

# A tuple is a collection which is ordered and unchangeable.

#Tuples are written with round brackets.

thistuple = ("apple", "banana", "cherry")
print(thistuple)

# tuple allows duplicates

thistuple = ("apple", "banana", "cherry", "apple", "cherry")
print(thistuple)

my_tuple = ('p','e','r','m','i','t')
my_tuple[0]

my_tuple[5]
my_tuple[0:4]
my_tuple[0:5]
my_tuple[0:6]

thistuple = ("apple", "banana", "cherry")
print(len(thistuple))

# One item tuple, remember the comma

thistuple = ("apple",)
print(type(thistuple))

#NOT a tuple
thistuple = ("apple")
print(type(thistuple))

tuple1 = ("apple", "banana", "cherry")
tuple2 = (1, 5, 7, 9, 3)
tuple3 = (True, False, False)


# Dictionaries: Create and access

# Dictionaries are used to store data values in key:value pairs.
# A dictionary is a collection which is ordered*, changeable and do not allow duplicates.
# Dictionaries are written with curly brackets, and have keys and values

thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
thisdict

print(thisdict["brand"])

# Duplicate values will overwrite existing values

thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964,
  "year": 2020
}
print(thisdict)

print(len(thisdict))

# The values in dictionary items can be of any data type

thisdict = {
  "brand": "Ford",
  "electric": False,
  "year": 2021,
  "colors": ["red", "white", "blue"]
}

thisdict
print(type(thisdict))

# Copying collections: Shallow
xs = [[1,2,3],[4,5,6],[7,8,9]]
xs
ys = list(xs)
ys

xs.append([10,11,12])
xs


