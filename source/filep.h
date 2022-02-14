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
#include <algorithm>

/**@param: filename is the file name(must be in inputs folder!
* @return: Returns a string of file name
*/
std::string stringConc(const char* filename);

/**
 * @param c This is the character which we are checking
 * @brief  Checks if the input character is an allowed character or not
 * @return 1 or 0 dependinf on if the character is allowed or not
 */
bool invalidChar(char c);

/**
 * @param inWord is a string we want to clean up
 * @brief just a garbage cleanup method that removes punctuation and other stuff from the word
 * @return The modified stream
 */
std::string cleanup(std::string inWord);
/**@param: The File name argument we recieved from CLI
* @brief: We open and read the File
* @return: Nothing
*/
std::vector<std::string> processFil(const char* argv);




#endif //TEXTANAL_FILEP_H
