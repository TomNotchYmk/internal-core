/**
 * @file main.cpp
 * @author John Lam (cklamaq@connect.ust.hk)
 * @brief Example code for using the GY53 driver.
 * @version 0.1
 * @date 2019-01-11
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
            palToggleLine(LINE_LED);
        chThdSleepMilliseconds(1);
    }
}
