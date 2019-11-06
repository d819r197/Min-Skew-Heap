#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

class Node {
  public:
    //Constructor
    Node();
    Node(int k);

    //Helper Functions
    void setKey(int k) { key = k; }
    int getKey() { return(key); }

    int getRank() { return(rank); }
    void ComputeRank();

    void setLeftChild(Node* child) { leftChild = child; }
    void setRightChild(Node* child) { rightChild = child; }
    Node* getLeftChild() { return(leftChild); }
    Node* getRightChild() { return(rightChild); }

  private:
    int key;
    int rank;
    Node* leftChild;
    Node* rightChild;
};

#endif
