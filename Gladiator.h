//
// Created by Oren Jacobian Pana on 11/23/2017.
//

#ifndef DSHW1_GLADIATOR_H
#define DSHW1_GLADIATOR_H



class Gladiator {
    int gladiatorID;
    int trainerID;
    int level;
    Gladiator* ptr;
    bool compareByLevel;

public:
    Gladiator(int gladiatorID, int trainerID, int level, Gladiator* ptr,
              bool compareByLevel);
    int GetGladiatorID() const;
    int GetTrainderID() const;
    int GetLevel() const;
    Gladiator* GetPointer() const;
    void SetGladiatorID(int id);
    void SetTrainderID(int id);
    void SetLevel(int level);
    void SetPointer(Gladiator* pointer);
    bool operator==(const Gladiator&) const;
    bool operator>(const Gladiator&) const;
    bool operator<(const Gladiator&) const;

    ~Gladiator() = default;
};





#endif //DSHW1_GLADIATOR_H
