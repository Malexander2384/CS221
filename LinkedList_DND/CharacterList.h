#ifndef CHARACTERLIST_H
#define CHARACTERLIST_H

#include "Character.h"

class CharacterList
{
private:
    Character* m_pHead;
public:

    bool addCharacter(Character *newCharacter);

    Character *deleteCharacter(char *characterName);

    bool addItem(char *characterName, Item *newItem);

    Item *getItem(char *characterName, char *itemName);

    Item *dropItem(char *characterName, char *itemName);
    
    void printCharacters();

};


#endif