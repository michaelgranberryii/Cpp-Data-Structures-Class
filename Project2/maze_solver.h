// Michael Granberry
// Project 2

#include <iostream>
#include "maze.h"
#include "stack.h"

#ifndef MAZE_SOLVER_H_
#define MAZE_SOLVER_H_

class MazeSolver {
public:
  MazeSolver(Maze* maze) {
    this->maze = maze;
  }

  // returns true if end symbol 'T' is reachable from start symbol 'S'
  // returns false otherwise
  //
  bool solve() { // DO NOT CHANGE THE INTERFACE FOR SOLVE()


    this->maze->draw(); // draws the maze to console
                        // see project1.pdf and maze.h for settings

    //  ==================================================== YOUR CODE HERE ================================
    // you may also need to add your own helper functions
      
      start_pair = this->maze->start_pair();
      
      // Push starting pair
      maze_stack.push(start_pair);
      
      // Mark starting pair as visited
      this->maze->mark_as_visited(start_pair);
      
      // If stack is empty, we are done. No Solution.
      if (maze_stack.is_empty()) {
          return false;
      }
      
      while (maze_stack.is_empty() == false) {
          
          Pair curr_pair = maze_stack.pop();
          
          // If goal, then done
          if (this->maze->is_goal(curr_pair)) {
              return true;
          }
          
          // Go west
          Pair west_pair = this->maze->west_of(curr_pair);
          searching(west_pair, &maze_stack);
          
          // Go east
          Pair east_pair = this->maze->east_of(curr_pair);
          searching(east_pair, &maze_stack);
          
          // Go north
          Pair north_pair = this->maze->north_of(curr_pair);
          searching(north_pair, &maze_stack);
          
          // Go south
          Pair south_pair = this->maze->south_of(curr_pair);
          searching(south_pair, &maze_stack);
          
      }
    return false;
  }
    
    void searching (Pair adjacent_pair, Stack *s) {
        if (this->maze->is_free(adjacent_pair) && this->maze->is_goal(adjacent_pair) == false ) {
               this->maze->mark_as_visited(adjacent_pair);
               s->push(adjacent_pair);
           }
           else if (this->maze->is_free(adjacent_pair) && this->maze->is_goal(adjacent_pair) == true) {
               s->push(adjacent_pair);
           }
    }
    
private:
  Maze* maze;
  Stack maze_stack;
  Pair  start_pair;

  // you may also need to add your own variables, such as a stack.
};

#endif // MAZE_SOLVER_H_

