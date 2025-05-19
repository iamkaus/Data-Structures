#include <iostream>

int decToBinary (int decNum) {
    int ansBin = 0;
    int power = 1;

    while ( decNum > 0 ) {
        int reminder = decNum % 2;
        decNum = decNum / 2;
        ansBin += (reminder * power);
        power = power * 10;
}
    return ansBin;
}

int main() {

    int decNum;
    std::cout << "Enter a decimal number: ";
    std::cin >> decNum;

    int ansBin = decToBinary(decNum);
    std::cout << "Binary equivalent: " << ansBin << std::endl;
    std::cout << "Decimal equivalent: " << decNum << std::endl;
    return 0;
}