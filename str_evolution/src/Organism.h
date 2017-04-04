/*
 * Organism.h
 *
 *  Created on: Apr 3, 2017
 *      Author: joshua
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include <string>
#include <stdlib.h>
#include <ctime>

class Organism {
public:
	Organism(std::string sequence);
	virtual ~Organism();
	//Mutation probability is an integer out of 100.
	Organism * reproduce(int mutation_probability);
	std::string getSequence();
	int getAge();
	void agePlusOne();

private:
	std::string _sequence;
	int _age;
};

#endif /* ORGANISM_H_ */
