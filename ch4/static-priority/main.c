#define TRUE 1 

void main(void)
{
    /* initialize the links and start the tasks */
    MotorPositionSensor_initRelations();
    MotorDisplay_initRelations();
    MotorController_initRelations();
    /* now let the tasks do their thing */
    while (TRUE)
    {
    };
};