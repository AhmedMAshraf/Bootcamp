/*
 * Det.c
 *
 *  Created on: Mar 26, 2019
 *      Author: AVE-LAP-062
 */
#include "Std_Types.h"
#include "Det.h"
#include "Reg.h"


/************************************************************************************
* Service Name: Det_ReportError
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ModuleId ,InstanceId , ApiId , ErrorId
* Parameters (inout): None
* Parameters (out): None
* Return value: Std_ReturnType
* Description: Function to report errors.
* [SWS_Dio_00140]
************************************************************************************/
FUNC(Std_ReturnType,memclass) Det_ReportError( VAR(uint16,memclass) ModuleId, VAR(uint8,memclass) InstanceId, VAR(uint8,memclass) ApiId, VAR(uint8,memclass) ErrorId)
{
    /* Check for type of error*/
    switch(ErrorId)
    {
        case DIO_E_PARAM_INVALID_CHANNEL_ID :
            /* Set LED3 ( PF3 ) and turn off LED1, LED2 (PF1,PF2) */
            PORTF->DATA |= (1<<3);
            PORTF->DATA &=~(0x06);
            break;
        case DIO_E_PARAM_INVALID_PORT_ID :
            /* Set LED3 ( PF3 ) and turn off LED1, LED2 (PF1,PF2) */
            PORTF->DATA |= (1<<3);
            PORTF->DATA &=~(0x06);
            break;
        case DIO_E_PARAM_INVALID_GROUP :
            /* Set LED3 ( PF3 ) and turn off LED1, LED2 (PF1,PF2) */
            PORTF->DATA |= (1<<3);
            PORTF->DATA &=~(0x06);
            break;
        case DIO_E_PARAM_POINTER :
            /* Set LED3 ( PF3 ) and turn off LED1, LED2 (PF1,PF2) */
            PORTF->DATA |= (1<<3);
            PORTF->DATA &=~(0x06);
            break;
    }
    return E_NOT_OK;
}
