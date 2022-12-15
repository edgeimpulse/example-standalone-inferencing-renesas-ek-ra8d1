/* Edge Impulse ingestion SDK
 * Copyright (c) 2022 EdgeImpulse Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/* Includes */
#include "timer_handler.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#include <stdint.h>


static volatile uint64_t _ms_time = 0;
volatile bool _timer_1_set = false;

/* public functions */
/**
 *
 */
void ei_timer_init(void)
{
    fsp_err_t err = FSP_SUCCESS;

    err = R_GPT_Open (&g_timer0_ctrl, &g_timer0_cfg);

    if (FSP_SUCCESS != err)
    {
        /* GPT Timer failure message */
        //APP_ERR_PRINT ("\r\n** R_GPT_TimerOpen API failed **\r\n");
    }
}

/**
 *
 */
void ei_timer0_start(void)
{
    fsp_err_t err = FSP_SUCCESS;

    /* Start GPT module - no error control for now */
    err = R_GPT_Start (&g_timer0_ctrl);

    _ms_time = 0;
}

/**


/**
 *
 */
void ei_timer0_stop(void)
{
    fsp_err_t err = FSP_SUCCESS;

    /* Stop GPT module - no error control for now */
    err =  R_GPT_Stop (&g_timer0_ctrl);

    _ms_time = 0;
}


/**
 * @brief callback function for interrupt
 *
 * @param p_args
 */
void periodic_timer_msgq_cb(timer_callback_args_t *p_args)
{
    FSP_PARAMETER_NOT_USED (p_args);

    _ms_time++;
}

/**
 *
 * @return
 */
uint64_t timer_get_ms(void)
{
    return _ms_time;
}
