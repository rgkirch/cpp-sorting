#include <iostream>
#include <cstdlib>
using namespace std;

// generates an array of integers that are in increasing order
int* generateIncreasingArray(const int& size){
    // dynamically create an array
    int* nums = NULL;
    nums = new int[size];

    for (int i = 0; i < size; i++){
        nums[i] = i;
    }

    // return int pointer for array
    return nums;
}

// generates an array of integers that are in decreasing order
int* generateDecreasingArray(const int& size){
    // dynamically allocate memory for array
    int* nums = NULL;
    nums = new int[size];

    for (int i = 0; i < size; i++){
        nums[i] = size - 1 - i;
    }

    // return pointer to dynamic array of ints
    return nums;
}

// generates an array of unique integers in random order
int* generateRandomArray(const int& size){
    // seed random
    srand(time(NULL));

    // values left to copy
    int leftToCheck = size;

    // populate nums with unique ints then copy to random places in random
    int* nums = NULL;
    int* random = NULL;
    nums = new int[size];
    random = new int[size];

    // initialize random to -1
    for (int i = 0; i < size; i++){
        random[i] = -1;
    }

    // populate nums
    for (int i = 0; i < size; i++){
        nums[i] = i;
    }

    // copy over to random places in random
    // if int already there, keep going
    // iterate through the nums array once and every item
    for (int i = 0; i < size; i++){
        // start k at a random number
        int k = rand()%size;
        // k will get really big so use k%size so it wraps back to begining
        // should keep going until leftToCheck is 0
        for (; 0 < leftToCheck; k++){ // dont forget to still mod k by size
            // if random[k] is empty then add nums[i] to random[k]
            if (random[k%size] < 0){
                random[k%size] = nums[i];
                leftToCheck--;
                // one less left to check
                // go back to i loop
                break;
            } // end if
        } // end k for loop
    } // end i for loop
    delete [] nums;
    return random;
} // end generateRandomArray

// generates an array of items that are all the same value
template <typename T>
T* generateConstArray(T value, const int& size){
    // dynamically allocate memory for array of T
    T* nums = NULL;
    nums = new T[size];

    for (int i = 0; i < size; i++){
        nums[i] = value;
    }

    // return T pointer
    return nums;
}




/*
2. Implement functions to generate arrays with specific properties.
For full credit, each function:
• Must be generic, unless otherwise specified.
• Must be implemented in file arrayGeneration.h
(a) [2 points] Implement a function that generates an array of integers that are in increasing order.
int* generateIncreasingArray(const int& size), where size is the number of elements that should
be in the resulting array.
For example, generateIncreasingArray(10) should result in the array [0,1,2,3,4,5,6,7,8,9].
(b) [2 points] Implement a function that generates an array of integers that are in decreasing order.
int* generateDecreasingArray(const int& size), where size is the number of elements that should
be in the resulting array.
For example, generateDecreasingArray(10) should result in the array [9,8,7,6,5,4,3,2,1,0].
(c) [2 points] Implement a function that generates an array of random integers that are in random order.
int* generateRandomArray(const int& size), where size is the number of elements that should be
in the resulting array. Note that each element in the resulting array should be unique.
For example, generateRandomArray(10) could result in the array [4,1,8,5,7,0,6,3,2,9].
(d) [2 points] Implement a function that generates an array of items that are all the same value.
T* generateConstArray(T value, const int& size), where T is the type of item that the array
should hold, value is the value of each item in the resulting array, and size is the number of elements
that should be in the resulting array.
For example, generateConstArray(‘‘A’’,5) should result in the array [“A”,“A”,“A”,“A”,“A”].
*/
