#include <iostream>
#include <ctime>

#include "MinSkewHeap.h"

//Constructor
MinSkewHeap::MinSkewHeap() {
  treeRoot = nullptr;
  treeSize = 0;
  treeHeight = 0;
}

//Class Methods
void MinSkewHeap::Build(){

}

void MinSkewHeap::Insert(int key) {
  int oldHeight = treeHeight;

  treeSize++;
  treeRoot = Merge(new Node(key), treeRoot);
  CalculateTree_Height();
  if(!(oldHeight == treeHeight) && oldHeight < treeHeight) {
    std::cout <<"Tree height was incremented to: " <<treeHeight <<std::endl;
  }
}

Node* MinSkewHeap::RecMerge(Node* h1, Node* h2) {
  if (h1->getLeftChild() == nullptr) {
    h1->setLeftChild(h2);
  }
  else {
    h1->setRightChild(Merge(h1->getRightChild(), h2));
    // if ((h1->getLeftChild())->getRank() < (h1->getRightChild())->getRank()) {
      Node * temp = h1->getLeftChild();
      h1->setLeftChild(h1->getRightChild());
      h1->setRightChild(temp);
    // }
    // h1->ComputeRank();
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

bool MinSkewHeap::Delete(int value, Node* child, Node* parent) {
  //Value Found - Base Case
  if(child != nullptr) {
      if(child->getKey() == value) {
        Node * tempNode = treeRoot;
        treeRoot = Merge(tempNode->getLeftChild(), tempNode->getRightChild());
        delete(tempNode);

        bool isRightChild = false;
        Node* leftC = parent->getLeftChild();
        Node* rightC = parent->getRightChild();

        //Find out which child has value
        //Parent Node has both children
        if(leftC != nullptr && rightC != nullptr) {
          if(leftC->getKey() == value) {
            isRightChild = false;
          }
          else if(rightC->getKey() == value) {
            isRightChild = true;
          }
          else {
            std::cout <<"Error: Both children do not contain searched value as their key.\n";
          }
        }
        //Use Right Child
        else if(leftC == nullptr) {
          isRightChild = true;
        }
        //Use Left Child
        else if (rightC == nullptr) {
          isRightChild = false;
        }
        //Should never happen
        else {
          std::cout <<"Error: Delete called on parent with no children\n";
        }

        //Start replacing nodes and deleting found value
        if(isRightChild) {
          Node * tempChildNode = parent->getRightChild();
          Node * tempChildLeftNode = tempChildNode -> getLeftChild();
          Node * tempChildRightNode = tempChildNode -> getRightChild();
          Node * mergedChildren = nullptr;

          //Set Parent Child to null
          parent->setRightChild(nullptr);

          //Merge the two children of the node being deleted
          mergedChildren = Merge(tempChildLeftNode, tempChildRightNode);

          //Delete the child node of Parent
          delete child;

          //Merge Parent with merged children
          treeRoot = Merge(treeRoot, mergedChildren);
      }
      else {
        Node * tempChildNode = parent->getLeftChild();
        Node * tempChildLeftNode = tempChildNode -> getLeftChild();
        Node * tempChildRightNode = tempChildNode -> getRightChild();
        Node * mergedChildren = nullptr;

        //Set Parent Child to null
        parent->setLeftChild(nullptr);

        //Merge the two children of the node being deleted
        mergedChildren = Merge(tempChildLeftNode, tempChildRightNode);

        //Delete the child node of Parent
        delete child;

        //Merge Parent with merged children
        treeRoot = Merge(treeRoot, mergedChildren);
      }
      return(true);
    }
  }

  //Root has left child
  if(Delete(value, child->getLeftChild(), child)) {
    return(true);
  }
  //Root has right child
  else if(Delete(value, child->getRightChild(), child)) {
    return(true);
  }
  //Root has no children
  else {
    return(false);
  }
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
    // std::cout << "RecLO, level " <<level <<": ";

    if(level == 1) {
      std::cout <<root->getKey() <<", ";
    }
    else {
      level--;
      if(root->getLeftChild() != nullptr) {
        RecPrintLevelorder(root->getLeftChild(), level);
      }
      if(root->getRightChild() != nullptr) {
        RecPrintLevelorder(root->getRightChild(), level);
      }
    }
  }
}

void MinSkewHeap::Levelorder() {

  for(int lcv = 1; lcv <= treeHeight; lcv++) {
    RecPrintLevelorder(treeRoot, lcv);
  }
}

int MinSkewHeap::RecCalculateTree_Height(int level, Node* root) {
  if(root != nullptr) {
    if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
      return(level);
    }
    // std::cout <<"Increasing level: " <<level <<" to: " <<level+1 <<std::endl;
    level++;
    //Return right child length
    if(root->getLeftChild() == nullptr) {
      return(RecCalculateTree_Height(level, root->getRightChild()));
    }
    //Return left childs lenght
    else if(root->getRightChild() == nullptr) {
      return(RecCalculateTree_Height(level, root->getLeftChild()));
    }
    //Compare both childs lengths
    else if(RecCalculateTree_Height(level, root->getLeftChild()) > RecCalculateTree_Height(level, root->getRightChild())) {
      return(RecCalculateTree_Height(level, root->getLeftChild()));
    }
    else if(RecCalculateTree_Height(level, root->getLeftChild()) <= RecCalculateTree_Height(level, root->getRightChild())) {
      return(RecCalculateTree_Height(level, root->getLeftChild()));
    }
    else {
      std::cout << "ERROR: RecCalculateTree_Height entered non intended section of recursive definition.\n";
    }
  }
}

void MinSkewHeap::CalculateTree_Height() {
  treeHeight = RecCalculateTree_Height(1, treeRoot);
}
