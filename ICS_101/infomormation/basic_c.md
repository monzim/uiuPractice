<!-- Basic Infomation and thing about C -->

# Basic Infomation and thing about C

## What is C?

C is a general-purpose, imperative computer programming language, supporting structured programming, lexical variable scope and recursion, while a static type system prevents many unintended operations. By design, C provides constructs that map efficiently to typical machine instructions. It has found lasting use in applications previously coded in assembly language. Such applications include operating systems and various application software for computer architectures that range from supercomputers to PLCs and embedded systems.

## What is C used for?

C is a general-purpose programming language that is widely used to develop operating systems, compilers, database management systems, and so on. It is a middle-level language as it comprises a low-level language and a high-level language. The language was developed at Bell Labs between 1969 and 1973 by Dennis Ritchie. The main features of C language include low-level access to memory, a simple set of keywords, and clean style, these features make C language suitable for system programming like an operating system or compiler development.

## C is a procedural programming language

## How to write a C program?

### 1. Write a C program

```c
#include <stdio.h>

int main()
{
		printf("Hello, World!");
		return 0;
}
```

### 2. Compile the C program

```bash
gcc -o hello hello.c
```

### 3. Run the C program

```bash

./hello
```

## What is a C compiler?

A C compiler is a computer program that transforms C code into machine code. A compiler is a computer program that translates source code written in a programming language into another computer language. The most common reason for converting source code is to create an executable program. The name "compiler" is primarily used for programs that translate source code from a high-level programming language to a lower level language (e.g., assembly language, object code, executable code, etc.). The name "compiler" is also used for programs that translate source code from a low-level programming language to a higher level language (e.g., a compiler for a virtual machine).

Example: gcc, clang, tcc, icc, etc.

## What is a C interpreter?

An interpreter is a computer program that directly executes, i.e. performs, instructions written in a programming or scripting language, without previously compiling a program into machine-language instructions. The interpreter executes the program directly, translating each statement into a sequence of one or more subroutines already compiled into machine code. The interpreter executes the program directly, translating each statement into a sequence of one or more subroutines already compiled into machine code.

Example: Python, Ruby, Perl, PHP, JavaScript, etc.

## What is a C preprocessor?

The C preprocessor is a program that is run before the compilation of a C program. It is a tool that is used to expand macros within source code, to include code from other files, and to perform other simple source code transformations. The C preprocessor is invoked by the compiler driver program (e.g., gcc) with the -E option. The preprocessor is invoked before the compiler proper, and its output is then fed into the compiler. The preprocessor is invoked before the compiler proper, and its output is then fed into the compiler.

Example:

```c
#include <stdio.h>

#define PI 3.14159

int main()
{
		printf("The value of PI is %f", PI);
		return 0;
}
```

## What is a C header file?

A header file is a file that contains C function declarations and macro definitions to be shared between several source files. When a C source file #includes a header file, the preprocessor inserts the contents of the header file into the source file at that point. The header file is processed by the preprocessor, and the result is then inserted into the source file. The header file is processed by the preprocessor, and the result is then inserted into the source file.

Example:

```c
#include <stdio.h>
```

## What is a C library?

A library is a collection of functions and data structures that can be used by a C program. A library is a collection of functions and data structures that can be used by a C program. A library is a collection of functions and data structures that can be used by a C program. A library is a collection of functions and data structures that can be used by a C program.

Example:

```c
#include <stdio.h>

int main()
{
		printf("Hello, World!");
		return 0;
}
```

## What is a C function?

A function is a group of statements that together perform a task. Functions help break our program into smaller and modular chunks. As our program grows larger and larger, functions make it more organized and manageable. Furthermore, it avoids repetition and makes the program reusable.

Example:

```c
#include <stdio.h>

/* function declaration */
int max(int num1, int num2);

int main ()
{
		/* local variable definition */
		int a = 100;
		int b = 200;
		int ret;

		/* calling a function to get max value */
		ret = max(a, b);

		printf( "Max value is : %d\n", ret );

		return 0;
}

```

## What is a C variable?

A variable is a name given to a storage area that our programs can manipulate. Each variable in C has a specific type, which determines the size and layout of the variable's memory; the range of values that can be stored within that memory; and the set of operations that can be applied to the variable. The variable name is the symbolic representation of the memory location that contains the value. The variable name is the symbolic representation of the memory location that contains the value. The variable name is the symbolic representation of the memory location that contains the value. The variable name is the symbolic representation of the memory location that contains the value.

Example:

```c
int a, b;
float f;
char c;
double d;
long l;
```

## What is a C array?

An array is a collection of items stored at contiguous memory locations. The idea is to store multiple items of the same type together. This makes it easier to calculate the position of each element by simply adding an offset to a base value, i.e., the memory location of the first element of the array (generally denoted by the name of the array). The base value is index 0 and the difference between the two indexes is the offset. The base value is index 0 and the difference between the two indexes is the offset. The base value is index 0 and the difference between the two indexes is the offset. The base value is index 0 and the difference between the two indexes is the offset.

Example:

```c
int arr[10]; // Declares an array of 10 integers
```

## What is a C pointer?

A pointer is a variable whose value is the address of another variable, i.e., direct address of the memory location. Like any variable or constant, you must declare a pointer before using it to store any variable address. The general form of a pointer variable declaration is: type _var-name; where type is the pointer's base type; it must be a valid C data type and var-name is the name of the pointer variable. The asterisk _ used to declare a pointer is the same asterisk used for multiplication. However, in this statement, it is being used to designate a variable as a pointer. The asterisk _ used to declare a pointer is the same asterisk used for multiplication. However, in this statement, it is being used to designate a variable as a pointer. The asterisk _ used to declare a pointer is the same asterisk used for multiplication. However, in this statement, it is being used to designate a variable as a pointer.

Example

```c
#include <stdio.h>

int main()
{
		int var = 20; /* actual variable declaration */
		int *ip; /* pointer variable declaration */

		ip = &var; /* store address of var in pointer variable*/

		printf("Address of var variable: %x\n", &var  );

		/* address stored in pointer variable */
		printf("Address stored in ip variable: %x\n", ip );

		/* access the value using the pointer */
		printf("Value of *ip variable: %d\n", *ip );

		return 0;
}
```

## What is a C structure?

A structure is a user-defined data type in C that allows us to combine data items of different kinds. Structures are used to represent a record. For example, we may want to keep track of a student's name, roll number, and marks in three different subjects. A structure makes this possible by grouping all these data items at a single place. A structure makes this possible by grouping all these data items at a single place. A structure makes this possible by grouping all these data items at a single place. A structure makes this possible by grouping all these data items at a single place.

Example:

```c
struct student
{
		char name[50];
		int roll;
		float marks;
};
```

## What is a C union?

A union is a special data type available in C that allows to store different data types in the same memory location. You can define a union with many members, but only one member can contain a value at any given time. Unions provide an efficient way of using the same memory location for multiple-purpose. Unions provide an efficient way of using the same memory location for multiple-purpose. Unions provide an efficient way of using the same memory location for multiple-purpose. Unions provide an efficient way of using the same memory location for multiple-purpose.

Example:

```c
#include <stdio.h>
#include <string.h>

union Data {
	 int i;
	 float f;
	 char str[20];
};

int main() {
	 union Data data;

	 data.i = 10;
	 data.f = 220.5;
	 strcpy(data.str, "C Programming");

	 printf("data.i : %d\n", data.i);
	 printf("data.f : %f\n", data.f);
	 printf("data.str : %s\n", data.str);

	 return 0;
}
```

## What is a C enumeration?

An enumeration is a user-defined data type in C that consists of integral constants. The keyword enum is used to declare an enumeration. An enumeration is a set of named integer constants. An enumeration is a set of named integer constants. An enumeration is a set of named integer constants. An enumeration is a set of named integer constants.

Example:

```c
enum week {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
```

## What is a C typedef?

A typedef is a way to give a type a new name. It is generally used to give shorter names to types. It is generally used to give shorter names to types. It is generally used to give shorter names to types. It is generally used to give shorter names to types.

Example:

```c
typedef int feet;
feet distance;
```

## What is a C file?

A file is a named location on disk to store related information. We use files for permanent storage of data in a non-volatile memory (e.g. hard disk). Therefore, a file contains a collection of information organized and stored on the disk. A file is a named location on disk to store related information. We use files for permanent storage of data in a non-volatile memory (e.g. hard disk). Therefore, a file contains a collection of information organized and stored on the disk. A file is a named location on disk to store related information. We use files for permanent storage of data in a non-volatile memory (e.g. hard disk). Therefore, a file contains a collection of information organized and stored on the disk. A file is a named location on disk to store related information. We use files for permanent storage of data in a non-volatile memory (e.g. hard disk). Therefore, a file contains a collection of information organized and stored on the disk.

Example:

```c
FILE *fp;
fp = fopen("file.txt", "w+");
```

## What is a C macro?

A macro is a way to define a symbolic name or shorthand notation for a program fragment, which can be used as an alternative to typing the program fragment each time it is needed. Macros are used to define constants, functions, and other macros. Macros are used to define constants, functions, and other macros. Macros are used to define constants, functions, and other macros. Macros are used to define constants, functions, and other macros.

Example:

```c
#define PI 3.14159
```

# C Programming Questions

## What is the difference between C and C++?

C is a procedural programming language while C++ is an object-oriented programming language. C is a procedural programming language while C++ is an object-oriented programming language. C is a procedural programming language while C++ is an object-oriented programming language. C is a procedural programming language while C++ is an object-oriented programming language.

## What is the difference between C and Java?

C is a procedural programming language while Java is an object-oriented programming language. C is a procedural programming language while Java is an object-oriented programming language. C is a procedural programming language while Java is an object-oriented programming language. C is a procedural programming language while Java is an object-oriented programming language.

## What is the difference between C and Python?

C is a procedural programming language while Python is an object-oriented programming language. C is a procedural programming language while Python is an object-oriented programming language. C is a procedural programming language while Python is an object-oriented programming language. C is a procedural programming language while Python is an object-oriented programming language.

# 99.99 % of this is copy pasted from https://www.tutorialspoint.com/cprogramming/index.htm
