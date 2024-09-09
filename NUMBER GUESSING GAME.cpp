#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    // Seed the random number generator with the current time
    srand(std::time(0));
    int num_range ;
    cout<<"\n"<<"Enter what would you like the range of the numbers to be? : ";
    cin>>num_range;
    // Generate a random number between 1 and 100
    int randomNumber = rand() % (num_range + 1);

    int userGuess = 0, step = 0 ;
    bool guessedCorrectly = false;

    cout << "Welcome to the Guessing Game!" << std::endl;
    cout << "I have selected a random number between 1 and 100." << std::endl;
    cout << "Try to guess the number!" << std::endl;

    // Loop until the user guesses the correct number
    while (!guessedCorrectly) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        step ++ ;
        if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number in " << step <<" step !" << std::endl;
            guessedCorrectly = true;
        }
    }

    return 0;
}
