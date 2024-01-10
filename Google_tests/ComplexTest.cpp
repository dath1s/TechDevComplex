#include "gtest/gtest.h"
#include "Complex.h"

// Constructor tests
TEST(ComplexTests, DefaultConstructorTest){
    Complex num;

    bool correct_num = (num.getReal() == 0 && num.getImg() == 0);

    ASSERT_TRUE(correct_num);
}

TEST(ComplexTests, OnlyRealConstructorTest){
    Complex num{1};

    bool correct_num = (num.getReal() == 1 && num.getImg() == 0);

    ASSERT_TRUE(correct_num);
}

TEST(ComplexTests, FullConstructorTest){
    Complex num{1, 1};

    bool correct_num = (num.getReal() == 1 && num.getImg() == 1);

    ASSERT_TRUE(correct_num);
}

// Get/set real/imaginary test
TEST(ComplexTests, getRealTest){
    Complex num{1};

    bool correct_real = (num.getReal() == 1);

    ASSERT_TRUE(correct_real);
}

TEST(ComplexTests, getImgTest){
    Complex num{0, 1};

    bool correct_img = (num.getImg() == 1);

    ASSERT_TRUE(correct_img);
}

TEST(ComplexTests, setRealTest){
    Complex num;
    num.setReal(1);

    bool correct_real = (num.getReal() == 1);

    ASSERT_TRUE(correct_real);
}

TEST(ComplexTests, setImgTest){
    Complex num;
    num.setImg(1);

    bool correct_img = (num.getImg() == 1);

    ASSERT_TRUE(correct_img);
}

// Module test
TEST(ComplexTests, AbsTest){
    Complex num{3, 4};

    bool correct_abs = (num.abs() == 5);

    ASSERT_TRUE(correct_abs);
}

// Arithmetics tests
TEST(ComplexTests, SumTest){
    bool correct_sum = Complex(5, -5) + Complex(-5, 5) == Complex(0, 0);

    ASSERT_TRUE(correct_sum);
}

TEST(ComplexTests, SubTest){
    bool correct_sub = Complex(-1, -1) - Complex(-1, -1) == Complex(0, 0);

    ASSERT_TRUE(correct_sub);
}

TEST(ComplexTests, MulTest){
    bool correct_mul = Complex(1, 2) * Complex(3, 4) == Complex(-5, 10);

    ASSERT_TRUE(correct_mul);
}

TEST(ComplexTests, DivComplexTest){
    bool correct_div = Complex(1, 2) / Complex(3, 4) == Complex(0.44, 0.08);

    ASSERT_TRUE(correct_div);
}

TEST(ComplexTests, DivIntTest){
bool correct_div = Complex(4, 4) / 2 == Complex(2, 2);

ASSERT_TRUE(correct_div);
}

// Compare tests
TEST(ComplexTests, EqTest){
    bool correct_eq = Complex(1, 1) == Complex(1, 1);

    ASSERT_TRUE(correct_eq);
}

TEST(ComplexTests, NeTest){
    bool correct_ne = Complex(1, 2) != Complex(0, 2);

    ASSERT_TRUE(correct_ne);
}

TEST(ComplexTests, GtComplexTest){
    bool correct_gt = Complex(1, 1) > Complex(0, 0);

    ASSERT_TRUE(correct_gt);
}

TEST(ComplexTests, LtComplexTest){
        bool correct_lt = Complex(0, 0) < Complex(1, 1);

        ASSERT_TRUE(correct_lt);
}

TEST(ComplexTests, GtNumberTest){
    bool correct_gt = Complex(1, 1) > 1;

    ASSERT_TRUE(correct_gt);
}

TEST(ComplexTests, LtNumberTest){
    bool correct_lt = Complex(0, 0) < 1.1;

    ASSERT_TRUE(correct_lt);
}

// Test formating to string
TEST(ComplexTest, ToStringTest){
    bool correct_string = (Complex(0, 0).toString() == "0+0i");

    ASSERT_TRUE(correct_string);
}

// Pow test
TEST (ComplexTests, PowTest){
    Complex num(1, 1);
    int exp = 3;

    bool correct_pow = num.pow(exp) == Complex(-2, -0.5);

    ASSERT_TRUE(correct_pow);
}