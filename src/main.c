/**
 * @file main.c
 * @brief Main file
 * @version 0.1
 * @date 2019-09-23
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "ch.h"
#include "hal.h"

static volatile uint16_t val = 0;

int main(void)
{
    /*
     * System initializations.
     * - HAL initialization, this also initializes the configured device drivers
     *   and performs the board-specific initializations.
     * - Kernel initialization, the main() function becomes a thread and the
     *   RTOS is active.
     */
    halInit();
    chSysInit();

    /***************************************************************
     ***************************************************************/

    while (true)
    {
        val++;
        if (val % 500 == 0)
            // toggle LED
            palToggleLine(LINE_LED);
        chThdSleepMilliseconds(1);
    }
}
