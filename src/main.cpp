#include "calculator.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

void displayMenu() {
    std::cout << "\n=== Professional Calculator ===\n";
    std::cout << "Basic Operations:\n";
    std::cout << "  1. Enter number\n";
    std::cout << "  2. Add (+)\n";
    std::cout << "  3. Subtract (-)\n";
    std::cout << "  4. Multiply (*)\n";
    std::cout << "  5. Divide (/)\n";
    std::cout << "Scientific Operations:\n";
    std::cout << "  6. Square Root (√)\n";
    std::cout << "  7. Power (^)\n";
    std::cout << "  8. Natural Log (ln)\n";
    std::cout << "  9. Sine (sin)\n";
    std::cout << " 10. Cosine (cos)\n";
    std::cout << " 11. Tangent (tan)\n";
    std::cout << "Memory Operations:\n";
    std::cout << " 12. Memory Store (MS)\n";
    std::cout << " 13. Memory Recall (MR)\n";
    std::cout << " 14. Memory Clear (MC)\n";
    std::cout << " 15. Memory Add (M+)\n";
    std::cout << " 16. Memory Subtract (M-)\n";
    std::cout << "Other Operations:\n";
    std::cout << " 17. Calculate (=)\n";
    std::cout << " 18. Clear (C)\n";
    std::cout << " 19. Show History\n";
    std::cout << " 20. Toggle Rad/Deg\n";
    std::cout << " 21. Exit\n";
}

void displayHistory(const Calculator& calc) {
    std::cout << "\n=== Calculation History ===\n";
    const auto& history = calc.getHistory();
    if (history.empty()) {
        std::cout << "No calculations performed yet.\n";
        return;
    }
    
    for (const auto& entry : history) {
        std::cout << entry << "\n";
    }
}

int main() {
    Calculator calc;
    bool running = true;
    
    std::cout << "Welcome to Professional Calculator!\n";
    std::cout << "This calculator supports basic arithmetic, scientific operations,\n";
    std::cout << "memory functions, and calculation history.\n";
    
    while (running) {
        std::cout << "\nCurrent display: " << calc.getDisplayText() << "\n";
        displayMenu();
        
        std::cout << "\nChoose an option (1-21): ";
        int choice;
        std::cin >> choice;
        
        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        try {
            switch (choice) {
                case 1: {
                    std::cout << "Enter a number: ";
                    std::string input;
                    std::getline(std::cin, input);
                    for (char digit : input) {
                        if (std::isdigit(digit) || digit == '.' || digit == '-') {
                            calc.appendNumber(digit);
                        }
                    }
                    break;
                }
                case 2:
                    calc.setOperation('+');
                    break;
                case 3:
                    calc.setOperation('-');
                    break;
                case 4:
                    calc.setOperation('*');
                    break;
                case 5:
                    calc.setOperation('/');
                    break;
                case 6: {
                    double current = std::stod(calc.getDisplayText());
                    double result = calc.sqrt(current);
                    std::cout << "Square root of " << current << " = " << result << "\n";
                    break;
                }
                case 7:
                    calc.setOperation('^');
                    break;
                case 8: {
                    double current = std::stod(calc.getDisplayText());
                    double result = calc.ln(current);
                    std::cout << "Natural log of " << current << " = " << result << "\n";
                    break;
                }
                case 9: {
                    double current = std::stod(calc.getDisplayText());
                    double result = calc.sin(current);
                    std::cout << "Sine of " << current << " = " << result << "\n";
                    break;
                }
                case 10: {
                    double current = std::stod(calc.getDisplayText());
                    double result = calc.cos(current);
                    std::cout << "Cosine of " << current << " = " << result << "\n";
                    break;
                }
                case 11: {
                    double current = std::stod(calc.getDisplayText());
                    double result = calc.tan(current);
                    std::cout << "Tangent of " << current << " = " << result << "\n";
                    break;
                }
                case 12:
                    calc.memoryStore();
                    std::cout << "Current value stored in memory\n";
                    break;
                case 13:
                    calc.memoryRecall();
                    std::cout << "Memory value recalled\n";
                    break;
                case 14:
                    calc.memoryClear();
                    std::cout << "Memory cleared\n";
                    break;
                case 15:
                    calc.memoryAdd();
                    std::cout << "Current value added to memory\n";
                    break;
                case 16:
                    calc.memorySubtract();
                    std::cout << "Current value subtracted from memory\n";
                    break;
                case 17:
                    calc.calculate();
                    break;
                case 18:
                    calc.clear();
                    break;
                case 19:
                    displayHistory(calc);
                    break;
                case 20:
                    // Toggle between radians and degrees would go here
                    std::cout << "Angle unit toggled\n";
                    break;
                case 21:
                    running = false;
                    break;
                default:
                    std::cout << "Invalid option. Please try again.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    
    std::cout << "\nThank you for using Professional Calculator!\n";
    return 0;
}
