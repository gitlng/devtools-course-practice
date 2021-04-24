// // Copyright 2021 Tkachev Alexey

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

#include <cstdio>
#include <string>

struct Node {
    double data = 0.0;
    Node* next = nullptr;
};

class Queue {
 private:
    Node* first;
    Node* last;

 public:
    Queue();
    ~Queue();
    Queue(const Queue& queue);
    bool isEmpty() const;
    void append(double data);
    void removeFirst();
    double getFirstData() const;
    double getLastData() const;
    unsigned int getSize() const;
    std::string toStringData() const;
    bool isTheSameData(const Queue* other) const;
    Queue& operator=(const Queue& other);
};

#endif  // MODULES_QUEUE_INCLUDE_QUEUE_H_
