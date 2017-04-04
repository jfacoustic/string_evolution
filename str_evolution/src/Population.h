/*
 * Population.h
 *
 *  Created on: Apr 3, 2017
 *      Author: joshua
 */

#ifndef POPULATION_H_
#define POPULATION_H_
#include <vector>
#include <iostream>
#include "Organism.h"
class Population {
public:
	Population(int prob, std::string name);
	void updateCount();
	void addOrganism(std::string sequence);
	void killOrganism(int id);
	virtual ~Population();
	int getCount();
	void reproduce(int id);
	std::vector< Organism * > copyPopulation();
	void iterate(int birthChance, int deathChance);
	void printPopulation();
	int getAge();
private:
	unsigned int _count;
	unsigned int _prob;
	std::vector < Organism * > _population;
	unsigned int _popAge;
	std::string _name;
};

#endif /* POPULATION_H_ */

