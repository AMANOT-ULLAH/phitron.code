
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Generate random number between 1 and 100
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;
    bool isCorrect = false;

    std::cout << "Welcome to Guess the Number Game!\n";
    std::cout << "I have selected a number between 1 and 100.\n";

    while (!isCorrect && attempts < 7) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        attempts++;

        if (guess == secretNumber) {
            isCorrect = true;
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Too high! Try again.\n";
        }
    }

    if (isCorrect) {
        std::cout << "Congratulations! You guessed the number "
                  << secretNumber << " correctly in " << attempts
                  << " attempts.\n";
    } else {
        std::cout << "Sorry, you've reached the maximum number of attempts.\n";
        std::cout << "The secret number was: " << secretNumber << "\n";
    }

    return 0;
}
