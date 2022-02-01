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
#include <algorithm>

/** @var index is an integer that tells you which thread in order it is
 * @var numOfThread lets it know how many threads are there
 * @var bookP is the pointer to the saved book we are analyzing
 * @var wordFreq is a pointer to the vector we are saving our word frequency too
 */
struct inputStruct{
    unsigned int index, numOfThread;
    std::vector<std::string>* bookP;
    //std::vector<std::pair <std::string,int>>* wordFreq;
    std::map<std::string,int>* wordMap;
};



/**
 * @param: The book saved as a vector of strings, numThread is the number of threads to be created
 * @brief: This is the "main function" creates all the other threads based on the number given
 */
void processText(std::vector<std::string>bookVec,int numOfThread);

/**
 * @param threadid This is the inputStruct above it contains index of thread, numofthreads that exist and the book
 * @brief The brains behind the application: Iterates through its subsection of book depending on #threads,
 * And from there it itemizes each element in the book into a map.
 * @return
 */
void *task(void *threadid);

void outputReport(std::map<std::string,int> wordM);

#endif //TEXTANAL_COMPUTATION_H
