#include "diamond.h"

using namespace std;

Diamond::Diamond(int v):RedCard(v)
{
	SetValue(v);
	SetColor("red");
	SetSuit('D');
}

string Diamond::Description() const
{
	string output;
	output = Card::Description() + GetColor() + GetSuit();
	return output;	
}