#include "set_ops.h"
#include <iostream>
#include <algorithm> // Для std::sort та std::unique

// Виведення множини
void printSet(const std::vector<int>& set) {
    for (const int& element : set) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Об'єднання множин
std::vector<int> unionSets(const std::vector<int>& set1, const std::vector<int>& set2) {
    std::vector<int> result = set1;

    result.insert(result.end(), set2.begin(), set2.end());
    std::sort(result.begin(), result.end());
    
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
}

// Перетин множин
std::vector<int> intersectSets(const std::vector<int>& set1, const std::vector<int>& set2) {
    std::vector<int> result;
    for (const int& element1 : set1) {
        for (const int& element2 : set2) {
            if (element1 == element2) {
                result.push_back(element1);
                break; // Переходимо до наступного елемента першої множини
            }
        }
    }
    return result;
}

// Доповнення множин (комплемент)
std::vector<int> complementSets(const std::vector<int>& set1, const std::vector<int>& set2) {
    std::vector<int> result;

    for (size_t i = 0; i < set2.size(); ++i) {
        bool found = false;
        for (size_t j = 0; j < set1.size(); ++j) {
            if (set2[i] == set1[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.push_back(set2[i]);
        }
    }

    return result;
}
