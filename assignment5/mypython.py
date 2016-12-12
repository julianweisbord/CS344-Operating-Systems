#!/usr/bin/env python2.7
import string
import random

def main():
    alpha = string.letters.lower()

    #Open the files
    file1 = open('file1.txt', 'w+')
    file2 = open('file2.txt', 'w+')
    file3 = open('file3.txt', 'w+')

    #Enter random string for files the 3 files and print it
    for i in range(0, 10):
        rand = random.choice(alpha)
        file1.write(rand)
    file1.write('\n')
    file1 = open('file1.txt', 'r+')
    print "file1: ", file1.read(10)

    for i in range(0, 10):
        rand = random.choice(alpha)
        file2.write(rand)
    file2.write('\n')
    file2 = open('file2.txt', 'r+')
    print "file2: ", file2.read(10)

    for i in range(0, 10):
        rand = random.choice(alpha)
        file3.write(rand)
    file3.write('\n')
    file3 = open('file3.txt', 'r+')
    print "file3: ", file3.read(10)

    #When executed, after the file contents of all three files have been printed,
    #print out two random integers (whose range is from 1 to 42, inclusive),
    #and print out the product of the two numbers.

    product1 = random.randint(1,42)
    product2 = random.randint(1,42)
    print "Random Numbers: ", product1," ", product2
    print product1 * product2

    file1.close()
    file2.close()
    file3.close()
    # with open(filename, 'a') as out:
    # out.write(var + '\n')
if __name__ == '__main__':
    main()
