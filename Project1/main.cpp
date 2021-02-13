#include <iostream>
#include <string>
#include "linefam.h"

void test1() {
  std::string expected =
    "amy pete joe mike \n"
    "amy pete joe mike \n"
    "amy pete joe mike \n"
    "amy pete joe mike \n";

  std::cout << "=== Expected:\n" << expected;
  std::cout << "=== Result:\n";

  Person amy("amy");
  Person pete("pete");
  Person joe("joe");
  Person mike("mike");

  pete.insertParent(&amy);
  pete.insertChild(&joe);
  joe.insertChild(&mike);

  amy.printAncestors();
  std::cout << amy.getName() << " ";
  amy.printDescendants();
  std::cout << std::endl;

  pete.printAncestors();
  std::cout << pete.getName() << " ";
  pete.printDescendants();
  std::cout << std::endl;

  joe.printAncestors();
  std::cout << joe.getName() << " ";
  joe.printDescendants();
  std::cout << std::endl;

  mike.printAncestors();
  std::cout << mike.getName() << " ";
  mike.printDescendants();
  std::cout << std::endl;
}


void test2() {
  std::string expected =
    "amy is an ancestor of mike\n"
    "amy is not a descendant of mike\n"
    "mike is not an ancestor of mike\n"
    "amy is not an ancestor of amy\n"
    "mike is not a descendant of mike\n"
    "amy is not a descendant of amy\n"
    "pete is an ancestor of joe\n"
    "pete is not a descendant of joe\n"
    "joe is not an ancestor of pete\n"
    "joe is a descendant of pete\n";

  std::cout << "=== Expected:\n" << expected;
  std::cout << "=== Result:\n";

  Person amy("amy");
  Person pete("pete");
  Person joe("joe");
  Person mike("mike");

  pete.insertParent(&amy);
  pete.insertChild(&joe);
  joe.insertChild(&mike);

  std::cout << "amy is ";
  std::cout << ( mike.hasAncestor("amy") ? "" : "not " );
  std::cout << "an ancestor of mike" << std::endl;

  std::cout << "amy is ";
  std::cout << ( mike.hasDescendant("amy") ? "" : "not " );
  std::cout << "a descendant of mike" << std::endl;

  std::cout << "mike is ";
  std::cout << ( mike.hasAncestor("mike") ? "" : "not " );
  std::cout << "an ancestor of mike" << std::endl;

  std::cout << "amy is ";
  std::cout << ( amy.hasAncestor("amy") ? "" : "not " );
  std::cout << "an ancestor of amy" << std::endl;

  std::cout << "mike is ";
  std::cout << ( mike.hasDescendant("mike") ? "" : "not " );
  std::cout << "a descendant of mike" << std::endl;

  std::cout << "amy is ";
  std::cout << ( amy.hasDescendant("amy") ? "" : "not " );
  std::cout << "a descendant of amy" << std::endl;

  std::cout << "pete is ";
  std::cout << ( joe.hasAncestor("pete") ? "" : "not " );
  std::cout << "an ancestor of joe" << std::endl;

  std::cout << "pete is ";
  std::cout << ( joe.hasDescendant("pete") ? "" : "not " );
  std::cout << "a descendant of joe" << std::endl;

  std::cout << "joe is ";
  std::cout << ( pete.hasAncestor("joe") ? "" : "not " );
  std::cout << "an ancestor of pete" << std::endl;

  std::cout << "joe is ";
  std::cout << ( pete.hasDescendant("joe") ? "" : "not " );
  std::cout << "a descendant of pete" << std::endl;
 
}

int main() {
    std::cout << "test1(): " << std::endl;
    test1();
    
    std::cout << std::endl;
    
    std::cout << "test2(): " << std::endl;
    test2();
}
