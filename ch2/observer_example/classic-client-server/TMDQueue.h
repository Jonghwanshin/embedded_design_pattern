#ifndef TMDQueue_H
#define TMDQueue_H

/*##auto_generated */
#include <stdio.h>
#include "ECGPkg.h"
#include "TimeMarkedData.h"

typedef struct TMDQueue TMDQueue;
/* this queue is meant to operate as a "leaky queue".
In this queue, data are never removed perse, 
but are instead overwritten when the buffer pointer wraps around.
This allows for many clients to read the same data from the queue. */

struct TMDQueue {
    int head;
    int size;
    struct TimeMarkedData buffer[QUEUE_SIZE];
}

/* Constructors and desctructors: */
void TMDQueue_Init(TMDQueue* const me);
void TMDQueue_Cleanup(TMDQeueu* const me);

/* Operations */
int TMDQueue_getNextIndex(TMDQueue* const me, int index);
void TMDQueue_insert(TMDQueue* const me, const struct TimeMarkedData tmd);
boolean TMDQueue_isEmpty(TMDQueue* const me);
struct TimeMarkedData TMDQueue_remove(TMDQueue* const me, int index);
int TMDQueue_getBuffer(const TMDQueue* const me);
TMDQueue* TMDQueue_Create(void);
void TMDQueue_Destroy(TMDQueue* const me);
#endif