//
// Created by jpark on 1/19/2022.
//

#ifndef TEXTANAL_STATISTICS_H
#define TEXTANAL_STATISTICS_H

#include <map>
#include <iostream>
#include <vector>
#include <string>
#include "algorithms.h"

/**
 * @param wordM The word map that contains all the words in the file and their frequency
 * @param bookVec The book itself saved as a vector. Could be used for collocation later down the line
 * @brief This function primarily is where we go and call all specific statistics such as Collocation,Concordance,classification
 * Will must likely call an output function itself which then in turn redirects all output to logs/report
 * @return Nothing at the moment
 */
void collectStats(std::map<std::string,int> wordM, std::vector<std::string>bookVec);

/**
 * NOTE TO SELF COULD REFACTOR THIS IN FUTURE TO ACCOUNT FOR MULTI INPUT, like most frequent phrase and word
 * @param wordM The word map that contains all the words in the file and their frequency
 * @param size determines how many words we display(top 10,25,50)
 * @brief Just output a ranking of top size words(10,20,30)
 */
void wordFrequency(std::map<std::string,int> wordM, int size);

/***
 * @param bookVec: All the sentences of the book put into a vector
 */
void sentSimilairty(std::vector<std::string>bookVec);
#endif //TEXTANAL_STATISTICS_H
