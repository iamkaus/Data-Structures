#include <iostream>

int main() {
    int nums[] = {5, 15, 22, 1, -15, 0, 1};
    int smallest = INT_MAX;

    int size = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < size; i++) {
        if (nums[i] < smallest) {
            smallest = nums[i];
        }
    }
    std::cout << "smallest: " << smallest << std::endl;
    return 0;
}