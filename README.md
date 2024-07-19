# LINQc
C# Linq implemented for C++

Note: An experiment to explore options of building on top of C++ Vectors.<br>
Takeaways:
- Seperation of containers and algorithms in C++ was probably a good idea.
- It's hard to make C++ lambdas look pretty. C#'s solution using `x => x == 5` is way cleaner.
  - Partially solved by macros.
- There would have to be way more thought process behind the memory management of this. Often times unnecessary copy calls definitely occur.
- Something like this can be useful, however I think it would be quite hard to use with more complex types, again returning to point 2.
