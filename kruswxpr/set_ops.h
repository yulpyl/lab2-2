#pragma once

#ifndef SET_OPS_H
#define SET_OPS_H

#include <vector>

// Оголошення функцій
void printSet(const std::vector<int>& set);
std::vector<int> unionSets(const std::vector<int>& set1, const std::vector<int>& set2);
std::vector<int> intersectSets(const std::vector<int>& set1, const std::vector<int>& set2);
std::vector<int> complementSets(const std::vector<int>& set1, const std::vector<int>& set2);

#endif 
