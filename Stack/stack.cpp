#include <iostream>
#include <new>
#include "stack.h"

Stack::Stack(int n){
    //Creating array to the specified size
    array = new int [n];

    //0 is the beginning of the array so start at -1 upon creation
    top = -1;
}

Stack::~Stack(){
    //Should delete stack(I hope)
    delete [] array;
}

void Stack::Push(int n){
    //Add to the top of the stack and add value
    top++;
    array[top] = n;
}

void Stack::Pop(){
    //Try setting top to null
    try
    {
        //Check if stack is empty
        if(top>0){
            top--;
        }
    }
    //Throws to Exception Handling Class
    catch(StackEmpty){}
}

int Stack::Top()const{
    //Returns array at top
    return array[top];
}

bool Stack::IsEmpty()const{
    //If array is empty it will be -1
    return (top==-1);
}

bool Stack::IsFull()const{
    try
    {
        return (top == (num-1));
    }
    catch(StackFull){}    
}

void Stack::MakeEmpty(){
    top = -1;
}

int Stack::Size() const{

    int size = sizeof(array) / sizeof(array[0]);
    return size;
}

int Stack::Capacity() const{
    return num;
}
//####################################
int Stack::Max() const{
    return 0;
} 

int Stack::Min() const{
    return 0;
}

int Stack::Peek(unsigned int n) const{
    return 0;
}

