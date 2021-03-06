//
// Created by John Parkhurst on 1/19/2022.
//

#include "statistics.h"


void collectStats(std::map<std::string,int> wordM,std::vector<std::string>bookVec){
    wordFrequency(wordM,10);
    //std::cout << 5;
}

void wordFrequency(std::map<std::string,int> wordM, int size){
    if(size>wordM.size() || size<0){
        //Error in parameters size > size of map or -size
        exit(393); 
    }
    std::vector<std::pair<std::string,int>> mostOccur= sortByVal(wordM);
    /*
    std::cout << "Most Frequently Occured Words: " << std::endl;
    for(int i = 0; i <size; i++)
    {
        std::cout << mostOccur[i].first << ": " << mostOccur[i].second << std::endl;
    }
    */
}