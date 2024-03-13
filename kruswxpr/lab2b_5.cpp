#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

void printVector(const std::vector<int>& v) {
    for (int item : v) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void remove_multi_values(std::vector<int>& original, const std::vector<int>& second) {
    for (int val : second) {
        original.erase(std::remove(original.begin(), original.end(), val), original.end());
    }
}

void interactiveMode() {
    std::vector<int> original, second;
    int sizeOriginal, sizeSecond, input;

    std::cout << "Enter size of the original list: ";
    std::cin >> sizeOriginal;
    std::cout << "Enter original list elements:\n";
    for (int i = 0; i < sizeOriginal; ++i) {
        std::cin >> input;
        original.push_back(input);
    }

    std::cout << "Enter size of the second list (count of values to remove): ";
    std::cin >> sizeSecond;
    std::cout << "Enter second list elements (values to remove):\n";
    for (int i = 0; i < sizeSecond; ++i) {
        std::cin >> input;
        second.push_back(input);
    }

    remove_multi_values(original, second);
    std::cout << "Original list after removal: ";
    printVector(original);
}

void demoMode() {
    std::vector<int> original = { 1, 2, 3, 4, 5, 3, 2 };
    std::vector<int> second = { 2, 3 };

    std::cout << "Original list before removal: ";
    printVector(original);
    std::cout << "Values to remove: ";
    printVector(second);

    remove_multi_values(original, second);
    std::cout << "Original list after removal: ";
    printVector(original);
}

void benchmarkMode() {
    std::vector<int> original(1000000, 1);
    std::vector<int> second = { 1 };

    auto start = std::chrono::high_resolution_clock::now();
    remove_multi_values(original, second);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout << "Benchmark time: " << diff.count() << " s\n";
}

int main() {
    std::cout << "Select the mode:\n"
        << "1. Interactive mode\n"
        << "2. Demonstration mode\n"
        << "3. Automatic mode 'benchmark'\n"
        << "4. Exiting from program\n"
        << "Enter mode number: ";
    int mode;
    std::cin >> mode;

    switch (mode) {
    case 1: 
        interactiveMode();
        break;
    case 2: 
        demoMode(); 
        break;
    case 3: 
        benchmarkMode();
        break;
    case 4:
        std::cout << "Exiting from program" << std::endl;
        break;
    default: 
        std::cout << "Invalid mode selected\n";
    }

    return 0;
}
