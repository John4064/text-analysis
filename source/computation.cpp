//
// Created by jpark on 1/3/2022.
//

#include "computation.h"


void gatherStat(std::vector<std::string>bookVec,int numOfThread){
    pthread_t threads[numOfThread];
    int rc;
    for(int i = 0; i < numOfThread; i++ ) {
        std::cout << "main() : creating thread, " << i << std::endl;
        rc = std::pthread_create(&threads[i], NULL, task, (void *)i);

        if (rc) {
            std::cout << "Error:unable to create thread," << rc << std::endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return;
}
void task(void *threadid) {
    std::cout << 1;
    return;
}

void outputReport(){

}
