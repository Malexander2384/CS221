#include "Character.h"


Character::Character(){

}
Character::Character(char *name, int clas, int alignment, int hitpoints, int strength,
	int dexterity, int constitution, int intelligence, int wisdom,int charisma){
    //Setters for normal
    setName(name);
    setClass(clas);
    setAlignment(alignment);
    setHitPoints(hitpoints);

    //Setters for array 
    setStrength(strength);
    setDexterity(dexterity);
    setConstitution(constitution);
    setIntelligence(intelligence);
    setWisdom(wisdom);
    setCharisma(charisma);
}

Character::~Character(){

}

char* Character::getName(){
    return m_sName;
}

void Character::setName(char *name){
    for(int i=0; i<sizeof(m_sName); i++){
        m_sName[i] = name[i];
    }
}

// The get functions for Class, Alignment, and Hit Points
int Character::getClass(){
    return m_iClass; 
}			        
void Character::setClass(int cl){
    m_iClass = cl;
}			

int Character::getAlignment(){
    return m_iAlignment;
}		
void Character::setAlignment(int al){
    m_iAlignment = al;
}


int Character::getHitPoints(){
    return m_iHitPoints;
}
void Character::setHitPoints(int hp){
    m_iHitPoints = hp;
}

// Char traits get/set methods

int Character::getStrength(){
    return m_iCharTraits[0];
}		        
void Character::setStrength(int str){
    m_iCharTraits[0] = str;
}

int Character::getDexterity(){
    return m_iCharTraits[1];
}
void Character::setDexterity(int dex){
    m_iCharTraits[1] = dex;
}	

int Character::getConstitution(){
    return m_iCharTraits[2];
}
void Character::setConstitution(int cn){
    m_iCharTraits[2] = cn;
}	

int Character::getIntelligence(){
    return m_iCharTraits[3];
}	 
void Character::setIntelligence(int itl){
    m_iCharTraits[3] = itl;
}

int Character::getWisdom(){
    return m_iCharTraits[4];
}		        
void Character::setWisdom(int wis){
    m_iCharTraits[4] = wis;
}

int Character::getCharisma(){
    return m_iCharTraits[5];
}
void Character::setCharisma(int chr){
    m_iCharTraits[5] = chr;
}

void Character::printAll(){
    std::cout<<"Name: "<<getName()<<"\n";
    std::cout<<"Class: "<<getClass()<<"\n";
    std::cout<<"Alignment: "<<getAlignment()<<"\n";
    std::cout<<"HitPoints: "<<getHitPoints()<<"\n";
    std::cout<<"Strength: "<<getStrength()<<"\n";
    std::cout<<"Dexterity: "<<getDexterity()<<"\n";
    std::cout<<"Constitution: "<<getConstitution()<<"\n";
    std::cout<<"Intelligence: "<<getIntelligence()<<"\n";
    std::cout<<"Wisdom: "<<getWisdom()<<"\n";
    std::cout<<"Charisma: "<<getCharisma()<<"\n";

    for(int i=0;i<itemCount;i++){
        std::cout<<"\n"<<m_Items[i].m_sItemName<<": "<<"\n";
        std::cout<<"Value is "<<m_Items[i].m_dValue<<"\t"<<"||"<<"\t"<<"Weight is "<<m_Items[i].m_dWeight;
    }
}

//TODO charname.next for print all?

bool Character::addItem(Item *item){

    
    if(length>itemCount){
        //Set values to imputted item
        m_Items[itemCount].m_dValue = item->m_dValue;
        m_Items[itemCount].m_dWeight = item->m_dWeight;
        m_Items[itemCount].m_iType = item->m_iType;
        m_Items[itemCount].right = item->right;
        m_Items[itemCount].left = item->right;
        strcpy(m_Items[itemCount].m_sDesc,item->m_sDesc);
        strcpy(m_Items[itemCount].m_sItemName,item->m_sItemName);

        //Update Count
        itemCount++;

        return true;
    }
    else{
        return false;
    }
}


Item *Character::getItem(char *itemName){

}

Item *Character::dropItem(char *itemName){

}


int main(){

    char name[65] = "John";
    Character testClass(name,1,1,1,1,1,1,1,1,1);

    // Item* testStruct = new Item;
    Item testStruct = {0};
    strcpy(testStruct.m_sItemName,name);
    Item* structPtr = &testStruct;
    // testStruct->m_dValue=1;
    
    // testStruct->m_sItemName="John";
    // testStruct->m_iType=1;
    // testStruct->m_dValue=1;
    // testStruct->m_dValue=1.1;
    // testStruct->m_dWeight=1.1;
    

    // //.m_sItemName[65];
    // char    m_sDesc[128];
    // int     m_iType = 2;
    // double  m_dValue = 2;
    // double  m_dWeight = 2;

    testClass.addItem(structPtr);

    testClass.printAll();


}