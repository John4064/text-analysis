//
// Created by jpark on 1/3/2022.
//

#include "computation.h"


void gatherStat(std::vector<std::string>bookVec,int numOfThread){
    pthread_t threads[numOfThread];
    int rc;
    for(unsigned int i = 0; i < numOfThread; i++ ) {
        rc = pthread_create(&threads[i], NULL, task, (void *)i);
        if (rc) {
            std::cout << "Error:unable to create thread," << rc << std::endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return;
}

void *task(void *threadid) {
    unsigned int tid;
    tid = (unsigned int)threadid;

    std::cout << "Hello World! Thread ID, " << 5 << std::endl;
    pthread_exit(NULL);
    void *p = &tid;
    return p;
}

void outputReport(){

}
