#include <iostream>
#include <cstdlib>
#include <time.h>
#include "arrayGeneration.h"
#include "sorting.h"

using namespace std;

// ostream& operator<<(ostream &out, int arr[]){
//     cout << sizeof(*arr);
//     // for (int i = sizeof(arr))
//     // for (int* i = &arr[0]; i != &arr[sizeof(*arr)]; ++i){
//     //     cout << *i << endl;
//     // }
//     cout << endl;
// }

// return TRUE if the items are sorted in increasing order and FALSE otherwise
template <typename T>
bool isSorted(T* items, const int& size){
    for (int i = 1; i < size; i++){
        if (items[i - 1] > items[i]){
            return false;
        } // end if
    } // end for
    return true;
} // end isSorted

int main(){
    int* nums;

    cout << endl;


    // set to 10 000
    int sizeMagnifier = 1000;
    long timeStart = 0;
    long timeEnd = 0;
    long timeElapsed = 0;
    int avgVals[10] = {0};
    // [sortScheme][size][arrayGen]
    int avgTable[4][10][4] = {0};
    string sortStr = "";
    string arrayStr = "";
    string runStr = "";

    // nums = generateRandomArray(sizeMagnifier);
    // insertionsort(nums, sizeMagnifier);
    // cout << (isSorted(nums, sizeMagnifier) ? "sorted" : "not") << endl;

    // nums = generateRandomArray(sizeMagnifier);
    // quicksort(nums, sizeMagnifier);
    // cout << (isSorted(nums, sizeMagnifier) ? "sorted" : "not") << endl;

    // nums = generateRandomArray(sizeMagnifier);
    // cout << nums[0] << endl;
    // cout << nums[1] << endl;
    // cout << nums[2] << endl;
    // cout << nums[3] << endl;
    // cout << nums[4] << endl;
    // cout << nums[5] << endl;
    // cout << nums[6] << endl;
    // cout << nums[7] << endl;
    // cout << nums[8] << endl;
    // cout << nums[9] << endl;

    // mergesort(nums, sizeMagnifier);
    // cout << (isSorted(nums, sizeMagnifier) ? "sorted" : "not") << endl;

    // int thing[] = {1,9,2,4,7};

    // nums = generateRandomArray(5);
    // quicksort(nums, 5);

    // cout << nums[0] << endl;
    // cout << nums[1] << endl;
    // cout << nums[2] << endl;
    // cout << nums[3] << endl;
    // cout << nums[4] << endl;
    // cout << nums[5] << endl;
    // cout << nums[6] << endl;
    // cout << nums[7] << endl;
    // cout << nums[8] << endl;
    // cout << nums[9] << endl;

    // delete [] nums;

    if (1){
        for (int sortScheme = 0; sortScheme < 4; sortScheme++){
            // set string for which sorting method is being used
            switch(sortScheme){
                case 0: sortStr = "insertionsort";
                break;
                case 1: sortStr = "quicksort with random pivot";
                break;
                case 2: sortStr = "quicksort with last element as pivot";
                break;
                case 3: sortStr = "mergesort";
                break;
                default: sortStr = "error";
                break;
            }
            for (int arrayGen = 0; arrayGen < 4; arrayGen++){
                // set string for which generation scheme is being used
                switch(arrayGen){
                    case 0: arrayStr = "an increasing";
                    break;
                    case 1: arrayStr = "a decreasing";
                    break;
                    case 2: arrayStr = "a random";
                    break;
                    case 3: arrayStr = "a const";
                    break;
                    default: arrayStr = "error";
                    break;
                }
                cout << sortStr << " on " << arrayStr << " array of integers" << endl;
                for (int i = 1; i < 11; i++){
                    cout << "\t" << i * sizeMagnifier;
                }
                cout << endl;

                for (int run = 1; run < 6; run++){
                    // strings for which run
                    switch(run){
                        case 1: runStr = "1st";
                        break;
                        case 2: runStr = "2nd";
                        break;
                        case 3: runStr = "3rd";
                        break;
                        case 4: runStr = "4th";
                        break;
                        case 5: runStr = "5th";
                        break;
                        default: runStr = "error";
                        break;
                    }
                    cout << runStr << "\t";
                    for (int size = 1; size < 11; size++){
                        // make the array
                        switch(arrayGen){
                            case 0: nums = generateIncreasingArray(size*sizeMagnifier);
                            break;
                            case 1: nums = generateDecreasingArray(size*sizeMagnifier);
                            break;
                            case 2: nums = generateRandomArray(size*sizeMagnifier);
                            break;
                            case 3: nums = generateConstArray(1, size*sizeMagnifier);
                            break;
                            default: arrayStr = "error";
                            break;
                        }
                        // start the timer
                        timeStart = clock();
                        // call the sorting method
                        switch(sortScheme){
                            case 0: insertionsort(nums, size*sizeMagnifier);
                            break;
                            case 1: isRandomPivot = true;
                                    quicksort(nums, size*sizeMagnifier);
                            break;
                            case 2: isRandomPivot = false;
                                    quicksort(nums, size*sizeMagnifier);
                            break;
                            case 3: mergesort(nums, size*sizeMagnifier);
                            break;
                            default:
                            break;
                        }
                        // stop the timer
                        timeEnd = clock();
                        delete [] nums;
                        // calculate ms elapsed
                        timeElapsed = (timeEnd - timeStart)/(CLOCKS_PER_SEC/1000);
                        avgVals[size - 1] += timeElapsed;
                        // print ms
                        cout << timeElapsed << "\t" << flush;
                    } // 1 to 11 for loop, will have finished printing one row
                    cout << endl;
                } // 1 to 6 for loop, will have finished printing one graph
                cout << "avg\t";
                for (int i = 0; i < 10; i++){
                    cout << avgVals[i]/5 << "\t";
                    avgTable[sortScheme][i][arrayGen] = avgVals[i]/5;
                    avgVals[i] = 0;
                }
                cout << "\n" << endl;
            } // 0 to 4 for loop, will have finished trying each array type
        } // 0 to 4 for loop, will have finished trying each sorting method

        cout << "***** average value times *****" << endl;

        for (int sortScheme = 0; sortScheme < 4; sortScheme++){
            switch(sortScheme){
                case 0: sortStr = "insertionsort";
                break;
                case 1: sortStr = "quicksort with random pivot";
                break;
                case 2: sortStr = "quicksort with last element as pivot";
                break;
                case 3: sortStr = "mergesort";
                break;
                default: sortStr = "error";
                break;
            }
            cout << sortStr << endl;
            cout << "\tinc\tdec\tran\tconst" << endl;
            for (int size = 0; size < 10; size++){
                cout << (size+1)*sizeMagnifier<< "\t";
                for (int arrayGen = 0; arrayGen < 4; arrayGen++){
                    cout << avgTable[sortScheme][size][arrayGen] << "\t";
                }
                cout << endl;
            }
            cout << endl;
        }
    // not a comment
    // cout << (isSorted(nums, 10) ? "sorted" : "not") << endl;

    // delete nums; // :(
    }
    cout << endl;
    cout << "total time" << (clock())/(CLOCKS_PER_SEC/1000) << " ms" << endl;
    return 0;
}

// here there be air
