// Copyright 2021 Tkachev Alexey

#include "include/node.h"

Node::Node(): data(0.0), next(nullptr) {}

Node::Node(const Node& other) {
    if (this == &other) {
        return;
    }

    delete this;

    this->next = nullptr;
    this->data = other.data;
}

Node::~Node() {
    delete(this->next);
}

double Node::getData() const {
    return this->data;
}

Node* Node::getNext() const {
    return this->next;
}

void Node::setDada(const double& data_) {
    this->data = data_;
}

void Node::setNext(Node* next_) {
    this->next = next_;
}
