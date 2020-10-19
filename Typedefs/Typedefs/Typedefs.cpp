// Typedefs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
// typedef basically allows us to create are own vars and such, useful
// if you want to be arrcuate on things?

typedef float FLOAT32;

/*size_t or any unsigned type might be seen used as loop variable
 *as loop variables are typically greater than or equal to 0.
 * 
 *Note: When we use a size_t object, we have to make sure that in all
 * the contexts it is used, including arithmetic, we want only non - negative
 * values.For instance, the following program would definitely give the
 * unexpected result :
 * */

// so good for array index string lengths etc
typedef size_t size_type();
int main()
{

    FLOAT32 hey = 90;
    std::cout << hey << std::endl;
}

