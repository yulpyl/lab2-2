#include "set_ops.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

void interactiveMode();
std::vector<int> inputSet();
void demonstrationMode();
void benchmarkMode();

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
        demonstrationMode();
        break;
    case 3:
        benchmarkMode();
        break;
    case 4:
        std::cout << "Exiting program " << std::endl;
        break;
    default:
        std::cout << "Incorrect mode selection. Please try again.\n";
    }

    return 0;
}

void interactiveMode() {
    std::cout << "Interactive mode. Choose operation: 1 - Union, 2 - Intersection, 3 - Complement" << std::endl;
    int operation;
    std::cin >> operation;

    std::cout << "Input first set (end with any non-integer): ";
    std::vector<int> set1 = inputSet();

    std::cout << "Input second set (end with any non-integer): ";
    std::vector<int> set2 = inputSet();

    switch (operation) {
    case 1: {
        std::vector<int> result = unionSets(set1, set2);
        std::cout << "Union: ";
        printSet(result);
        break;
    }
    case 2: {
        std::vector<int> result = intersectSets(set1, set2);
        std::cout << "Intersection: ";
        printSet(result);
        break;
    }
    case 3: {
        std::vector<int> result = complementSets(set1, set2);
        std::cout << "Complement: ";
        printSet(result);
        break;
    }
    default:
        std::cout << "Invalid operation selected." << std::endl;
    }
}

std::vector<int> inputSet() {
    std::vector<int> set;
    int element;
    while (std::cin >> element) {
        set.push_back(element);
    }
    std::cin.clear(); // Скидуємо стан помилки, якщо ввід не є числом
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ігноруємо решту рядка
    return set;
}

void demonstrationMode() {
    // Фіксовані множини для демонстрації
    std::vector<int> set1 = { 1, 2, 3, 4, 5 };
    std::vector<int> set2 = { 4, 5, 6, 7, 8 };

    // Демонстрація об'єднання
    std::vector<int> unionResult = unionSets(set1, set2);
    std::cout << "Union of set1 and set2: ";
    printSet(unionResult);

    // Демонстрація перетину
    std::vector<int> intersectResult = intersectSets(set1, set2);
    std::cout << "Intersection of set1 and set2: ";
    printSet(intersectResult);

    // Демонстрація різниці
    std::vector<int> complementResult = complementSets(set1, set2);
    std::cout << "Complement of set1 in set2: ";
    printSet(complementResult);
}


void benchmarkMode() {
    const size_t setSize = 10000; // Розмір генерованих множин
    std::vector<int> set1(setSize), set2(setSize);

    // Генерація великих множин
    for (size_t i = 0; i < setSize; ++i) {
        set1[i] = i;
        set2[i] = i + setSize / 2; // Перекриття між множинами для перетину
    }

    // Вимірювання часу для об'єднання множин
    auto start = std::chrono::high_resolution_clock::now();
    auto unionResult = unionSets(set1, set2);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Union operation time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    // Вимірювання часу для перетину множин
    start = std::chrono::high_resolution_clock::now();
    auto intersectResult = intersectSets(set1, set2);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Intersection operation time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    // Вимірювання часу для різниці множин
    start = std::chrono::high_resolution_clock::now();
    auto complementResult = complementSets(set1, set2);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Complement operation time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";
}
