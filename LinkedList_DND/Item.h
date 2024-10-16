#ifndef ITEM_H
#define ITEM_H

#define BATTLE_ITEM   1
#define TREASURE_ITEM 2

struct Item
{
    char    m_sItemName[65];
    char    m_sDesc[128];
    int     m_iType;
    double  m_dValue;
    double  m_dWeight;
    Item    *left;
    Item    *right;
};

#endif

