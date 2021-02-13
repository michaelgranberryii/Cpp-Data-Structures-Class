#include <iostream>

#ifndef SORTER_H_
#define SORTER_H_

template <typename T>
class Sorter {
public:
  Sorter() {}
  Sorter(T* list, int length) {
    this->list = list;
    this->length = length;
  }
  virtual ~Sorter() { }

  virtual void sort() = 0;        // sorts this->list inplace
  virtual std::string name() = 0; // returns name of the sorting algorithm

  void print() const {
    // print the contents of the list
    for(int i = 0; i < length; i++)
      std::cout << list[i] << " ";
    std::cout << std::endl;
  }

  int size() const {
    return this->length;
  }

  bool is_sorted() const {
    // returns true if the list is sorted, returns false otherwise
    bool sorted = true;
    for (int i = 0; i < this->length-1; i++)
      if (this->list[i] > this->list[i+1]) {
        sorted = false;
        break;
      }
    return sorted;
  }

protected:
  T* list;
  int length;
};

template <typename T>
class InsertionSorter: public Sorter<T> {
public:
  InsertionSorter(T* list, int length) : Sorter<T>::Sorter(list,length) {}

  virtual void sort() {
    // sort the list using insertion sort
    for (int i = 1; i < this->length; i++) {
      int j;
      T value = this->list[i];
      for (j = i-1; j >= 0; j--) {
        if (this->list[j] > value)
          this->list[j+1] = this->list[j];
        else
          break;
      }
      this->list[j+1] = value;
    }
  }

  virtual std::string name() {
    // returns name of the sorting algorithm
    return std::string("insertion sort");
  }

};

template <typename T>
class QuickSorter: public Sorter<T> {
public:
  QuickSorter(T* list, int length) : Sorter<T>::Sorter(list,length) {}

  virtual void sort() {
    sort(this->list,this->length);
  }

  virtual void sort(T* a, int length) {
    // sort the list using quick sort
    if (length <= 1) return;
    int lo_length = partition(a,length);
    sort(a,lo_length-1);
    sort(a+lo_length,length-lo_length);
  }

  virtual std::string name() {
    // returns name of the sorting algorithm
    return std::string("quick sort");
  }

private:
  void swap(T &i, T &j) {
    T k = i;
    i = j;
    j = k;
  }

  int partition(T* a, int length) {
    int lo = 1, hi = length-1;
    T pivot = a[0];
    while (lo < hi) {
      while (lo <= hi && a[lo] <= pivot)
        lo++;
      while (a[hi] > pivot)
        hi--;
      if (lo < hi)
        swap(a[lo],a[hi]);
    }
    swap(a[0],a[hi]);
    return lo;
  }

};

#endif // SORTER_H_
