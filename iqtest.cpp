#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

// Function to generate a random password
std::string generatePassword(int length, bool includeLowercase, bool includeUppercase, bool includeDigits, bool includeSpecialChars) {
    std::string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    std::string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string digitChars = "0123456789";
    std::string specialChars = "!@#$%^&*";
    std::string validChars;
    std::string password;

    if (includeLowercase)
        validChars += lowercaseChars;
    if (includeUppercase)
        validChars += uppercaseChars;
    if (includeDigits)
        validChars += digitChars;
    if (includeSpecialChars)
        validChars += specialChars;

    if (validChars.empty()) {
        std::cout << "No character types selected. Please try again.\n";
        return "";
    }

    const int charCount = validChars.length();

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % charCount;
        password += validChars[randomIndex];
    }

    return password;
}

int main() {
    int passwordLength;
    bool includeLowercase, includeUppercase, includeDigits, includeSpecialChars;

    std::cout << "Welcome to the Advanced Password Generator!\n";
    std::cout << "Enter the desired length of the password: ";
    std::cin >> passwordLength;

    std::cout << "Include lowercase characters? (1 for yes, 0 for no): ";
    std::cin >> includeLowercase;

    std::cout << "Include uppercase characters? (1 for yes, 0 for no): ";
    std::cin >> includeUppercase;

    std::cout << "Include digits? (1 for yes, 0 for no): ";
    std::cin >> includeDigits;

    std::cout << "Include special characters? (1 for yes, 0 for no): ";
    std::cin >> includeSpecialChars;

    std::string password = generatePassword(passwordLength, includeLowercase, includeUppercase, includeDigits, includeSpecialChars);

    if (!password.empty()) {
        std::cout << "Generated Password: " << password << "\n";
    }

    return 0;
}
