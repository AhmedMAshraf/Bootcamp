/*
 * Dio_Internal.h
 *
 *  Created on: Mar 25, 2019
 *      Author: AVE-LAP-062
 */

#ifndef DIO_DIO_INTERNAL_H_
#define DIO_DIO_INTERNAL_H_

#include "Platform_Types.h"
#include "Std_Types.h"

#define MAX_CHANNEL_ID 41u
#define MAX_PORT_ID 5u

#define PORTA_NO 0u
#define PORTB_NO 1u
#define PORTC_NO 2u
#define PORTD_NO 3u
#define PORTE_NO 4u
#define PORTF_NO 5u

#define PF1_ID 38u
#define PF2_ID 39u
#define PF3_ID 40u
#define PF4_ID 41u

#define PF0 0u
#define PF1 1u
#define PF2 2u
#define PF3 3u
#define PF4 4u

#define IP 0u
#define OP 1u

typedef struct
{
    uint8 Id        ;
    uint8 Channel   ;
    uint8 Port      ;
    uint8 Direction ;
}Dio_Cfg_S;


#endif /* DIO_DIO_INTERNAL_H_ */
