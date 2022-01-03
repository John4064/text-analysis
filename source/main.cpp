#include <iostream>
#include <thread>
#include <string>
#include <regex>

#define multithread	0
int main(int argc, char *argv[]) {

    //Input Handling
    #if multithread
        std::cout << "This Version is multithreaded \n";
    #endif
    //Check that argv[1] contains text file
    std::string s = argv[1];
    if (regex_match (s, std::regex("(../inputs/)(.*)") )){
        std::cout << argv[1]<< " MATCHED THE REGEX\n";
    }else{
        std::cout << argv[1] << " NO MATCH FOUND FOR REGEX\n";
    }


    return 0;
}
