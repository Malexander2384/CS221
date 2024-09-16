#include "spade.h"

using namespace std;

Spade::Spade(int v):BlackCard(v)
{
	SetValue(v);
	SetColor("black");
	SetSuit('S');
}

string Spade::Description() const
{
	string output;
	output = Card::Description() + GetSuit();
	return output;
}