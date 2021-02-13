// Michael Granberry
// April 11, 2020
// CS20A
// Project 3 - Bucket Sort

#include <iostream>
#include "sorter.h"
#include "linked_list.h"

#ifndef BUCKET_SORTER_H_
#define BUCKET_SORTER_H_

using namespace std;

template <typename T>
void LinkedList<T>::sort() {
  // not needed, but here maybe for extra credit
}

class BucketSorter: public Sorter<int> {
public:
  BucketSorter(int* list, int length, int max = 100) :
    Sorter<int>::Sorter(list,length) {
    this->max = max;
    this->buckets = new LinkedList<int>[max];
  }

  virtual ~BucketSorter() {
    delete[] this->buckets;
  }

  virtual void sort() {
    // sort the list using bucket sort
    // YOUR CODE HERE (and possibly elsewhere in this file)
      
    Node<int>* node_ptr = nullptr;
    LinkedList<int>* bucket_ptr = nullptr;
      
    Iterator<int> itr(node_ptr);
    itr = this->buckets->begin();
      
      for (int i = 0; i < this->length; i++) {
          bucket_ptr = &buckets[this->list[i]]; // Setting ListList pointer to
          bucket_ptr->insert(this->list[i]); // Inserting number in list into it's corresponding bucket
      }
    
      int list_index = 0; //
      
      for (int i = 0; i < max; i++) {
          bucket_ptr = &buckets[i];
          itr = bucket_ptr->begin();
          while (itr != nullptr) {
              for (int j = 0; j < bucket_ptr->length(); j++) {
                  this->list[list_index++] = *(itr)++;
              }
          }
      }
  }

  virtual std::string name() {
    // returns name of the sorting algorithm
    return std::string("bucket sort");
  }

private:
  int max;
  LinkedList<int>* buckets;
};

#endif // BUCKET_SORTER_H_
