//============================================================================
// Name        : String_Evolution.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Organism.h"
#include "Population.h"
using namespace std;


int main() {
	srand(time(NULL));
	string startingSequence = "AGTCAGAAAGGTT";
	Organism * a = new Organism(startingSequence);
	Organism * b = a->reproduce(10);
	cout << b->getSequence() << endl;
	delete a;
	for (int i = 0; i < 10; i ++) {
		Organism * a = b->reproduce(10);
		delete b;
		cout << startingSequence << " " << a->getSequence() << endl;
		Organism * b = a->reproduce(10);
		delete a;
		cout << startingSequence << " " << b->getSequence() << endl;
	}
	Population * test = new Population(10);
	test->addOrganism("AGTC");
	for (int i = 0; i < 100; i ++) {
		test->reproduce(i);

	}

	cout << test->getCount() << endl;
	std::vector < Organism * > temp = test->copyPopulation();
	for (int i = 0; i < temp.size() ; i++)
		cout << temp[i]->getSequence() << endl;
	return 0;
}
