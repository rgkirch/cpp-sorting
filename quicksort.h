#include <iostream>

using namespace std;

//determines if quick sort pivot is random(TRUE) or last element(FALSE)
bool isRandomPivot = false;

// implement quick sort
// be able to specify whether the pivot point is the last element of the array or is randomly selected
// give a tight upper and tight lower bound for the best case, average, and worst case of quick sort
template <typename T>
void quicksort(T* items, const int& size){
    if (size > 1){
        // swap last element with a random element
        if (isRandomPivot){
            srand(time(NULL));
            int ran = rand()%size;
            T temp = items[size-1];
            items[size-1] = items[ran];
            items[ran] = temp;
        }

        T temp;
        int sortedSize = 0;
        T* pivot = items + size - 1;
        T* index = items;

        while (index < pivot){
            if (*index < *pivot){
                // swap *index with sortedsize
                temp = items[sortedSize];
                items[sortedSize] = *index;
                *index = temp;

                sortedSize++;
                index++;
            } else {
                index++;
            }
        }
        // swap index with s
        temp = items[sortedSize];
        items[sortedSize] = *index;
        *index = temp;
        // i++
        sortedSize++;

        quicksort(items, sortedSize - 1);
        quicksort(items + sortedSize, size - sortedSize);


        // cout << *pivot << endl;


        // partition


        // quicksort(items, pivot - items);
        // quicksort(pivot + 1, size - (pivot - items));
    }
}
