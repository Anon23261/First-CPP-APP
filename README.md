# 🚀 Advanced C++ Scientific Calculator

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![Build System](https://img.shields.io/badge/build-CMake-green.svg)](https://cmake.org/)
[![Code Style](https://img.shields.io/badge/code%20style-professional-brightgreen.svg)](./STYLE_GUIDE.md)
[![Documentation](https://img.shields.io/badge/docs-Doxygen-orange.svg)](./docs)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](./CONTRIBUTING.md)

<div align="center">
  <img src="https://raw.githubusercontent.com/yourusername/calculator/main/docs/images/calculator-logo.png" alt="Calculator Logo" width="200"/>

  <p align="center">
    A professional-grade scientific calculator showcasing modern C++ development practices
    <br />
    <a href="#features">View Features</a>
    ·
    <a href="#getting-started">Quick Start</a>
    ·
    <a href="#usage">Documentation</a>
    ·
    <a href="#roadmap">Roadmap</a>
  </p>
</div>

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Tech Stack](#-tech-stack)
- [Getting Started](#-getting-started)
- [Usage Examples](#-usage-examples)
- [Architecture](#-architecture)
- [Testing](#-testing)
- [Contributing](#-contributing)
- [License](#-license)
- [Contact](#-contact)

## 🌟 Overview

This advanced scientific calculator is a showcase of professional C++ development practices, designed to demonstrate expertise in:

- Modern C++ (14/17) features and best practices
- Object-Oriented Design principles
- Test-Driven Development (TDD)
- Clean Code architecture
- Professional documentation
- Continuous Integration/Deployment

Perfect for both learning purposes and real-world applications, this project serves as a portfolio piece demonstrating professional software engineering capabilities.

## ✨ Features

### 🔢 Core Mathematical Operations
- Basic arithmetic (addition, subtraction, multiplication, division)
- Scientific functions (square root, power, natural logarithm)
- Trigonometric functions (sine, cosine, tangent)
- Support for both radians and degrees

### 💾 Memory Management
- Store and recall values (MS, MR)
- Memory addition and subtraction (M+, M-)
- Memory clear function (MC)

### 📊 Advanced Features
- Calculation history tracking
- Error handling and input validation
- Floating-point precision control
- Professional number formatting
- Expression parsing
- Real-time calculation display

### 🛠️ Technical Features
- Exception-safe operations
- RAII principles
- Modern C++ practices
- Comprehensive unit testing
- Detailed documentation

## 🔧 Tech Stack

- **Language**: C++14/17
- **Build System**: CMake 3.10+
- **Testing Framework**: Google Test
- **Documentation**: Doxygen
- **CI/CD**: GitHub Actions
- **Code Coverage**: gcov/lcov
- **Static Analysis**: clang-tidy
- **Code Formatting**: clang-format

## 🚀 Getting Started

### Prerequisites

```bash
# Required packages
sudo apt-get update && sudo apt-get install -y \
    build-essential \
    cmake \
    libgtest-dev \
    doxygen \
    graphviz \
    clang-tidy \
    clang-format
```

### Building the Project

```bash
# Clone the repository
git clone https://github.com/yourusername/calculator.git
cd calculator

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
make

# Run tests (optional)
make test

# Generate documentation (optional)
make docs
```

## 📖 Usage Examples

```cpp
// Basic arithmetic
calculator.add(5, 3);      // Returns 8
calculator.multiply(4, 2); // Returns 8

// Scientific operations
calculator.sqrt(16);       // Returns 4
calculator.power(2, 3);    // Returns 8
calculator.sin(M_PI/2);    // Returns 1

// Memory operations
calculator.memoryStore(5);
calculator.memoryAdd(3);   // Memory now contains 8
calculator.memoryRecall(); // Returns 8
```

## 🏗️ Architecture

The project follows clean architecture principles:

```
calculator/
├── src/           # Source files
├── include/       # Header files
├── tests/         # Unit tests
├── docs/          # Documentation
├── examples/      # Usage examples
└── scripts/       # Build scripts
```

## 🧪 Testing

Comprehensive testing suite including:

- Unit tests for all operations
- Edge case testing
- Memory leak detection
- Performance benchmarks
- Integration tests

```bash
# Run all tests
./build/calculator_test

# Run specific test suite
./build/calculator_test --gtest_filter="CalculatorTest.*"
```

## 📈 Roadmap

Future enhancements planned:

- [ ] Complex number support
- [ ] Unit conversion capabilities
- [ ] Graphing functionality
- [ ] Expression parser
- [ ] Custom function definitions
- [ ] Plugin system
- [ ] GUI interface

## 🤝 Contributing

Contributions are welcome! Please read our [Contributing Guidelines](CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📫 Contact

Your Name - [your.email@example.com](mailto:your.email@example.com)

LinkedIn: [Your LinkedIn Profile](https://linkedin.com/in/yourprofile)
GitHub: [Your GitHub Profile](https://github.com/yourusername)
Portfolio: [Your Portfolio Website](https://yourportfolio.com)

---

<div align="center">
  Made with ❤️ by [Your Name]
  <br />
  Star ⭐ this repository if you find it helpful!
</div>
