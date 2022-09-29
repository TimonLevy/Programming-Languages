# Sfot Tichnut
## __Answers__

""" Those are not legitment answears """

##### 1.
```
The best animal in the world is Falemingo!

1. It's unique leg shape allows it to do a sick kickflip on a skate.
2. The Flamingo does not drink a Shnitzel.
3. The Flamingo does not dine at Mickie Deez (nuts). 
```

##### 4.
```
A loop in prgramming language is a block of code which repeats itself until\as long as a given statement becomes\is true.
Loops are used to process information using the same code multiple times or to count objects.

A recusion in programming language is the calling of a function from whithin itself, to perform the same operation on a set of information.
The difference between them comes from the way they are both manifested:

1.
In a loop the memory structures that are used to affect the processed information remain in the same variable space. We do not call another function and we stay inside the loop.
In a recursive loop the machine creates new memory structures for each function that is being called (Constants, Parameters and such) and thosre are just being returned.
This means that recursive functions can put a heavy strain on the memory of the computer if not used correctly.

2.
Recursive functions are very complicated in their nature, and may be hard to understand or even contruct. However the complexity comes from the flexibility which the functions presume.
Loops retains a form of simplicity in their execution but they also can suffer from over-complexity.

3.
Recursive functions are slower than loops in execution.

Due tot he memory strains and the complexity it is extremely important to make sure our exit statement is 100% correct, otherwise we would end up with an infinite loop that could exhaust
the prgrams memory.
```

##### 8.
```
.pyc files are the intermediate code files that the python interperter compiles.
The python Interperter works like this:

	                            Source Code
	                                ||
	                                \/
	+-------------------------------------------------------------------+
	|                           [Interperter]                           |
	|    +----------+    +-----------------+    +-----------------+     |
	|    | Compiler | -> | Byte Code (pyc) | -> | Virtual Machine |     |
	|    +----------+    +-----------------+    +-----------------+     |
	+-------------------------------------------------------------------+
	                                ||
	                                \/
	                             Execution
								
After running the code ther interperter runs the source code through a compiler which translate our source Python code
into a bytcode which is machine independant (universal), efficeint and intermidiary that is then used to run using a virtual machine inside the interperter.

The pyc format is exactly that, the intermidiate version of the code. It can be uncomplied and compiled by hand.
```
