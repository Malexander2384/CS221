#include "redcard.h"

using namespace std;

RedCard::RedCard(int v):Card(v)
{
	SetValue(v);
	SetColor("red");
	SetSuit('U');	
}

string RedCard::Description() const
{
	string output;
	output = Card::Description() + GetColor();
	return output;	
}