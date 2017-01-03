# cyclical-figurate-numbers 
Finds the sum of cyclic, polygonal ("figurate") numbers.

### Definitions
#### Cyclic Sets
A set of numbers is cyclic if the last digits of one of the numbers determine the first digits of the next number.  
Ex. `1234, 3456, 5612` is cyclic.  
Ex. `1029, 2938, 3847, 4756, 5665, 6510` is cyclic.  

#### Polygonal Numbers
A number is polygonal if it is triangular, square, pentagonal, hexagonal, heptagonal, or octagonal.
##### Triangular Numbers
The *n*<sup>th</sup> term of a sequence of triangle numbers is given by `n * (n + 1) / 2`  

So, the first ten triangular numbers are `1, 3, 6, 10, 15, 21, 28, 36, 45, 55`

##### Square Numbers
The *n*<sup>th</sup> term of a sequence of square numbers is given by `n * n`  

So, the first ten square numbers are `1, 4, 9, 16, 25, 36, 49, 64, 81, 100`

##### Pentagonal Numbers
The *n*<sup>th</sup> term of a sequence of pentagon numbers is given by `n * (3*n - 1) / 2`  

So, the first ten pentagonal numbers are `1, 5, 12, 22, 35, 51, 70, 92, 117, 145`

##### Hexagonal Numbers
The *n*<sup>th</sup> term of a sequence of hexagon numbers is given by `n * (2*n - 1)`  

So, the first ten hexagonal numbers are `1, 6, 15, 28, 45, 66, 91, 120, 153, 190`

##### Heptagonal Numbers
The *n*<sup>th</sup> term of a sequence of heptagon numbers is given by `n * (5*n - 3) / 2`  

So, the first ten heptagonal numbers are `1, 7, 18, 34, 55, 81, 112, 148, 189, 235`

##### Octagonal Numbers
The *n*<sup>th</sup> term of a sequence of octagon numbers is given by `n * (3*n - 2)`  

So, the first ten octagonal numbers are `1, 8, 21, 40, 65, 96, 133, 176, 225, 280`

### Problem Statement
Find the sum of the only set of six cyclic 4-digit numbers, where each number in the set is a different polygonal type from above.

That is, where one of the numbers of the cyclic set is triangular, another is square, another is pentagonal, another is hexagonal, another is heptagonal, and the last is octagonal, in any order.

### Motivation
This project was completed for [Project Euler - Problem 61](https://projecteuler.net/problem=61).

I recommend that this code should only be viewed _after_ you've completed your own implementation.  
If you're super stuck, take a break, take a walk, and it will come to you; good luck.
