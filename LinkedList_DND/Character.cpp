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
}

//TODO charname.next for print all?

bool Character::addItem(Item *item){

    int length = sizeof(m_Items)/sizeof(m_Items[0]);
    bool check1 = false;

    for (int i = 0;i<length; i++) {
            if (m_Items[i] == 0) {
                b = true;
            }
        }


    for(int i=0; i<length; i++){

        if(m_Items[i] == 1){
            return;
        }

    }
}

Item *Character::getItem(char *itemName){

}

Item *Character::dropItem(char *itemName){

}

//C:\Users\Admin\CodeStuff\CS221\LinkedList_DND


int main(){
    std::cout<<"hello";
}