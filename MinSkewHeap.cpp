#include <iostream>
#include <ctime>

#include "MinSkewHeap.h"

//Constructor
MinSkewHeap::MinSkewHeap() {
  treeRoot = nullptr;
  treeSize = 0;
  treeHeight = 0;

  nodesInLevel = 0;
  maxNodesInLevel = 1;
}

//Class Methods
void MinSkewHeap::Build(){

}

void MinSkewHeap::Insert(int key) {
  treeSize++;
  nodesInLevel++;
  if(nodesInLevel == maxNodesInLevel) {
    treeHeight++;
    maxNodesInLevel = maxNodesInLevel*2;
    nodesInLevel = 0;
    std::cout <<"incrementing tree height. Current height: " <<treeHeight <<std::endl;
  }
  treeRoot = Merge(new Node(key), treeRoot);
}

Node* MinSkewHeap::RecMerge(Node* h1, Node* h2) {
  if (h1->getLeftChild() == nullptr) {
    h1->setLeftChild(h2);
  }
  else {
    h1->setRightChild(Merge(h1->getRightChild(), h2));
    if ((h1->getLeftChild())->getRank() < (h1->getRightChild())->getRank()) {
      Node * temp = h1->getLeftChild();
      h1->setLeftChild(h1->getRightChild());
      h1->setRightChild(temp);
    }
    h1->ComputeRank();
    }
  return(h1);
}

Node* MinSkewHeap::Merge(Node* h1, Node* h2) {
  if (h1 == nullptr) {
    return(h2);
  }
  if (h2 == nullptr) {
    return(h1);
  }
  // std::cout <<"H1 and H2 are not null\n";
  if (h1->getKey() < h2->getKey())
    return(RecMerge(h1, h2));
  else
    return(RecMerge(h2, h1));
}

bool MinSkewHeap::Delete(int value, Node* root) {
  // Node * tempNode = treeRoot;
  // treeRoot = Merge(tempNode->getLeftChild(), tempNode->getRightChild());
  // delete(tempNode);
}


bool MinSkewHeap::Find(int value, Node* root) {
  //Value Found - Base Case
  if(treeRoot != nullptr) {
      if(root->getKey() == value) {
        return(true);
      }
    }

  //Root has 2 children
  if(root->getLeftChild() != nullptr && root->getRightChild() != nullptr) {
    if(Find(value, root->getLeftChild())) {
      return(true);
    }
    else if(Find(value, root->getRightChild())) {
      return(true);
    }
    else {
      return(false);
    }
  }
  //Root has left child
  else if(root->getLeftChild() != nullptr) {
    return(Find(value, root->getLeftChild()));
  }
  //Root has right child
  else if(root->getRightChild() != nullptr) {
    return(Find(value, root->getRightChild()));
  }
  //Root has no children
  else {
    return(false);
  }
}

void MinSkewHeap::RecPrintPreorder(Node* root) {
  if(treeRoot != nullptr) {
      std::cout <<root->getKey() << ", ";
      if(root->getLeftChild() != nullptr) {
        RecPrintInorder(root->getLeftChild());
      }
      if(root->getRightChild() != nullptr) {
        RecPrintInorder(root->getRightChild());
      }
    }
}

void MinSkewHeap::RecPrintPostorder(Node* root) {
  if(treeRoot != nullptr) {
      if(root->getLeftChild() != nullptr) {
        RecPrintInorder(root->getLeftChild());
      }
      if(root->getRightChild() != nullptr) {
        RecPrintInorder(root->getRightChild());
      }
      std::cout <<root->getKey() << ", ";
    }
}

void MinSkewHeap::RecPrintInorder(Node* root) {
  if(treeRoot != nullptr) {
    if(root->getLeftChild() != nullptr) {
      RecPrintInorder(root->getLeftChild());
    }
    std::cout <<root->getKey() << ", ";
    if(root->getRightChild() != nullptr) {
      RecPrintInorder(root->getRightChild());
    }
  }
}

void MinSkewHeap::RecPrintLevelorder(Node* root, int level) {
  if(!isEmpty()) {
    if(treeHeight == 1) {
      std::cout <<root->getKey() <<", ";
    }
    else {
      level--;
      RecPrintLevelorder(root->getLeftChild(), level);
      RecPrintLevelorder(root->getRightChild(), level);
    }
  }
}

void MinSkewHeap::Levelorder() {
  for(int lcv = 1; lcv < treeHeight; lcv++) {
    RecPrintLevelorder(treeRoot, lcv);
  }
}
