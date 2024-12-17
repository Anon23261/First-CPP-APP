#include "calculator.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <vector>

Calculator::Calculator()
    : currentNumber(0)
    , storedNumber(0)
    , memoryValue(0)
    , currentOperation(' ')
    , newNumber(true)
    , useRadians(true) {
    displayText = "0";
}

// Basic Operations
double Calculator::add(double a, double b) {
    double result = a + b;
    addToHistory(formatNumber(a) + " + " + formatNumber(b) + " = " + formatNumber(result));
    return result;
}

double Calculator::subtract(double a, double b) {
    double result = a - b;
    addToHistory(formatNumber(a) + " - " + formatNumber(b) + " = " + formatNumber(result));
    return result;
}

double Calculator::multiply(double a, double b) {
    double result = a * b;
    addToHistory(formatNumber(a) + " × " + formatNumber(b) + " = " + formatNumber(result));
    return result;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw std::domain_error("Division by zero");
    }
    double result = a / b;
    addToHistory(formatNumber(a) + " ÷ " + formatNumber(b) + " = " + formatNumber(result));
    return result;
}

// Scientific Operations
double Calculator::sqrt(double x) {
    if (x < 0) {
        throw std::domain_error("Square root of negative number");
    }
    double result = std::sqrt(x);
    addToHistory("√(" + formatNumber(x) + ") = " + formatNumber(result));
    return result;
}

double Calculator::power(double base, double exp) {
    double result = std::pow(base, exp);
    addToHistory(formatNumber(base) + "^" + formatNumber(exp) + " = " + formatNumber(result));
    return result;
}

double Calculator::ln(double x) {
    if (x <= 0) {
        throw std::domain_error("Logarithm of non-positive number");
    }
    double result = std::log(x);
    addToHistory("ln(" + formatNumber(x) + ") = " + formatNumber(result));
    return result;
}

double Calculator::sin(double x) {
    double result = useRadians ? std::sin(x) : std::sin(degreesToRadians(x));
    addToHistory("sin(" + formatNumber(x) + ") = " + formatNumber(result));
    return result;
}

double Calculator::cos(double x) {
    double result = useRadians ? std::cos(x) : std::cos(degreesToRadians(x));
    addToHistory("cos(" + formatNumber(x) + ") = " + formatNumber(result));
    return result;
}

double Calculator::tan(double x) {
    double result = useRadians ? std::tan(x) : std::tan(degreesToRadians(x));
    addToHistory("tan(" + formatNumber(x) + ") = " + formatNumber(result));
    return result;
}

// Memory Operations
void Calculator::memoryStore() {
    memoryValue = currentNumber;
    addToHistory("M← " + formatNumber(currentNumber));
}

double Calculator::memoryRecall() {
    currentNumber = memoryValue;
    displayText = formatNumber(memoryValue);
    addToHistory("MR " + formatNumber(memoryValue));
    return memoryValue;
}

void Calculator::memoryClear() {
    memoryValue = 0;
    addToHistory("MC");
}

void Calculator::memoryAdd() {
    memoryValue += currentNumber;
    addToHistory("M+ " + formatNumber(currentNumber));
}

void Calculator::memorySubtract() {
    memoryValue -= currentNumber;
    addToHistory("M- " + formatNumber(currentNumber));
}

// History Operations
std::vector<std::string> Calculator::getHistory() const {
    return history;
}

void Calculator::clearHistory() {
    history.clear();
}

void Calculator::addToHistory(const std::string& entry) {
    history.push_back(entry);
    if (history.size() > 100) { // Keep only last 100 entries
        history.erase(history.begin());
    }
}

// Display and Input Operations
void Calculator::appendNumber(char digit) {
    if (newNumber) {
        displayText = digit;
        newNumber = false;
    } else {
        displayText += digit;
    }
    currentNumber = std::stod(displayText);
}

void Calculator::setOperation(char op) {
    calculate();
    currentOperation = op;
    storedNumber = currentNumber;
    newNumber = true;
}

void Calculator::calculate() {
    if (currentOperation == ' ') return;

    try {
        switch (currentOperation) {
            case '+': currentNumber = add(storedNumber, currentNumber); break;
            case '-': currentNumber = subtract(storedNumber, currentNumber); break;
            case '*': currentNumber = multiply(storedNumber, currentNumber); break;
            case '/': currentNumber = divide(storedNumber, currentNumber); break;
            case '^': currentNumber = power(storedNumber, currentNumber); break;
        }
        displayText = formatNumber(currentNumber);
    } catch (const std::exception& e) {
        displayText = "Error: " + std::string(e.what());
        currentNumber = 0;
    }

    currentOperation = ' ';
    newNumber = true;
}

void Calculator::clear() {
    currentNumber = 0;
    storedNumber = 0;
    currentOperation = ' ';
    displayText = "0";
    newNumber = true;
}

std::string Calculator::getDisplayText() const {
    return displayText;
}

// Utility Functions
double Calculator::degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

double Calculator::radiansToDegrees(double radians) {
    return radians * 180.0 / M_PI;
}

std::string Calculator::formatNumber(double num) const {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(6);
    ss << num;
    std::string str = ss.str();
    
    // Remove trailing zeros after decimal point
    if (str.find('.') != std::string::npos) {
        str = str.substr(0, str.find_last_not_of('0') + 1);
        if (str.back() == '.') {
            str = str.substr(0, str.size() - 1);
        }
    }
    return str;
}
