//
// Created by jpark on 1/3/2022.
//


#include "computation.h"



void gatherStat(std::vector<std::string>bookVec,int numOfThread){
    pthread_t threads[numOfThread];
    int rc;
    struct inputStruct thrStruct[numOfThread];
    std::map<std::string, int>* foo;
    for(unsigned int i = 0; i < numOfThread; i++ ) {
        //FIlling the inputstruct with the values
        thrStruct[i].index = i;
        thrStruct[i].numOfThread = numOfThread;
        thrStruct[i].test = foo;
        thrStruct[i].bookP = &bookVec;
        rc = pthread_create(&threads[i], NULL, task, &thrStruct[i]);
        if (rc) {
            std::cout << "Error:unable to create thread," << rc << std::endl;
            exit(-1);
        }
        //This function below waits for the thread to exit before it continues
        pthread_join(threads[i], NULL);
    }
    //This exists the main threads
    //pthread_exit(nullptr);
    return;
}

void *task(void *rec_struct) {

    auto *struct_ptr = (struct inputStruct*) rec_struct;
    //How large the thread processes ex 4 threads of 100 lines do 25 each
    unsigned int size =struct_ptr->bookP->size()/struct_ptr->numOfThread;
    unsigned int ind = struct_ptr->index;
    //The start index of the pages to analyze
    unsigned int startInd = size*ind;
    std::vector<std::string> bookVec = *struct_ptr->bookP;
    std::map<std::string, int> mymap = *struct_ptr->test;
    //Iterate through our subsection!
    for(int i =startInd; i < startInd+size; i++){
        //We split each string by space then put into vector based on frequency
        //This is the string stream of our line
        std::stringstream ss(bookVec[i]);
        //Each individual word
        std::string inWord;

        while (ss>> inWord) {
            std::map<std::string, int>::iterator it = mymap.find(inWord);
            if(it != mymap.end()) {
                //Update
                it->second = it->second+1;
            }else{
                //Doesnt Exist so insert into map
                mymap.insert(std::make_pair(inWord,1));
            }
        }
    }
    //Print thru our map to check
    std::cout << "THIS MAP IS FOR THREAD: "<< ind << std::endl;
    for (const auto [key, value] : mymap) {
        std::cout << key << " : " << value << std::endl;
    }
    pthread_exit(nullptr);
}

void outputReport(){

}
