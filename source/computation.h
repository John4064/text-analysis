//
// Created by jpark on 1/3/2022.
//

#ifndef TEXTANAL_COMPUTATION_H
#define TEXTANAL_COMPUTATION_H

#include <vector>
#include <string>
#include <pthread.h>
#include <thread>
#include <iostream>
#include <mutex>
#include <map>
#include <sstream>
//#include <bits/stdc++.h>

struct inputStruct{
    unsigned int index, numOfThread;
    std::map<std::string, int> *test;
    std::vector<std::string>* bookP;
};


/**
 * @param: The book saved as a vector of strings, numThread is the number of threads to be created
 * @brief: This is the "main function" creates all the other threads based on the number given
 */
void gatherStat(std::vector<std::string>bookVec,int numOfThread);

/**
 * @param threadid This is the inputStruct above it contains index of thread, numofthreads that exist and the book
 * @brief Description
 * @return
 */
void *task(void *threadid);

void outputReport();
#endif //TEXTANAL_COMPUTATION_H
