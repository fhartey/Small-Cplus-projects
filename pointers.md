##### Table of Contents  
- [General OOP Questions](#general-oop-questions)
  - [4 Principals of OOP](#4-principals-of-oop)
  - [Abstract Class vs Interface](#abstract-class-vs-interface) 
  - [Design Patterns](#design-patterns) 
- [Memory Management](#memory-management)
  - [Stack vs Heap](#stack-vs-heap)
  - [Ownership](#ownership-models)
  - [Move and Copy Semantics](#move-vs-deep-copy-vs-shallow-copy)
- [C++ Questions](#c-specific-questions)
- [Interview Qestions](#interview-questions)
  - [Inital Screening](#initial-screening)
  - [General Questions](#general-interview-questions)
  - [Technical Questions](#technical-querstions)
  - [System Design Questions](#system-design-questions)
  - [Intervier Questions](#questions-to-ask-interviewers)
  - [Salary](#salary)
  - [Red flags](#red-flags)
- [Additional Resources](#additional-resources)

# General OOP Questions
## 4 principals of OOP
1. Encapsulation
    - Encapsulation is to  take a piece of code that is repetitive and put it into a function. Usually we would want to make the function as reusable as possible so that we are able to call that function in other parts of are program, and allow it to take parameters that give us different resultsIn turn Encapsulation allows for a cleaner and more reusable code base.

2. Inheritance 
    - Allows us to inherit or take all of another class functions and properties and use those in a brand new class where we can create new properties in. Basically Inheritance allows use to reuse code, keeping are code base shorter and more organized.

3) Abstraction
    - Abstraction is the process of pulling out duplicate code into one function or class. In OOP we can do this through the use of abstract classes. Abstract classes  have set functions that already do what they need to do.
    - One common example of this is the function [map](https://hackage.haskell.org/package/base-4.18.0.0/docs/Data-List.html#v:map) found in many functional languages. Map takes a list and produces a new list by applying the supplied function to each element. __Consider the naive approach__
      ```cpp
      #include <vector>
      std::vector<int> addFive(std::vector<int> const &lst) {
        std::vector<int> res;
        for (auto num : lst) {
            res.push_back(num + 5);
        }
        
        return res;
      }


      std::vector<int> multFive(std::vector<int> const &lst) {
        std::vector<int> res;
        for (auto num : lst) {
            res.push_back(num * 5);
        }
        
        return res;
      }


      int main() {
        std::vector<int> nums = {1,2,3,4,5};
        
        std::vector<int> nums_plus_five = addFive(nums); // [6, 7, 8, 9, 10]
        std::vector<int> nums_mult_five = multFive(nums); // [5, 10, 15, 20, 25]
      }
      ```
      Instead we could abstract the functions `addFive` and `multFive` into a abstract function called map

      ```cpp
      #include <vector>
      #include <functional>

      template<typename A, typename B>
      std::vector<B> map(std::vector<A> const &lst, std::function<B(A)> func) {
        std::vector<B> res;
        for (A val : lst) {
            res.push_back(func(val));
        }
        
        return res;
      }

      int main() {
        std::vector<int> nums = {1,2,3,4,5};
        
        std::vector<int> nums_plus_five = map<int, int>(nums, [](int v) { return v + 5; }); // [6, 7, 8, 9, 10]
        std::vector<double> nums_mult_five_point_five = map<int, double>(nums, [](int v) { return v * 5.5; }); // [5.5, 10.5, 15.5, 20.5, 25.5]
      }
      ```

4. Polymorphism TODO THIS NEEDS MORE WORK
    - Can be applied in two simple ways
      1. Method Overloading
      2. Method Overriding
    
    - __Method Overloading__
      - When a class has multiple methods with the same names but a different set of parameters, it is called Method overloading. 
      - You can proceed with method overloading, only if your methods satisfy any one of the following rules 
        1. Have method with the same name and different parameters or return types.

    - __Method Overriding__
      - The second way to go ahead with polymorphism is method overriding. This is only possible if a subclass ( or ) sister class has the same method as the parent class. Much like Method overloading, there are also some rules for method overriding to work, so if your subclass has a method name function1, then class A, and B inheited or extend that Then they can call that same function however you can changes what that function does when there call so A and B could have two different implimentations of Function 1 and depending on which class is called, Then that implentation of it will happens

    ```cpp
    // Overloading
    void print(int x);
    void print(float x)
    void print(char* chars)
    
    // Overriding
    class BaseClass {
      public:
        virtual void print(); { ... }
    }

    class ChildClass : public BaseClass {
      public:
        // Overriding the BaseClass's implimentation
        void print() { .. };
    }
    ```


## Abstract class vs Interface
So two different classes have the same method  and one class is used  as interface or is inherited the method will need the same parameters and return types,but then inside the function the function can implant different code, and depend on when you create the object and call that function, it will do the implanted code that was done in that septic class.

abstact class is where you can have pre named function that are not implented adn have functions that are implmented where then a class can intehit and the functions that are not implmented that class can create there own implention of them and where the ones that are implented that class will now be able to implemnt them as well

Where as interface all the function are not implented yet, and is used for a class to inhiterit it, and make its own implention of those set functions. An interface is an empty shell. There are only the signatures of the methods, which implies that the methods do not have a body. The interface can't do anything. It's just a pattern.





# Design Patterns
## Singleton Pattern
- A class where you __ONLY__ have a single instance of that class, or struct.
- Used when only one instance of an object should ever be made. (i.e. A class that represents a cache)
- Can only have a private constructor

## Factory Pattern
- TODO

## Visitor Pattern
- TOOD

## Adapter Pattern
- TODO

## Builder Pattern
- TODO


# Memory Management
## Stack vs Heap
- Heap
  - expensive to allocate
  - Can hold large amoutns of data
  - allocate using `new` or `malloc`
  - deallowcate using `delete` or `free`
- Stack
  - Where local variables are stored
  - cheap to allocate, but can not hold as much data
## Ownership Models
- Single Ownership `std::unique_ptr` 
  - A smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope
  - Only non-const unique_ptrs can transfer ownership
- Shared Ownership `std::shared_ptr`
  - A smart pointer that retains shared ownership of an object through a pointer. Several shared_ptr objects may own the same object. The object is destroyed and its memory deallocated when either of the following happens:
    1. the last remaining shared_ptr owning the object is destroyed;
    2. the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset()
  - Use shared_ptr when you want multiple objects pointing to the same resource. Shared pinters can always equal each other.

## Move vs Deep Copy vs Shallow Copy
- Shallow Copy
  - You just copy the pointer address
  - Cheap to do
  ```cpp
  int main() {
    int* x = new int[4];
    // Shallow copy the ptr address
    int y = x;
  }
  ```
- Deep Copy
  - You copy the physical value instead of the pointer
  - Expensive
  - If your new variable is modified, the original object will not be modified,
  ```cpp
  struct Test {
    int a;
    int *p;

    Test (int x) {
      a = x;
      p = new int[a];
    }
    // Copy constructor
    Test (Test & t) {
      a = t.a;
      p = new int[a];
      if (p) {
        for (int i = 0; i < a; i++) {
          p[i] = t.p[i];
        }
      }
    }
  };

  int main()
  {
      Test t (5);
      t.p[0] = 1;
      // Deep Copy
      Test t2 (t);
  }
  ```
- Move 
  - Faster then Deep Copy
  - A typical use is 'moving' resources from one object to another instead of copying
  ```cpp 
  // using Copy
  template <class T>
  swap(T& a, T& b) {
      T tmp(a);   // we now have two copies of a
      a = b;      // we now have two copies of b (+ discarded a copy of a)
      b = tmp;    // we now have two copies of tmp (+ discarded a copy of b)
  }

  // Using Move
  template <class T>
  swap(T& a, T& b) {
      T tmp(std::move(a));
      a = std::move(b);   
      b = std::move(tmp);
  }
  ```

## C++ Specific Questions
- ### What are function pointers ( void pointers?)
  - Function pointers are the adrress of an actual funciton. They are a way to pass function as either a parameter or store to memorty location of a function.
    ```cpp
    int multiply(int a, int b) { return a * b; }

    int main() {
      int (*func)(int, int);
      func = multiply;

      int prod = func(15, 2);
    }
    ```
  - `std::function` - A wrapper that can hold any type of callable object (objects that can be used like functions). This allows you to pass functions, lambdas, etc. 

- ### What is a pointer
  - A pointer is a variable that stores the memory address of an object.  Pointers are used extensively in both C and C++ for three main purposes: 
    1. to allocate new objects on the heap
    1. to pass functions to other functions. 
    1. to iterate over elements in arrays or other data structures.

- ### What is a reference
  - A reference variable is an alias, that is, another name for an already existing variable. Once a reference is initialized with a variable, either the variable name or the  reference name may be used to refer to the variable. a pointer variable points to a variable whose memory location is stored in it. The reference variable is an alias for a variable which is assigned to it.

- ### What is a void pointer
  - A void pointer in C++ is a special pointer that can point to objects of any data type. In other words, a void pointer is a general purpose pointer that can store the address of any data type, and it can be typecasted to any type

- ### What are the different data types present in C++?
  1. `Primitive Datatype`(basic datatype). Example- char, short, int, float, long, double, bool, etc.
  1. `Derived datatype`. Example- array, pointer, etc.
  1. `Enumeration`. Example- enum
  1. `User-defined data types`. Example- structure, class, etc

- ### Compile time vs runtime polymorphism
  - Compile time polymorphism
    - It provides fast execution because it is known at the compile time. It is achieved by function overloading and operator overloading.
  - Runtime polymorphism
    - In this method, we come to know at run time which method will be called. The call is not resolved by the compiler.
    - It provides slow execution compared to compile-time polymorphism because it is known at the run time. Can be achieved by virtual functions and pointers.
- ### What do you know about friend class and friend function?
  - A friend class can access private, protected, and public members of other classes in which it is declared as friends. Like friend class, friend function can also access private, protected, and public members. But, Friend functions are not member functions.
- ### What are the C++ access specifiers?
  1. `Public`: All data members and member functions are accessible outside the class.
  1. `Protected`: All data members and member functions are accessible inside the class and to the derived class.
  1. `Private`: All data members and member functions are not accessible outside the class.

- ### Is deconstructor overloading possible? If yes then explain and if no then why?
  - No destructor overloading is not possible. Destructors take no arguments, so there’s only one way to destroy an object. That’s the reason destructor overloading is not possible.

- ### What do you mean by call by value and call by reference?
  - In `call by value method`, we pass a copy of the parameter is passed to the functions. For these copied values a new memory is assigned and changes made to these values do not reflect the variable in the main function.
  - In `call by reference method`, we pass the address of the variable and the address is used to access the actual argument used in the function call. So changes made in the parameter alter the passing argument.

- ###  What are the static members and static member functions?
  - When a variable in a class is declared static, space for it is allocated for the lifetime of the program. No matter how many objects of that class have been created, there is only one copy of the static member. So same static member can be accessed by all the objects of that class.
- ### What is "this" pointer in C++?
  - The member functions of every object have a pointer named this, which points to the object itself. The value of this is set to the address of the object for which it is called. It can be used to access the data in the object it points to.

- ### Static vs Dynamic Variables
  - `Static varibles` are only one per object so if object A, changes 3 it changes for all objects including A, and B

  - `Dynamic varbiles` are not set per object so object A and B could have the same variable name but two different values for that variable 
    ```cpp
    #include <iostream>
    class A {
      public:
        int one = 2;
        int two = 9;
        static int three;
      A(int one1, int two2) : one(one1), two(two2) {};
      A (){};
    };

    int A::three = 0;
    int main() {
      A _a;
      A _b;
      std::cout << _a.one <<std::endl;
      std::cout << _a.two <<std::endl;
      _a.three = 8;
      std::cout << "is now 8: "<< _a.three <<std::endl;
      _b.three = 6;
      std::cout << "is now 6: "<< _a.three <<std::endl;
      return 0;
    }
    ```

- ### What is Function overriding in C++ 
  - It is a concept by which you can define a function of the same name and the same function signature (parameters and their data types) in both the base class and derived class with a different function definition. It redefines a function of the base class inside the derived class, which overrides the base class function. Function overriding is an implementation of the run-time polymorphism. So, it overrides the function at the run-time of the program.


- ### Virtual vs Pure Virtual Functions
  - `Pure Virtual` - abstract functions that defer their implimentation to the classes that inherit it. 
    - All derived class must redefine pure virtual function of base class otherwise derived class also becomes abstract just like base class. If derived class do not redefine virtual function of base class, then no compilation error but derived class also becomes abstract just like the base class.
  - `Virtual Function` - Base class having virtual function can be instantiated i.e. its object can be made.
    - If derived class do not redefine virtual function of base class, then it does not affect compilation.
  - ```cpp
    // pure virtual
    class Abstract {
      public:
        virtual int add(int a, int b) = 0;
    };

    // virtual
    class Abstract {
      public:
        virtual int add(int a, int b) {
          return a + b;
        }
    };
    ```

# Interview Questions

## Initial Screening
**IMPORTANT** Make sure to sell yourself! Tell a story about your career and future goals as a developer and how company can fit into these goals. Start the sotry out broad then narrow in on accomplishments

- Tell us about yourself?
  - Currently im working in a c++ backend software role doing devlopment for the aegis system My day consits of wiritng new devlopment features for the system and doing bug fixes, and Before this job i was mianly in college working on my CS degree, while also working part time for another company doing C#. currently for my future goals is to find more challeging opputines that can help me grow as a software devloper

- Why do you want to work at X comapny?
  - I want to work at comcast because comcast seems like an exciting company looking from the outside it seems like theres a lot of oputiny for devlpoment espically with stream services, and cable tv and movies becoming bigger then ever before

- What is your greatest strength
  - I would have to say my greatest strength is never giving up and always trying to aceive contnous growth when i recive a problem i always make sure to complete it no matter the challenges that it my face, and im always on my free time trying to learn new and more techologies to stay up with current times and best partices

- What is your greatest weakness?
  - A big weakness of mine is i work to hard, once i find a problem very intresting, and hard to solve, i feel as if i can get every into it, and will continue working until i have figure out the problem. Sadly because thois i sometimes will  neglect my friends and family, and other responseabilites

- Why should we hire you?
  - I believe you should hire me because i already have decent work expirence in c++ and working in a big code base, that is currently moved into micro services. I have knowedlge of working in a agile envoriment with a team. and using version control tools with that being said i think my skill set would be a good asset to this position


- What motivates you?
  - Learning new things and tech that is in our field. Coming up with creative ideas to improve something, or make something new. Finding a way to solve a problem, or overcome a challenge

- How did you find this job?
 
- Where do you see yourself in 5 years
  - Currently id see myself hoefully being in a senior role  as a c++ devloper taking on more responsites  and hopefully maybe being able to lead a new project one day

- What do you like most about your current or last job
  - I honestly love everything about my job and have great time here the only thing is i feel that I have learned all I can in that role and are now looking for new challenges.
  - The most chllenging part i had to over come was fitting these control in the legacy system, working on very lose base requirments from the cutmoer this was challenging because the custimer wasnt sure want they wanted so there were many re itterations of itwhile we tested it to gether and i would have to come up with  solutions on the fly to give them exactly what they wanted
## General Interview questions
1. Tell me about you as a person
1. What is the most proudest project you have worked on?
    - The most proudest project that i have worked on was  createing the radar control for my current employer

1. What was a challenging thing that you had to over come in the project?
1. What would you want to see more into your new role
1. What do you must like and dislike of your current role
1. Tell me a challenging project you were a part of
1. Tell me about challenges you faced with group members while doing group project ?
1. Explain how you handled a stressful situation.


## Technical Querstions
1. Merge a linked list using Java api
1. What is a thread pool
1. What is thread join and fork
1. What is a Microservice
1. What is CI/CD
1. How would you sort a list? Follow up : What is the most efficient way to find a number in a list
1. What is a REST API?
1. How would you sort a list and what is the most efficient way to find a number in a list 
    * For sorting: `QuickSort` (`MergeSort` is generally faster on large datasets)
        * Merge sort is better for larger satay sets quick sort is better for small data sets
    * Once sorted `BinarySearch` is the best way to find the element
        * Which is when we start in the middle of the array and compare it the number we want to find, if it isn’t the number we know can get rid of that half then repeat the process until we find the number

## System Design Questions
- Which frameworks do you prefer to use for x type of development
- Explain the process of a user visiting a web page. What HTTP methods are involved?
- Desing a URL shortener

## Questions to ask interviewers
1. What qualities do you think one needs to succeed in this role
1. What do you like and dislike of your current role

## Red Flags
- 10x developer, rockstar dev, ninja dev, we are family
- Un-realistic expectations
- (Startup) Dont reveal questions about evaluation

### Salary
- **KNOW YOUR WORTH!!!**
- [levels.fyi](https://www.levels.fyi/?compare=Vanguard,Comcast,JPMorgan%20Chase&track=Software%20Engineer) to see going rates for position
- Options are a lottary ticket if conampy is private
- RSU's are better but can be taxed!

# Additional Resources
#### Problems
- [Problems and solutions](https://docs.google.com/spreadsheets/d/1A2PaQKcdwO_lwxz9bAnxXnIQayCouZP6d-ENrBz_NXc/edit#gid=0)
  - focus on: Arrays, Dynamic Programming, Graph, Tree

#### Books
- [System Design Interview – An insider's guide](https://www.amazon.com/System-Design-Interview-Insiders-Guide-ebook/dp/B08B3FWYBX/ref=sr_1_2_sspa?gclid=Cj0KCQjwn9CgBhDjARIsAD15h0ANGrm5KJQGzvUHlZiK8JdcT_cog-XK2yCAsbXlxPS3Fwd8SMxUMc0aAg1PEALw_wcB&hvadid=557460599202&hvdev=c&hvlocphy=9007449&hvnetw=g&hvqmt=e&hvrand=17502231599931071867&hvtargid=kwd-915044167393&hydadcr=18915_13357676&keywords=system+design+interviews&qid=1679071610&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExM1hTWkVRWDhMRVI3JmVuY3J5cHRlZElkPUEwMjA0MTUwMzJaUDhCSkU3UVlZVSZlbmNyeXB0ZWRBZElkPUEwMzc1NzQ4M09HWlI1SjBWQTdOQyZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=)
- [Designing Data-Intensive Applications: The Big Ideas Behind Reliable, Scalable, and Maintainable Systems](https://www.amazon.com/Designing-Data-Intensive-Applications-Reliable-Maintainable/dp/1449373321/ref=pd_bxgy_img_sccl_2/137-5714055-7123139?pd_rd_w=oL7gN&content-id=amzn1.sym.6953b182-f957-43e6-9fe3-866e180e1e05&pf_rd_p=6953b182-f957-43e6-9fe3-866e180e1e05&pf_rd_r=95BXGF3SVGFW6TT5101Q&pd_rd_wg=xJyhG&pd_rd_r=dd53774e-465f-4a5f-bb58-87fb854b66c3&pd_rd_i=1449373321&psc=1)