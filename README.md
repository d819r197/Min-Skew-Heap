# Min-Leftist-Heap
## Implementation of a Min-Leftist Heap data structure.

### Purpose:
The purpose of this lab is to implement a min-leftist heap in C++.

### General Requirements:
For this assignment, you will work on a pointer-based implementation of min-leftist heap. You
are to read in the numbers from a data file of integers and insert each number into a min-leftist
heap. Min-leftist heaps should not allow duplicate numbers.

For this lab, you should build the heap using the samples which are in the data.txt. After that,
your program should have a simple menu like this:

```
Please choose one of the following commands:
1- Insert
2- Merge
3- Deletemin
4- Findmin
5- Preorder
6- Inorder
7- Postorder
8- Levelorder
9- Exit
```

### Min-leftist heap:
The min-leftist heap methods should be implemented as follows:
  - Buildheap() - should build the min-leftist heap using the insert function.
  - Insert(x) - should insert x into the min-leftist heap using the merge function. If the
insertion causes the subtrees to be swapped, show that swapping has occurred as shown
in the expected output illustration.
  - Deletemin() - should delete the minimum value from the min-leftist heap and merge the
remaining two sub heaps.
  - Findmin() - should print the minimum value from the min-leftist heap.
  - Merge(H1,H2) – this function should merge the two trees H1 and H2, where H1 and H2
are two min leftist heaps. As an example to be shown explicitly by your program to
illustrate the working of this function, you are required to execute this function on two
trees called H1 and H2, where H1, the first parameter, is the tree created by reading the
data.txt file, and H2, the second parameter, is a tree created by taking 3 user inputs from 
EECS 560 Lab 8 – Implementation of Min-Leftist Heap
Prof.: Dr.Shontz, GTAs: Chiranjeevi Pippalla, Anubhav Ghosh
the command line, i.e., 88, 105, and 222. The new tree formed after merging is H3. Note
that the task mentioned is only an example that is to be shown for the purpose of
illustrating the proper working of this function through the menu. In general, this function
should be called every time it is presented with two min leftist heaps and not only when
it is called from the 2nd option of the menu.
  - Preorder() should print the preorder traversal of the min-leftist heap.
  - Inorder() -– should print the inorder traversal of the min-leftist heap.
  - Postorder() – should print the postorder traversal of the min-leftist heap.
  - Levelorder() – should print the level order traversal of the min-leftist heap.

### Data file:
data.txt: 21 15 24 38 25 5 55 87 71 14

We will insert these values, in the given order, into the min-leftist heap. The numbersin the boxes
in the following diagrams indicate the rank.
