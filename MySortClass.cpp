//
// Created by Abhilash Arnipalli on 2/08/23.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "SortClass.h"
using namespace std;


SortClass::SortClass(int n, bool genRandom)
{
    swapCount = 0;
    if (genRandom)
    {
        for (int i = 0; i < n; i++)
            array.push_back((rand() % 1000) * 1.0);
    }
    else
    {
        for (int i = 0; i < n; i++)
            array.push_back(0.0);
    }
}

SortClass::SortClass(const SortClass& st)
{
    swapCount = st.swapCount;
    for (int i = 0 ; i < st.array.size(); i++)
        array.push_back(st.array[i]);

}

int SortClass::count()
{
    return array.size();
}

int SortClass::getSwapCount()
{
    return swapCount;
}

void SortClass::clear(bool genRandom)
{
    swapCount = 0;
    if (genRandom)
    {
        //srand(time(0));
        for (int i = 0; i < array.size(); i++)
            array[i] = (rand() % 1000) * 1.0;
    }
    else
    {
        for (int i = 0; i < array.size(); i++)
            array[i] = 0.0;
    }
}

bool SortClass::lessthan(int i, int j)
{
    return (array[i] < array[j]);
}

void SortClass::swap(int i, int j)
{
    float temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    swapCount++;
}

ostream& operator<<(ostream& os, SortClass& s)
{
    for (int i = 0; i < s.array.size(); i++)
    {
        if (!(i % 10))
            os << endl;
        os << s.array[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, SortClass& s)
{
    for (int i = 0; i < s.array.size(); i++)
    {
        is >> s.array[i];
    }
    return is;
}



//SHELL SORT FUNCTION
void ShellSort(SortClass& s, int code) {

    const int n = s.count(); //constant int n is assigned the value of the number of objects s.
    vector<int> hlist; //empty vector hlist to store the gap sequence

    //Push back 1 into hlist.
    if (code == 0) {
        hlist.push_back(1);
    }

        //Find the max k where k^2 is still smaller than n using the sqrt().
        //Push k^2 to hlist and decrement k. Repeat until k = 0.
    else if (code == 1) {
        int k = sqrt(n);
        while (k >= 1) {
            int kSquared = (k * k);
            hlist.push_back(kSquared);
            k--;
        }
    }

        //Find the max value of k where (2^k - 1) is less than n using the pow() function.
        //Push (2^k - 1) to hlist and decrement k. Repeat until k = 0.
    else if (code == 2) {
        int k = 1;
        while (pow(2, k) - 1 < n) {
            k++;
        }
        while (k > 0) {
            hlist.push_back(pow(2, k) - 1);
            k--;
        }
    }

        //Find the max value of k where ((3^k - 1) / 2) is less than n.
        //Push ((3^k - 1) / 2) to hlist, decrement k and repeat until k = 0.
    else if (code == 3) {
        int k = 1;
        int size = 1;
        while (size <= n) {
            k++;
            size = (pow(3, k) - 1) / 2;
        }
        k--;
        while (k >= 0) {
            hlist.push_back((pow(3, k) - 1) / 2);
            k--;
        }
    }

        //Exit if invalid input
    else {
        cout << "ERROR! Exiting the program..." << endl;
        exit(1);
    }

    //Sort the SortClass object s using the gap sequence in hlist.
    //For each gap size in hlist, starting from the largest the algorithm performs insertion sort on each subset of elements that are that gap size apart.
    for (int i = 0; i < hlist.size(); i++) {
        int size = hlist[i];
        for (int j = size; j < n; j++) {
            int k = j;
            while (k >= size && s.lessthan(k, k - size)) {
                s.swap(k, k - size);
                k = ( k - size );
            }
        }
    }
}