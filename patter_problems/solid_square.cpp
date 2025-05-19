#include <iostream>

int main() {

    int row;
    std::cout << "Enter the number of rows: ";
    std::cin >> row;

    int col;
    std::cout << "Enter the number of columns: ";
    std::cin >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
        }
        return 0;
}