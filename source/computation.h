//
// Created by jpark on 1/3/2022.
//

#ifndef TEXTANAL_COMPUTATION_H
#define TEXTANAL_COMPUTATION_H

#include <vector>
#include <string>
#include <pthread.h>
#include <iostream>



/**
 * @param: The book saved as a vector of strings, numThread is the number of threads to be created
 * @brief: This will iterate through based on the number of threads and gather a bunch of statistics
 */
void gatherStat(std::vector<std::string>bookVec,int numOfThread);

void task(std::vector<std::string>bookVec);

void outputReport();
#endif //TEXTANAL_COMPUTATION_H
