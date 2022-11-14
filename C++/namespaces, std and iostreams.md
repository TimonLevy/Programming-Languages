# NAMESPACES, STL & IOSTREAMS: WHAT ARE THEY?

### Namespaces
In **C++** it is possible to have multiple *variables*, *functions* and *type names* that use the same name but have different meaning to al of them, how is that possible? It's actually very simple, the variable's value is relative to a namespace.
A namespace is a declared region in the code that contains and localizes variables, functions and etc. They are used to logically separate groups of variables and other data so to avoid name collision/overriding.

A namespace is declared like this:

		namespace NAME_OF_NAMESPACE
		{
			class NAME_OF_CLASS
			{
			public: 
				void Func1() {} 
			};
			void Func2(NAME_OF_CLASS) {}
		}
		
Data inside the namespace may be accessed in the global namespace using a **Fully Qualified Name**:

	NAME_OF_NAMESPACE::NAME_OF_CLASS classObj;
	classObj.Func1();
	NAME_OF_NAMESPACE::Func2(classObj);
	
or you may use specific data from the namespace using the **using** directive:

	using NAME_OF_NAMESPACE::NAME_OF_CLASS;
	NAME_OF_CLASS classObj;
	classObj.Func1();

### The C++ Standard Library
The C++ standard library contains a bunch of classes, data structures and function (written in c++) that extend the usability and functionality of the language. It is also a product of many standardization procedures. The standard library is used a lot simply because it contains most basic and common data structure functions and classes like: time calculations, arrays, error handling and strings.

For references on the contents of the library you may refer [here](https://en.cppreference.com/w/cpp/header).

(not that io-streams)
### IO-Streams
iostreams are the input and output streams that your machine uses (io = input output), a stream is a sequence of characters read from or written to an IO device (like a keyboard or screen). By default C++ doesn't provide any io operations, instead you must use the **iostream** library included in the standard library.

The library is contains different types of streams:
* **istream** - An **input** stream, this stream gets input from an IO device like a keyboard, mouse, Joystick, Scanner or a camera.
* **ostream** - An  **output** stream, this stream is used to end output to an IO device like a screen or a printer. 

However there are other io stream in C++ language like the **fstream**, This stream is used for **operating on files**, it can read and write to files. Other streams like *ofstream* and *ifstream* exist to fulfill a single purpose.
