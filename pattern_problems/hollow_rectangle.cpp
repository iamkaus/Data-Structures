#include <iostream>
int main() {
    int rows;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    int cols;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}