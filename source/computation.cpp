//
// Created by jpark on 1/3/2022.
//


#include "computation.h"



void gatherStat(std::vector<std::string>bookVec,int numOfThread){
    pthread_t threads[numOfThread];
    int rc;
    struct inputStruct thrStruct[numOfThread];
    //std::vector<std::pair<std::string, int>*> foo;
    int d = 5;
    for(unsigned int i = 0; i < numOfThread; i++ ) {
        //FIlling the inputstruct with the values
        thrStruct[i].index = i;
        thrStruct[i].numOfThread = numOfThread;
        //thrStruct[i].wordL = foo;
        thrStruct[i].bookP = &bookVec;
        thrStruct[i].funtime = &d;
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
    std::cout << d << std::endl;
    return;
}

std::string cleanup(std::string inWord){
    inWord=removeChar(inWord,'.');
    inWord=removeChar(inWord,',');
    inWord=removeChar(inWord,'"');
    inWord=removeChar(inWord,'?');
    inWord=removeChar(inWord,';');
    inWord=removeChar(inWord,'!');
    inWord=removeChar(inWord,'(');
    inWord=removeChar(inWord,')');
    inWord=removeChar(inWord,':');
    //May remove numbers not sure.
    return inWord;
}

void *task(void *rec_struct) {

    auto *struct_ptr = (struct inputStruct*) rec_struct;
    //How large the thread processes ex 4 threads of 100 lines do 25 each
    unsigned int size =struct_ptr->bookP->size()/struct_ptr->numOfThread;
    unsigned int ind = struct_ptr->index;
    //The start index of the pages to analyze
    unsigned int startInd = size*ind;
    std::vector<std::string> bookVec = *struct_ptr->bookP;
    //Example how to modify with a basic int
    int* test = struct_ptr->funtime;
    *test+=1;
    
    //std::map<std::string, int>* mymap = struct_ptr->wordL;
    //Iterate through our subsection!
    for(int i =startInd; i < startInd+size; i++){
        //We split each string by space then put into vector based on frequency
        //This is the string stream of our line
        std::stringstream ss(bookVec[i]);
        //Each individual word
        std::string inWord;
        while (ss>> inWord) {
            //Preprocess inword For punctuation
            inWord=cleanup(inWord);
            //mymap->insert(std::make_pair("abc",5));
            /*
            if(inWord.empty()){
                //Skips just empty periods
                continue;
            }
            std::map<std::string, int>::iterator it = mymap->find(inWord);
            if(it != mymap->end()) {
                //Update
                it->second = it->second+1;
            }else{
                //Doesnt Exist so insert into map
                mymap->insert(std::make_pair(inWord,1));
            }
             */
        }
    }
    //Made It here
    std::cout << *test<<'\n';
    /*
    //Print thru our map to check
    std::cout << "THIS MAP IS FOR THREAD: "<< ind << std::endl;
    for (const auto [key, value] : mymap) {
        std::cout << key << " : " << value << std::endl;
    }
     */
    //Without this print it goes roughly .009 seconds for 4 threads

    pthread_exit(nullptr);
    return nullptr;
}

std::string removeChar(std::string str, char bad){
    str.erase(remove(str.begin(),str.end(),bad),str.end());
    return str;
}

void outputReport(){

}
