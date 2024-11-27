//---------------------------------------------------------------
// File: GameGraph.h
// Purpose: Header file for a D&D game class
// Programming Language: C++
// Author: Dr. Rick Coleman
//---------------------------------------------------------------
#ifndef GAMEGRAPH_H
#define GAMEGRAPH_H
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define NUMROOMS 20

struct Room
{
		char	m_sRoomName[64];
		char	m_sRoomDesc[128];
		char	m_sItemName[32];
		char	m_sCreatureName[64];
};

class GameGraph
{
	private:
		ifstream	m_InFile;					// File to read from
		char        m_cAdjMatrix[NUMROOMS][NUMROOMS];
		Room		m_Rms[NUMROOMS];
		int			m_iLocation;	// Index of current room location


	public:
		GameGraph();						// Class constructor
		~GameGraph();						// Class destructor
		bool LoadGame(char *filename);	// Read game file, build scenario
		                                // and describe first room.
		bool doCommand(char *cmd);		// Execute a command
		void PrintAll();
	private:
		void getNextLine(char *line, int lineLen);
		void setLink(int roomIdx, int linkIdx, char dCode);
		void describeRoom(int roomIdx);

};

#endif