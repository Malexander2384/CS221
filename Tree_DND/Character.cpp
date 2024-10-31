#include "Character.h"

Character::Character(char *name, int clas, int alignment, int hitpoints, int strength,
	int dexterity, int constitution, int intelligence, int wisdom,int charisma){
    
    // Tree of items
    BattleItems = new Possessions();
    TreasureItems = new Possessions();

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
    BattleItems = new Possessions();
    TreasureItems = new Possessions();
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

    std::cout<<"Battle Items: "<<"\n";
    BattleItems->printTree();
    std::cout<<"\n";
    std::cout<<"Treasure Items: "<<"\n";
    TreasureItems->printTree();

}

bool Character::addItem(Item *item){

    if(item->m_iType == 1){
        BattleItems->addItem(item);
        return true;
    }
    else if(item->m_iType == 2){
        TreasureItems->addItem(item);
        return true;
    }
    else{
        return false;
    }
}

Item *Character::getItem(char *itemName){

    if(BattleItems->getItem(itemName)){
        return BattleItems->getItem(itemName);
    }
    else{
        return TreasureItems->getItem(itemName);
    }

}

Item *Character::dropItem(char *itemName){

    if(BattleItems->getItem(itemName)){
        return BattleItems->dropItem(itemName);
    }
    else{
        return TreasureItems->dropItem(itemName);
    }
}

int Character::compare_Char(Character* a, Character* b){
    return strcmp(a->m_sName,b->m_sName);
}


// int main(){

//     char Classname[65] = "John";

//     Character testClass(Classname,1,1,1,1,1,1,1,1,1);

// 	Item* item = new Item();
//     char Spear[] = "Spear";
// 	strcpy(item->m_sItemName, Spear);
// 	item->m_dValue = 75;
// 	item->m_dWeight = 3;
//     item->m_iType = 1; 

//     Possessions TestTree;
//     TestTree.addItem(item);
//     TestTree.printTree();

//     std::cout<<"\n"<<"#############################################################################################"<<"\n";

//     testClass.printAll();

//     std::cout<<"\n"<<"#############################################################################################"<<"\n";

//     testClass.addItem(item);
//     // testClass.printAll();    
// }

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


//     // Test->printTree();


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