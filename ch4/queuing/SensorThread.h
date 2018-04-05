#ifndef SENSORTHREAD_H_
#define SENSORTHREAD_H_
#include "GasData.h"
/* … initial declaratons stuff above … */
typedef struct SensorThread SensorThread;
struct SensorThread
{
    struct GasDataQueue *itsGasDataQueue;
    struct HeSensor itsHeSensor;
    struct N2Sensor itsN2Sensor;
    struct O2Sensor itsO2Sensor;
};
enum SensorType{
    HE_SENSOR = 0,
    N2_SENSOR,
    O2_SENSOR
}
/* Operations */
void SensorThread_updateData(SensorThread *const me);
/* … other operations declared too … */
#endif