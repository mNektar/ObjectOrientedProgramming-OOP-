#include<iostream>

using namespace std;

template <class X> void shuffle(X** myArray, int myArraySize){
    int i, j;
    X* temp = nullptr;
    for(i = myArraySize -1; i > 1; i--){
        j = rand() % (i + 1);
        temp = myArray[i];
        myArray[i] = myArray[j];
        myArray[j] = temp;
    }
}
