#include <gtest/gtest.h>
#include "calculator.h"
#include <cmath>
#include <stdexcept>

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc;
    
    void SetUp() override {
        calc.clear();
    }
    
    static bool nearlyEqual(double a, double b, double epsilon = 1e-7) {
        return std::abs(a - b) < epsilon;
    }
};

// Basic Operations Tests
TEST_F(CalculatorTest, Addition) {
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-2, 3), 1);
    EXPECT_EQ(calc.add(0, 0), 0);
    EXPECT_TRUE(nearlyEqual(calc.add(0.1, 0.2), 0.3));
}

TEST_F(CalculatorTest, Subtraction) {
    EXPECT_EQ(calc.subtract(5, 3), 2);
    EXPECT_EQ(calc.subtract(3, 5), -2);
    EXPECT_EQ(calc.subtract(0, 0), 0);
    EXPECT_TRUE(nearlyEqual(calc.subtract(0.3, 0.1), 0.2));
}

TEST_F(CalculatorTest, Multiplication) {
    EXPECT_EQ(calc.multiply(2, 3), 6);
    EXPECT_EQ(calc.multiply(-2, 3), -6);
    EXPECT_EQ(calc.multiply(0, 5), 0);
    EXPECT_TRUE(nearlyEqual(calc.multiply(0.1, 0.2), 0.02));
}

TEST_F(CalculatorTest, Division) {
    EXPECT_EQ(calc.divide(6, 2), 3);
    EXPECT_TRUE(nearlyEqual(calc.divide(5, 2), 2.5));
    EXPECT_EQ(calc.divide(0, 5), 0);
    EXPECT_THROW(calc.divide(5, 0), std::domain_error);
}

// Scientific Operations Tests
TEST_F(CalculatorTest, SquareRoot) {
    EXPECT_TRUE(nearlyEqual(calc.sqrt(4), 2));
    EXPECT_TRUE(nearlyEqual(calc.sqrt(2), std::sqrt(2)));
    EXPECT_THROW(calc.sqrt(-1), std::domain_error);
}

TEST_F(CalculatorTest, Power) {
    EXPECT_EQ(calc.power(2, 3), 8);
    EXPECT_EQ(calc.power(2, 0), 1);
    EXPECT_EQ(calc.power(0, 5), 0);
    EXPECT_TRUE(nearlyEqual(calc.power(2, -1), 0.5));
}

TEST_F(CalculatorTest, NaturalLogarithm) {
    EXPECT_TRUE(nearlyEqual(calc.ln(1), 0));
    EXPECT_TRUE(nearlyEqual(calc.ln(std::exp(1)), 1));
    EXPECT_THROW(calc.ln(0), std::domain_error);
    EXPECT_THROW(calc.ln(-1), std::domain_error);
}

TEST_F(CalculatorTest, Trigonometry) {
    // Test in radians
    EXPECT_TRUE(nearlyEqual(calc.sin(0), 0));
    EXPECT_TRUE(nearlyEqual(calc.sin(M_PI/2), 1));
    EXPECT_TRUE(nearlyEqual(calc.cos(0), 1));
    EXPECT_TRUE(nearlyEqual(calc.cos(M_PI), -1));
    EXPECT_TRUE(nearlyEqual(calc.tan(0), 0));
    EXPECT_TRUE(nearlyEqual(calc.tan(M_PI/4), 1));
}

// Memory Operations Tests
TEST_F(CalculatorTest, MemoryOperations) {
    calc.appendNumber('5');
    calc.memoryStore();
    EXPECT_EQ(calc.memoryRecall(), 5);
    
    calc.appendNumber('3');
    calc.memoryAdd();
    EXPECT_EQ(calc.memoryRecall(), 8);
    
    calc.appendNumber('2');
    calc.memorySubtract();
    EXPECT_EQ(calc.memoryRecall(), 6);
    
    calc.memoryClear();
    EXPECT_EQ(calc.memoryRecall(), 0);
}

// Display and Input Tests
TEST_F(CalculatorTest, DisplayOperations) {
    calc.appendNumber('1');
    EXPECT_EQ(calc.getDisplayText(), "1");
    
    calc.appendNumber('2');
    EXPECT_EQ(calc.getDisplayText(), "12");
    
    calc.appendNumber('.');
    calc.appendNumber('5');
    EXPECT_EQ(calc.getDisplayText(), "12.5");
}

TEST_F(CalculatorTest, ComplexCalculations) {
    calc.appendNumber('5');
    calc.setOperation('+');
    calc.appendNumber('3');
    calc.calculate();
    EXPECT_EQ(calc.getDisplayText(), "8");
    
    calc.setOperation('*');
    calc.appendNumber('2');
    calc.calculate();
    EXPECT_EQ(calc.getDisplayText(), "16");
}

// History Tests
TEST_F(CalculatorTest, HistoryTracking) {
    calc.add(2, 3);
    calc.multiply(4, 5);
    auto history = calc.getHistory();
    EXPECT_EQ(history.size(), 2);
    EXPECT_EQ(history[0], "2 + 3 = 5");
    EXPECT_EQ(history[1], "4 × 5 = 20");
    
    calc.clearHistory();
    EXPECT_TRUE(calc.getHistory().empty());
}

// Error Handling Tests
TEST_F(CalculatorTest, ErrorHandling) {
    // Division by zero
    calc.appendNumber('5');
    calc.setOperation('/');
    calc.appendNumber('0');
    calc.calculate();
    EXPECT_TRUE(calc.getDisplayText().find("Error") != std::string::npos);
    
    // Invalid square root
    calc.clear();
    calc.appendNumber('-');
    calc.appendNumber('4');
    EXPECT_THROW(calc.sqrt(-4), std::domain_error);
}

// Number Formatting Tests
TEST_F(CalculatorTest, NumberFormatting) {
    calc.appendNumber('1');
    calc.appendNumber('.');
    calc.appendNumber('0');
    EXPECT_EQ(calc.getDisplayText(), "1");
    
    calc.clear();
    calc.appendNumber('1');
    calc.appendNumber('.');
    calc.appendNumber('2');
    calc.appendNumber('3');
    calc.appendNumber('0');
    EXPECT_EQ(calc.getDisplayText(), "1.23");
}
