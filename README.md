# Min-Skew-Heap
Implementation of the Min-Skew Heap data structure

## Purpose:
The purpose of this lab is to implement a min-skew heap in C++.

## General Requirements:
For this assignment, you will work on a pointer-based implementation of min-skew heap. You
are to read in the numbers from a data file of integers and insert each number into a min-skew
heap. Your min-skew heaps should not allow duplicate numbers.
For this lab, you should build the heap using the samples which are in the data.txt file. After
that, your program should have a simple menu like this:

```
------------------------------------------------------------
Please choose one of the following commands:
1- Insert
2- Merge
3- Delete
4- Find
5- Preorder
6- Inorder
7- Postorder
8- Levelorder
9- Exit
```

## Min-skew heap:
The min-skew heap methods should be implemented as follows:

- Buildheap() - should build the min-skew heap using the insert function.
- Insert(x) - should insert x into the min-skew heap using the merge function. If the
insertion causes the sub trees to be swapped, show that swapping has occurred as
shown in the expected output illustration.
- Delete(x) - should delete the element x from the min-skew heap and merge the sub
heaps.
- Find(x) - this function should print whether or not the given element is present in the
min-skew heap.
- Merge(H1,H2) – this function should merge the two trees H1 and H2, where H1 and H2
are two min skew heaps. As an example to be shown explicitly by your program to
illustrate the working of this function, you are required to execute this function on two
trees called H1 and H2, where H1, the first parameter, is the tree created by reading the 
EECS 560 Lab 9 – Implementation of Min-Skew Heap
Prof.: Dr.Shontz, GTAs: Chiranjeevi Pippalla, Anubhav Ghosh
data.txt file, and H2, the second parameter, is a tree created by taking 3 user inputs
from the command line, i.e., 89, 106, and 226. The new tree formed after merging is H3.
Note that the task mentioned is only an example that is to be shown for the purpose of
illustrating the proper working of this function through the menu. In general, this
function should be called every time it is presented with two min skew heaps and not
only when it is called from the 2nd option of the menu.
- Preorder() should print the preorder traversal of the min-skew heap.
- Inorder() -– should print the inorder traversal of the min-skew heap.
- Postorder() – should print the postorder traversal of the min-skew heap.
- Levelorder() – should print the level order traversal of the min-skew heap.

## Data file:
data.txt: 
```
22 16 25 39 26 6 56 88 72 15
```
