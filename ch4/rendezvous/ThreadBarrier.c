#include "ThreadBarrier.h"

/* Constructors and destructors:*/
void ThreadBarrier_Init(ThreadBarrier *const me)
{
    me->currentCount = 0;
    me->expectedCount = 3;
    me->mutex = OSSemaphore_Create();
    me->barrier = OSSemaphore_Create();
    if (me->barrier)
    {
        OSSemaphore_lock(me->barrier);
        printf("BARRIER IS LOCKED FIRST ME\n");
    }
}
void ThreadBarrier_Cleanup(ThreadBarrier *const me)
{
    OSSemaphore_Destroy(me->barrier);
    OSSemaphore_Destroy(me->mutex);
}
/* Operations */
void ThreadBarrier_reset(ThreadBarrier *const me, int x)
{
    me->expectedCount = x;
    me->currentCount = 0;
}
void ThreadBarrier_synchronize(ThreadBarrier *const me)
{
    /* 
        protect the critical region around 
        the currentCount
        currentCount: the variable for counting entered semaphores
    */
    OSSemaphore_lock(me->mutex);
        ++me->currentCount; /* critical region */
    OSSemaphore_release(me->mutex);

    /*
        are conditions for unblocking met?
        if so, then release the first blocked
        thread or the hightest priority blocked
        thread(depending on the OS)
    */
    if (me->currentCount == me->expectedCount)
    {
        printf("Conditions met \n");
        OSSemaphore_release(me->barrier);
    }
    /*
        lock the semaphore and when released
        then release it for the next blocked thread
    */
    OSSemaphore_lock(me->barrier);
    OSSemaphore_release(me->barrier);
}
ThreadBarrier *ThreadBarrier_Create(void)
{
    ThreadBarrier *me = (ThreadBarrier *)malloc(sizeof(ThreadBarrier));
    if (me != NULL)
    {
        ThreadBarrier_Init(me);
        return me;
    }
}
void ThreadBarrier_Destroy(ThreadBarrier *const me)
{
    if (me != NULL)
    {
        ThreadBarrier_Cleanup(me);
    }
    free(me);
}

struct barrier_type
{
    int arrive_counter;
    int leave_counter;
    int flag;
    std::mutex lock;
}

void barrier(barrier_type* b, int p)
{
    b->lock.lock();
    if(b->leave_counter != p)
    {
        b->lock.unlock();
        while (b->leave_counter != p); //wait for all to leave before clearing
        b->lock.lock();
    }
    if(b->arrive_counter == 0)
    {
        b->flag = 0;
    }
    b->arrive_counter++;
    int arrived = b->arrive_counter;
    b->lock.unlock();
    if(arrived == p)
    {
        b->arrive_counter = 0;
        b->leave_counter = 1;
        b->flag = 1;
    }
    else
    {
        while(b->flag == 0);
        b->lock.lock();
        b->leave_counter++;
        b->lock.unlock();
    }
}