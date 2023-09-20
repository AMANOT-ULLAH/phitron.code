#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> cards(21);

    // Fill the cards with numbers from 1 to 21
    for (int i = 0; i < 21; ++i) {
        cards[i] = i + 1;
    }

    // Shuffle the cards
    std::random_shuffle(cards.begin(), cards.end());

    std::cout << "Magician: Welcome to the Magic Card Trick!\n";
    std::cout << "Magician: Think of a number between 1 and 21.\n";
    std::cout << "Magician: I will now perform some magic...\n\n";

    std::vector<int> selectedPart;
    int guessNumber;

    for (int i = 0; i < 3; ++i) {
        std::vector<int> part1(cards.begin(), cards.begin() + 7);
        std::vector<int> part2(cards.begin() + 7, cards.begin() + 14);
        std::vector<int> part3(cards.begin() + 14, cards.end());

        std::cout << "Magician: Please choose the part where your card is (1, 2, or 3): ";
        int chosenPart;
        std::cin >> chosenPart;

        switch (chosenPart) {
            case 1:
                cards.clear();
                cards.insert(cards.end(), part2.begin(), part2.end());
                cards.insert(cards.end(), part1.begin(), part1.end());
                cards.insert(cards.end(), part3.begin(), part3.end());
                break;
            case 2:
                cards.clear();
                cards.insert(cards.end(), part1.begin(), part1.end());
                cards.insert(cards.end(), part2.begin(), part2.end());
                cards.insert(cards.end(), part3.begin(), part3.end());
                break;
            case 3:
                cards.clear();
                cards.insert(cards.end(), part1.begin(), part1.end());
                cards.insert(cards.end(), part3.begin(), part3.end());
                cards.insert(cards.end(), part2.begin(), part2.end());
                break;
            default:
                std::cout << "Magician: Oops! That's an invalid choice.\n";
                return 0;
        }

        std::cout << "\nMagician: Your card is still among these cards:\n";
        for (const auto& card : cards) {
            std::cout << card << " ";
        }
        std::cout << "\n\n";

        if (i == 2) {
            std::cout << "Magician: This is your final chance. Please enter your guessed number: ";
            std::cin >> guessNumber;
        } else {
            std::cout << "Magician: I will now repeat the process.\n\n";
        }
    }

    std::cout << "\nMagician: After performing the magic trick, I have your guessed number: " << guessNumber << "!\n";
    std::cout << "Magician: Thank you for participating in the Magic Card Trick!\n";

    return 0;
}
