/**
 * @file	sim_watchdog.h
 * @brief	Simulator of Independent Watchdog (IWDG) high-level API
 *
 * @date Nov 28, 2023
 * @author	Andrey Belomutskiy, (c) 2012-2023
 * @author	andreika <prometheus.pcb@gmail.com>
 */

#pragma once

#include "engine_controller.h"

// 100 ms is our empiric choice based on 2 * SLOW_CALLBACK_PERIOD_MS
#define WATCHDOG_RESET_MS (2 * SLOW_CALLBACK_PERIOD_MS)
// 300 ms is our default timeout
#define WATCHDOG_TIMEOUT_MS (3 * WATCHDOG_RESET_MS)
// 5 secs should be enough to wait until
#define WATCHDOG_FLASH_TIMEOUT_MS 5000


// we use 'int' for compatibility with addConsoleActionI()
// can be called multiple times to change the timeout
static void startWatchdog(int = WATCHDOG_TIMEOUT_MS) { }

// Can be called for debug reasons to test the watchdog
static void setWatchdogResetPeriod(int resetMs) { }

// A reset is done only if enough time has passed since the last reset.
static void tryResetWatchdog() { }
