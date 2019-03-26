/*
 * Dio.c
 *
 *  Created on: Mar 25, 2019
 *      Author: AVE-LAP-062
 */


#include "Dio.h"
#include "Dio_MemMap.h"
#include "Det.h"
#include "../Reg.h"

extern Dio_Cfg_S Dio_Channels[MAX_CHANNELS];
extern Dio_ChannelGroupType Channel_Groups[MAX_CH_GROUPS];

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return level of channel.
* [SWS_Dio_00133]
************************************************************************************/
FUNC(Dio_LevelType,memclass) Dio_ReadChannel(VAR(Dio_ChannelType,memclass) ChannelId)
{
    uint8 Channel_Value=0 , Index = 0u ;

    /* Check if id is not valid */
    if(ChannelId > MAX_CHANNEL_ID)
    {
        Det_ReportError(0u, 0u, 0u, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
    {
        for(Index=0u ; Index<MAX_CHANNELS ; Index++)
        {
            if(Dio_Channels[Index].Id == ChannelId)
            {
                if(Dio_Channels[Index].Direction == IP)
                {
                    switch(Dio_Channels[Index].Port)
                    {
                        case PORTA_NO : Channel_Value =(uint8) ((PORTA->DATA) & (1u<<(Dio_Channels[Index].Channel)));
                                        break;
                        case PORTB_NO : Channel_Value =(uint8) ((PORTB->DATA) & (1u<<(Dio_Channels[Index].Channel)));
                                        break;
                        case PORTC_NO : Channel_Value =(uint8) ((PORTC->DATA) & (1u<<(Dio_Channels[Index].Channel)));
                                        break;
                        case PORTD_NO : Channel_Value =(uint8) ((PORTD->DATA) & (1u<<(Dio_Channels[Index].Channel)));
                                        break;
                        case PORTE_NO : Channel_Value =(uint8) ((PORTE->DATA) & (1u<<(Dio_Channels[Index].Channel)));
                                        break;
                        case PORTF_NO : Channel_Value =(uint8) ((PORTF->DATA) & (1u<<(Dio_Channels[Index].Channel)));
                                        break;
                        default :       /*Invalid PORT ID */
                                        Det_ReportError(0u,0u,0u,DIO_E_PARAM_INVALID_PORT_ID);
                                        break;
                    }
                    /* Exit from loop */
                    break ;
                }
                else
                {
                    /* Invalid Direction  */
                }
            }
            else
            {
                /* DET Error Invalid Channel ID */
                if(Index == MAX_CHANNELS-1u)
                {
                    Det_ReportError(0u,0u,0u,DIO_E_PARAM_INVALID_CHANNEL_ID);
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
    }
    /* Specifies [SWS_Dio_00027] */
    return Channel_Value ;
}

/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
* [SWS_Dio_00134]
************************************************************************************/
FUNC(void,memclass) Dio_WriteChannel(VAR(Dio_ChannelType,memclass) ChannelId , VAR(Dio_LevelType,memclass) Level)
{
    uint8 Index1 = 0u ;

    /* Check if id is not valid */
    if(ChannelId > MAX_CHANNEL_ID)
    {
        Det_ReportError(0u, 0u, 0u, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
    {
        for(Index1=0u ; Index1<MAX_CHANNELS ; Index1++)
        {
            if(Dio_Channels[Index1].Id == ChannelId)
            {
                if(Dio_Channels[Index1].Direction == OP)
                {
                    /* [SWS_Dio_00028] */
                    switch(Dio_Channels[Index1].Port)
                    {
                        case PORTA_NO : (PORTA->DATA) &= ~(1u<<Dio_Channels[Index1].Channel);
                                        if(Level == STD_HIGH)
                                            (PORTA->DATA) |= 1u<<Dio_Channels[Index1].Channel;
                                        break;
                        case PORTB_NO : (PORTB->DATA) &= ~(1u<<Dio_Channels[Index1].Channel);
                                        if(Level == STD_HIGH)
                                            (PORTB->DATA) |= 1u<<Dio_Channels[Index1].Channel;
                                        break;
                        case PORTC_NO : (PORTC->DATA) &= ~(1u<<Dio_Channels[Index1].Channel);
                                        if(Level == STD_HIGH)
                                            (PORTC->DATA) |= 1u<<Dio_Channels[Index1].Channel;
                                        break;
                        case PORTD_NO : (PORTD->DATA) &= ~(1u<<Dio_Channels[Index1].Channel);
                                        if(Level == STD_HIGH)
                                            (PORTD->DATA) |= 1u<<Dio_Channels[Index1].Channel;
                                        break;
                        case PORTE_NO : (PORTE->DATA) &= ~(1u<<Dio_Channels[Index1].Channel);
                                        if(Level == STD_HIGH)
                                            (PORTE->DATA) |= 1u<<Dio_Channels[Index1].Channel;
                                        break;
                        case PORTF_NO : (PORTF->DATA) &= ~(1u<<Dio_Channels[Index1].Channel);
                                        if(Level == STD_HIGH)
                                            (PORTF->DATA) |=1u<<Dio_Channels[Index1].Channel;
                                        break;
                        default :       /* DET Error */
                                        Det_ReportError(0u,0u,0u,DIO_E_PARAM_INVALID_PORT_ID);
                                        break;
                    }
                    /*Exit from loop*/
                    break;
                }
                else
                {
                    /* Invalid Direction Do nothing */
                    /*[SWS_Dio_00079] , [SWS_Dio_00029]*/
                }
            }
            else
            {
                /* DET Error Invalid Channel ID */
                if(Index1 == MAX_CHANNELS-1u)
                {
                    Det_ReportError(0u,0u,0u,DIO_E_PARAM_INVALID_CHANNEL_ID);
                }
                else
                {
                    /* Do Nothing */
                }
            }
        }
    }
}

/************************************************************************************
* Service Name: Dio_ReadPort
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO port..
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType
* Description: Function to read a level of a port.
* [SWS_Dio_00135]
************************************************************************************/
FUNC(Dio_PortLevelType,memclass) Dio_ReadPort(VAR(Dio_PortType,memclass) PortId)
{
    uint8 Port_Value , Index3 = 0u ;

    /* Check if id is not valid */
    if(PortId > MAX_PORT_ID)
    {
        Det_ReportError(0u, 0u, 0u, DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
    {
        for(Index3=0u ; Index3<MAX_CHANNELS ; Index3++)
        {
            if(Dio_Channels[Index3].Port == PortId)
            {
                switch(PortId)
                {
                    case PORTA_NO : Port_Value =(uint8)(PORTA->DATA);
                                    break;
                    case PORTB_NO : Port_Value =(uint8)(PORTB->DATA);
                                    break;
                    case PORTC_NO : Port_Value =(uint8)(PORTC->DATA);
                                    break;
                    case PORTD_NO : Port_Value =(uint8)(PORTD->DATA);
                                    break;
                    case PORTE_NO : Port_Value =(uint8)(PORTE->DATA);
                                    break;
                    case PORTF_NO : Port_Value =(uint8)(PORTF->DATA);
                                    break;
                    default :       Det_ReportError(0u,0u,0u,DIO_E_PARAM_INVALID_PORT_ID);
                                    break;
                }
                /* break from loop */
                break ;
            }
            else
            {
                /* DET Error Invalid Port ID */
                if(Index3 == MAX_CHANNELS-1u)
                {
                    Det_ReportError(0u,0u,0u,DIO_E_PARAM_INVALID_PORT_ID);
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
    }
    /* Specifies [SWS_Dio_00031] */
    return Port_Value ;
}

/************************************************************************************
* Service Name: Dio_WritePort
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO port.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a port.
* [SWS_Dio_00136]
* [SWS_Dio_00034]
* [SWS_Dio_00035]
* [SWS_Dio_00105]
************************************************************************************/
FUNC(void,memclass) Dio_WritePort(VAR(Dio_PortType,memclass) PortId , VAR(Dio_PortLevelType,memclass) Level)
{
    uint8 Index4 = 0u ;

    /* Check if id is not valid */
    if(PortId > MAX_PORT_ID)
    {
        Det_ReportError(0u, 0u, 0u, DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
    {
        for(Index4=0u ; Index4<MAX_CHANNELS ; Index4++)
        {
            if(Dio_Channels[Index4].Direction == OP)
            {
                if(Dio_Channels[Index4].Port == PortId)
                {
                    switch(PortId)
                    {
                        /* [SWS_Dio_00034] ,  [SWS_Dio_00105] */
                        case PORTA_NO : if(Level == 1u)
                                        {
                                            (PORTA->DATA) |= 1u<<Dio_Channels[Index4].Channel;
                                        }
                                        else
                                        {
                                            (PORTA->DATA) &= ~(1u<<Dio_Channels[Index4].Channel);
                                        }
                                        break;
                        case PORTB_NO : if(Level == 1u)
                                        {
                                            (PORTB->DATA) |= 1u<<Dio_Channels[Index4].Channel;
                                        }
                                        else
                                        {
                                            (PORTB->DATA) &= ~(1u<<Dio_Channels[Index4].Channel);
                                        }
                                        break;
                        case PORTC_NO : if(Level == 1u)
                                        {
                                            (PORTC->DATA) |= 1u<<Dio_Channels[Index4].Channel;
                                        }
                                        else
                                        {
                                            (PORTC->DATA) &= ~(1u<<Dio_Channels[Index4].Channel);
                                        }
                                        break;
                        case PORTD_NO : if(Level == 1u)
                                        {
                                            (PORTD->DATA) |= 1u<<Dio_Channels[Index4].Channel;
                                        }
                                        else
                                        {
                                            (PORTD->DATA) &= ~(1u<<Dio_Channels[Index4].Channel);
                                        }
                                        break;
                        case PORTE_NO : if(Level == 1u)
                                        {
                                            (PORTE->DATA) |= 1u<<Dio_Channels[Index4].Channel;
                                        }
                                        else
                                        {
                                            (PORTE->DATA) &= ~(1u<<Dio_Channels[Index4].Channel);
                                        }
                                        break;
                        case PORTF_NO : if(Level == 1u)
                                        {
                                            (PORTF->DATA) |= 1u<<Dio_Channels[Index4].Channel;
                                        }
                                        else
                                        {
                                            (PORTF->DATA) &= ~(1u<<Dio_Channels[Index4].Channel);
                                        }
                                        break;
                        default :       /* Inaccessible condition*/
                                        break;
                    }
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else
            {
                /* Do Nothing to I/P pins */
                /* [SWS_Dio_00035] */
            }
        }
    }
}

/************************************************************************************
* Service Name: Dio_ReadChannelGroup
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr - const pointer to channel group
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType
* Description: Function to read a level of a channel group.
* [SWS_Dio_00137]
************************************************************************************/
FUNC(Dio_PortLevelType,memclass) Dio_ReadChannelGroup(P2CONST(Dio_ChannelGroupType,memclass,ptrclass) ChannelGroupIdPtr)
{
    uint8 Ch_Group = 0 , Index5 = 0 ;

    /* Check if port id is not valid */
    if(ChannelGroupIdPtr == 0)
    {
        Det_ReportError(0u, 0u, 0u, DIO_E_PARAM_POINTER);
    }
    else
    {
        /* Check if port id is not valid */
        if(ChannelGroupIdPtr->port > MAX_PORT_ID)
        {
            Det_ReportError(0u, 0u, 0u, DIO_E_PARAM_INVALID_PORT_ID);
        }
        else
        {
            for(Index5=0u ; Index5<MAX_CH_GROUPS ; Index5++)
            {
                if(Channel_Groups[Index5].port == ChannelGroupIdPtr->port )
                {
                    switch(Dio_Channels[Index5].Port)
                    {
                        /* [SWS_Dio_00092] , [SWS_Dio_00093] */
                        case PORTA_NO :
                            Ch_Group = (PORTA->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                            break;
                        case PORTB_NO :
                            Ch_Group = (PORTB->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                            break;
                        case PORTC_NO :
                            Ch_Group = (PORTC->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                            break;
                        case PORTD_NO :
                            Ch_Group = (PORTD->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                            break;
                        case PORTE_NO :
                            Ch_Group = (PORTE->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                            break;
                        case PORTF_NO :
                            Ch_Group = (PORTF->DATA & (ChannelGroupIdPtr->mask)) >> ChannelGroupIdPtr->offset;
                            break;
                        default : /* DET */
                            break;
                    }
                    /* break from loop */
                    break ;
                }
                else
                {
                    /* DET Error Invalid Port ID */
                    if(Index5 == MAX_CH_GROUPS-1u)
                    {
                        Det_ReportError(0u,0u,0u,DIO_E_PARAM_INVALID_PORT_ID);
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
            }
        }
    }
    return Ch_Group;
}


/************************************************************************************
* Service Name: Dio_WriteChannelGroup
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr - pointer to channel group.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel group.
************************************************************************************/
FUNC(void,memclass) Dio_WriteChannelGroup(P2CONST(Dio_ChannelGroupType,memclass,ptrclass) ChannelGroupIdPtr, VAR(Dio_PortLevelType,memclass) Level)
{
    uint8 Index6 = 0 ;
    for(Index6=0u ; Index6<MAX_CH_GROUPS ; Index6++)
    {
        if(Channel_Groups[Index6].port == ChannelGroupIdPtr->port )
        {
            switch(Dio_Channels[Index6].Port)
            {
                case PORTA_NO :
                    PORTA->DATA &= ~(ChannelGroupIdPtr->mask);
                    if(Level)
                        PORTA->DATA |= (ChannelGroupIdPtr->mask);
                    break;
                case PORTB_NO :
                    PORTB->DATA &= ~(ChannelGroupIdPtr->mask);
                    if(Level)
                        PORTB->DATA |= (ChannelGroupIdPtr->mask);
                    break;
                case PORTC_NO :
                    PORTC->DATA &= ~(ChannelGroupIdPtr->mask);
                    if(Level)
                        PORTC->DATA |= (ChannelGroupIdPtr->mask);
                    break;
                case PORTD_NO :
                    PORTD->DATA &= ~(ChannelGroupIdPtr->mask);
                    if(Level)
                        PORTD->DATA |= (ChannelGroupIdPtr->mask);
                    break;
                case PORTE_NO :
                    PORTE->DATA &= ~(ChannelGroupIdPtr->mask);
                    if(Level)
                        PORTE->DATA |= (ChannelGroupIdPtr->mask);
                    break;
                case PORTF_NO :
                    PORTF->DATA &= ~(ChannelGroupIdPtr->mask);
                    if(Level)
                        PORTF->DATA |= (ChannelGroupIdPtr->mask);
                    break;
            }
        }
        else
        {

        }
    }
}

/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the level of a channel and return the level of the channel after flip.
************************************************************************************/
FUNC(Dio_LevelType, memclass) Dio_FlipChannel(VAR(Dio_ChannelType, memclass) ChannelId)
{
   uint8 index = 0U;/*index for loop */
       if (ChannelId > MAX_CHANNELS)/*check if channel ID is valid with my channels */
       {
           /*check if the channel id is maximum 42 report INVALID_ERROR_ID for DET fun */
           /*if there is invalid id LED2 will turn on */
           Det_ReportError(0, 0, 0, DIO_E_PARAM_INVALID_CHANNEL_ID);
       }
       else
       {
           for (index = 0U; index < (uint8) MAX_CHANNELS; index++)
           {
               if (Dio_Channels[index].Id == ChannelId)/*check if ID argument is equal to configuration*/
               {
                       switch (Dio_Channels[index].Port)
                       /*switch on port */
                       {
                       case PORTA_NO:
                           (PORTA->DATA) ^= (1U << Dio_Channels[index].Channel);/*clear data register in PORTA */
                           break;
                       case PORTB_NO:
                           (PORTB->DATA) ^= (1U << Dio_Channels[index].Channel); /*clear data register in PORTB */
                           break;
                       case PORTC_NO:
                           (PORTC->DATA) ^= (1U << Dio_Channels[index].Channel);/*clear data register in PORTB */
                           break;
                       case PORTD_NO:
                           (PORTD->DATA) ^= (1U << Dio_Channels[index].Channel);/*clear data register in PORTC */
                           break;
                       case PORTE_NO:
                           (PORTE->DATA) ^= (1U << Dio_Channels[index].Channel);/*clear data register in PORTE */
                           break;
                       case PORTF_NO:
                           (PORTF->DATA) ^= (1U << Dio_Channels[index].Channel);/*clear data register in PORTD */
                           break;
                       default:
                           break;
                       }
                   }
                   else
                   {
                       /*SWS_Dio_00108*/
                   }
           }
       }
}



