#include <iostream>
#include <sstream>

#ifndef MAZE_H_
#define MAZE_H_

// settings to control animation
#define VISUAL true  // set to false to turn off animation
#define CLEAR true   // set to false to not clear each time
#define DELAY 500    // make delay (ms) smaller to speed up animation

#ifdef __linux__
// this code block is used for compiling in linux
#include <unistd.h>
void clear_screen() { if(CLEAR) system("clear"); } // hack
void sleep() { usleep(1000*DELAY); }
//void sleep() { std::cin.get(); }
#elif __APPLE__
// this code block is used for compiling in mac
#include <unistd.h>
void clear_screen() { if(CLEAR) system("clear"); } // hack
void sleep() { usleep(1000*DELAY); }
//void sleep() { std::cin.get(); }
#else
// this code block is used for compiling in windows
#include <Windows.h>
void clear_screen() { if(CLEAR) system("CLS"); } // hack
void sleep() { Sleep(DELAY); }
//void sleep() { std::cin.get(); }
#endif

// you can redefine these to make better ASCII art
#define CORNER '+'
#define V_WALL '|'
#define H_WALL '-'
#define ST 'S' // STart
#define GO 'T' // GOal
#define WA '#' // WAll
#define SP ' ' // SPace
#define VI 'X' // VIsited

// This class holds grid coordinates for the maze
class Pair {
public:
  Pair() { // default constructor (error pair)
    this->i = this->j = -1;
  }
  Pair(int i, int j) {
    this->i = i;
    this->j = j;
  }
  Pair(const Pair& pair) {
    this->i = pair.i;
    this->j = pair.j;
  }
  int i,j;
};

// for using Pair objects with std::cout
// (an example of operator overloading)
std::ostream& operator<<(std::ostream& os, const Pair& pair) {
    return os << "(" << pair.i << "," << pair.j << ")";
}

// This class represents an n-by-n grid maze
//
// An example maze specification:
// int n = 5;
// std::string maze =
// "S    "
// "#### "
// "     "
// " ####"
// "    T";
// Note that the above string has no new lines.
// The compiler concatenates all of the above strings.
//
// 'S' means start
// 'T' means end
// '#' means wall
// ' ' means an open space
// 'X' means marked (used internally, not in input)
// no other characters should appear---and no new lines!

class Maze {
public:
  Maze(int n, std::string spec) {
    this->n = n;
    // check spec length
    if (spec.length() != n*n)
      error("specification length does not match expected length");
    // allocate space
    this->grid = (char**)malloc(n*sizeof(char*));
    for (int i = 0; i < n; i++)
      this->grid[i] = (char*)malloc(n*sizeof(char));
    // copy spec into grid
    bool start_found = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char c = spec.at(i*n + j); // index in string
        if ( c == SP || c == ST || c == GO || c == WA )
          this->grid[i][j] = c;
        else
          error("unexpected character in spec.");
        if (c == ST) {
          if (start_found)
            error("more than one start symbol found.");
          this->start = Pair(i,j);
          start_found = true;
        }
      }
    }
    if (!start_found)
      error("no start symbol.");
  }

  ~Maze() {
    for (int i = 0; i < n; i++)
      free(this->grid[i]);
    free(this->grid);
  }

  Pair start_pair() {
    return this->start;
  }

  // given an input pair, mark the grid cell by 'X'
  void mark_as_visited(Pair pair) {
    this->grid[pair.i][pair.j] = VI;
  }

  // returns true if grid cell is a goal state
  bool is_goal(Pair pair) {
    return this->grid[pair.i][pair.j] == GO;
  }

  // returns true if grid cell is free to move into (not a wall, and
  // not already visited). otherwise returns false
  bool is_free(Pair pair) {
    return (0 <= pair.i && pair.i < this->n) &&
           (0 <= pair.j && pair.j < this->n) &&
           (this->grid[pair.i][pair.j] != WA) &&
           (this->grid[pair.i][pair.j] != VI);
  }

  // the following four functions return a new Pair object that is one
  // step above (north), below (south), to the right (east), or to the
  // left (west), of the given Pair
  Pair north_of(Pair pair) { return Pair(pair.i-1,pair.j); }
  Pair south_of(Pair pair) { return Pair(pair.i+1,pair.j); }
  Pair east_of(Pair pair) { return Pair(pair.i,pair.j+1); }
  Pair west_of(Pair pair) { return Pair(pair.i,pair.j-1); }

  // gives operator<< access to private
  friend std::ostream& operator<<(std::ostream& os, const Maze& maze);

  // draw the maze on console screen if the line
  //   #define VISUAL true
  // appears at the top of ACACAC
  void draw() {
    if (VISUAL) {
      clear_screen();
      std::cout << *this << std::endl;
      sleep();
    }
  }

private:
  Pair start;  // starting location
  int n;       // dimension of grid
  char** grid; // n-by-n grid

  // helper for printing error messages
  void error(const char* message) {
    std::cerr << "error: " << message << std::endl;
    exit(1); // program returns 1 on error
  }
};

// for using Maze objects with std::cout
// pretty-print the maze (basically just a border)
// (an example of operator overloading)
std::ostream& operator<<(std::ostream& os, const Maze& maze) {
  // print top wall
  os << CORNER;
  for (int a = 0; a < maze.n; a++)
    os << H_WALL;
  os << CORNER << std::endl;
  // print map
  for (int i = 0; i < maze.n; i++) {
    os << V_WALL;
    for (int j = 0; j < maze.n; j++)
      os << maze.grid[i][j];
    os << V_WALL << std::endl;
  }
  // print bottom wall
  os << CORNER;
  for (int a = 0; a < maze.n; a++)
    os << H_WALL;
  os << CORNER;
  return os;
}

#endif // MAZE_H_
