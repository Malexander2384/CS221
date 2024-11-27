//===========================================================
// GameMain.cpp
//
// Purpose: Demonstration of programming assignment 4
// Author: Dr. Rick Coleman
//===========================================================================
#include "GameGraph.h"

#define DataFile "gamelayout.txt"

void makeUpper(char *line);

int main(int argc, char **argv)
{
	GameGraph	*game;
	bool		done = false;
	char		command[64];

	game = new GameGraph();

	cout << "Welcome to Program Assignment 4 for CS 221.\n";
	// Add your name in the line below
	cout << "Programming by: Michael Alexander\n";
	cout << "This is a Dungeons and Dragons style role \n";
	cout << "playing game.  At the prompt enter enter your commands.\n\n";

	game->LoadGame(DataFile);	// Load the game
 
	while(!done)
	{
		cout << "\n\nWhat do you want to do?  ";
		cin.getline(command, 64, '\n');
		makeUpper(command);
		if((game->doCommand(command))) // If doCommand returns true end game
			done = true;
	}
	return 0;
}

//--------------------------------------
// makeUpper()
// Converts input line to all upper case
//--------------------------------------
void makeUpper(char *line)
{
	char *temp;

	temp = line;
	while(*temp != '\0') 
	{
		*temp = toupper(*temp);
		temp++;
	}
}













//-------------------------------------------
// GetNextLine()
// Read the next line from the file.
//-------------------------------------------
void GameGraph::getNextLine(char *line, int lineLen)
{
    int    done = false;

    while(!done)
    {
        m_InFile.getline(line, lineLen);  
        // Note: m_InFile is an ifstream object that is part of the GameGraph class

        if(m_InFile.good())    // If a line was successfully read
        {
           if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else done = true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");
            return;
        }
    } // end while
}
//---------------------------------------
// LoadGame()
// Open and read the game layout file and
//   build the adjacency matrix.
//---------------------------------------
bool GameGraph::LoadGame(char *filename)
{
    char line[128];
    int link;
    bool done;

    m_InFile.open(filename, ifstream::in); 
    if(!m_InFile.is_open())
    {
        // m_InFile.is_open() returns false if the file could not be found or
        //    if for some other reason the open failed.
        return false;
    }

    done = false;
    for(int i=0; i<20; i++)
    {
        // Read room name
        getNextLine(line, 128);
        /* --- Copy room name into data structure i --- */

        // Read room description
        getNextLine(line, 128);
        /* --- Copy room description into data structure i --- */

        // Read room item
        getNextLine(line, 128);
        /* --- Copy room item name into data structure i --- */

        // Read room creature
        getNextLine(line, 128);
        /* --- Copy room creature name into data structure i --- */

        // Read North door
        getNextLine(line, 128);
        link = atoi(line); // Convert to room index
        // Call function to set link in adjacency matrix

        // Read South door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix

        // Read East door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix

        // Read West door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix

        // Read up stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix

        // Read down stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
    }
    return true;
}
