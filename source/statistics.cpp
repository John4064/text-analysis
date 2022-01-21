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
    std::cout << "FREQUENCY"<< std::endl;
    wordM=selectSort(*wordM);
    for( auto i: wordM){
    //for(int i = 0; i <5; i++){
        std::cout << i.first << " " << i.second << "\n";
    }
}