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

   if(!IsFull()){
        top++;
        array[top] = n;
    }
    else if (IsFull())
    {
        Resize(n);
    }
    else{
        throw StackFull();
    }
}

void Stack::Resize(int n){
    int newSize = num*2;
    int* newArray = new int[newSize];

    //Copy array contents over
    std::copy(array, array + std::min(num,newSize), newArray);

    delete [] array;
    array = newArray;

    Push(n);
}

void Stack::Pop(){

    if(top>=0){
        top--;
    }
    else{
        throw StackEmpty();
    }

}

int Stack::Top()const{
    
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

    return (top == (num-1));
 
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

