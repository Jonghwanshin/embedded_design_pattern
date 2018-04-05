#include "FlightDataDisplay.h"
/* Constructors and destructors:*/
static void cleanUpRelations(FlightDataDisplay *const me)
{
    if (me->itsKinematicData != NULL)
    {
        me->itsKinematicData = NULL;
    }
}

void FlightDataDisplay_Init(FlightDataDisplay *const me)
{
    me->itsKinematicData = NULL;
}
void FlightDataDisplay_Cleanup(FlightDataDisplay *const me)
{
    cleanUpRelations(me);
}
/* Operations */
void FlightDataDisplay_showFlightData(FlightDataDisplay *const me)
{
    Attitude a;
    Position p;
    a = KinematicData_getAttitude(me->itsKinematicData);
    p = KinematicData_getPosition(me->itsKinematicData);
    printf(
        :)
}
struct KinematicData *FlightDataDisplay_getItsKinematicData(const FlightDataDisplay *const me)
{
    return (struct KinematicData *)me->itsKinematicData;
}
void FlightDataDisplay_setItsKinematicData(FlightDataDisplay *const me, struct KinematicData *p_KinematicData)
{
    me->itsKinematicData = p_KinematicData;
}
FlightDataDisplay *FlightDataDisplay_Create(void)
{
    FlightDataDisplay *me = (FlightDataDisplay *)malloc(sizeof(FlightDataDisplay));
    if (me != NULL)
    {
        FlightDataDisplay_Init(me);
    }
    return me;
}
void FlightDataDisplay_Destroy(FlightDataDisplay *const me)
{
    if (me != NULL)
    {
        FlightDataDisplay_Cleanup(me);
    }
    free(me);
}