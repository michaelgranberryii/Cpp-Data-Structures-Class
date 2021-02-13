// Michael Granberry
// SI: 1353583
// CS20A
// Project 1
// Due Mar 9, 2020

#include <iostream>
#include <string>

#ifndef LINEFAM_H_
#define LINEFAM_H_

class Person {
public:
  Person() {
    this->name = "unnamed";
    this->parent = nullptr;
    this->child = nullptr;
  }

  Person(std::string name) {
    this->name = name;
    this->parent = nullptr;
    this->child = nullptr;
  }

  ~Person() {
      
  }

  std::string getName() {
    return this->name;
  }

  void insertParent(Person* new_parent) {
    // replace parent with new_parent
    if (this->parent != NULL) // If current obj's *parent pointer variable != 0x0, then:
      this->parent->child = NULL; //
    new_parent->child = this;
    this->parent = new_parent;
  }

  void insertChild(Person* new_child) {
    // replace child with new_child
    if (this->child != NULL)
      this->child->parent = NULL;
    new_child->parent = this;
    this->child = new_child;
  }

  void printAncestors() {
    // print ancestors from oldest to youngest
    Person* ptr = this;
    while (ptr->parent != nullptr)
      ptr = ptr->parent;
    while (ptr != this) {
      std::cout << ptr->name << " ";
      ptr = ptr->child;
    }
  }

  void printDescendants() {
    // print descendants from oldest to youngest

    // ==================================================== YOUR CODE HERE ================================
    Person* ptr = this;
    while (ptr->child != nullptr ) {
        ptr = ptr->child;
        std::cout << ptr->name << " ";
      }
  }

  bool hasAncestor(std::string other_name) {
    // returns true if other_name is a parent, grandparent, etc.
    // returns false otherwise
    // the name comparison should be case-sensitive

    //  ==================================================== YOUR CODE HERE ================================
    Person* ptr = this;
    while (ptr->parent != nullptr) {
        ptr = ptr->parent;
        if (ptr->name == other_name) {
            return true;
        }
    }
    return false;
  }

  bool hasDescendant(std::string other_name) {
    // returns true if other is a child, grandchild, etc.
    // returns false otherwise
    // the name comparison should be case-sensitive
      
    //  ==================================================== YOUR CODE HERE ================================
    Person* ptr = this;
    while (ptr->child != nullptr ) {
        ptr = ptr->child;
        if (ptr->name == other_name) {
            return true;
        }
    }
    return false;
  }


private:
  std::string name;
  Person* parent;
  Person* child;
};

#endif // LINEFAM_H_
