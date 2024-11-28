//===========================================================
// GameMain.cpp
//
// Purpose: Demonstration of programming assignment 4
// Author: Dr. Rick Coleman
//===========================================================================
#include "GameGraph.h"

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

    char DataFile[] = "gamelayout.txt";
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

GameGraph::GameGraph(){
    m_iLocation = 0;
    for (int i = 0; i < NUMROOMS; i++) {
        for (int j = 0; j < NUMROOMS; j++) {
            m_cAdjMatrix[i][j] = 0;
        }
    }
}

bool GameGraph::doCommand(char *cmd) {
    makeUpper(cmd);
    char cmd1[32], cmd2[32];

    sscanf(cmd, "%s %s", cmd1, cmd2);

    if (strcmp(cmd1, "TAKE") == 0 || strcmp(cmd1, "FIGHT") == 0) {
        cout << cmd1 << " not implemented yet.\n";
        return false;
    }
    else if (strcmp(cmd1, "QUIT") == 0) return true;
    else if (strcmp(cmd1, "GO") == 0) {
        char direction;

        if (strcmp(cmd2, "NORTH") == 0) direction = 'N';
        else if (strcmp(cmd2, "SOUTH") == 0) direction = 'S';
        else if (strcmp(cmd2, "EAST") == 0) direction = 'E';
        else if (strcmp(cmd2, "WEST") == 0) direction = 'W';
        else if (strcmp(cmd2, "UP") == 0) direction = 'U';
        else if (strcmp(cmd2, "DOWN") == 0) direction = 'D';
        else {
            cout << "You cannot move in that direction.\n";
            return false;
        }
        
        for (int i = 0; i < NUMROOMS; i++) {
            if (m_cAdjMatrix[m_iLocation][i] == direction) {
                m_iLocation = i;
                describeRoom(m_iLocation);
                return false;
            }
        }
        cout << "You cannot move in that direction.\n";
    }
    else {
        cout << "Invalid command.\n";
    }
    return false;
}

void GameGraph::PrintAll(){
    for (int i = 0; i < NUMROOMS; i++) {
        for (int j = 0; j < NUMROOMS; j++)
            printf("%d ", m_cAdjMatrix[i][j]);
        printf("\n");
    }
}

void GameGraph::setLink(int roomIdx, int linkIdx, char dCode){
    m_cAdjMatrix[roomIdx][linkIdx] = dCode;

    switch(dCode) {
        case 'N': m_cAdjMatrix[linkIdx][roomIdx] = 'S'; break;
        case 'S': m_cAdjMatrix[linkIdx][roomIdx] = 'N'; break;
        case 'E': m_cAdjMatrix[linkIdx][roomIdx] = 'W'; break;
        case 'W': m_cAdjMatrix[linkIdx][roomIdx] = 'E'; break;
        case 'U': m_cAdjMatrix[linkIdx][roomIdx] = 'D'; break;
        case 'D': m_cAdjMatrix[linkIdx][roomIdx] = 'U'; break;
    }
}

void GameGraph::describeRoom(int roomIdx){
    cout << "You are in " << m_Rms[roomIdx].m_sRoomName << "\n";
    cout << m_Rms[roomIdx].m_sRoomDesc << "\n";
    cout << "You find a " << m_Rms[roomIdx].m_sItemName << "\n";
    cout << "You see an enemy " << m_Rms[roomIdx].m_sCreatureName << "\n";

    for(int i = 0; i<NUMROOMS;i++){
        switch(m_cAdjMatrix[roomIdx][i]){
            case 'N':cout << "There is a door in the North wall.\n";break;
            case 'S':cout << "There is a door in the South wall.\n";break;
            case 'E':cout << "There is a door in the East wall.\n";break;
            case 'W':cout << "There is a door in the West wall.\n";break;
            case 'U':cout << "There is a stairway going up.\n";break;
            case 'D':cout << "There is a stairway going down.\n";break;
        }
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

    m_InFile.open(filename, ifstream::in);
    if(!m_InFile.is_open())
    {
        return false;
    }

    for(int i=0; i<NUMROOMS; i++)
    {
        getNextLine(line, 128);
        strcpy(m_Rms[i].m_sRoomName, line);

        getNextLine(line, 128);
        strcpy(m_Rms[i].m_sRoomDesc, line);

        getNextLine(line, 128);
        strcpy(m_Rms[i].m_sItemName, line);

        getNextLine(line, 128);
        strcpy(m_Rms[i].m_sCreatureName, line);

        getNextLine(line, 128);
        link = atoi(line);
        if (link != -1) setLink(i, link, 'N');

        getNextLine(line, 128);
        link = atoi(line);
        if (link != -1) setLink(i, link, 'S');

        getNextLine(line, 128);
        link = atoi(line);
        if (link != -1) setLink(i, link, 'E');

        getNextLine(line, 128);
        link = atoi(line);
        if (link != -1) setLink(i, link, 'W');

        getNextLine(line, 128);
        link = atoi(line);
        if (link != -1) setLink(i, link, 'U');

        getNextLine(line, 128);
        link = atoi(line);
        if (link != -1) setLink(i, link, 'D');
    }

    m_InFile.close();
    describeRoom(m_iLocation);
    return true;
}