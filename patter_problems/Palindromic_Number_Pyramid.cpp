#include <iostream>

int main() {
    int n;
    std::cout << "Enter number of rows: ";
    std::cin >> n;
    

    if (n < 1 || n > 20) {
        std::cout << "Please enter a number between 1 and 20." << std::endl;
        return 1;
    }
    

    for (int i = 1; i <= n; i++) {
  
        for (int j = n; j > i; j--) {
            std::cout << "  ";
        }
        
        
        for (int j = i; j >= 1; j--) {
            std::cout << j << " ";
        }
        
       
        for (int j = 2; j <= i; j++) {
            std::cout << j << " ";
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}