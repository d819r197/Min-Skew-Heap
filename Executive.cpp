#include <iostream>
#include <string>
#include <fstream>

#include "MinSkewHeap.h"
#include "Executive.h"

#define MAXINPUT 9

Executive::Executive(std::string path) {
  msHeap = new MinSkewHeap();
  filePath = path;
}

int Executive::menuInput() {
  int choice;

  std::cout << "Please choose one of the following commands: \n";
  std::cout << "1. Insert \n";
  std::cout << "2. Merge \n";
  std::cout << "3. Delete \n";
  std::cout << "4. Find \n";
  std::cout << "5. Preorder \n";
  std::cout << "6. Inorder \n";
  std::cout << "7. Postorder \n";
  std::cout << "8. Levelorder \n";
  std::cout << "9. Exit \n";

  std::cout << ">> ";
  std::cin >> choice;
  std::cout << std::endl;

  return(choice);
}

void Executive::run() {
  bool quit = false;
  while(!quit) {
    switch (menuInput()) {
      //Insert - TODO
      case 1: {
        int input;
        std::cout << "Please enter the value which you want to enter into the Min-Left Heap: ";
        std::cin >> input;
        msHeap->Insert(input);
        std::cout << "Output: ";

        break;
      }
      //Merge - TODO
      case 2: {
        std::cout << "Output: ";

        break;
      }
      //Delete - TODO
      case 3: {
        std::cout << "Output: ";
        if(msHeap->isEmpty()) {
          std::cout << "Empty tree, no element to delete\n.";
        }
        else {
          // msHeap->Delete();
          // std::cout <<"Min element has been removed from the tree.\n";
        }
        break;
      }
      //Find - Complete
      case 4: {
        std::cout << "Output: ";
        if(msHeap->isEmpty()) {
          std::cout << "Empty tree, no element to find\n.";
        }
        else {
          int input;
          std::cout << "Enter the element to be found: ";
          std::cin >> input;
          std::cout << std::endl;
          if(msHeap->Find(input, msHeap->GetTree_Root())) {
            std::cout <<"The Element: " <<input <<" was found in Min-Skew Heap\n";
          }
          else {
            std::cout <<"The Element: " <<input <<" was not found in Min-Skew Heap\n";
          }
        }
        break;
      }
      //Preorder - Complete
      case 5: {
        std::cout <<"Output: ";
        if(msHeap->isEmpty()) {
          std::cout << "Empty tree, no traversal shown.\n.";
        }
        else {
          std::cout <<"Preorder traversal: ";
          msHeap->Preorder();
          std::cout << std::endl;
        }
        break;
      }
      //Inorder - Complete
      case 6: {
        std::cout <<"Output: ";
        if(msHeap->isEmpty()) {
          std::cout << "Empty tree, no traversal shown.\n.";
        }
        else {
          std::cout <<"Inorder traversal: ";
          msHeap->Inorder();
          std::cout << std::endl;
        }
        break;
      }
      //Postorder - Complete
      case 7: {
        std::cout <<"Output: ";
        if(msHeap->isEmpty()) {
          std::cout << "Empty tree, no traversal shown.\n.";
        }
        else {
          std::cout <<"Postorder traversal: ";
          msHeap->Postorder();
          std::cout << std::endl;
        }
        break;
      }
      //Levelorder - Complete
      case 8: {
        std::cout <<"Output: ";
        if(msHeap->isEmpty()) {
          std::cout << "Empty tree, no traversal shown.\n.";
        }
        else {
          std::cout <<"Levelorder traversal: ";
          msHeap->Levelorder();
          std::cout << std::endl;
        }
        break;
      }
      //Exit
      case 9: {
        std::cout <<"Output: Bye!!!\n";
        quit = true;
        break;
      }
      //Invalid Input
      default: {
          std::cout << "Please input a number between 1 and " <<MAXINPUT <<".\n\n";
          break;
      }
    }
  }
}

bool Executive::parseInputFile() {
  // pq = *msHeap;
  std::ifstream inputFile(filePath);
  std::string input;
  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ' && c != '\n') {
        input += c;
        // std::cout <<"current input: " <<input <<std::endl;
      }
      else {
        // std::cout << "In loop, inserting: " <<input <<" into pq of size: " <<msHeap->GetHeap_Size() <<std::endl;
        int strInt = std::stoi(input);
        msHeap->Insert(strInt);
        // msHeap->PrintHeap();
        input = "";
      }
    }
    inputFile.close();
    return(true);
  }
  else {
    std::cout << "File Path: " <<filePath <<" is an invalid path.\n";
    return(false);
  }
}
