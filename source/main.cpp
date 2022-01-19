
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <chrono>
#include "filep.h"
#include "computation.h"


#define numThread 4


int main(int argc, char *argv[]) {
    //Correct amt of arguments
    if (argc != 2) {
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
    std::cout << "Processing File As we Speak!\n";
    //The beginning Step you may say! It opens and reads the book
    std::vector<std::string> bookVec =processFil(argv[1]);
    //Here we gather the Statistics
    auto start = std::chrono::high_resolution_clock::now();

    processText(bookVec,numThread);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    //In the report we output  Thread # and time efficiency
    std::cout << "The Execution Time for "<<numThread<<" threads was "<< duration.count()*.000001 << " Seconds"<<std::endl;
    return 0;
}
