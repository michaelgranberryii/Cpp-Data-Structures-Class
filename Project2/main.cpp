#include <iostream>
#include "maze.h"
#include "maze_solver.h"

using namespace std;

// 'S' means start
// 'T' means end
// '#' means wall
// ' ' means an open space

void check(Maze *maze, int sol) {
  MazeSolver solver(maze);
  bool answer = solver.solve();
  cout << "====================" << endl;
  cout << "S and T are " << (sol ? "" : "not ") << "connected." << endl;
  cout << "solver says " << ( answer ? "" : "not ") << "connected." << endl;
  cout << "solver is " << ( answer==sol ? "correct" : "WRONG") << endl;
}

void test1() {
  Maze maze(5,"S    "
              "#### "
              "     "
              " ####"
              "    T");
  bool sol = true;
  check(&maze,sol);
}

void test2() {
  Maze maze(1,"S");
  bool sol = false;
  check(&maze,sol);

}

void test3() {
  Maze maze(7,"S     #"
              " #  #  "
              " #  # #"
              " #  #  "
              " # # ##"
              " #     "
              "#T#    ");
  bool sol = false;
  check(&maze,sol);
}

void test4() {
  Maze maze(10,"S   #     "
               "    #   T "
               "    #     "
               "    #     "
               "          "
               "          "
               "          "
               "          "
               "          "
               "          ");
  bool sol = true;
  check(&maze,sol);
}

int main() {
  test1();
  test2();
  test3();
  test4();
}
