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

bool invalidChar (char c) 
{  
	//Checks if characters are A-Z, a-z, 0-9, "-", " ' " or space
	//The characters above are the allowed characters

	
	
	std::string inChar{c};
	std::string  pattern = "[- 'a-zA-Z0-9]";
	return !(std::regex_match(inChar, std::regex(pattern)));
} 

//Test
std::string cleanup(std::string inWord) {
	//Remove all characters according to the invalidChar function above
	inWord.erase(remove_if(inWord.begin(),inWord.end(),invalidChar),inWord.end());

    //Convert to all lowercase: .02 to .03 with 25 values printed runtime ideal
    transform (inWord.begin(), inWord.end(), inWord.begin(), ::tolower);
    return inWord;
}

std::vector<std::string> processFil(const char* argv){

    //Open the File specified
    std::string filName = stringConc(argv);
	std::cout << filName << std::endl;
    //Read the File
    std::ifstream fil(filName);
    std::string buffer;
    std::vector<std::string> bookVec;
    if(fil.is_open()){
        while (getline (fil, buffer)) {
            buffer = cleanup(buffer);
            //Checks buffer isnt empty!
            if(buffer.empty()){
                continue;
            }
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
