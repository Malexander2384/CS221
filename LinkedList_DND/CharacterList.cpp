#include "CharacterList.h"
#include "Character.h"


bool CharacterList::addCharacter(Character *newCharacter)
{
    // Added Character for return
    Character* addedChar = new Character();
    addedChar = newCharacter;
    // Checking to see if head exists
    if(m_pHead == nullptr){
        // Updating Head
        addedChar->m_pNext = m_pHead;
        m_pHead = addedChar;

        return true;
    }
    else if(m_pHead != nullptr){
        
        Character **pp = &m_pHead;
        // Runs through the entire list and reorders using strcmp
        while (*pp != NULL && addedChar->compare_Char(addedChar, *pp) >= 0) {
        pp = &(*pp)->m_pNext;
    }

    addedChar->m_pNext = *pp;
    *pp = addedChar;

        return true;
    }
    else{
        return false;
    }
}



Character* CharacterList::deleteCharacter(char *characterName){
    // New object needed for the reuturn
    Character* removedChar = new Character();
    // Used to traverse the list
    Character* curr = m_pHead;
    Character* prev = nullptr;
    
    // Traverse till end of list
    while(curr != nullptr){
        if(strcmp(curr->getName(),characterName) == 0){
            // Setting the character to be removed here before any changes
            removedChar = curr;
            
            // Need to check if head is null
            if(prev == nullptr){
                m_pHead = curr->m_pNext;
            }
            else{
                prev->m_pNext = curr->m_pNext;
            }

            // Move to next node
            curr = curr->m_pNext;

            // Returning created char for function
            return removedChar;

        }
        else{
            prev = curr;
            curr = curr->m_pNext;
        }
    }

}


bool CharacterList::addItem(char *characterName, Item *newItem){

    // Used to traverse the list
    Character* curr = m_pHead;
    Character* prev = nullptr;
    
    // Traverse till end of list
    while(curr != nullptr){
        // Find the correct character        
        if(strcmp(curr->getName(),characterName) == 0){
            // Note add Item does the addition while returning info
            if(curr->addItem(newItem)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            prev = curr;
            curr = curr->m_pNext;
        }
    }
}

Item* CharacterList::getItem(char *characterName, char *itemName){

    Character* curr = m_pHead;
    Character* prev = nullptr;
    
    // Traverse till end of list
    while(curr != nullptr){
        // Find the correct character        
        if(strcmp(curr->getName(),characterName) == 0){
            // Note add Item does the addition while returning info
            if(curr->getItem(itemName)){
                return curr->getItem(itemName);
            }
            else{
                return nullptr;
            }
        }
        else{
            prev = curr;
            curr = curr->m_pNext;
        }
    }
}

Item* CharacterList::dropItem(char *characterName, char *itemName){
    
    Character* curr = m_pHead;
    Character* prev = nullptr;
    
    // Traverse till end of list
    while(curr != nullptr){
        // Find the correct character        
        if(strcmp(curr->getName(),characterName) == 0){
            return curr->dropItem(itemName);
        }
        else{
            prev = curr;
            curr = curr->m_pNext;
        }
    }
}

void CharacterList::printCharacters(){
    // Used for traversal
    Character* curr = m_pHead;

    // Iterates through and prints requited values
    while(curr != NULL){

        curr->printAll();

        curr = curr->m_pNext;
    }
    
}

// int main(){
// 	char Rimbard[] = "Aimbard";
// 	char Silverleaf[] = "Bilverleaf";
// 	char Grayhawk[] = "Crayhawk";
// 	char Marcus_Leonus[] = "Marcus_Leonus";

//     Character* player1 = new Character(Rimbard, 5, 1, 31, 11, 15, 14, 18, 18, 14);
//     Character* player2 = new Character(Silverleaf, 5, 1, 31, 11, 15, 14, 18, 18, 14);
//     Character* player3 = new Character(Grayhawk, 5, 1, 31, 11, 15, 14, 18, 18, 14);


//     CharacterList* theList = new CharacterList();
//     theList->addCharacter(player1);
//     theList->addCharacter(player2);
//     theList->addCharacter(player3);

//     theList->printCharacters();

// }

