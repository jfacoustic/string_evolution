/*
 * Population.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: joshua
 */

#include "Population.h"
Population::Population( int prob ) {
	// TODO Auto-generated constructor stub
	_count = 0;
	_popAge = 0;
	_prob = prob;
}

Population::~Population() {
	// TODO Auto-generated destructor stub
}
void Population::updateCount() {
	if (_count != _population.size()) {
		_count = _population.size();
	}
}
void Population::addOrganism( std::string sequence ) {
	_population.push_back( new Organism( sequence ) );
	updateCount();
}

void Population::reproduce( int id ) { //id is id of parent
	_population.push_back( _population[id]->reproduce( _prob ) );
	updateCount();
}

void Population::killOrganism( int id ) {
	delete _population[id];
	_population[id] = NULL;
	for (int i = id; i < _population.size() -1; i++) {
		Organism * temp = _population[i];
		_population[i] = _population[i+1];
		_population[i+1] = temp;
	}
	_population.pop_back();
	updateCount();
}

int Population::getCount(){
	return _count;
}

std::vector< Organism * > Population::copyPopulation() {
	return _population;
}

void Population::iterate(int birthChance, int deathChance) {
	for(int i = 0; i < _population.size(); i++) {
		_population[i]->agePlusOne();
		int birthRand = rand() % 101;
		if ( birthRand <= birthChance )
			reproduce(i);
		int deathRand = rand() % 101;
		if ( deathRand <= deathChance ) {
			killOrganism(i);
		}
	}
	_popAge++;
}

void Population::printPopulation() {
	std::cout << std::endl << "Population Age: " << _popAge << std::endl;
	std::cout << _count << " Organisms" << std::endl;
	for (int i = 0; i < _population.size(); i++) {
		std::cout << _population[i]->getSequence() << " age: " << _population[i]->getAge() << std::endl;
	}
}

int Population::getAge() {
	return _popAge;
}
