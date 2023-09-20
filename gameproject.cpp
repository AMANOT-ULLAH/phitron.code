#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void playGame() {
    const int NUM_PROBLEMS = 5; // Number of problems to solve
    const int TIME_LIMIT = 10; // Time limit per problem in seconds

    int score = 0;

    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < NUM_PROBLEMS; ++i) {
        int num1 = generateRandomNumber(1, 100);
        int num2 = generateRandomNumber(1, 50);
        char operators[] = {'+', '-', '*', '/'};
        char op = operators[generateRandomNumber(0, 3)];

        cout << "Problem " << i + 1 << ": " << num1 << " " << op << " " << num2 << " = ";

        time_t startTime = time(0); // Start the timer

        int userAnswer;
        cin >> userAnswer;

        time_t endTime = time(0); // Stop the timer

        int elapsedTime = endTime - startTime; // Calculate the time taken

        if (elapsedTime <= TIME_LIMIT) {
            int correctAnswer;
            switch (op) {
                case '+':
                    correctAnswer = num1 + num2;
                    break;
                case '-':
                    correctAnswer = num1 - num2;
                    break;
                case '*':
                    correctAnswer = num1 * num2;
                    break;
                case '/':
                    correctAnswer = num1 / num2;
                    break;
            }

            if (userAnswer == correctAnswer) {
                cout << "Correct!" << endl;
                ++score;
            } else {
                cout << "Wrong!" << endl;
            }
        } else {
            cout << "Time's up!" << endl;
        }

        cout << endl;
    }

    cout << "Game Over!"<<endl <<"Your score: " << score << " out of " << NUM_PROBLEMS << endl;
}

int main() {
    cout << "Welcome to the Rapid Calculation Game!" << endl;
    cout << "You will be given a series of arithmetic problems to solve within a time limit." << endl;
    cout << "Let's begin!" << endl << endl;

    playGame();

    return 0;
}
