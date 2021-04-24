// Copyright 2021 Tkachev Alexey

#include <gtest/gtest.h>

#include "include/node.h"

TEST(node_test, empty_node_creation) {
    ASSERT_NO_THROW(new Node());
}

TEST(node_test, node_copy) {
    Node* node = new Node();

    ASSERT_NO_THROW(new Node(*node));
}

TEST(node_test, node_delete) {
    Node* node = new Node();

    ASSERT_NO_THROW(delete node);
}

TEST(node_test, without_new_init_node) {
    ASSERT_NO_THROW(Node node);
}

TEST(node_test, node_set_get_data) {
    Node *node = new Node();
    node->setDada(5.0);

    ASSERT_EQ(node->getData(), 5.0);
}

TEST(node_test, node_get_next) {
    Node* node = new Node();

    ASSERT_EQ(node->getNext(), nullptr);
}

TEST(node_test, node_set_next_nullptr) {
    Node* node = new Node();

    ASSERT_NO_THROW(node->setNext(nullptr));
}
