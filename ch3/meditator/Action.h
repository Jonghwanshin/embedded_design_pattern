#ifndef ACTION_H_
#define ACTION_H_
typedef struct {
    int rotationArmJoint1;
    int rotationArmJoint2;
    int rotationArmJoint3;
    int rotationArmJoint4;
    int slidingArmJoint1;
    int slidingArmJoint2;
    int slidingArmJoint3;
    int slidingArmJoint4;
    int manipulatorForce;
    int manipulatorOpen;
} Action;

Action* Action_Create();
#endif