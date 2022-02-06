//
// Created by John Parkhurst on 1/19/2022.
//

#include "statistics.h"


void collectStats(std::map<std::string,int> wordM,std::vector<std::string>bookVec){
    wordFrequency(wordM,100);
    //Could display as top 15 most common words, percentage it appears compared to all words
    //Could group certain words like colors
    //Remove determiners
    //std::cout << 5;
}

void wordFrequency(std::map<std::string,int> wordM, int size){
    if(size>wordM.size() || size<0){
        //Error in parameters size > size of map or -size
        exit(393);
    }
    std::cout << "Test Report"<< std::endl;
    //Code Breaking Line here
    std::vector<std::pair<std::string,int>> mostOccur= sortByVal(wordM);
    std::cout <<"The Size of Vector is: "<< mostOccur.size()<< std::endl;
    std::cout << "The map, sorted by value is: " << std::endl;
    for(int i = 0; i <size; i++)
    {
        std::cout << mostOccur[i].first << ": " << mostOccur[i].second << std::endl;
    }
}

void sentSimilairty(std::vector<std::string>bookVec){

}