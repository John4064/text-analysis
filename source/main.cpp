#include <thread>
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include "filep.h"


#define multithread	0

#if multithread
    void test(int a){
        std::cout<< a;
    }
#endif
//



int main(int argc, char *argv[]) {
    //Correct amt of arguments
    if (argc == 3) {
        std::cout << ("error: missing command line arguments\n");
        exit(41);
    }
    //Check that argv[1] contains text file
    if (!regex_search (argv[1], std::regex(".txt$") )){
        std::cout << argv[1] << " has an Invalid Filetype Must be txt File\n";
        exit(42);
    }
    //Input Handling
    #if multithread
        std::cout << "This Version is multithreaded \n";
        exit(59);
    #endif
    std::cout << "RUN PARALLEL PROCESSES!\n";
    //The beginning Step you may say! It opens and reads the book
    std::vector<std::string> bookVec =processFil(argv[1]);
    

    return 0;
}
