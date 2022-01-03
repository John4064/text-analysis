//
// Created by jpark on 1/3/2022.
//

#include "filep.h"

FILE* openF(const char* filename){
    /**@param: filename is the file name!
     * @return: Returns a pointer to a file structure
     */
    FILE* fil;
    //Some string Concatenation to combine the default input location and filenbame provided
    std::string fileString;
    fileString.append(inputloc);
    fileString.append(filename);
    fil = std::fopen(fileString.c_str(),"r");
    if (fil == NULL){
        perror ("Error opening file");
        exit(43);
    }else{
        return fil;
    }
}
