/*
 * Dio_Lcfg.c
 *
 *  Created on: Mar 25, 2019
 *      Author: AVE-LAP-062
 */

#include "Dio.h"
#include "Dio_MemMap.h"
#include "Dio_Internal.h"


/* Cfg struct for Dio Channels/Ports */
Dio_Cfg_S Dio_Channels[MAX_CHANNELS]={{PF4_ID,PF4,PORTF_NO,IP},{PF3_ID,PF3,PORTF_NO,OP},{PF1_ID,PF1,PORTF_NO,OP},{PF2_ID,PF2,PORTF_NO,OP}};

/* Cfg struct for Dio channel/Port groups */
Dio_ChannelGroupType Channel_Groups[MAX_CH_GROUPS]={{0x1E,1,PORTF_NO},{0xBB,0,PORTF_NO}};
