# C++ Coding Style Guide

## 🎯 General Principles

- Write clean, readable, and maintainable code
- Follow the DRY (Don't Repeat Yourself) principle
- Keep functions small and focused
- Use meaningful names for variables, functions, and classes

## 📝 Naming Conventions

### Variables
- Use camelCase for variable names
- Make names descriptive and meaningful
- Boolean variables should ask a question: `isReady`, `hasData`

```cpp
int maxValue;
std::string userName;
bool isValid;
```

### Functions
- Use camelCase for function names
- Verbs for functions that perform actions
- Nouns for functions that return values

```cpp
void calculateTotal();
std::string getUserName();
bool isValidInput();
```

### Classes
- Use PascalCase for class names
- Nouns or noun phrases

```cpp
class Calculator;
class DataProcessor;
```

### Constants
- Use UPPER_SNAKE_CASE for constants

```cpp
const int MAX_BUFFER_SIZE = 1024;
```

## 🏗️ Code Structure

### Headers
- Use header guards
- Group includes logically
- Forward declare when possible

```cpp
#ifndef MODULE_NAME_H
#define MODULE_NAME_H

// Standard library includes
#include <string>
#include <vector>

// Project includes
#include "project_header.h"

class ClassName {
    // ...
};

#endif // MODULE_NAME_H
```

### Classes
- Order members: public, protected, private
- Group similar functions together
- Document class purpose and member functions

## 📊 Formatting

### Indentation
- Use 4 spaces for indentation
- No tabs

### Line Length
- Maximum 80 characters per line
- Break long lines logically

### Braces
- Opening brace on the same line
- Closing brace on its own line

```cpp
if (condition) {
    // code
}
```

### Spacing
- One space after keywords
- One space around operators
- No space after function names

```cpp
if (x == y) {
    foo(x);
}
```

## 💭 Comments

### General Rules
- Write comments that explain why, not what
- Keep comments up to date
- Use complete sentences

### Function Comments
- Document parameters and return values
- Explain side effects
- Use Doxygen style

```cpp
/**
 * @brief Calculate the sum of two numbers
 * @param a First operand
 * @param b Second operand
 * @return Sum of a and b
 */
double add(double a, double b);
```

## 🛡️ Error Handling

- Use exceptions for error handling
- Document exceptions in function comments
- Always catch exceptions at appropriate levels

```cpp
try {
    // code that might throw
} catch (const std::exception& e) {
    // handle error
}
```

## 🔍 Best Practices

### Memory Management
- Use smart pointers instead of raw pointers
- Follow RAII principles
- Avoid memory leaks

### Modern C++ Features
- Use auto when it improves readability
- Use range-based for loops when possible
- Use constexpr for compile-time constants

### Performance
- Pass large objects by const reference
- Use move semantics when appropriate
- Consider cache coherency

## 🧪 Testing

- Write unit tests for all public functions
- Test edge cases
- Keep tests readable and maintainable

## 📚 Documentation

- Document public interfaces
- Keep documentation up to date
- Use Doxygen for API documentation

## 🔄 Version Control

- Write meaningful commit messages
- Keep commits focused and atomic
- Follow conventional commits format

---

This style guide is a living document and may be updated as needed to reflect best practices and team preferences.
