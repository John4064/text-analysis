//
// Created by jpark on 1/3/2022.
//

#include "filep.h"

std::string stringConc(const char* filename){
    //Some string Concatenation to combine the default input location and filenbame provided
    std::string fileString;
    fileString.append(inputloc);
    fileString.append(filename);
    //open file
    return fileString;
}

std::vector<std::string> processFil(const char* argv){

    //Open the File specified
    std::string filName = stringConc(argv);
    //Read the File
    std::ifstream fil(filName);
    //fil.open(filName, std::ofstream::in);
    std::string buffer;
    std::vector<std::string> bookVec;
    if(fil.is_open()){
        while (getline (fil, buffer)) {
            // Output the text from the file
            bookVec.push_back(buffer);
        }
    }
    //cleanup
    fil.close();
    return bookVec;
}