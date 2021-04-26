// Copyright 2021 Tkachev Alexey

#include "include/node.h"

Node::Node(): data(0.0), next(nullptr) {}

Node::~Node() {
    delete this->next;
}

double Node::getData() {
    return this->data;
}

Node* Node::getNext() {
    return this->next;
}

void Node::setDada(double data_) {
    this->data = data_;
}

void Node::setNext(Node* next_) {
    this->next = next_;
}
