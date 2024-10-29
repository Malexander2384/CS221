#include "Possessions.h"

#include <iostream>


bool Possessions::addItem(Item *newItem){
    // TODO Remove if not tested
    // Check for null pointer
    if (!newItem){
        return false;
    }
    // If tree is empty, create root
    if (!m_pRoot){
        m_pRoot = newItem;
        newItem->m_pLeft = nullptr;
        newItem->m_pRight = nullptr;
        return true;
    }
   // These will be used to iterate through the list
    Item *current = m_pRoot;
    Item *parent = nullptr;

    // Traverse the tree to find the correct insertion point
    while (current){

        parent = current;
        
        // Compare item names
        int compareResult = strcmp(newItem->m_sItemName, current->m_sItemName);
        
        if (compareResult == 0){
        // Item with same name already exists
            return false;
        }
        // Check if new Item is higher than current 
        else if (compareResult < 0){
            current = current->m_pLeft;
        }
        else{
            current = current->m_pRight;
        }
    } 

    // Insert the new item
    if (strcmp(newItem->m_sItemName, parent->m_sItemName) < 0){
        parent->m_pLeft = newItem;
    }
    else{
        parent->m_pRight = newItem;
    }
    // Initialize the new item's pointers otherwise undefined behavior
    newItem->m_pLeft = nullptr;
    newItem->m_pRight = nullptr;

    return true;
}

Item* Possessions::getSuccessor(Item* current){

    current = current->m_pRight;
    while(current && current->m_pLeft){
        current = current->m_pLeft;
        return current;
    }
}

Item* Possessions::dropItem(char* itemName){

    // Null check for Root/Item 
    // TODO get rid of if not tested for
    if (!m_pRoot || !itemName){
      return nullptr;  
    } 
    
    // Used to iterate again
    Item* current = m_pRoot;
    Item* parent = nullptr;

    // Traverse the tree to find the item
    while (current){

        int compareResult = strcmp(itemName, current->m_sItemName);

        // Found the item
        if (compareResult == 0){

            Item* itemToReturn = nullptr;
            
            // Root node with no children
            if (current == m_pRoot && !current->m_pLeft && !current->m_pRight){
                itemToReturn = m_pRoot;
                m_pRoot = nullptr;
                return itemToReturn;
            }
            
            // Root node with one child
            if (current == m_pRoot && (!current->m_pLeft || !current->m_pRight)){
                itemToReturn = m_pRoot;
                if(current->m_pLeft){
                    m_pRoot = current->m_pLeft;
                }
                else{
                    m_pRoot = current->m_pRight;
                }
                itemToReturn->m_pLeft = itemToReturn->m_pRight = nullptr;
                return itemToReturn;
            }
            
            // Root node with two children or any other node
            if (!current->m_pLeft || !current->m_pRight){
                // One or no child cases
                Item* child;
                if(current->m_pLeft){
                    child = current->m_pLeft;
                }
                else{
                    child = current->m_pRight;
                }
                if (parent){
                    if (parent->m_pLeft == current)
                        parent->m_pLeft = child;
                    else
                        parent->m_pRight = child;
                } 
                else{
                    m_pRoot = child;
                }
                
                itemToReturn = current;
                itemToReturn->m_pLeft = itemToReturn->m_pRight = nullptr;
                return itemToReturn;
            } 
            else{
                // Two children case
                // Find the successor (smallest item in right subtree)
                Item* succParent = current;
                Item* succ = current->m_pRight;
                
                while (succ->m_pLeft){
                    succParent = succ;
                    succ = succ->m_pLeft;
                }
                
                // Create duplicate of current node before overwriting
                itemToReturn = new Item(*current);
                itemToReturn->m_pLeft = itemToReturn->m_pRight = nullptr;
                
                // If successor is not the right child
                if (succParent != current){
                    succParent->m_pLeft = succ->m_pRight;
                    succ->m_pRight = current->m_pRight;
                }
                
                succ->m_pLeft = current->m_pLeft;
                
                if (parent){
                    if (parent->m_pLeft == current){
                        parent->m_pLeft = succ;
                    }
                    else{
                        parent->m_pRight = succ;
                    }
                } 
                else{
                    m_pRoot = succ;
                }
                
                delete current;
                return itemToReturn;
            }
        }
        
        // Continue searching
        parent = current;
        if (compareResult < 0){
            current = current->m_pLeft;
        }
        else{
            current = current->m_pRight;
        }
    }
    
    return nullptr;  
}


Item* Possessions::getItem(char *itemName){
    // These will be used to iterate through the list
    Item *current = m_pRoot;
    Item *parent = nullptr;

    // Traverse the tree to find the correct insertion point
    while (current) {

        parent = current;
        
        // Compare item names
        int compareResult = strcmp(itemName, current->m_sItemName);
        
        if (compareResult == 0) {
            return current;
        }
        // Check if new Item is higher than current 
        else if (compareResult < 0) {
            current = current->m_pLeft;
        }
        else {
            current = current->m_pRight;
        }
    }
    return nullptr;
}

void Possessions::printOne(Item* item){
    if(item){
        std::cout<<"Item Name: "<<item->m_sItemName<<"\n";
        std::cout<<"Item Value: "<<item->m_dValue<<"\n";
        std::cout<<"Item Weight: "<<item->m_dWeight<<"\n";
        std::cout<<"Item Description: "<<item->m_sDesc<<"\n";
    }
}

void Possessions::printAll(Item *rt){
    if (rt) {
        printOne(rt->m_pLeft);
        printOne(rt);
        printOne(rt->m_pRight);
    }
}

void Possessions::printTree(){
    printAll(m_pRoot);
}


// int main() {
//     char Staff[] = "Staff";
// 	char Spellbook[] = "Spellbook";
// 	char Sword[] = "Sword";
    

//     Item* item = new Item;
// 	strcpy(item->m_sItemName, Staff);
// 	item->m_dValue = 5;
// 	item->m_dWeight = 1;

//     Item* item2 = new Item;
// 	strcpy(item2->m_sItemName, Spellbook);
// 	item2->m_dValue = 5;
// 	item2->m_dWeight = 1;

//     Item* item3 = new Item;
// 	strcpy(item3->m_sItemName, Sword);
// 	item3->m_dValue = 5;
// 	item3->m_dWeight = 1;

//     Possessions* pos = new Possessions();
//     Possessions* Test = pos;

//     Test->addItem(item);
//     Test->addItem(item2);
//     Test->addItem(item3);
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//     Test->printTree();


//     // std::cout << "In-order traversal: ";
//     // Test->printOne(Test->m_pRoot);
//     std::cout << std::endl;

//     // Item* getTest = Test->getItem(Sword);
//     // std::cout<< getTest->m_sItemName<< "\n";

//     // Test->dropItem(Sword);

//     // std::cout << "In-order traversal: ";
//     // Test->printOne(Test->m_pRoot);
//     std::cout << std::endl;

//     return 0;
// }