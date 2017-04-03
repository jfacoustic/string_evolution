//============================================================================
// Name        : String_Evolution.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Organism.h"
using namespace std;


int main() {
	srand(time(NULL));
	string startingSequence = "AGTCAGAAAGGTT";
	Organism * a = new Organism(startingSequence);
	Organism * b = a->reproduce(1);
	cout << b->getSequence() << endl;
	delete a;
	for (int i = 0; i < 10000; i ++) {
		Organism * a = b->reproduce(1);
		delete b;
		cout << startingSequence << " " << a->getSequence() << endl;
		Organism * b = a->reproduce(1);
		delete a;
		cout << startingSequence << " " << b->getSequence() << endl;
	}
	return 0;
}
