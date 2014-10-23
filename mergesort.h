#include <iostream>
using namespace std;

template <typename T>
void merge(T* left, int leftLen, T* right, int rightLen, T* result){
    // T* result = new T[leftLen + rightLen];
    int l = 0;
    int r = 0;

    for (int i = 0; i < leftLen + rightLen; i++){
        // cout << l << " " << r << endl;
        if (l < leftLen && r < rightLen && left[l] <= right[r]){
            result[i] = left[l];
            l++;
            // cout << "one" << endl;
        } else if (l < leftLen && r < rightLen && left[l] >= right[r]){
            result[i] = right[r];
            r++;
            // cout << "two" << endl;
        } else if (l < leftLen){
            result[i] = left[l];
            l++;
            // cout << "three" << endl;
        } else if (r < rightLen){
            result[i] = right[r];
            r++;
            // cout << "four" << endl;
        }
    }
    // delete left;

    // return result;
}

template <typename T>
void mergeHelper(T* items, int size, T* result){
    if (size > 1){

        int llen = size/2;
        int rlen = size/2 + size%2;

        T* left = new T[llen];
        T* right = new T[rlen];

        for (int i = 0; i < llen; i++){
            left[i] = items[i];
        }
        for (int i = 0; i < rlen; i++){
            right[i] = items[llen + i];
        }

        // T* left = items;
        // T* right = items + size/2;

        // return merge(mergeHelper(items, size/2), size/2, mergeHelper(items + size/2, size/2 + size%2), size/2 + size%2);

        T* leftRe = new T[llen];
        T* rightRe = new T[rlen];

        // cout << "here" << endl;
        mergeHelper(left, llen, leftRe);
        mergeHelper(right, rlen, rightRe);
        merge(leftRe, llen, rightRe, rlen, result);
        delete left;
        delete right;
        delete leftRe;
        delete rightRe;

        // for (int i = 0; i < size; i++){
        //     result[i] = re[i];
        // }
        // delete re;

        // cout << "mergehelper\t" << left[0] << " " << left[1] << endl;

        // items = NULL;
        // left = NULL;
        // right = NULL;
        // cout << "merg merg\t" << items[0] << " " << items[1] << endl;
        // cout << items[0] << endl;
        // cout << items[1] << endl;
        // cout << items[2] << endl;
        // cout << items[3] << endl;
        // cout << items[4] << endl;


        // cout << left << " " << right << endl;
        // free(left);
        // free(right);
        // delete left;
        // delete right;

        // return items;
    } else if (size > 0){
        // cout << "item " << *items << endl;
        *result = *items;
    }
    // delete items;
}

// implement merge sort
// give a tight upper and tight lower bound for the best case, average, and worst case of quick sort
template <typename T>
void mergesort(T* items, const int& size){
    T* re = new T[size];
    mergeHelper(items, size, re);
    // cout << "here" << endl;
    // cout << re[0] << endl;
    // cout << re[1] << endl;
    // cout << re[2] << endl;
    // cout << re[3] << endl;
    // cout << "end" << endl;

    for (int i = 0; i < size; i++){
        items[i] = re[i];
    }
    delete re;
}
