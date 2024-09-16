#include "blackcard.h"

using namespace std;

BlackCard::BlackCard(int v):Card(v)
{
	SetValue(v);
	SetColor("black");
	SetSuit('U');	
}

string BlackCard::Description() const
{
	string output;
	output = Card::Description() + GetColor();
	return output;	
}