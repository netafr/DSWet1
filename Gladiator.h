//
// Created by Oren Jacobian Pana on 11/23/2017.
//

#ifndef DSHW1_GLADIATOR_H
#define DSHW1_GLADIATOR_H
#include <iostream>
#include "Splay.h"
using namespace std;


class Gladiator {
	int gladiatorID;
	int trainerID;
	int level;
	SplayTree<Gladiator>* ptr;
	bool compareByLevel;

public:
	Gladiator() = default;
	Gladiator(int gladiatorID, int trainerID, int level, SplayTree<Gladiator>* ptr,
		bool compareByLevel);
	Gladiator(const Gladiator& glad) = default;
	int GetGladiatorID() const;
	int GetTrainderID() const;
	int GetLevel() const;
	SplayTree<Gladiator>* GetPointer() const;
	void SetGladiatorID(int id);
	void SetTrainderID(int id);
	void SetLevel(int level);
	void SetPointer(SplayTree<Gladiator>* pointer);
	bool operator==(const Gladiator&) const;
	bool operator>(const Gladiator&) const;
	bool operator<(const Gladiator&) const;
	friend std::ostream& operator<<(std::ostream& output, const Gladiator& glad);
	~Gladiator() = default;
};

std::ostream& operator<<(std::ostream& output, const Gladiator& glad);



#endif //DSHW1_GLADIATOR_H
