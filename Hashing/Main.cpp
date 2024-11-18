#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

#define TABLESIZE 100
#define KEYSIZE 4
#define EMPTYKEY "----"
#define DATAFILE "P4DATA.TXT"


// Define the structure for use in the hash table
struct HashStruct {
    char key[5];
    int data;
};

// Modulus is needed to avoid seg faults because the values become too big for the table

// Djb2
unsigned long Hash_1(const char* key) {
    unsigned long hash = 5381;
    for(int i = 0; key[i]; i++) {
        hash = ((hash << 5) + hash) + key[i];
    }
    return hash % TABLESIZE;
}
// fnv1a
unsigned long Hash_2(const char* key){
    unsigned long hash_value = 2166136261u;
    for(int i = 0; key[i]; i++){
        hash_value ^= key[i];
        hash_value *= 16777619u;
    }
    return hash_value % TABLESIZE;
}
// Stack
int Hash_3(const char* key) {
    int hash_value = 0;
    for (int i = 0; i < sizeof(key); i++) {
        hash_value += key[i] * std::pow(31, i);
    }
    return hash_value % TABLESIZE;
}

int ProbeDec_1(const char* key) {
    return 1;
}
int ProbeDec_2(const char* key) {
    return (Hash_1(key) % 31) + 1;
}
int ProbeDec_3(const char* key) {
    return 31 - (Hash_1(key) % 31);
}

//===========================================================================
// Snippet 5: Hash Insert function
int HashInsert(HashStruct T[], char *key, int data, int hNum, int dhNum) {
    int testNum = (hNum * 3) + dhNum;
    int colCount = 0;
    int hashIndex, probeDec;

    switch(testNum) {
        case 0: // Hash function 1 -- Double hash 1 (linear probing)
            hashIndex = Hash_1(key);
            probeDec = ProbeDec_1(key); break;
        case 1: // Hash function 1 -- Double hash 2
            hashIndex = Hash_1(key);
            probeDec = ProbeDec_2(key); break;
        case 2: // Hash function 1 -- Double hash 3
            hashIndex = Hash_1(key);
            probeDec = ProbeDec_3(key); break;
        case 3: // Hash function 2 -- Double hash 1 (linear probing)
            hashIndex = Hash_2(key);
            probeDec = ProbeDec_1(key); break;
        case 4: // Hash function 2 -- Double hash 2
            hashIndex = Hash_2(key);
            probeDec = ProbeDec_2(key); break;
        case 5: // Hash function 2 -- Double hash 3
            hashIndex = Hash_2(key);
            probeDec = ProbeDec_3(key); break;
        case 6: // Hash function 3 -- Double hash 1 (linear probing)
            hashIndex = Hash_3(key);
            probeDec = ProbeDec_1(key); break;
        case 7: // Hash function 3 -- Double hash 2
            hashIndex = Hash_3(key);
            probeDec = ProbeDec_2(key); break;
        case 8: // Hash function 3 -- Double hash 3
            hashIndex = Hash_3(key);
            probeDec = ProbeDec_3(key); break;
    }

    // Find a place to insert into the table
    while(strcmp(T[hashIndex].key, EMPTYKEY) != 0) {
        colCount++;
        hashIndex -= probeDec; 
        if(hashIndex < 0) 
            hashIndex += TABLESIZE; 
    }

    // Add code to insert key and data into the table at index `hashIndex`

    strcpy(T[hashIndex].key, key);
    T[hashIndex].data = data;
    
    return colCount; // Return collision count
}

//===========================================================================
void InitTable(HashStruct hashT[], int TableSize) {
    for(int i=0; i<TableSize; i++) {
        strcpy(hashT[i].key, EMPTYKEY);
        hashT[i].data = 0;
    }
}
// Snippet 4: Initialize table function

int main(){
    //===========================================================================
    // Snippet 1: Partial list of variables defined in main()
    int i, hashNum, dHashNum, count;
    std::ifstream *inFile;
    HashStruct T[100]; // Hash table array of 100 data structures
    char line[64]; // Array to hold lines read from file
    char key[5]; // Array to hold 4-character keys
    int data; // Integer data


    //===========================================================================
    // Snippet 2: The following code can be used to perform the 9 tests.
    for(hashNum = 0; hashNum < 3; hashNum++) {
        for(dHashNum = 0; dHashNum < 3; dHashNum++) {
            InitTable(T, TABLESIZE); // Initialize table to empty
            inFile = new std::ifstream();

            inFile->open(DATAFILE, std::ifstream::in); // Open data file for this test
            
            if(!inFile->is_open()) {
                std::cout << "Unable to open data file. Program terminating\n";
            }
            
            count = 0; // Initialize collision counter
            
            for(int i = 0; i < 50; i++) {
                inFile->getline(line, 64, '\n');
                sscanf(line, "%s %d", key, &data);
                count += HashInsert(T, key, data, hashNum, dHashNum);
            }
            //==========================================================================
            // Snippet 3: Code to create a diagram of results of a single test.
            std::cout << "Testing hash function " << hashNum+1 << " using double hash " << dHashNum+1 << ".\n";
            std::cout << "Total collisions = " << count << ".\n";

            // Show form of array
            for(int i=0; i < TABLESIZE; i++) {
                if(strcmp(T[i].key, EMPTYKEY)) // Key is NOT EMPTYKEY

                    std::cout << "|"; // Indicate an entry at this location
                else 
                    std::cout << "-"; // Indicate no entry at this location
            }
            std::cout << "\n\n";
            
            inFile->close(); // Close the text file
            delete inFile;
        }
    }

}