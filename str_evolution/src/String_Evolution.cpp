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
#include "matplotlibcpp.h"
using namespace std;

namespace  plt = matplotlibcpp;
int main() {
	bool running = true;
	srand(time(NULL));
	int mutateProb, birthProb, deathProb, iter;
	string initSequence = "";
	cout << "Enter probability for a mutation: ";
	cin >> mutateProb;
	cout << endl << "Enter probability for birth: ";
	cin >> birthProb;
	cout << endl << "Enter probability for death: ";
	cin >> deathProb;
	cout << endl << "Enter number of iterations: ";
	cin >> iter;
	cout << endl << "Enter initial sequence in A,T,C,G: ";
	cin >> initSequence;
	vector<int>x;
	vector<int>y;

	Population * test = new Population(mutateProb);
	test->addOrganism(initSequence);
	while (running) {
		for (int i = 0; i < iter; i++) {
			test->iterate(birthProb, deathProb);
			test->printPopulation();
			x.push_back(test->getAge());
			y.push_back(test->getCount());
		}
		plt::plot(x,y);
		plt::show();
		char yn;
		cout << "Keep going?  y/N ";
		cin >> yn;
		if (yn != 'y') running = false;
		else {
			cout << endl << "How many iterations? ";
			cin >> iter;
		}
	}
	return 0;
}

