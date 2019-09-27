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
#include "peripherals/usbcfg.h"
#include "shell/shell.h"
#include "shell/shell_manager.h"
#include "count.h"
#include "chprintf.h"

static volatile uint16_t val = 0;

void countCmd(BaseSequentialStream *chp, int argc, char *argv[])
{
    static const uint8_t err[] = "Invalid input";
    if (argc != 1)
    {
        streamWrite(chp, err, sizeof(err));
        return;
    }
    Result r = getLargestConsecutiveChar(argv[0]);
    chprintf(chp, "Char: %c, Count: %d\r\n", r.c, r.length);
}

ShellCommand cmd[] = {{"count", countCmd}, {NULL, NULL}};

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
    setup_USB();
    shellManagerStart(cmd);

    /***************************************************************
     ***************************************************************/

    while (true)
    {
        val++;
        chThdSleepMilliseconds(1);
    }
}
