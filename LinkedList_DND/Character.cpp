#include "Character.h"

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

Character::Character(){
    
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

    // Print stats and every item name with weight/value
    for(int i=0;i<itemCount;i++){
        std::cout<<"\n"<<m_Items[i].m_sItemName<<": "<<"\n";
        std::cout<<"Value is "<<m_Items[i].m_dValue<<"\t"<<"||"<<"\t"<<"Weight is "<<m_Items[i].m_dWeight<<"\n";
    }

}

bool Character::addItem(Item *item){
    
    if(length>itemCount){

        m_Items[itemCount] = *item;
        //Update Count
        itemCount++;

        return true;
    }
    else{
        return false;
    }
}

Item *Character::getItem(char *itemName){

    // Check every item in item array
    for(int i=0;i<itemCount;i++){

        if(strcmp(m_Items[i].m_sItemName,itemName) == 0){
            // Setting temp pointer for the return
            Item* tempPtr = &m_Items[i];
            return tempPtr;
        }
        else{
            return NULL;
        }
    }
}

Item *Character::dropItem(char *itemName){

    for(int i=0; i<itemCount; i++){
        if(strcmp(m_Items[i].m_sItemName,itemName) == 0){

            // Create copy for return
            Item* droppedItem = new Item();
            memcpy(droppedItem, &m_Items[i], sizeof(Item));

            // Clearing all values
            memset(&m_Items[i], 0, sizeof(Item));

            // Rearrange array to fix gap
            for(int j=i; j<itemCount-1;j++){
                m_Items[j] = m_Items[j+1];
            }

            // Updating item amount
            itemCount--;

            // Return 
            return droppedItem;
        }
    }
    // Item wasnt found
    return nullptr;
}

int Character::compare_Char(Character* a, Character* b){
    return strcmp(a->m_sName,b->m_sName);
}


// int main(){

//     char Classname[65] = "John";
//     char Structname1[65] = "Excali";
//     char Structname2[65] = "FUNW";
//     char Structname3[65] = "HRUNTING";
//     Character testClass(Classname,1,1,1,1,1,1,1,1,1);

//     // Test Struct setup
//     Item testStruct1 = {0};
//     strcpy(testStruct1.m_sItemName,Structname1);
//     Item* structPtr = &testStruct1;

//     Item testStruct2 = {0};
//     strcpy(testStruct2.m_sItemName,Structname2);
//     Item* structPtr2 = &testStruct2;
    

//     Item testStruct3 = {0};
//     strcpy(testStruct3.m_sItemName,Structname3);
//     Item* structPtr3 = &testStruct3;

	// Item* item = new Item();
    // char Spear[] = "Spear";
	// strcpy(item->m_sItemName, Spear);
	// item->m_dValue = 75;
	// item->m_dWeight = 3;

    
//     testClass.addItem(item);
//     // testClass.addItem(structPtr2);
//     // testClass.addItem(structPtr3);

//     testClass.dropItem(item->m_sItemName);
//     // testClass.addItem(structPtr);


//     // testClass.printAll();


// }