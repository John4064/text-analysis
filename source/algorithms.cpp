//
// Created by jpark on 1/19/2022.
//

#include "algorithms.h"


void swap(std::pair<std::string, int>& target, std::pair<std::string, int>& dest){


}

auto increment(std::pair<std::string, int> target){
    if(target.first == "you"){
        std::cout <<"Triggers";
        target.second = 7;
    }
    return target;
}


void selectSort(std::map<std::string,int>& unSortedMap, unsigned int size){
    //Makes sure it is the right size
    if (size>unSortedMap.size()){
        size = unSortedMap.size();
    }
    //Iterates through the entire map
    std::transform(unSortedMap.begin(),unSortedMap.end(), std::inserter(unSortedMap,unSortedMap.end()), increment);
    // Iterate over the map using c++11 range based for loop
    //unSortedMap["Earth"] = 5;
    //TEST CODE
    // std::cout << "Testing Pointers EARTH IS:  " <<unSortedMap["Earth"]<< std::endl;
    return;
}
