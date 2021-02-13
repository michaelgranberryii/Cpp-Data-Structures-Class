#include <iostream>
#include <ctime>
#include <cstdlib>
#include "sorter.h"
#include "bucket_sorter.h"

template <typename T>
void test(Sorter<T> &sorter, bool print_list = false) {
  std::cout << "========================================" << std::endl;
  if (print_list) {
    std::cout << "list: ";
    sorter.print();
  }
  std::cout << "is sorted? " << (sorter.is_sorted()?"yes":"no") << std::endl;
  std::cout << "sorting " << sorter.size() << " elements using " << sorter.name() << " ..." << std::endl;
  std::clock_t start_time = std::clock();
  sorter.sort();
  double sort_time = (std::clock()-start_time)/(double)CLOCKS_PER_SEC;
  if (print_list) {
    std::cout << "list: ";
    sorter.print();
  }
  std::cout << "is sorted? " << (sorter.is_sorted()?"yes":"no") << std::endl;
  std::cout<<"sort time: "<< sort_time << " seconds" << std::endl;
}

void test_1a() {
  int list[] = {3,5,1,2,4};
  InsertionSorter<int> sorter(list,5);
  test(sorter,true);
}

void test_1b() {
  int list[] = {3,5,1,2,4};
  QuickSorter<int> sorter(list,5);
  test(sorter,true);
}


//========BucketSort=========
void test_1c() {
  int list[] = {3,5,1,2,4};
  BucketSorter sorter(list,5);
  test(sorter,true);
}

void test_2a() {
  std::string list[] = {std::string("three"),
                        std::string("five"),
                        std::string("one"),
                        std::string("two"),
                        std::string("four")};
  InsertionSorter<std::string> sorter(list,5);
  test(sorter,true);
}

void test_2b() {
  std::string list[] = {std::string("three"),
                        std::string("five"),
                        std::string("one"),
                        std::string("two"),
                        std::string("four")};
  QuickSorter<std::string> sorter(list,5);
  test(sorter,true);
}

void test_3a() {
  int length = 1e5; // 2x10^5 = 200,000
  int max = 100;
  int list[length];
  std::srand(0); // random number seed
  for (int i = 0; i < length; i++)
    list[i] = std::rand() % max;
  InsertionSorter<int> sorter(list,length);
  test(sorter);
}

void test_3b() {
  int length = 1e5; // 2x10^5 = 200,000
  int max = 100;
  int list[length];
  std::srand(0); // random number seed
  for (int i = 0; i < length; i++)
    list[i] = std::rand() % max;
  QuickSorter<int> sorter(list,length);
  test(sorter);
}

//========BucketSort=========
void test_3c() {
  int length = 1e5; // 2x10^5 = 200,000
  int max = 100;
  int list[length];
  std::srand(0); // random number seed
  for (int i = 0; i < length; i++)
    list[i] = std::rand() % max;
  BucketSorter sorter(list,length);
  test(sorter);
}

void test_4b() {
  int length = 5e5; // 5x10^5 = 500,000
  int max = 10;
  int list[length];
  std::srand(0); // random number seed
  for (int i = 0; i < length; i++)
    list[i] = std::rand() % max;
  QuickSorter<int> sorter(list,length);
  test(sorter);
}

//========BucketSort=========
void test_4c() {
  int length = 5e5; // 5x10^5 = 500,000
  int max = 10;
  int list[length];
  std::srand(0); // random number seed
  for (int i = 0; i < length; i++)
    list[i] = std::rand() % max;
  BucketSorter sorter(list,length);
  test(sorter);
}

int main() {
  std::cout << "%% test sorting integers" << std::endl;
  test_1a();
  test_1b();
  test_1c();// BucketSort
  std::cout << "%% test sorting strings" << std::endl;
  test_2a();
  test_2b();
  std::cout << "%% test sorting a lot of integers" << std::endl;
  std::cout << "%% insertion sort should be slow!" << std::endl;
  test_3a();
  test_3b();
  test_3c(); // BucketSort
  std::cout << "%% test sorting even more integers" << std::endl;
  std::cout << "%% quick sort should be slow!" << std::endl;
  test_4b();
  test_4c(); // BucketSort
}
