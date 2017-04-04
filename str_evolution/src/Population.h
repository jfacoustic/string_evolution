/*
 * Population.h
 *
 *  Created on: Apr 3, 2017
 *      Author: joshua
 */

#ifndef POPULATION_H_
#define POPULATION_H_
#include <vector>
#include "Organism.h"
class Population {
public:
	Population(int prob);
	void updateCount();
	void addOrganism(std::string sequence);
	void killOrganism(int id);
	virtual ~Population();
	int getCount();
	void reproduce(int id);
	std::vector< Organism * > copyPopulation();
private:
	unsigned int _count;
	unsigned int _prob;
	std::vector < Organism * > _population;
};

#endif /* POPULATION_H_ */
