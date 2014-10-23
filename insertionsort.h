#include <iostream>
using namespace std;

// implement insertion sort
// give a tight upper and tight lower bound for the best case, average, and worst case of insertion sort
template <typename T> // done
void insertionsort(T* items, const int& size){
    // O(n^2)
    // create temp to hold value for swap
    T temp;
    // loop i goes from begining to end one by one through once starting at one
    for (int i = 1; i < size; i++){
        // loop k starts at i and goes down to 0 each i
        for (int k = i; k > 0; k--){
            // if items k-1 and k are out of order
            if (items[k - 1] > items[k]){
                // then swap items k-1 and k
                temp = items[k - 1];
                items[k - 1] = items[k];
                items[k] = temp;
            } // end if
        } // end k for
    } // end i for
    // return void
} // end insertionsort
