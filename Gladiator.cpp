//
// Created by Oren Jacobian Pana on 11/23/2017.
//

#include "Gladiator.h"
#include <iostream>
#include "Gladiator.h"

Gladiator::Gladiator(int gladiatorID, int trainerID, int level, Gladiator* ptr,
                     bool compareByLevel) :
        gladiatorID(gladiatorID), trainerID(trainerID), level(level), ptr(ptr),
        compareByLevel(compareByLevel) {}

int Gladiator::GetGladiatorID() const {
    return gladiatorID;
}
int Gladiator::GetTrainderID() const {
    return trainerID;
}
int Gladiator::GetLevel() const {
    return level;
}
Gladiator* Gladiator::GetPointer() const {
    return ptr;
}
void Gladiator::SetGladiatorID(int id) {
    gladiatorID = id;
}
void Gladiator::SetTrainderID(int id) {
    trainerID = id;
}
void Gladiator::SetLevel(int level) {
    level = level;
}
void Gladiator::SetPointer(Gladiator* pointer) {
    ptr = pointer;
}
bool Gladiator::operator==(const Gladiator& gladiator) const {
    return gladiatorID == gladiator.GetGladiatorID() &&
                   trainerID == gladiator.GetTrainderID() &&
                   level == gladiator.GetLevel() &&ptr == gladiator.GetPointer()
           && compareByLevel == gladiator.compareByLevel;
}
bool Gladiator::operator<(const Gladiator& gladiator) const {
    //assuming both blabla same bool blabla
    if (compareByLevel) {
        if (level == gladiator.GetLevel())
            return gladiatorID < gladiator.GetGladiatorID();
        return level < gladiator.GetLevel();
    }
    return gladiatorID < gladiator.GetGladiatorID();
}
bool Gladiator::operator>(const Gladiator& gladiator) const {
    return gladiator < (*this);
}
