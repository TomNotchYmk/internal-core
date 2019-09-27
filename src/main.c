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

static volatile uint16_t val = 0;

void turnOffLED(void)
{
    palSetLine(LINE_LED);
    return;
}

void turnOnLED(void)
{
    palClearLine(LINE_LED);
    return;
}

void hello(BaseSequentialStream *chp, int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    static char msg[] = "Hello\r\n";
    streamWrite(chp, msg, sizeof(msg));
}

ShellCommand cmd[] = {{"hello", hello}, {NULL, NULL}};

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
        if (val % 500 == 0)
            // toggle LED
            palToggleLine(LINE_LED);
        chThdSleepMilliseconds(1);
    }
}
