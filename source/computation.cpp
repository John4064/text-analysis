//
// Created by jpark on 1/3/2022.
//

#include "computation.h"



void gatherStat(std::vector<std::string>bookVec,int numOfThread){
    pthread_t threads[numOfThread];
    int rc;
    struct pair inputStruct[numOfThread];
    for(unsigned int i = 0; i < numOfThread; i++ ) {
        //FIlling the inputstruct with the values
        inputStruct[i].index = i;
        inputStruct[i].numOfThread = numOfThread;

        inputStruct[i].bookP = &bookVec;
        rc = pthread_create(&threads[i], NULL, task, &inputStruct[i]);
        if (rc) {
            std::cout << "Error:unable to create thread," << rc << std::endl;
            exit(-1);
        }
        //Optional may not need next line
        pthread_join(threads[i], NULL);
    }
    pthread_exit(nullptr);
    return;
}

void *task(void *rec_struct) {

    auto *struct_ptr = (struct pair*) rec_struct;
    //How large the thread processes ex 4 threads of 100 lines do 25 each
    unsigned int size =struct_ptr->bookP->size()/struct_ptr->numOfThread;
    unsigned int ind = struct_ptr->index;
    //The start index of the pages to analyze
    unsigned int startInd = size*ind;
    //Magic Happens Here




    pthread_exit(nullptr);
    void *p;
    return p;
}

void outputReport(){

}
