#include <iostream>

int main() {

    int largest = INT_MIN;
    int nums[] = {5, 15, 22, 1, -15, -24, 10000};
    int size = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < size; i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }

    std::cout << "largest: " << largest << std::endl;
    return 0;
}