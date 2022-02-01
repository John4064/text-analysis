//
// Created by john Parkhurst on 1/3/2022.
//


#include "computation.h"
#include "statistics.h"

//The Mutex for writing to our wordMap
std::mutex freqMtx;

void processText(std::vector<std::string>bookVec,int numOfThread){
    pthread_t threads[numOfThread];
    int rc;
    struct inputStruct thrStruct[numOfThread];
    //WordM is our word Frequency Map
    auto wordM = new std::map<std::string,int>;
    for(unsigned int i = 0; i < numOfThread; i++ ) {
        //Filling the input struct with the values desired(see struct for details)
        thrStruct[i].index = i;
        thrStruct[i].numOfThread = numOfThread;
        thrStruct[i].wordMap = wordM;
        thrStruct[i].bookP = &bookVec;
        rc = pthread_create(&threads[i], nullptr, task, &thrStruct[i]);
        if (rc) {
            std::cout << "Error:unable to create thread," << rc << std::endl;
            exit(-1);
        }
        //This function below waits for the thread to exit before it continues
        pthread_join(threads[i], nullptr);
    }
    //This exits the main threads
    //pthread_exit(nullptr);
    //After all the threads are complete we have wordM
    collectStats(*wordM, bookVec);
    //outputReport(*wordM);
    delete wordM;
}
void *task(void *rec_struct) {

    auto *struct_ptr = (struct inputStruct*) rec_struct;
    //How large the thread processes ex 4 threads of 100 lines do 25 each
    unsigned int size =struct_ptr->bookP->size()/struct_ptr->numOfThread;
    unsigned int ind = struct_ptr->index;
    //The start index of the pages to analyze
    unsigned int startInd = size*ind;
    //The vector the book is stored in & and word frequency map
    std::vector<std::string> bookVec = *struct_ptr->bookP;
    std::map<std::string, int>* wordL = struct_ptr->wordMap;
    //Iterate through our subsection!
    for(unsigned int i =startInd; i < startInd+size; i++){
        //We split each string by space then put into vector based on frequency
        //This is the string stream of our line
        std::stringstream ss(bookVec[i]);
        //Each individual word
        std::string inWord;
        while (ss>> inWord) {
            //Preprocess inWord For punctuation
            if(inWord.empty()){
                //Skips just empty
                continue;
            }
            //Determine if it is in vector
            freqMtx.lock();
            std::map<std::string, int>::iterator it = wordL->find(inWord);
            if(it != wordL->end()) {
                //Update
                it->second = it->second+1;
            }else{
                //Doesnt Exist so insert into map
                wordL->insert(std::make_pair(inWord,1));
            }
            freqMtx.unlock();
        }
    }
    pthread_exit(nullptr);
    return nullptr;
}
void outputReport(std::map<std::string,int> wordM){
    std::cout << "THIS MAP IS FOR MAIN THREAD: "<< std::endl;
    for (const auto& [key, value] : wordM) {
        std::cout << key << " : " << value << std::endl;
    }
}
