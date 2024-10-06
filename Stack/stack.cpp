#include <iostream>
#include <new>
#include "stack.h"

Stack::Stack(int n){

    array = new int [n];

    //Setting num to max allowed
    num = n;
    //0 is the beginning of the array so start at -1 upon creation
    top = -1;
}

Stack::~Stack(){
    delete [] array;
}

void Stack::Push(int n){
    
    //Perfect time to resize
    if (top==num-1)
    {
        //Doubles array size but Im not sure why it needs a parameter
        Resize(n);
        
        //Push again
        top++;
        array[top] = n;    
    }
    //This is the normal push method
    else if(top<num){
        top++;
        array[top] = n;
    }
    else{
        throw StackFull();
    }

}

void Stack::Resize(int n){
    //Setting temp array to double value
    num = num*2;
    int* tempArray = new int[num];

    //Copy array contents over
    for(int i=0;i<num;i++){
        tempArray[i] = array[i];
    }

    delete [] array;
    array = tempArray;
}

void Stack::Pop(){
    //Check if empty
    if(top>=0){
        top--;
    }
    else{
        throw StackEmpty();
    }

}

int Stack::Top()const{
    //Check if empty
    if(top != -1){
        return array[top];
    }
    else{
        throw StackEmpty();
    }
}

bool Stack::IsEmpty()const{
    //If array is empty it will be -1
    return (top==-1);
}

bool Stack::IsFull()const{
    //Quick empty check
    return (top == (num-1));
 
}

void Stack::MakeEmpty(){
    //No longer points to rest of stack
    top = -1;
}

int Stack::Size() const{
    //Size is top + 1
    return top+1;
}

int Stack::Capacity() const{
    //Capacity should just be allocated mem
    return num;
}

int Stack::Max() const{

     if(top==-1){
        throw StackEmpty();
    }
    //Tests array values against each other
    else{
        int max = array[0];
            for (int i = 1; i < top; i++) { 
                if (array[i] > max) { 
                max = array[i]; 
            } 
    }
    return max;
    }
} 

int Stack::Min() const{

    if(top==-1){
        throw StackEmpty();
    }
    //Tests array values against each other
    else{
        int min = array[0];
            for (int i = 1; i < top; i++) { 
                if (array[i] < min) { 
                min = array[i]; 
            } 
    }
    return min;
    }
}

int Stack::Peek(unsigned int n) const{
    //Check for overflow and empty 
    if(top>=n && top!=-1){
        return array[top-n];
    }
    else{
        throw StackInvalidPeek();
    }
}

