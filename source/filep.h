//
// Created by jpark on 1/3/2022.
//

#ifndef TEXTANAL_FILEP_H
#define TEXTANAL_FILEP_H
//This is the default directory location for input
#define inputloc "../inputs/"

#include <fstream>
#include <vector>
#include <iostream>
#include <fstream>

/**@param: filename is the file name(must be in inputs folder!
* @return: Returns a string of file name
*/
std::string stringConc(const char* filename);

/**@param: The File name argument we recieved from CLI
* @brief: We open and read the File
* @return: Nothing
*/
std::vector<std::string> processFil(const char* argv);

#endif //TEXTANAL_FILEP_H
