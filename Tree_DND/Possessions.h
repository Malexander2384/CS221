#ifndef POSSESSIONS_H
#define POSSESSIONS_H

#include "Item.h"
#include <string.h>


class Possessions
{
private:
    Item* m_pRoot = nullptr;
    void printAll(Item *rt);
public:

    bool addItem(Item *newItem);
    Item *dropItem(char *itemName);
    /* Used in in drop item for cases where there two child nodes
       of the parent*/
    Item* getSuccessor(Item* item);
    Item *getItem(char *itemName);

    void destroyTree(Item *rt);

    void printOne(Item *item);
    void printTree();


};








#endif