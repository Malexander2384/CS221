#include "heart.h"

using namespace std;

Heart::Heart(int v):RedCard(v)
{
	SetValue(v);
	SetColor("red");
	SetSuit('H');
}

string Heart::Description() const
{
	string output;
	output = Card::Description() + GetSuit();
	return output;	
}