//------------------------------------------------------------------
// Prog3Main.cpp
//
// Main demonstration and testing executible for programming 
//  assignment 3
// Author: Dr. Rick Coleman
// Date: January 2004
//------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "Character.h"
#include "Possessions.h"
#include "Item.h"
//#include "Utilities.h"

using namespace std;

void printMenu();
double addItemsToPlayer(Character *player);
double addItemsToPossessions(Possessions *possessions, char *name);
Item *createItem(char *playerName, int type, char num);

#define GRADING



int main(int argc, char **argv)
{
	Character	   *player;			// Pointer to Character to test
	Possessions	   *pos;			// Pointer to instance of Possessions to test separately
	double		   grade = 0.0;
	double		   maxGrade = 0.0;
	char           dummy[5];
	double		   itemPoints = 0.0;
	Item		   *item, *holditem;
	char			ans;


	cout << "\n=============== Creating an instance of Possessions for testing ======================\n";
	cout.flush();

	// Create an instance of Possessions for testing
	pos = new Possessions();
	cout << "Possessions instance created\n";
	cout << "\tAdding items to instance.\n";
	cout.flush();


	// Add items to the instance of Possessions
	// Add the items to the player's lists
	grade += addItemsToPossessions(pos, "Rimbard");
	maxGrade += 3.5;	// 14 items added at 0.25 points each
#ifdef GRADING
	cout << "\n====== After adding items to Possessions instance grade = " << grade << " out of " << maxGrade << endl;
	cout << "Press [Enter] to continue\n";
	cout.flush();
	cin.getline(dummy, 24);
#endif
	cout << "==========================================================================\n";
	cout << "                    Items in Possessions Instance \n";
	pos->printTree();
	cout << "==========================================================================\n";

	cout << "\n=============== Testing getItem  ======================\n";
	cout.flush();

	// Get a leaf
	item = pos->getItem("R_BItem_7");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_7")==0))
	{
		grade += 0.5;
	cout << "\n\t Successfully found R_BItem_7. Leaf node.\n";
	}
	else
	{
		cout << "\n\t*** Failed to find R_BItem_7. Leaf node.***\n";
		cout.flush();
	}
	maxGrade += 0.5;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Get an interior node
	item = pos->getItem("R_BItem_6");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_6")==0))
	{
		grade += 0.5;
	cout << "\n\t Successfully found R_BItem_6. Interior node.\n";
	}
	else
	{
		cout << "\n\t*** Failed to find R_BItem_6. Interior node.***\n";
		cout.flush();
	}
	maxGrade += 0.5;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Get the root
	item = pos->getItem("R_BItem_4");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_4")==0))
	{
		grade += 1.0;
	cout << "\n\t Successfully found R_BItem_4. Root node.\n";
	}
	else
	{
		cout << "\n\t*** Failed to find R_BItem_4. Root node.***\n";
		cout.flush();
	}
	maxGrade += 1.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Try to get a non-existing node
	item = pos->getItem("R_BItem_0");
	if(item == NULL)
	{
		grade += 1.0;
	cout << "\n\t Successfully reported not finding a non-existing node.\n";
	}
	else
	{
		cout << "\n\t*** Failed. Reported finding a non-existing node.***\n";
		cout.flush();
	}
	maxGrade += 1.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif


	cout << "\nPress [Enter] to demonstrate dropping items from the instance of Possessions.";
	cout.flush();
	cin.getline(dummy, 24);

// Tree results:
//                        4
//                      /   \
//                     2     6
//                    / \   /  \
//                   1   3 5    7

	// Test delete when item is not there
	item = pos->dropItem("R_BItem_8");
	if(item == NULL) 
	{
		grade += 0.5;
		cout << "\n\t Successfully reported unable to delete a node \n\t\tknown to not be in the tree.\n";
	}
	else
	{
		cout << "\n*** Unsuccessfully reported deleting a nonexistant node. ***\n";
	}
	maxGrade += 0.5;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Drop 7 = Node not root with no children or only 1 on right.
	item = pos->dropItem("R_BItem_7");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_7")==0))
	{
		grade += 1.0;
	cout << "\n\t Successfully removed R_BItem_7. \n\t\tNode not root with no children or only 1 on right.\n";
	}
	else
	{
		cout << "\n*** Failed to delete R_BItem_7. \n\t\tNode not root with no children or only 1 on right.***\n";
		cout.flush();
	}
	maxGrade += 1.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Drop 2 = Node not root with 2 children.
	item = pos->dropItem("R_BItem_2");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_2")==0))
	{
		grade += 2.0;
	cout << "\n\t Successfully removed R_BItem_2. \n\t\tNode not root with 2 children.\n";
	}
	else
	{
		cout << "\n*** Failed to delete R_BItem_2. \n\t\tNode not root with 2 children.***\n";
		cout.flush();
	}
	maxGrade += 2.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Drop 6 = Node not root with one child on left.
	item = pos->dropItem("R_BItem_6");
	if(item != NULL) 
	{
		grade += 1.0;
		cout << "\n\t Successfully removed R_BItem_6. \n\t\tNode not root with one child on left..\n";
	}
	else
	{
		cout << "\n*** Failed to delete item R_BItem_6. \n\t\tNode not root with one child on left..***\n";
		cout.flush();
	}
	maxGrade += 1.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif


	// Drop 1 = Node not root with 1 child on right.
	item = pos->dropItem("R_BItem_1");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_1")==0))
	{
		grade += 1.0;
	cout << "\n\t Successfully removed R_BItem_1. \n\t\tNode not root with 2 children.\n";
	}
	else
	{
		cout << "\n*** Failed to delete R_BItem_1. \n\t\tNode not root with 2 children.***\n";
		cout.flush();
	}
	maxGrade += 1.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Drop 4 = Root node with 2 children.
	item = pos->dropItem("R_BItem_4");
	holditem = item;
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_4")==0))
	{
		grade += 2.0;
		item->m_pLeft = item->m_pRight = NULL;
	cout << "\n\t Successfully removed R_BItem_4. \n\t\tRoot node with 2 children..\n";
	}
	else
	{
		cout << "\n*** Failed to delete R_BItem_4. \n\t\tRoot node with 2 children.***\n";
		cout.flush();
	}
	maxGrade += 2.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Drop 3 = Root node with 1 child on right.
	item = pos->dropItem("R_BItem_3");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_3")==0))
	{
		grade += 1.0;
	cout << "\n\t Successfully removed R_BItem_3. \n\t\tRoot node with 1 child on right.\n";
	}
	else
	{
		cout << "\n*** Failed to delete R_BItem_3. \n\t\tRoot node with 1 child on right.***\n";
		cout.flush();
	}
	maxGrade += 1.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Add 4 back for testing root with one child on left
	pos->addItem(holditem);

	//  Drop 5 = Root node, with one child on left
	item = pos->dropItem("R_BItem_5");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_5")==0))
	{
		grade += 1.0;
	cout << "\n\t Successfully removed R_BItem_5. \n\t\tRoot node, one child on left.\n";
	}
	else
	{
		cout << "\n*** Failed to delete R_BItem_5. \n\t\tRoot node, one child on left.***\n";
		cout.flush();
	}
	maxGrade += 1.0;

#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Drop 4 = Root node, last in tree
	item = pos->dropItem("R_BItem_4");
	holditem = item;
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_4")==0))
	{
		grade += 2.0;
	cout << "\n\t Successfully removed R_BItem_4. \n\t\tRoot node with 2 children..\n";
	}
	else
	{
		cout << "\n*** Failed to delete R_BItem_4. \n\t\tRoot node with 2 children.***\n";
		cout.flush();
	}
	maxGrade += 2.0;
#ifdef GRADING
	cout << "\n====== After dropping items grade = " << grade << " out of " << maxGrade << endl;
#endif


	// Print list
	cout << "\nDone testing delete...\nPress Enter to see the current character printout.\n";
	cout.flush();
	cin.getline(dummy, 24);
	cout << "==========================================================================\n";
	pos->printTree();
	cout << "==========================================================================\n";
	// Done with Possessions so destroy it
	cout << "Deleting the instance of Possessions to test the destructor function.\n";
	delete pos;
	// If we didn't crash then carry on 

	cout << "\n=============== Creating a character for testing ======================\n";
	cout.flush();

	// Create a single character
	player = new Character("Rimbard", 5, 1, 31, 11, 15, 14, 18, 18, 14);
	cout << "Rimbard created\n";
	cout << "\tAdding items to Rimbard's item lists.\n";
	cout.flush();

	// Add the items to the player's lists
	addItemsToPlayer(player);
	// Call Player's print all to see if everything is printed
	cout << "==========================================================================\n";
	player->printAll();
	cout << "==========================================================================\n";
#ifdef GRADING
	cout << "\nDoes the printout look correct? (press Y or N)\n";
	cin.get(ans);
	if((ans == 'Y') || (ans == 'y'))
		grade+=2;
#endif
	maxGrade += 2.0;	// Add items via the player works OK


#ifdef GRADING
	cout << "\n====== After adding items grade = " << grade << " out of " << maxGrade << endl;
	cout << "Press [Enter] to continue\n";
	cout.flush();
	cin.getline(dummy, 24);
#endif

	// Get a Battle item
	item = player->getItem("R_BItem_7");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_7")==0))
	{
		grade += 0.5;
	cout << "\n\t Successfully got back a Battle item R_BItem_7. \n";
	}
	else
	{
		cout << "\n\t*** Failed to get Battle item R_BItem_7 returned by the Character.***\n";
		cout.flush();
	}
	maxGrade += 0.5;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Get a Treasure item
	item = player->getItem("R_TItem_6");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_TItem_6")==0))
	{
		grade += 0.5;
	cout << "\n\t Successfully got back a Treasure item R_TItem_6.\n";
	}
	else
	{
		cout << "\n\t*** Failed to get Treasure item R_BItem_6 returned by the Character.***\n";
		cout.flush();
	}
	maxGrade += 0.5;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Test dropping things from both lists
	cout << "\nTesting dropping items from the Character's lists.\n";
	// Drop 7 = Battle item not root with no children or only 1 on right.
	item = player->dropItem("R_BItem_7");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_BItem_7")==0))
	{
		grade += 1.0;
		cout << "\n\t Player successfully dropped Battle item R_BItem_7. \n";
	}
	else
	{
		cout << "\n*** Player failed to drop Battle item R_BItem_7. \n***\n";
		cout.flush();
	}
	maxGrade += 1.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Drop 6 = Battle item not root with one child on left.
	item = player->dropItem("R_BItem_6");
	if(item != NULL) 
	{
		grade += 1.0;
		cout << "\n\t Player successfully dropped Battle item R_BItem_6. \n";
	}
	else
	{
		cout << "\n*** Player failed to drop Battle item R_BItem_6. \n***\n";
		cout.flush();
	}
	maxGrade += 1.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Drop 6 = Treasure item not root with 2 children.
	item = player->dropItem("R_TItem_6");
	if((item != NULL) && (strcmp(item->m_sItemName, "R_TItem_6")==0))
	{
		grade += 1.0;
		cout << "\n\t Player successfully dropped Treasure item R_TItem_6. \n";
	}
	else
	{
		cout << "\n*** Player failed to drop Treasure item R_TItem_6. \n***\n";
		cout.flush();
	}
	maxGrade += 1.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif

	// Drop 4 = Treasure item is root with 2 children.
	item = player->dropItem("R_TItem_4");
	if(item != NULL) 
	{
		grade += 1.0;
		cout << "\n\t Player successfully dropped Treasure item R_TItem_4. \n";
	}
	else
	{
		cout << "\n*** Player failed to drop Treasure item R_TItem_4. \n***\n";
		cout.flush();
	}
	maxGrade += 1.0;
#ifdef GRADING
		cout << "\t Grade = " << grade << " out of " << maxGrade << endl;
#endif



#ifdef GRADING
	cout << "\n===============================================================================\n";
	cout << "\nFinal grade = " << grade << "\n";
#endif

	cout << "\nPress Enter to end the demonstration of program 3.\n";
	cout.flush();
	cin.getline(dummy, 24);
	return 0;
}

//------------------------------------------
// Add items to each character for testing
// Add items in order BI 4, 2, 6, 1, 3, 5, 7
// Tree results:
//                        4
//                      /   \
//                     2     6
//                    / \   /  \
//                   1   3 5    7
//------------------------------------------
double addItemsToPlayer(Character *player)
{
	Item *item;
	char index[2];
	char initials[3];
	char *cpt;
	int i;
	double points = 0.0;

	cout << "\nAdding battle items for testing to " << player->getName() <<"'s possessions.\n";
	cout.flush();
	for(i=1; i<=7; i++)
	{
		// Set item name so it get inserted in the desired order for testing
		switch(i)
		{
			case 1 : strcpy(index, "4");  break;
			case 2 : strcpy(index, "2");  break;
			case 3 : strcpy(index, "6");  break;
			case 4 : strcpy(index, "1");  break;
			case 5 : strcpy(index, "3");  break;
			case 6 : strcpy(index, "5");  break;
			case 7 : strcpy(index, "7");  break;
		}
		item = new Item();
		initials[0] = player->getName()[0];
		cpt = strchr(player->getName(), '_');
		if(cpt != NULL)
		{
			cpt++; // Increment to next character
			initials[1] = *cpt;
			initials[2] = '\0'; // close the string
		}
		else
			initials[1] = '\0'; // close the string with just 1 initial

		strcpy(item->m_sItemName, initials);
		strcat(item->m_sItemName, "_BItem_");
		strcat(item->m_sItemName, index);
		strcpy(item->m_sDesc, "Battle item ");
		strcat(item->m_sDesc, index);
		strcat(item->m_sDesc, " for ");
		strcat(item->m_sDesc, initials);
		item->m_dValue = i*2;
		item->m_dWeight = i*3;
		item->m_iType = BATTLE_ITEM;
		item->m_pLeft = item->m_pRight = NULL;
		// Add the items to the player but we have already tested add item so don't add any points
		if(!player->addItem(item))
		{
			cout << "Failed to add battle item " << item->m_sItemName << " to " << player->getName() <<"'s list.\n";
		}
		else
		{
			cout << "Successfully added battle item " << item->m_sItemName << " to " << player->getName() <<"'s list.\n";
		}
	}

	cout << "\nAdding treasure items for testing to " << player->getName() <<"'s possessions.\n";
	for(i=1; i<=7; i++)
	{
		switch(i)
		{
			case 1 : strcpy(index, "4");  break;
			case 2 : strcpy(index, "2");  break;
			case 3 : strcpy(index, "6");  break;
			case 4 : strcpy(index, "1");  break;
			case 5 : strcpy(index, "3");  break;
			case 6 : strcpy(index, "5");  break;
			case 7 : strcpy(index, "7");  break;
		}
		item = new Item();
		initials[0] = player->getName()[0];
		cpt = strchr(player->getName(), '_');
		if(cpt != NULL)
		{
			cpt++; // Increment to next character
			initials[1] = *cpt;
			initials[2] = '\0'; // close the string
		}
		else
			initials[1] = '\0'; // close the string with just 1 initial

		strcpy(item->m_sItemName, initials);
		strcat(item->m_sItemName, "_TItem_");
		strcat(item->m_sItemName, index);
		strcpy(item->m_sDesc, "Treasure item ");
		strcat(item->m_sDesc, index);
		strcat(item->m_sDesc, " for ");
		strcat(item->m_sDesc, initials);
		item->m_dValue = i*2;
		item->m_dWeight = i*3;
		item->m_iType = TREASURE_ITEM;
		item->m_pLeft = item->m_pRight = NULL;
		// Add the items to the player but we have already tested add item so don't add any points
		if(!player->addItem(item))
		{
			cout << "Failed to add treasure item " << item->m_sItemName << " to " << player->getName() <<"'s list.\n";
		}
		else
		{
			cout << "Successfully added treasure item " << item->m_sItemName << " to " << player->getName() <<"'s list.\n";
		}
	}
	cout.flush();
	return points;
}

//------------------------------------------
// Add items to each character for testing
// Add items in order BI 4, 2, 6, 1, 3, 5, 7
// Tree results:
//                        4
//                      /   \
//                     2     6
//                    / \   /  \
//                   1   3 5    7
//------------------------------------------
double addItemsToPossessions(Possessions *possessions, char *name)
{
	Item *item;
	char index[2];
	char initials[3];
	char *cpt;
	int i;
	double points = 0.0;

	cout << "\nAdding battle items for testing to " << name <<"'s possessions.\n";
	cout.flush();
	for(i=1; i<=7; i++)
	{
		// Set item name so it get inserted in the desired order for testing
		switch(i)
		{
			case 1 : strcpy(index, "4");  break;
			case 2 : strcpy(index, "2");  break;
			case 3 : strcpy(index, "6");  break;
			case 4 : strcpy(index, "1");  break;
			case 5 : strcpy(index, "3");  break;
			case 6 : strcpy(index, "5");  break;
			case 7 : strcpy(index, "7");  break;
		}
		item = new Item();
		initials[0] = name[0];
		cpt = strchr(name, '_');
		if(cpt != NULL)
		{
			cpt++; // Increment to next character
			initials[1] = *cpt;
			initials[2] = '\0'; // close the string
		}
		else
			initials[1] = '\0'; // close the string with just 1 initial

		strcpy(item->m_sItemName, initials);
		strcat(item->m_sItemName, "_BItem_");
		strcat(item->m_sItemName, index);
		strcpy(item->m_sDesc, "Battle item ");
		strcat(item->m_sDesc, index);
		strcat(item->m_sDesc, " for ");
		strcat(item->m_sDesc, initials);
		item->m_dValue = i*2;
		item->m_dWeight = i*3;
		item->m_iType = BATTLE_ITEM;
		item->m_pLeft = item->m_pRight = NULL;
		if(!possessions->addItem(item))
		{
			cout << "Failed to add battle item " << item->m_sItemName << " to " << name <<"'s list.\n";
		}
		else
		{
			points+=0.5;
		}
	}
/*
	cout << "\nAdding treasure items for testing to " << name <<"'s possessions.\n";
	for(i=1; i<=7; i++)
	{
		switch(i)
		{
			case 1 : strcpy(index, "4");  break;
			case 2 : strcpy(index, "2");  break;
			case 3 : strcpy(index, "6");  break;
			case 4 : strcpy(index, "1");  break;
			case 5 : strcpy(index, "3");  break;
			case 6 : strcpy(index, "5");  break;
			case 7 : strcpy(index, "7");  break;
		}
		item = new Item();
		initials[0] = name[0];
		cpt = strchr(name, '_');
		if(cpt != NULL)
		{
			cpt++; // Increment to next character
			initials[1] = *cpt;
			initials[2] = '\0'; // close the string
		}
		else
			initials[1] = '\0'; // close the string with just 1 initial

		strcpy(item->m_sItemName, initials);
		strcat(item->m_sItemName, "_TItem_");
		strcat(item->m_sItemName, index);
		strcpy(item->m_sDesc, "Treasure item ");
		strcat(item->m_sDesc, index);
		strcat(item->m_sDesc, " for ");
		strcat(item->m_sDesc, initials);
		item->m_dValue = i*2;
		item->m_dWeight = i*3;
		item->m_iType = TREASURE_ITEM;
		item->m_pLeft = item->m_pRight = NULL;
		if(!possessions->addItem(item))
		{
			cout << "Failed to add treasure item " << item->m_sItemName << " to " << name <<"'s list.\n";
		}
		else
		{
			points+=0.25;
		}
	}
		*/
	cout.flush();
	return points;
}

