#include "club.h"

using namespace std;

Club::Club(int v):BlackCard(v)
{
	SetValue(v);
	SetColor("black");
	SetSuit('C');
}

string Club::Description() const
{
	string output;
	output = Card::Description() + GetColor() + GetSuit();
	return output;	
}