#include "CharacterList.h"

bool CharacterList::addCharacter(Character *newCharacter)
{
    if(m_pHead == nullptr){
        Character* addedChar = new Character();
        addedChar = newCharacter;
        addedChar->m_pNext = m_pHead;
        m_pHead = addedChar;

        return true;
    }
    // else if(m_pHead != nullptr{
    //     return
    // }

    return true;
} 



Character* CharacterList::deleteCharacter(char *characterName){
    Character* test = nullptr;
    return test;
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

