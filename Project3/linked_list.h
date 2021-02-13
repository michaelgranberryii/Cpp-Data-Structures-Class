template <typename T>
struct Node {
  T data;
  Node* next;
};

template <typename T>
class Iterator {
public:
  Iterator(const Node<T>* node) {
    this->current = node;
  }

  Iterator& operator=(Node<T>* node) {
    this->current = node;
    return *this;
  }

  Iterator& operator++() { // ++iterator (prefix)
    if (current)
      current = current->next;
    return *this;
  }

  Iterator operator++(T) { // iterator++ (postfix)
    Iterator iterator = *this;
    ++*this;
    return iterator;
  }

  bool operator!=(const Iterator<T>& iterator) {
    return this->current != iterator.current;
  }

  int operator*() {
    return current->data;
  }

private:
  const Node<T>* current;
};

template <typename T>
class LinkedList {
public:
  LinkedList() {
    this->head = nullptr;
    this->_length = 0;
  }

  ~LinkedList() {
    Node<T>* ptr = head;
    Node<T>* next;
    while (ptr != nullptr) {
      next = ptr->next;
      delete ptr;
      ptr = next;
    }
  }

  void insert(T data) {
    // insert data at head of linked list
    Node<T>* node = new Node<T>;
    node->data = data;
    node->next = head;
    this->head = node;
    this->_length++;
  }
    
    //print elements
    void Print () {
        Node<T>* curr_ptr = head;
        while (curr_ptr != nullptr) {
            std::cout << curr_ptr->data << " ";
            curr_ptr = curr_ptr->next;
        }
    }

  int length() {
    // returns the number of elements in the linked list
    return this->_length;
  }

  Iterator<T> begin() {
    // returns an iterator pointing to the head
    return Iterator<T>(this->head);
  }

  Iterator<T> end() {
    // returns an iterator pointing to null
    return Iterator<T>(nullptr);
  }

  void sort(); // sort the linked list

private:
  Node<T>* head;
  int _length;
};
