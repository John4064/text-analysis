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
    //CHECK SIZE OF BOOK If not an even number Add another blank line for proper calculations
    int remain = bookVec.size()%2;
    if(remain != 0){
        bookVec.push_back(" ");
    }

    //cleanup
    fil.close();
    return bookVec;
}