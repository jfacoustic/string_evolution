/*
 * Community.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: joshua
 */

#include "Community.h"

Community::Community() {
	// TODO Auto-generated constructor stub
	_count = 0;
}

Community::~Community() {
	// TODO Auto-generated destructor stub
}

void Community::updateCount() {
	_count = _community.size();
}

void Community::addSpecies(int mutationProbability, std::string initialSequence, std::string speciesName) {
	_community.push_back(new Population(mutationProbability, speciesName));
	_community.back()->addOrganism(initialSequence);
	updateCount();
}

void Community::removeSpecies(int id) {
	delete _community[id];
	_community[id] = NULL;
	for (int i = id; i < _community.size() - 1; i++) {
		Population * temp = _community[i];
		_community[i] = _community[i+1];
		_community[i+1] = temp;
	}
	_community.pop_back();
	updateCount();
}

void Community::checkExtinction() {
	for (int i = 0; i < _count; i ++) {
		if (_community[i]->getCount() <= 0) {
			removeSpecies(i);
			i--;
		}
	}
}
