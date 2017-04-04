/*
 * Community.h
 *
 *  Created on: Apr 4, 2017
 *      Author: joshua
 */

#ifndef SRC_COMMUNITY_H_
#define SRC_COMMUNITY_H_
#include <vector>
#include "Population.h"


class Community {
public:
	Community();
	void updateCount();
	void addSpecies(int mutationProbability, std::string initialSequence, std::string speciesName);
	void removeSpecies(int id);
	void checkExtinction();
	virtual ~Community();

private:
	std::vector<Population*> _community;
	int _count;
};

#endif /* SRC_COMMUNITY_H_ */
