// Copyright 2021 NNTU-CS
template<typename T>
class TPQueue {
private:
  struct Node {
    T data;
    Node* next;
    Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
  };
  
  Node* head;
  Node* tail;
  int size;

public:
  TPQueue() : head(nullptr), tail(nullptr), size(0) {}
  
  ~TPQueue() {
    while (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  void push(const T& item) {
    Node* newNode = new Node(item);
    
    if (head == nullptr || item.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
      if (tail == nullptr) {
        tail = head;
      }
      size++;
      return;
    }
    
    Node* current = head;
    while (current->next != nullptr && current->next->data.prior >= item.prior) {
      current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    if (newNode->next == nullptr) {
      tail = newNode;
    }
    
    size++;
  }

  T pop() {
    if (head == nullptr) {
      throw std::runtime_error("Queue is empty");
    }
    
    Node* temp = head;
    T data = head->data;
    head = head->next;
    
    if (head == nullptr) {
      tail = nullptr;
    }
    
    delete temp;
    size--;
    return data;
  }

  bool isEmpty() const {
    return head == nullptr;
  }

  int getSize() const {
    return size;
  }
};
