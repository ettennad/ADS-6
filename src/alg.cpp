// Copyright 2021 NNTU-CS
#include <stdexcept>

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;
    explicit Node(const T& value, Node* next = nullptr)
      : data(value), next(next) {}
  };
  Node* head;
  Node* tail;

 public:
  TPQueue() : head(nullptr), tail(nullptr) {}
  ~TPQueue() {
    while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  void push(const T& value) {
    Node* newNode = new Node(value);
    if (!head || item.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
      if (!tail) tail = head;
      return;
    }
   Node* current = head;
   while (current->next && 
    current->next->data.prior >= value.prior) {
    current = current->next;
   }
   newNode->next = current->next;
   current->next = newNode;
   if (!newNode->next) {
    tail = newNode;
   }
  }

T pop() {
 if (!head) {
  throw std::runtime_error("Queue is empty");
 }
 Node* temp = head;
 T value = head->data;
 head = head->next;
 if (!head) {
  tail = nullptr;
 }
 delete temp;
 return value;
}
bool isEmpty() const {
 return head == nullptr;
}
};

struct SYM {
char ch;
int prior;
};
