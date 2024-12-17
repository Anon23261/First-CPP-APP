/**
 * @file calculator.h
 * @brief Advanced Calculator Class Implementation
 * @author [Your Name]
 * @date 2024-12-17
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <functional>

/**
 * @class Calculator
 * @brief Advanced calculator with scientific and memory functions
 * 
 * This class implements a professional calculator with both basic arithmetic
 * and advanced scientific operations, including trigonometry, logarithms,
 * and memory functions.
 */
class Calculator {
public:
    /**
     * @brief Default constructor
     * Initializes the calculator with default values
     */
    Calculator();

    // Basic Operations
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    // Scientific Operations
    /**
     * @brief Calculate the square root of a number
     * @param x Input number
     * @return Square root of x
     * @throw std::domain_error if x < 0
     */
    double sqrt(double x);

    /**
     * @brief Calculate the power of a number
     * @param base Base number
     * @param exp Exponent
     * @return base raised to exp
     */
    double power(double base, double exp);

    /**
     * @brief Calculate the natural logarithm
     * @param x Input number
     * @return Natural logarithm of x
     * @throw std::domain_error if x <= 0
     */
    double ln(double x);

    /**
     * @brief Calculate sine in radians
     * @param x Angle in radians
     * @return Sine of x
     */
    double sin(double x);

    /**
     * @brief Calculate cosine in radians
     * @param x Angle in radians
     * @return Cosine of x
     */
    double cos(double x);

    /**
     * @brief Calculate tangent in radians
     * @param x Angle in radians
     * @return Tangent of x
     */
    double tan(double x);

    // Memory Operations
    /**
     * @brief Store current value in memory
     */
    void memoryStore();

    /**
     * @brief Recall value from memory
     * @return Value stored in memory
     */
    double memoryRecall();

    /**
     * @brief Clear memory
     */
    void memoryClear();

    /**
     * @brief Add current value to memory
     */
    void memoryAdd();

    /**
     * @brief Subtract current value from memory
     */
    void memorySubtract();

    // History Operations
    /**
     * @brief Get calculation history
     * @return Vector of previous calculations
     */
    std::vector<std::string> getHistory() const;

    /**
     * @brief Clear calculation history
     */
    void clearHistory();

    // Display and Input Operations
    std::string getDisplayText() const;
    void appendNumber(char digit);
    void setOperation(char op);
    void calculate();
    void clear();

    /**
     * @brief Convert between degrees and radians
     * @param degrees Angle in degrees
     * @return Angle in radians
     */
    static double degreesToRadians(double degrees);

    /**
     * @brief Convert between radians and degrees
     * @param radians Angle in radians
     * @return Angle in degrees
     */
    static double radiansToDegrees(double radians);

private:
    double currentNumber;    ///< Current input number
    double storedNumber;     ///< Previously stored number
    double memoryValue;      ///< Value stored in memory
    char currentOperation;   ///< Current operation to perform
    bool newNumber;          ///< Flag indicating start of new number input
    std::string displayText; ///< Current display text
    bool useRadians;         ///< Flag for angle unit (true for radians, false for degrees)
    std::vector<std::string> history; ///< Calculation history

    /**
     * @brief Add entry to calculation history
     * @param entry Calculation to add to history
     */
    void addToHistory(const std::string& entry);

    /**
     * @brief Format number for display
     * @param num Number to format
     * @return Formatted string
     */
    std::string formatNumber(double num) const;
};

#endif // CALCULATOR_H
