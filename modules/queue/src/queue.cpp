// Copyright 2021 Tkachev Alexey

#include <string>
#include <iostream>

#include "include/Queue.h"


Queue::Queue(): last(nullptr), first(last) {}

Queue::~Queue() {
    delete(first);
}
bool Queue::isEmpty() const {
    return (this->last == nullptr);
}

double Queue::getLastData() const {
    return this->last->data;
}

void Queue::append(double data) {
    Node* new_node = new Node();
    new_node->data = data;

    if (this->isEmpty()) {
        this->first = this->last = new_node;
    } else {
        this->last->next = new_node;
        this->last = new_node;
    }
}

double Queue::getFirstData() const {
    if (this->isEmpty()) {
        throw std::exception("The queue is empty!");
    }
    return this->first->data;
}

void Queue::removeFirst() {
    if (this->first == nullptr) {
        throw std::exception("The queue is empty!");
    }

    Node* new_first = this->first;
    this->first = first->next;

    if (this->first == nullptr) {
        this->last = nullptr;
    }

    delete(new_first);
}


bool Queue::isTheSameData(const Queue* other) const {
    return this->toStringData() == other->toStringData();
}

Queue& Queue::operator=(const Queue& other) {
    if (this == &other) {
        return *this;
    } else {
        if (!this->isEmpty() || other.isEmpty()) {
            this->~Queue();
        }

        this->first = new Node(*(other.first));

        Node* other_first = other.first;
        Node* other_first_next = other.first->next;

        Node* this_first = this->first;

        while (other_first_next != nullptr) {
            this_first->next = new Node(*other_first_next);
            this_first = new Node(*other_first_next);
            other_first = other_first_next;
            other_first_next = other_first_next->next;
        }

        this->last = new Node(*other.last);
    }
    return *this;
}

unsigned int Queue::getSize() const {
    unsigned int size = 1;
    Node current = *this->first;

    for (; current.next != nullptr; size++,
        current.next = current.next->next) {}

    return size;
}

std::string Queue::toStringData() const {
    Node current = *this->first;
    std::string string_queue = std::to_string(current.data) + " ";
    while (current.next != nullptr) {
        string_queue += std::to_string(current.next->data) + " ";
        current.next = current.next->next;
    }
    return string_queue;
}
