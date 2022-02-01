//
// Created by jpark on 1/19/2022.
//

#include "algorithms.h"


bool swapVal(const std::pair<std::string, int> &target,const std::pair<std::string, int> &dest){
    return (target.second > dest.second);
}

std::vector<std::pair<std::string,int>> sortByVal(std::map<std::string,int>& unSortedMap){
    //Create Empty Vector
    std::vector<std::pair<std::string,int>> valVector;
    // Iterate over the map copying the key-value pairs over to the vector
    std::map<std::string, int> :: iterator it2;
    for (it2=unSortedMap.begin(); it2!=unSortedMap.end(); it2++)
    {
        valVector.emplace_back(it2->first, it2->second);
    }

    sort(valVector.begin(), valVector.end(), swapVal);


    return valVector;
}
