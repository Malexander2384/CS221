//------------------------------------------------------------------
// Prog2Main.cpp
//
// Main demonstration and testing executible for programming 
//  assignment 2
// Author: Dr. Rick Coleman
//------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "CharacterList.h"
#include "Character.h"
#include "Item.h"
//#include "Utilities.h"

void printMenu();

using namespace std;

#define GRADING

int main(int argc, char **argv)
{
	//Character Names:
	char Rimbard[] = "Rimbard";
	char Silverleaf[] = "Silverleaf";
	char Grayhawk[] = "Grayhawk";
	char Marcus_Leonus[] = "Marcus_Leonus";
	char Balrug[] = "Balrug";
	char Johnny[] = "Johnny";
	char Bob[] = "Bob";

	//Items for the Characters:
	char Staff[] = "Staff";
	char Spellbook[] = "Spellbook";
	char Pouch[] = "Pouch";
	char Bow[] = "Bow";
	char Quiver[] = "Quiver";
	char Arrows[] = "Arrows";
	char Sword[] = "Sword";
	char Shield[] = "Shield";
	char Dagger[] = "Dagger";
	char Spear[] = "Spear";
	char Bag_of_gold[] = "Bag_of_gold";
	char Lantern[] = "Lantern";
	char Ring[] = "Ring";
	char Helmet[] = "Helmet";
	char Cloak_of_Spider_Climbing[] = "Cloak_of_Spider_Climbing";
	char Whip[] = "Whip";
	char Club[] = "Club";
	char Magic_Scroll[] = "Magic_Scroll";
	char Magic_Cup[] = "Magic_Cup";
	CharacterList  *theList;
	double		   grade = 0.0;
	double         maxGrade = 0.0;
	Character	   *player, *p1, *p2, *p3, *p4, *p5;
	Item		   *item;
	char           dummy[5];
	char           ans[5];// Points to deduct for printing or press [Enter] for all OK
//	char		   name[64];

//	printMenu();

	theList = new CharacterList();
//	util = new Utilities();

	cout << "==========================================================\n";
//	cout << "\n----- Menu is non-function in this demonstration ------\n";
	cout << "Characters being added for demonstration.\n\n";

	// Add Character 1

	player = new Character(Rimbard, 5, 1, 31, 11, 15, 14, 18, 18, 14);

	cout << "Player Rimbard created\n";
	cout.flush();
	p1 = player;
	if(theList->addCharacter(player)) 
	{
#ifdef GRADING
		cout << "Player Rimbard added as first in the list.  1 point added.\n";
		grade += 1.0;	// Assume first player added correctly at start of list
#else
		cout << "Player Rimbard added\n";
#endif
		cout.flush();
	}
	else
	{
		cout << "Failed to add player Rimbard\n";
		cout.flush();
	}
	maxGrade += 1.0;
	// p1 = Rimbard

	// Order in list should be 
	// Rimbard

	// Add 3 items to player's list
	item = new Item();
	strcpy(item->m_sItemName, Staff);
	item->m_dValue = 5;
	item->m_dWeight = 1;
	if(theList->addItem(Rimbard, item)) 
	{
		grade += 0.3;
		cout << " Staff added to Rimbard's items.\n";
		cout.flush();
	}
	else
	{
		cout << " Failed to add Staff to Rimbard's items.\n";
	}
	maxGrade += 0.3;

	item = new Item();
	strcpy(item->m_sItemName, Spellbook);
	item->m_dValue = 25;
	item->m_dWeight = 5;
	if(theList->addItem(Rimbard, item))
	{
		grade += 0.3;
		cout << " Spellbook added to Rimbard's items.\n";
		cout.flush();
	}
	else
	{
		cout << " Failed to add Spellbook to Rimbard's items.\n";
	}
	maxGrade += 0.3;

	item = new Item();
	strcpy(item->m_sItemName, Pouch);
	item->m_dValue = 1;
	item->m_dWeight = 1;
	if(theList->addItem(Rimbard, item))
	{
		grade += 0.3;
		cout << " Pouch added to Rimbard's items.\n";
		cout.flush();
	}
	else
	{
		cout << " Failed to add Pouch to Rimbard's items.\n";
	}
	maxGrade += 0.3;

	// Testing new get functions in Character class
	cout << "\nTesting new \"get\" functions in Character class.\n";
	if(p1->getClass() == 5)
	{
		grade += 0.3;
		cout << "\tNew getClass function works correctly.\n";
	}
	else
	{
		cout << "\tNew getClass function does not work correctly.\n";
	}
	maxGrade += 0.3;
	if(p1->getAlignment() == 1)
	{
		grade += 0.3;
		cout << "\tNew getAlignment function works correctly.\n";
	}
	else
	{
		cout << "\tNew getAlignment function does not work correctly.\n";
	}
	maxGrade += 0.3;
	if(p1->getHitPoints() == 31)
	{
		grade += 0.3;
		cout << "\tNew getHitPoints function works correctly.\n";
	}
	else
	{
		cout << "\tNew getHitPoints function does not work correctly.\n";
	}
	maxGrade += 0.3;
	if(p1->getStrength() == 11)
	{
		grade += 0.3;
		cout << "\tNew getStrength function works correctly.\n";
	}
	else
	{
		cout << "\tNew getStrength function does not work correctly.\n";
	}
	maxGrade += 0.3;
	if(p1->getDexterity() == 15)
	{
		grade += 0.3;
		cout << "\tNew getDexterity function works correctly.\n";
	}
	else
	{
		cout << "\tNew getDexterity function does not work correctly.\n";
	}
	maxGrade += 0.3;
	if(p1->getConstitution() == 14)
	{
		grade += 0.3;
		cout << "\tNew getConstitution function works correctly.\n";
	}
	else
	{
		cout << "\tNew getConstitution function does not work correctly.\n";
	}
	maxGrade += 0.3;
	if(p1->getIntelligence() == 18)
	{
		grade += 0.3;
		cout << "\tNew getIntelligence function works correctly.\n";
	}
	else
	{
		cout << "\tNew getIntelligence function does not work correctly.\n";
	}
	maxGrade += 0.3;
	if(p1->getWisdom() == 18)
	{
		grade += 0.3;
		cout << "\tNew getWisdom function works correctly.\n";
	}
	else
	{
		cout << "\tNew getWisdom function does not work correctly.\n";
	}
	maxGrade += 0.3;
	if(p1->getCharisma() == 14)
	{
		grade += 0.3;
		cout << "\tNew getCharisma function works correctly.\n";
	}
	else
	{
		cout << "\tNew getCharisma function does not work correctly.\n";
	}
	maxGrade += 0.3;


#ifdef GRADING
	cout << "Grade = " << grade <<	" out of a possible " << maxGrade << " points\n"; 
	cout.flush();
#endif

	// Add Character 2
	
	player = new Character(Silverleaf, 1, 1, 52, 18, 16, 16, 11, 9, 8);

	cout << "\nPlayer Silverleaf created\n";
	cout.flush();
	p2 = player;
	if(theList->addCharacter(player))
	{
#ifdef GRADING
		if((p1->m_pNext != NULL) && (strcmp(p1->m_pNext->getName(), Silverleaf) == 0))
		{
			cout << "Player Silverleaf added to list in correct location. 1 point added.\n";
			grade += 1.0;	
		}
		else
		{
			cout << "Player Silverleaf added to list but not in correct location. 1 point NOT added.\n";
		}
#else
		cout << "Player Silverleaf added to list.\n";
#endif
		cout.flush();
	}
	else
	{
		cout << "Failed to add player Silverleaf\n";
		cout.flush();
	}
	maxGrade += 1.0;
	// p1 = Rimbard
	// p2 = Silverleaf

	// Order in list should be 
	// Rimbard - Silverleaf

	// Add 3 items to player's list
	item = new Item();
	strcpy(item->m_sItemName, Bow);
	item->m_dValue = 15;
	item->m_dWeight = 2;
	if(theList->addItem(Silverleaf, item))
	{
		grade += 0.2;
		cout << " Bow added to Silverleaf's items.\n";
		cout.flush();
	}
	maxGrade += 0.2;

	item = new Item();
	strcpy(item->m_sItemName, Quiver);
	item->m_dValue = 3;
	item->m_dWeight = 2;
	if(theList->addItem(Silverleaf, item))
	{
		grade += 0.2;
		cout << " Quiver added to Silverleaf's items.\n";
		cout.flush();
	}
	maxGrade += 0.2;

	item = new Item();
	strcpy(item->m_sItemName, Arrows);
	item->m_dValue = 12;
	item->m_dWeight = 5;
	if(theList->addItem(Silverleaf, item))
	{
		grade += 0.2;
		cout << " Arrows added to Silverleaf's items.\n";
		cout.flush();
	}
	maxGrade += 0.2;
#ifdef GRADING
	cout << "Grade = " << grade <<	" out of a possible " << maxGrade << " points\n"; 
	cout.flush();
#endif

	// Add Character 3
	
	player = new Character(Grayhawk, 3, 3, 48, 17, 15, 17, 12, 8, 9);

	cout << "\nPlayer Grayhawk created\n";
	cout.flush();
	p3 = player;
	if(theList->addCharacter(player))
	{
#ifdef GRADING
		if((p3->m_pNext != NULL) && (strcmp(p3->m_pNext->getName(), Rimbard) == 0))
		{
			cout << "Player Grayhawk added to list in correct location. 1 point added.\n";
			grade += 1.0;	
		}
		else
		{
			cout << "Player Grayhawk added to list but not in correct location. 1 point NOT added.\n";
		}
#else
		cout << "Player Grayhawk added to list.\n";
#endif
		cout.flush();
	}
	else
	{
		cout << "Failed to add player Grayhawk\n";
		cout.flush();
	}
	maxGrade += 1.0;
	// p1 = Rimbard
	// p2 = Silverleaf
	// p3 = Grayhawk

	// Order in list should be 
	// Grayhawk - Rimbard - Silverleaf

	// Add 3 items to player's list
	item = new Item();
	strcpy(item->m_sItemName, Sword);
	item->m_dValue = 100;
	item->m_dWeight = 5;
	if(theList->addItem(Grayhawk, item))
	{
		grade += 0.2;
		cout << " Sword added to Grayhawk's items.\n";
		cout.flush();
	}
	maxGrade += 0.2;

	item = new Item();
	strcpy(item->m_sItemName, Shield);
	item->m_dValue = 75;
	item->m_dWeight = 5;
	if(theList->addItem(Grayhawk, item))
	{
		grade += 0.2;
		cout << " Shield added to Grayhawk's items.\n";
		cout.flush();
	}
	maxGrade += 0.2;

	item = new Item();
	strcpy(item->m_sItemName, Dagger);
	item->m_dValue = 5;
	item->m_dWeight = 1;
	if(theList->addItem(Grayhawk, item))
	{
		grade += 0.2;
		cout << " Dagger added to Grayhawk's items.\n";
		cout.flush();
	}
	maxGrade += 0.2;
#ifdef GRADING
	cout << "Grade = " << grade <<	" out of a possible " << maxGrade << " points\n"; 
	cout.flush();
#endif

	// Add Character 4
	
	player = new Character(Marcus_Leonus, 1, 3, 46, 18, 16, 16, 11, 8, 8);

	cout << "\nPlayer Marcus_Leonus created\n";
	cout.flush();
	p4 = player;
	if(theList->addCharacter(player))
	{
#ifdef GRADING
		if((p3->m_pNext != NULL) && (strcmp(p3->m_pNext->getName(), Marcus_Leonus) == 0))
		{
			cout << "Player Marcus_Leonus added to list in correct location. 1 point added.\n";
			grade += 1.0;	
		}
		else
		{
			cout << "Player Marcus_Leonus added to list but not in correct location. 1 point NOT added.\n";
		}
#else
		cout << "Player Marcus_Leonus added to list.\n";
#endif
		cout.flush();
	}
	else
	{
		cout << "Failed to add player Marcus_Leonus\n";
		cout.flush();
	}
	maxGrade += 1.0;
	// p1 = Rimbard
	// p2 = Silverleaf
	// p3 = Grayhawk
	// p4 = Marcus_Leonus

	// Order in list should be 
	// Grayhawk - Marcus_Leonus - Rimbard - Silverleaf

	// Add 10 items to player's list

	item = new Item();
	strcpy(item->m_sItemName, Sword);
	item->m_dValue = 100;
	item->m_dWeight = 5;
	if(theList->addItem(Marcus_Leonus, item))
	{
		grade += 0.05;
		cout << " Sword added to Marcus_Leonus's items.\n";
		cout.flush();
	}
	maxGrade += 0.05;

	item = new Item();
	strcpy(item->m_sItemName, Shield);
	item->m_dValue = 75;
	item->m_dWeight = 5;
	if(theList->addItem(Marcus_Leonus, item))
	{
		grade += 0.05;
		cout << " Shield added to Marcus_Leonus's items.\n";
		cout.flush();
	}
	maxGrade += 0.05;

	item = new Item();
	strcpy(item->m_sItemName, Spear);
	item->m_dValue = 75;
	item->m_dWeight = 3;
	if(theList->addItem(Marcus_Leonus, item))
	{
		grade += 0.05;
		cout << " Spear added to Marcus_Leonu's items.s\n";
		cout.flush();
	}
	maxGrade += 0.05;

	item = new Item();
	strcpy(item->m_sItemName, Bag_of_gold);
	item->m_dValue = 50;
	item->m_dWeight = 10;
	if(theList->addItem(Marcus_Leonus, item))
	{
		grade += 0.05;
		cout << " Bag_of_gold added to Marcus_Leonus's items.\n";
		cout.flush();
	}
	maxGrade += 0.05;

	item = new Item();
	strcpy(item->m_sItemName, Pouch);
	item->m_dValue = 1;
	item->m_dWeight = 1;
	if(theList->addItem(Marcus_Leonus, item))
	{
		grade += 0.05;
		cout << " Pouch added to Marcus_Leonus's items.\n";
		cout.flush();
	}
	maxGrade += 0.05;

	item = new Item();
	strcpy(item->m_sItemName, Lantern);
	item->m_dValue = 5;
	item->m_dWeight = 1;
	if(theList->addItem(Marcus_Leonus, item))
	{
		grade += 0.05;
		cout << " Lantern added to Marcus_Leonus's items.\n";
		cout.flush();
	}
	maxGrade += 0.05;

	item = new Item();
	strcpy(item->m_sItemName, Ring);
	item->m_dValue = 25;
	item->m_dWeight = 1;
	if(theList->addItem(Marcus_Leonus, item))
	{
		grade += 0.05;
		cout << " Ring added to Marcus_Leonus's items.\n";
		cout.flush();
	}
	maxGrade += 0.05;

	item = new Item();
	strcpy(item->m_sItemName, Helmet);
	item->m_dValue = 50;
	item->m_dWeight = 10;
	if(theList->addItem(Marcus_Leonus, item))
	{
		grade += 0.05;
		cout << " Helmet added to Marcus_Leonus's items.\n";
		cout.flush();
	}
	maxGrade += 0.05;

	item = new Item();
	strcpy(item->m_sItemName, Dagger);
	item->m_dValue = 5;
	item->m_dWeight = 1;
	if(theList->addItem(Marcus_Leonus, item))
	{
		grade += 0.05;
		cout << " Dagger added to Marcus_Leonus's items.\n";
		cout.flush();
	}
	maxGrade += 0.05;

	item = new Item();
	strcpy(item->m_sItemName, Cloak_of_Spider_Climbing);
	item->m_dValue = 50;
	item->m_dWeight = 1;
	if(theList->addItem(Marcus_Leonus, item))
	{
		grade += 0.05;
		cout << " Cloak_of_Spider_Climbing added to Marcus_Leonus's items.\n";
		cout.flush();
	}
	maxGrade += 0.05;
#ifdef GRADING
	cout << "Grade = " << grade <<	" out of a possible " << maxGrade << " points\n"; 
	cout.flush();
#endif

	// Add Character 5
	
	player = new Character(Balrug, 5, 3, 29, 12, 14, 15, 17, 18, 12);

	cout << "\nPlayer Balrug created\n";
	cout.flush();
	p5 = player;
	if(theList->addCharacter(player))
	{
#ifdef GRADING
		if((p5->m_pNext != NULL) && (strcmp(p5->m_pNext->getName(), Grayhawk) == 0))
		{
			cout << "Player Balrug added to list in correct location. 1 point added.\n";
			grade += 1.0;	
		}
		else
		{
			cout << "Player Balrug added to list but not in correct location. 1 point NOT added.\n";
		}
#else
		cout << "Player Balrug added to list.\n";
#endif
		cout.flush();
	}
	else
	{
		cout << "Failed to add player Balrug\n";
		cout.flush();
	}
	maxGrade += 1.0;
	// p1 = Rimbard
	// p2 = Silverleaf
	// p3 = Grayhawk
	// p4 = Marcus_Leonus
	// p5 = Balrug

	// Order in list should be 
	// Balrug - Grayhawk - Marcus_Leonus - Rimbard - Silverleaf

	// Add 5 items to player's list
	item = new Item();
	strcpy(item->m_sItemName, Whip);
	item->m_dValue = 50;
	item->m_dWeight = 1;
	if(theList->addItem(Balrug, item))
	{
		grade += 0.2;
		cout << " Whip added to Balrug's items.\n";
		cout.flush();
	}
	maxGrade += 0.2;

	item = new Item();
	strcpy(item->m_sItemName, Club);
	item->m_dValue = 25;
	item->m_dWeight = 5;
	if(theList->addItem(Balrug, item))
	{
		grade += 0.2;
		cout << " Club added to Balrug's items.\n";
		cout.flush();
	}
	maxGrade += 0.2;

	item = new Item();
	strcpy(item->m_sItemName, Pouch);
	item->m_dValue = 1;
	item->m_dWeight = 1;
	if(theList->addItem(Balrug, item))
	{
		grade += 0.2;
		cout << " Pouch added to Balrug's items.\n";
		cout.flush();
	}
	maxGrade += 0.2;

	// p1 = Rimbard
	// p2 = Silverleaf
	// p3 = Grayhawk
	// p4 = Marcus_Leonus
	// p5 = Balrug

	// Order in list should be 
	// Balrug
	// Grayhawk
	// Marcus_Leonus
	// Rimbard
	// Silverleaf

	cout << "\n\nPress [Enter] to see a list of the demonstration players.";
	cout.flush();
	cin.getline(dummy, 24);
	cout << "\n";
	theList->printCharacters();

#ifdef GRADING
	cout << "===================================================================\n";
	cout << "Grade after adding characters and items = " << grade <<
		" out of a possible " << maxGrade << " points"; 
	cout << "\n";
	cout.flush();
	cout << "===================================================================\n";
	// Max grade = 7.4
#endif

	cout << "\n-------------------------------------------------------------------\n";
	cout << "Press Enter to continue...\n";
	cout.flush();
	cin.getline(ans, 24);

	// Attempt to add an item to Character 4's list
	item = new Item();
	strcpy(item->m_sItemName, Magic_Scroll);
	item->m_dValue = 50;
	item->m_dWeight = 1;
	cout << "Trying to add item to Marcus when his item list is full\n";
	cout.flush();

	if(theList->addItem(Marcus_Leonus, item))
		cout << "   Oops! Item was added when it should not have been.\n";
	else
	{
		cout << "   Program correctly reported unable to add item to full list.\n";
		cout.flush();
		grade += 1.0;	// Max = 
	}
	maxGrade += 1.0;


	// Add an item to Character 1's list
	item = new Item();
	strcpy(item->m_sItemName, Magic_Cup);
	item->m_dValue = 50;
	item->m_dWeight = 1;
	cout << "Trying to add item to Rimbard.\n";
	cout.flush();
	if(theList->addItem(Rimbard, item))
	{
		cout << "   Item added successfully.\n";
		cout.flush();
		grade += 1.0;	// Max = 9.4
	}
	else
		cout << "   Oops!  Failed to add the item to the list.\n";
	maxGrade += 1.0;


	// Attempt to add an item to a Character that does not exist
	item = new Item();
	strcpy(item->m_sItemName, Magic_Scroll);
	item->m_dValue = 50;
	item->m_dWeight = 1;
	cout << "Trying to add item to non-existant character.\n";
	cout.flush();
	
	if(theList->addItem(Johnny, item))
		cout << "   Oops! Item was added when it should not have been.\n";
	else
	{
		grade += 1.0;	// Max = 10.4
		cout << "   Correctly reported inability to add item to non-existant character.\n";
		cout.flush();
	}
	maxGrade += 1.0;

	cout << "\nTesting getting items from characters.\n";
	
	item = theList->getItem(Rimbard, Staff);
	if((item != NULL) && (strcmp(item->m_sItemName, Staff) == 0))
	{
		cout << "     Correctly got a pointer to Rimbard's Staff.\n";
		grade += 1.0;
	}
	maxGrade += 1.0;

	item = theList->getItem(Silverleaf, Bow);
	if((item != NULL) && (strcmp(item->m_sItemName, Bow) == 0))
	{
		cout << "     Correctly got a pointer to Silverleaf's bow.\n";
		grade += 1.0;
	}
	maxGrade += 1.0;
	
	item = theList->getItem(Bob, Bow);
	if(item == NULL)
	{
		cout << "     Correctly did not find character Bob in the list.\n";
		grade += 1.0;
	}
	maxGrade += 1.0;
	item = theList->getItem(Silverleaf, Sword);
	if(item == NULL)
	{
		cout << "     Correctly did not find character Silverleaf's sword.\n";
		grade += 1.0;
	}
	maxGrade += 1.0;

	// p1 = Rimbard
	// p2 = Silverleaf
	// p3 = Grayhawk
	// p4 = Marcus_Leonus
	// p5 = Balrug

	cout << "\n\nTesting dropping items from characters.\n";
	cout.flush();
	// Drop an item from Character 4's list
	if(theList->dropItem(Marcus_Leonus, Spear) != NULL)
	{
		cout << "   Spear dropped by Marcus Leonus.\n";
		grade += 1.0;	// Max = 11.4
	}
	else
		cout << "   Oops!  Failed to delete spear from Marcus.\n";
	maxGrade += 1.0;

	// Attempt to drop an item from a player that does not exist
	if(theList->dropItem(Johnny, Spear) != NULL)
		cout << "   Oops!  Should not have been able to delete spear from Johnny.\n";
	else
	{
		cout << "   Correctly reported inability to drop an item from a non-existant character.\n";
		grade += 1.0;	// Max = 11.4
	}
	maxGrade += 1.0;
#ifdef GRADING
	cout << "---Character listing after testing drop items ---";
	theList->printCharacters();
	cout << "/n===================================================================\n";
	cout << "Current grade total = " << grade << " out of a possible " << maxGrade <<
		" points\n\n";
	cout << "===================================================================\n";
#endif
	cout << "\nTesting deleting characters.\n";
	// Attempt to remove a non-existing player
	if(theList->deleteCharacter(Johnny) != NULL)
		cout << "   Oops! Delete player function reported success in deleting non-existant character.\n";
	else
	{
		cout << "   Program correctly reported failure to delete a non-existant character.\n";
		grade += 1.2;	// Max = 15
	}
	maxGrade += 1.2;

	// Remove player at end of list
	player = theList->deleteCharacter(Silverleaf);
	if((player != NULL) && (strcmp(player->getName(), Silverleaf) == 0))
	{
		cout << "   Successfully deleted last character in the list (Silverleaf).\n";
		grade += 1.3;	// Max = 12.4
	}
	else
		cout << "   Oops! Delete player function did not return pointer to Silverleaf.\n";
	maxGrade += 1.3;

	// Remove player at beginning of list
	player = theList->deleteCharacter(Balrug);
	if((player != NULL) && (strcmp(player->getName(), Balrug) == 0))
	{
		cout << "   Successfully deleted first character in the list. (Balrug)\n";
		grade += 1.3;	// Max = 13.4
	}
	else
		cout << "   Oops! Delete player function did not return pointer to Balrug.\n";
	maxGrade += 1.3;

	// Remove player 3
	player = theList->deleteCharacter(Marcus_Leonus);
	if((player != NULL) && (strcmp(player->getName(), Marcus_Leonus) == 0))
	{
		cout << "   Successfully deleted middle character in the list. (Marcus_Leonus)\n";
		grade += 1.3;	// Max = 14.4
	}
	else
		cout << "   Oops! Delete player function did not return pointer to Marcus_Leonus.\n";
	maxGrade += 1.3;


	// Print list
	cout << "\n-------------------------------------------------------------------\n";
	cout << "Printing final list of characters...\n"; 
	cout.flush();
	theList->printCharacters();
	cout << "-------------------------------------------------------------------\n";

#ifdef GRADING
	cout << "===================================================================\n";
	cout << "\nFinal grade = " << grade << " out of a possible " << maxGrade <<
		" points\n";
	cout << "===================================================================\n";
#endif

	cout << "\nPress the Enter key to terminate this demonstration.\n";
	getchar();
	return 0;
}

void printMenu()
{
	//----------------------------------------------------------------
	// Screen display stuff
	//----------------------------------------------------------------
	system("cls");  // Clear the screen
	cout << "==========================================================\n";
	cout << "=                       Welcome To                       =\n";
	cout << "=                                                        =\n";
	cout << "=            M A Z E S   A N D   M O N S T E R S         =\n";
	cout << "=                                                        =\n";
	cout << "=  A role playing game created by the UAH CS 221 class.  =\n";
	cout << "==========================================================\n";
	cout << "\n\n";
	cout << "                   M A I N   M E N U \n";
	cout << "\n\n";
	cout << "     1. Start a new game.\n";
	cout << "     2. Load a saved game.\n";
	cout << "     3. Load a set of characters.\n";
	cout << "     4. Create a new character.\n";
	cout << "     5. Save the current game.\n";
	cout << "     6. Quit.\n";
	cout << "\n";
	cout << "  Enter a number (1-6) and press [Enter]\n";
}
