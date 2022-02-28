//
// Created by jpark on 1/19/2022.
//

#ifndef TEXTANAL_ALGORITHMS_H
#define TEXTANAL_ALGORITHMS_H


#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

/**Depracated Dead Code
 * @param target The first pair we are swapping with the second(dest)
 * @param dest the second pair we are swapping with the first(target)
 * @brief A simple swap function can be modified easily for different dataStructures
 * @return: return a boolean expression to differentiate which is greater
 */
bool swapVal(const std::pair<std::string, int> &target,const std::pair<std::string, int> &dest);




/**
 * @param unsortMap Is a map that we will sort based on value. Used in Word Frequency
 * @brief Standard Selection Sort
 * @return The map now Sorted!
 */
std::vector<std::pair<std::string,int>> sortByVal(std::map<std::string,int>& unsortMap);


#endif //TEXTANAL_ALGORITHMS_H
