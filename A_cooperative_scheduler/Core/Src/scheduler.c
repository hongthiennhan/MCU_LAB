/*
 * scheduler.c
 *
 *  Created on: Nov 7, 2025
 *      Author: Thien-Nhan
 */

#include "scheduler.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void) {

}

void SCH_Update(void) {
    if (SCH_tasks_G[0].pTask == 0) return;

    if (SCH_tasks_G[0].Delay == 0) {
        SCH_tasks_G[0].RunMe++;
    } else {
        SCH_tasks_G[0].Delay--;
    }
}


unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD) {
    uint32_t i = 0;
    uint32_t accumulated = 0;

    // Find insert position
    while (i < SCH_MAX_TASKS && SCH_tasks_G[i].pTask != 0 && accumulated + SCH_tasks_G[i].Delay <= DELAY) {
        accumulated += SCH_tasks_G[i].Delay;
        DELAY -= SCH_tasks_G[i].Delay;
        i++;
    }

    // If full
    if (i == SCH_MAX_TASKS) return SCH_MAX_TASKS;

    // Shift tasks
    for (uint32_t j = SCH_MAX_TASKS-1; j > i; j--) {
        SCH_tasks_G[j] = SCH_tasks_G[j-1];
    }

    // Insert new task
    SCH_tasks_G[i].pTask  = pFunction;
    SCH_tasks_G[i].Period = PERIOD;
    SCH_tasks_G[i].RunMe  = 0;
    SCH_tasks_G[i].Delay  = DELAY;

    // Fix delay
    if (SCH_tasks_G[i+1].pTask != 0) {
        SCH_tasks_G[i+1].Delay -= DELAY;
    }

    return i;
}


void SCH_Dispatch_Tasks(void) {
    if (SCH_tasks_G[0].RunMe > 0) {

        (*SCH_tasks_G[0].pTask)();
        SCH_tasks_G[0].RunMe--;

        uint32_t period = SCH_tasks_G[0].Period;

        SCH_Delete_Task(0);  // Remove first task (O(n))

        // Reschedule periodic task
        if (period > 0) {
            SCH_Add_Task((*SCH_tasks_G[0].pTask), period, period); 
        }
    }
}

void SCH_Delete_Task(const uint32_t TASK_INDEX) {
    if (SCH_tasks_G[TASK_INDEX].pTask == 0) return;

    uint32_t removed_delay = SCH_tasks_G[TASK_INDEX].Delay;

    // Shift tasks up
    for (uint32_t i = TASK_INDEX; i < SCH_MAX_TASKS-1; i++) {
        SCH_tasks_G[i] = SCH_tasks_G[i+1];
    }

    // Fix delay of new first element
    SCH_tasks_G[TASK_INDEX].Delay += removed_delay;

    // Clear last entry
    SCH_tasks_G[SCH_MAX_TASKS-1].pTask = 0;
}

