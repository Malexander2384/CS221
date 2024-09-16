#include <string>
using namespace std;

#ifndef CARD_H
#define CARD_H

class Card                      
{
 private:
  int value;			        // Card value: 2-10 for number cards, 11-14 for JQKA; 0 for unknown
  string color;			        // Card color: "red", "black", or "unknown"
  char suit;			        // Card suit: 'H' for hearts, 'D' for diamonds, 'C' for clubs, 'S' for spades or 'U' for unknown

 public:
  //******** Add Constructor Prototypes Below  *********//
  Card();	        // Default constructor prototype: creates card with value v, color unknown, and suit U
	
  Card(int v);	    // Parameterized constructor prototype: creates card with value v, color unknown, and suit U
	
	
  //******** Add Transformer Prototypes Below *********//
  void SetValue(int v);      // SetValue prototype: Sets card value equal to v
	
  void SetColor(string c);      // SetColor prototype: Sets color value equal to c
	
  void SetSuit(char s);      // SetSuit prototype:  Sets suit value equal to s
	
	
  //******** Add Observer Prototypes Below *********//
  int GetValue() const; 	    // GetValue prototype: Returns current value of value
	
  string GetColor() const;      // GetColor prototype: Returns current value of color
	
  char GetSuit() const;      // GetSuit prototype:  Returns current value of suit
	
  virtual string Description() const;      // Description prototype: Polymorphic Function!!!
	                            // Outputs card characteristics - value as a string (see sample output from p01input1.txt)
};


#endif