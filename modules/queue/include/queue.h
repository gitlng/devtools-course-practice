// // Copyright 2021 Tkachev Alexey

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

#include <cstdio>
#include <string>

class Queue {
 public:
    struct Node {
        double data = 0.0;
        Node* next = nullptr;
    };
    Queue();
    ~Queue();
    bool isEmpty() const;
    void append(double data);
    void removeFirst();
    double getFirstData() const;
    double getLastData() const;
    unsigned int getSize() const;
    std::string toStringData() const;
    bool isTheSameData(const Queue* other) const;
    Queue& operator=(const Queue& other);

 private:
    Node* first;
    Node* last;
};

#endif  // MODULES_QUEUE_INCLUDE_QUEUE_H_
