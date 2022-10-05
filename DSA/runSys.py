import os
from subprocess import Popen

# Creating a new Directory and changing current dir to that
path = '/home/light/Personal/Code/temp'
os.chdir(path)
os.makedirs('newFolder', exist_ok=True)
os.chdir('./newFolder')

# Creating a cpp file
cProgram = '''
#include <iostream>
using namespace std;
int main() {
    cout<<"Runnig a C++ program using Ptyhon"<<endl;
    cout<<"Hello World"<<endl;
    return 0;
}
'''

with open('hello.cpp', 'w') as f:
    f.write(cProgram)

print(os.getcwd())
Popen(['g++', 'hello.cpp', '-o', 'hello'])
Popen(['./hello'])