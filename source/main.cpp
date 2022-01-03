#include <iostream>
#include <thread>
#include <string>
#include <regex>
#include <fstream>
#include "filep.h"


#define multithread	0

#if multithread
    void test(int a){
        std::cout<< a;
    }
#endif
//

void processFil(const char* argv){
    /**@param: The File name argument we recieved from CLI
     * @brief: We open and read the File
     *
     * @return: Nothing
     */
    //Open the File specified
    std::string filename = "../inputs/sun.txt";
    FILE* fil = openF(argv);
    //Read the File
    char buffer [255];
    while (!feof (fil) )
    {
        if ( fgets (buffer , 255 , fil) == NULL ) {
            break;
        }
        fputs (buffer , stdout);
    }
    //Cleanup
    std::cout << "REACHED!\n";
    fclose(fil);
    return;
}

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
    std::cout << "RUN PARRALEL PROCESSES!\n";
    //The beginning Step you may say!
    processFil(argv[1]);

    return 0;
}
