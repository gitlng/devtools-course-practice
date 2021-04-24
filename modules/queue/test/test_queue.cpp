// Copyright 2021 Tkachev Alexey

#include <gtest/gtest.h>

#include "include/queue.h"

TEST(queue_test, no_exception_during_crearing) {
    ASSERT_NO_THROW(new Queue());
}

TEST(queue_test, get_first_exception) {
    Queue *testing_queue = new Queue();

    ASSERT_ANY_THROW(testing_queue->getFirstData());
}

TEST(queue_test, no_throw_destructor) {
    Queue *testing_queue = new Queue();

    ASSERT_NO_THROW(testing_queue->~Queue(););
}

TEST(queue_test, throw_get_first) {
    Queue *testing_queue = new Queue();

    ASSERT_ANY_THROW(testing_queue->getFirstData());
}

TEST(queue_test, throw_remove_first) {
    Queue *testing_queue = new Queue();

    ASSERT_ANY_THROW(testing_queue->removeFirst());
}

TEST(queue_test, queue_equals_itself) {
    Queue *testing_queue = new Queue();

    ASSERT_NO_THROW(*testing_queue = *testing_queue;);
}

TEST(queue_test, empty_queues_equal) {
    Queue *testing_queue_1 = new Queue();
    Queue *testing_queue_2 = new Queue();

    *testing_queue_1 = *testing_queue_2;

    ASSERT_EQ(testing_queue_1->isTheSameData(testing_queue_2), true);
}

TEST(queue_test, not_empty_queues_equal) {
    Queue *testing_queue_1 = new Queue();
    Queue *testing_queue_2 = new Queue();

    testing_queue_2->append(2.5);
    testing_queue_2->append(3.5);

    *testing_queue_1 = *testing_queue_2;

    ASSERT_EQ(testing_queue_1->isTheSameData(testing_queue_2), true);
}

TEST(queue_test, not_empty_equals_empty) {
    Queue *testing_queue_1 = new Queue();

    testing_queue_1->append(5.2);
    testing_queue_1->append(3.2);

    Queue *testing_queue_2 = new Queue();

    ASSERT_EQ(testing_queue_1->isTheSameData(testing_queue_2), false);
}

TEST(queue_test, empty_equals_not_empty) {
    Queue *testing_queue_1 = new Queue();
    Queue *testing_queue_2 = new Queue();

    testing_queue_2->append(5.2);
    testing_queue_2->append(3.2);

    *testing_queue_1 = *testing_queue_2;

    ASSERT_EQ(testing_queue_1->isTheSameData(testing_queue_2), true);
}

TEST(queue_test, is_empty_true) {
    Queue * testing_queue = new Queue();

    ASSERT_EQ(testing_queue->isEmpty(), true);
}

TEST(queue_test, is_empty_false) {
    Queue* testing_queue = new Queue();
    testing_queue->append(25.5);

    ASSERT_EQ(testing_queue->isEmpty(), false);
}

TEST(queue_test, get_append_expection) {
    Queue* testing_queue = new Queue();

    const double number_to_add = 2.5;

    ASSERT_NO_THROW(testing_queue->append(number_to_add););
}

TEST(queue_test, get_last_expection) {
    Queue* testing_queue = new Queue();

    ASSERT_ANY_THROW(testing_queue->getLastData(););
}

TEST(queue_test, copy_constructor_equal) {
    Queue* testing_queue_1 = new Queue();

    for (size_t i = 0; i < 10; i++) {
        testing_queue_1->append(static_cast<double>(i));
    }

    Queue* testing_queue_2 = new Queue(*testing_queue_1);

    ASSERT_EQ(testing_queue_1->isTheSameData(testing_queue_2), true);
}

TEST(queue_test, operator_equals) {
    Queue* testing_queue_1 = new Queue();

    for (size_t i = 0; i < 10; i++) {
        testing_queue_1->append(static_cast<double>(i));
    }

    Queue* testing_queue_2 = new Queue();

    for (size_t i = 10; i < 20; i++) {
        testing_queue_2->append(static_cast<double>(i));
    }

    *testing_queue_1 = *testing_queue_2;

    ASSERT_EQ(testing_queue_1->isTheSameData(testing_queue_2), true);
}

TEST(queue_test, comparing_two_queues_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    for (size_t i = 0; i < 10; i++) {
        testing_queue_1->append(static_cast<double>(i));
    }

    for (size_t i = 0; i < 10; i++) {
        testing_queue_2->append(static_cast<double>(i));
    }

    ASSERT_EQ(testing_queue_1->isTheSameData(testing_queue_2), true);
}

TEST(queue_test, comparing_two_queues_not_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    for (size_t i = 0; i < 100; i++) {
        testing_queue_1->append(static_cast<double>(i));
    }

    for (size_t i = 0; i < 100; i++) {
        testing_queue_2->append(static_cast<double>(i));
    }

    for (size_t i = 0; i < 10; i++) {
        testing_queue_1->removeFirst();
    }

    ASSERT_EQ(testing_queue_1->isTheSameData(testing_queue_2), false);
}

TEST(queue_test, comparing_get_first_two_queues) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    testing_queue_1->append(1.2);
    testing_queue_2->append(1.2);

    testing_queue_1->append(2.0);
    testing_queue_2->append(3.2);

    testing_queue_1->append(9.5);
    testing_queue_2->append(53.1);

    const double get_first_queue_1 = testing_queue_1->getFirstData();
    const double get_first_queue_2 = testing_queue_2->getFirstData();

    ASSERT_EQ(get_first_queue_1, get_first_queue_2);
}

TEST(queue_test, remove_first_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    testing_queue_1->append(2.5);
    testing_queue_1->append(3.5);
    testing_queue_1->append(4.5);
    testing_queue_1->append(5.5);

    testing_queue_1->removeFirst();
    testing_queue_1->removeFirst();

    testing_queue_2->append(4.5);
    testing_queue_2->append(5.5);

    ASSERT_EQ(testing_queue_1->isTheSameData(testing_queue_2), true);
}

TEST(queue_test, remove_get_last_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    testing_queue_1->append(2.0);
    testing_queue_1->append(4.4);

    testing_queue_2->append(4.0);
    testing_queue_2->append(4.4);

    ASSERT_EQ(testing_queue_1->getLastData(), testing_queue_2->getLastData());
}

TEST(queue_test, get_size_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    double number_to_append = 0.0;

    for (size_t i = 0; i < 100; i++) {
        number_to_append = i;
        testing_queue_1->append(static_cast<double>(number_to_append));
    }

    for (size_t i = 0; i < 100; i++) {
        number_to_append = i * 2 + 5;
        testing_queue_2->append(static_cast<double>(number_to_append));
    }

    ASSERT_EQ(testing_queue_1->getSize() == testing_queue_2->getSize(), true);
}

TEST(queue_test, get_size_not_equal) {
    Queue* testing_queue_1 = new Queue();
    Queue* testing_queue_2 = new Queue();

    double number_to_append = 0.0;

    for (size_t i = 0; i < 200; i++) {
        number_to_append = i;
        testing_queue_1->append(static_cast<double>(number_to_append));
    }

    for (size_t i = 0; i < 250; i++) {
        number_to_append = i;
        testing_queue_2->append(static_cast<double>(number_to_append));
    }

    ASSERT_EQ(testing_queue_1->getSize() == testing_queue_2->getSize(), false);
}

TEST(queue_test, to_string_equal) {
    Queue* testing_queue_1 = new Queue();

    for (size_t i = 0; i < 300; i++) {
        testing_queue_1->append(static_cast<double>(i));
    }

    Queue* testing_queue_2(testing_queue_1);

    ASSERT_EQ(testing_queue_1->toStringData() ==
              testing_queue_2->toStringData(), true);
}
