# Notes from Class
- An abstract data type (ADT) is an interface.
- A pointer is a programming language object that stores the memory
  address of another value located in computer memory.

### Memory Layout of a C Program
- Text - the program's executable instructions
- Data - global and static variables initialized by the programmer
- Stack - a LIFO data structure that contains "stack frames" that
  represent function calls. This is where a "stack trace" comes from.
- Heap - where dynamic memory all ocation takes places, managed by
  malloc and free.

- To make something persist after the end of a function, it has to be
  placed on the heap. You can use `malloc` to do this.

- 
