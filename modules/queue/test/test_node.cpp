// Copyright 2021 Tkachev Alexey

#include <gtest/gtest.h>

#include "include/node.h"

TEST(node_test, empty_node_creation) {
    ASSERT_NO_THROW(new Node());
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

    ASSERT_EQ(5.0, node->getData());
}

TEST(node_test, node_get_next) {
    Node* node = new Node();

    ASSERT_EQ(nullptr, node->getNext());
}

TEST(node_test, node_set_next_nullptr) {
    Node* node = new Node();

    ASSERT_NO_THROW(node->setNext(nullptr));
}

TEST(node_test, node_operator_equals_both_similar) {
    Node* node_1 = new Node();

    ASSERT_NO_THROW(Node* node_2 = node_1);
}

TEST(node_test, operator_equals_both_similar_get_data) {
    Node* node_1 = new Node();
    node_1->setDada(25.5);

    Node* node_2(node_1);
    node_2->setDada(25.5);

    ASSERT_EQ(node_1->getData(), node_2->getData());
}

TEST(node_test, not_empty_copy_not_empty_get_data) {
    Node* node_1 = new Node();
    node_1->setDada(345.3);

    Node* node_2 = new Node();
    node_2->setDada(234.1);

    node_1 = node_2;

    ASSERT_EQ(node_2->getData(), node_1->getData());
}

