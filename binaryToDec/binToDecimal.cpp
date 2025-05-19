#include <iostream>
#include <cmath>
#include <string>

int binToDecimal(std::string binStr) {
    int ansDec = 0;
    int len = binStr.length();                                                  // length of binary number

    for (int i = 0; i < len; i++) {
        if (binStr[len - i -1] == '1') {                                        // Check if the current bit (from the right) is '1'
            ansDec += pow(2, i);                                                // If it is '1', add 2 raised to the power of its position to the result
        } 
    }

    return ansDec;                                                             // return decimal number
}

int main() {
    std::string binStr;
    std::cout << "Enter a binary number: ";
    std::cin >> binStr;

    int decNum = binToDecimal(binStr);

    std::cout << "Decimal equivalent: " << decNum << std::endl;
    return 0;
}