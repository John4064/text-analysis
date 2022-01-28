//
// Created by jpark on 1/19/2022.
//

#ifndef TEXTANAL_ALGORITHMS_H
#define TEXTANAL_ALGORITHMS_H


#include <map>
#include <string>
#include <iostream>
#include <algorithm>

/**
 * @param target The first pair we are swapping with the second(dest)
 * @param dest the second pair we are swapping with the first(target)
 * @brief A simple swap function can be modified easily for different dataStructures
 */
void swap(std::pair<std::string, int>& target, std::pair<std::string, int>& dest);
/**
 * @param unsortMap Is a map that we will sort based on value. Used in Word Frequency
 * @brief Standard Selection Sort
 * @return The map now Sorted!
 */
void selectSort(std::map<std::string,int>& unsortMap, unsigned int size);


#endif //TEXTANAL_ALGORITHMS_H
