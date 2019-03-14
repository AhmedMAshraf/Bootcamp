/*
 * Delay.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-062
 */

#include "Delay.h"

void Delay_msec(uint32_t TimeInMsec)
{
    while(TimeInMsec > 0)
    {
        TimeInMsec -- ;
    }
}
