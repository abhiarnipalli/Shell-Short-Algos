# Project-1-----Shell-Short
Class SortClass
You are given a class call SortClass which contains objects to be sorted. For the current implementation,
the things to be sorted are floating point numbers, but practically I can change the content being stored
in the class to anything (or use a template construct) and the sorting program you implemented should
still work.
Here is the definition of the class:
• Members:
o Vector<float> array: a vector that store the items to be sorted. For now it is floating
point numbers
o swapCount: keep track of how many swaps has occurred.
• Constructor:
o SortClass(int n, bool genRandom = true): Create a SortClass object that store n items
(floating point numbers for now). If genRandom is set to true, than the initial value of
each number is randomly generated, otherwise every number is set to 0.0
o SortClass(const SortClass& st): copy constructor.
• Methods:
o Void clear(bool genRandom = true): if genRandom is true, than assign a random value to
each item of the SortClass array. Otherwise, it set every item of the array to be 0. Reset
swapCount to 0
o Int count(): return the number of items in the array
o Int getSwapCount(): return the current value of swapCount
o bool lessthan(int i, int j): return true if and only if array[i] < array[j]
o void swap(int I, int j): swap array[i] with array[j]; increment swapCount by 1.
• Overloaded operators:
o friend ostream& operator<<(ostream& os, SortClass& s): output the content of the
array. Add a newline character for every 10 items output.
o friend istream& operator>>(istream& os, SortClass& s): read the value of the items from
the input stream (items are stored from the first item to the last).
You are given 3 files:
1. SortClass.h : contains the declaration of the SortClass class
2. SortClass.cpp : contains implementation of all the methods (and overload operators) of the
SortClass class
3. SortTest.cpp: contains a main() driver, together with the following function
insertionSort(SortClass& s): sort the items in s by insertion sort.
Things to do
Part 1: Implementation
You are to implement the following function
• void ShellSort(SortClass& s, int code): Implement shellsort to sort the item inside the SortClass.
o s: the SortClass object
o code: an integer denoting how the hlist array (as in the source code) is to be formed:
▪ 0: hlist should be [1] (i.e. essentially insertion sort)
▪ 1: hlist should be [k
2
, (k-1)2
, …, 4, 1] where k is the maximum number such that
k
2
is still (strictly) smaller than the number of objects to be sorted. (Notice that
in this case 1 = 4*1 - 3)
▪ 2: hlist should be [2k
-1, 2
(k-1)
-1, 2
(k-2)
-1 … 3, 1] where k is the maximum number
such that 2k – 1 is still (strictly) smaller than the number of objects to be sorted.
(Notice that in this case 1 = 21
- 1)
▪ 3: hlist should be [(3k
-1)/2, (3(k-1)
-1)/2 , … 4 1], where k is k is the maximum
number such that (3k
-1)/2 is still (strictly) smaller than the number of objects to
be sorted. (Notice that in this case 1 = (31
-1)/2)
▪ If the code is anything either than 0,1,2,3, you should print an error message
and exit the program immediately.
