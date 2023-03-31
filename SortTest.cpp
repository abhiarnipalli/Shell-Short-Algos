//
// Created by Abhlash Arnipalli on 3/31/23.
//

#include <iostream>
#include "SortClass.h"
#include <cstdlib>
#include <ctime>



int main(){

    srand(time(0));


    SortClass sort(50);
    SortClass sort1 = sort;
    SortClass sort2 = sort;
    SortClass sort3 = sort;

    cout << "Unsorted: " ;
    cout << sort << endl;
    cout << "-------------------------" << endl;
    ShellSort(sort, 0);
    ShellSort(sort1, 1);
    ShellSort(sort2, 2);
    ShellSort(sort3, 3);

    cout << "Sorted: " ;
    cout << sort << endl;

    cout << endl << "SWAP COUNT: " << endl;
    cout << "Sort 0: " << sort.getSwapCount() << endl;
    cout << "Sort 1: " << sort1.getSwapCount() << endl;
    cout << "Sort 2: " << sort2.getSwapCount() << endl;
    cout << "Sort 3: " << sort3.getSwapCount() << endl;

    sort.clear(true);
    return 0;
}