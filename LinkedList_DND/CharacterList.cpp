#include "CharacterList.h"
#include "Character.h"


bool CharacterList::addCharacter(Character *newCharacter)
{

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
    
    Character* removedChar = new Character();
    Character* prev = m_pHead;

    if (m_pHead != nullptr && strcmp(m_pHead->getName(),characterName)) {
        m_pHead = m_pHead->m_pNext; // Changed head
        removedChar = m_pHead;
        delete m_pHead; // Free old head
        return removedChar;
    }

}

bool CharacterList::addItem(char *characterName, Item *newItem){
    return false;
}

Item* CharacterList::getItem(char *characterName, char *itemName){
    Item* test = nullptr;
    return test;
}

Item* CharacterList::dropItem(char *characterName, char *itemName){
    Item* test = nullptr;
    return test;    
}

void CharacterList::printCharacters(){
    return;
}

