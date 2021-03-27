// Copyright 2021 Tkachev Alexey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Tkachev_Alexey_ComplexNumberTest, full_of_zeros_no_throw) {
    const double real = 0.0;
    const double imaginary = 0.0;
    ASSERT_NO_THROW(ComplexNumber(real, imaginary));
}

TEST(Tkachev_Alexey_ComplexNumberTest, imaginary_only_no_throw) {
    const double real = 0.0;
    const double imaginary = 1.0;
    ASSERT_NO_THROW(ComplexNumber(real, imaginary));
}

TEST(Tkachev_Alexey_ComplexNumberTest, real_only_no_throw) {
    const double real = 1.0;
    const double imaginary = 0.0;
    ASSERT_NO_THROW(ComplexNumber(real, imaginary));
}

TEST(Tkachev_Alexey_ComplexNumberTest, summing) {
    const double real_1 = -30.0;
    const double imaginary_1 = 10.5;

    const double real_2 = -20.4;
    const double imaginary_2 = 20.9;

    const ComplexNumber complex_number_1(real_1, imaginary_1);
    const ComplexNumber complex_number_2(real_2, imaginary_2);

    const double real_true_solution = -50.4;
    const double imaginary_true_solution = 31.4;

    const ComplexNumber complex_numbers_true_sum(
           real_true_solution, imaginary_true_solution);

    ASSERT_EQ(complex_number_1 + complex_number_2,
        complex_numbers_true_sum);
}

TEST(Tkachev_Alexey_ComplexNumberTest, subtraction) {
    const double real_1 = 10.0;
    const double imaginary_1 = 25.4;

    const double real_2 = -150.5;
    const double imaginary_2 = 0.0;

    const ComplexNumber complex_number_1(real_1, imaginary_1);
    const ComplexNumber complex_number_2(real_2, imaginary_2);

    const double real_true_solution = 160.5;
    const double imaginary_true_solution = 25.4;

    const ComplexNumber complex_numbers_true_sub(
         real_true_solution, imaginary_true_solution);

    ASSERT_EQ(complex_number_1 - complex_number_2,
        complex_numbers_true_sub);
}

TEST(Tkachev_Alexey_ComplexNumberTest, division) {
    const double real_1 = 25.25;
    const double imaginary_1 = 45.45;

    const double real_2 = 100.1;
    const double imaginary_2 = 50.5;

    const ComplexNumber complex_number_1(real_1, imaginary_1);
    const ComplexNumber complex_number_2(real_2, imaginary_2);

    const double real_true_solution = 0.3836635041757291;
    const double imaginary_true_solution = 0.2604894409503065;

    const ComplexNumber complex_numbers_true_div(
         real_true_solution, imaginary_true_solution);

    ASSERT_EQ(complex_number_1 / complex_number_2,
        complex_numbers_true_div);
}

TEST(Tkachev_Alexey_ComplexNumberTest, multiplying) {
    const double real_1 = 0.0;
    const double imaginary_1 = 10.105;

    const double real_2 = -10.105;
    const double imaginary_2 = 35.1;

    const ComplexNumber complex_number_1(real_1, imaginary_1);
    const ComplexNumber complex_number_2(real_2, imaginary_2);

    const double real_true_solution = -354.68550000000005;
    const double imaginary_true_solution = -102.11102500000001;

    const ComplexNumber complex_numbers_true_mul(
         real_true_solution, imaginary_true_solution);

    ASSERT_EQ(complex_number_1 * complex_number_2,
        complex_numbers_true_mul);
}

TEST(Tkachev_Alexey_ComplexNumberTest, division_by_real_one) {
    const double real_1 = 1.1;
    const double imaginary_1 = -1.1;

    const double real_2 = 1.0;
    const double imaginary_2 = 0.0;

    const ComplexNumber complex_number_1(real_1, imaginary_1);
    const ComplexNumber complex_number_2(real_2, imaginary_2);

    ASSERT_EQ(complex_number_1 / complex_number_2,
         complex_number_1);
}
