#ifndef SLIDINGARMJOINT_H_
#define SLIDINGARMJOINT_H_

typedef struct {
    int currentLength;
    char deviceId;
    int minArmLength;
    int maxArmLength;
} SlidingArmJoint;

int SlidingArmJoint_getLength();
int SlidingArmJoint_setLength();
int SlidingArmJoint_zero();
#endif