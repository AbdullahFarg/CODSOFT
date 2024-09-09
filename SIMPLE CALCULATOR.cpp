#include <iostream>
#include <limits>   // For std::numeric_limits
#include <cmath>    // For std::pow

using namespace std;

int main() {

    int i;
    do{
    // Variables to hold user input
    double num1, num2;
    char operation;

    // Display the menu to the user
    cout << "Advanced Calculator Program" << endl;
    cout << "Enter two numbers and an operation to perform:" << endl;
    cout << "Available operations:" << endl;
    cout << "+ : Addition" << endl;
    cout << "- : Subtraction" << endl;
    cout << "* : Multiplication" << endl;
    cout << "/ : Division" << endl;
    cout << "% : Modulus (integer only)" << endl;
    cout << "^ : Exponentiation" << endl;

    // Get the first number
    cout << "Enter the first number: ";
    while (!(cin >> num1)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    // Get the second number
    cout << "Enter the second number: ";
    while (!(cin >> num2)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    // Get the operation
    cout << "Enter the operation (+, -, *, /, %, ^): ";
    cin >> operation;

    // Perform the operation and display the result
    switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        case '%':
            if (static_cast<int>(num2) != 0) {
                cout << "Result: " << static_cast<int>(num1) % static_cast<int>(num2) << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        case '^':
            cout << "Result: " << pow(num1, num2) << endl;
            break;
        default:
            cout << "Error: Invalid operation." << endl;
            break;
    }

        cout << "\n-----------------------------------------------------------------------------\n" << endl;
        cout << "Press 1 for Continue >>>" << endl;
        cout << "Press 0 for End >>>" << endl;
        cout << "\nAre You want to Continue? (1/0) : ";
        cin >> i;
    }
    while (i);

    return 0;
}
