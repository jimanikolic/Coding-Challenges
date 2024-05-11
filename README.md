Coding Challenges:

Challenge #1 - moveCapitals -Create a function that moves all capital letters to the front of a word.
Runtime - O(n^2), where n is the length of the string;
Solution - Simple bubble sort acting on ascii values

Challenge #2 - missingOhmsLaw - Create a function that calculates the missing value of 3 
inputs using Ohm’s law. The inputs are v, r or i (aka: voltage, resistance and current).
Runtime - O(1), constant
Solution - use getline to store three tokens, use istringsteam to convert tokens to doubles.
Empty strings are stored as 0.

Challenge #3 - dynamicArray - Write a program that dynamically allocates 
memory for an array of integers, prompts the user to input the 
elements of the array, reverses the array in-place using pointers, 
and then deallocates the memory. Ensure that the program handles 
memory allocation failure gracefully.
Runtime - O(1), constant

Challenge #4 - fizzBuzz- Write a program that prints the numbers from 1 to 100, 
but for multiples of three print “Fizz” instead of the number 
and for multiples of five print “Buzz”. 
Runtime - O(1), constant

Challenge #5 - fibonacci - Write a function that takes an integer n 
as input and returns the nth Fibonacci number. The 
Fibonacci sequence is defined as follows: the first 
two numbers in the sequence are 0 and 1, and each 
subsequent number is the sum of the two preceding ones.
So the sequence goes: 0, 1, 1, 2, 3, 5, 8, 13, 21, and so on.
Runtime - O(2^n), exponential

Challenge #6 - dnaReplication - Write a program to model dna replication. Output the conservative, 
semiconservative, and dispersive models. Then recreate the Meselson-Stahl experiment
with lowercase nucleotides representing light isotopes and uppercase representing heavy isotopes.
Runtime - O(1), constant

Challenge #7 -Write a function that adds two numbers and determines wether or not they can overflow, 
runtime O(1)

Challenge #8 - Write a examines two JSON files from instagram to determine who you are following 
that does not follow you back and vice-versa.
Runtime O(1) constant. Two implementation, python and cpp. Python uses downloaded data from instagram, cpp
uses downloaded data from chrome extensions. I have a scraper made in python but my bot accounts and seemingly my ip
was banned so I can not use it anymore.
