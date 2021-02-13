#include <iostream>
#include "maze.h" // for Pair

#ifndef STACK_H_
#define STACK_H_

#define MAX_STACK_SIZE 1024
#define STACK_WIDTH 5 // assuming single digit pair members

class Stack {
public:
  Stack() {
    this->head = 0; // first empty slot
  }

  ~Stack() {
  }

  // returns true if stack is empty, and false otherwise
  bool is_empty() {
    return this->head == 0;
  }

  // pushes pair on top of the stack
  void push(const Pair pair) {
    if (this->head >= MAX_STACK_SIZE) {
      std::cerr << "warning: stack is full" << std::endl;
      return;
    }
    this->stack[this->head] = pair;
    this->head++;
  }

  // pops the top pair off of the stack and returns it.
  // returns a special pair (-1,-1) if the stack is empty
  Pair pop() {
    if (this->head == 0)
      return Pair(); // error pair
    else {
      Pair pair = this->stack[this->head-1];
      this->head--;
      return pair;
    }
  }

  // pretty-print's a stack (assumes pairs are composed of single
  // digit numbers).
  void print() {
    // print a top of the stack
    std::cout << "|";
    for (int i = 0; i < STACK_WIDTH; i++)
      std::cout << " ";
    std::cout << "|" << std::endl;

    // print the contents of the stack
    for (int i = this->head-1; i >= 0; i--)
      std::cout << "|" << this->stack[i] << "|" << std::endl;

    // print a bottom of the stack
    std::cout << "+";
    for (int i = 0; i < STACK_WIDTH; i++)
      std::cout << "-";
    std::cout << "+" << std::endl;
  }

private:
  int head;
  Pair stack[MAX_STACK_SIZE];
};

#endif // STACK_H_
