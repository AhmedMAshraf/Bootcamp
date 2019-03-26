/*
 * Dio.h
 *
 *  Created on: Mar 25, 2019
 *      Author: AVE-LAP-062
 */

#ifndef DIO_DIO_H_
#define DIO_DIO_H_

#include "Std_Types.h"
#include "Dio_Cfg.h"
#include "Dio_Internal.h"

/*specifies [SWS_Dio_00183]*/
typedef uint8 DioPortOffset;
typedef uint8 DioPortMask;

/*specifies [SWS_Dio_00182]*/
typedef uint8 Dio_ChannelType;

/*specifies [SWS_Dio_00183]*/
typedef uint8 Dio_PortType;

/*specifies [SWS_Dio_00186]*/
typedef uint8 Dio_PortLevelType;

/*Specifies [SWS_Std_00007]*/
typedef uint8 Dio_LevelType;

/* [SWS_Dio_00184]
 * [SWS_Dio_00021]
 * [SWS_Dio_00022] */
typedef struct
{
    uint8 mask;
    uint8 offset;
    Dio_PortType port;
}Dio_ChannelGroupType;


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
************************************************************************************/
extern FUNC(Dio_LevelType,memclass) Dio_ReadChannel(VAR(Dio_ChannelType,memclass) ChannelId);

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
************************************************************************************/
extern FUNC(void,memclass) Dio_WriteChannel(VAR(Dio_ChannelType,memclass) ChannelId , VAR(Dio_LevelType,memclass) Level);

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
************************************************************************************/
extern FUNC(Dio_PortLevelType,memclass) Dio_ReadPort(VAR(Dio_PortType,memclass) PortId);

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
************************************************************************************/
extern FUNC(void,memclass) Dio_WritePort(VAR(Dio_PortType,memclass) PortId , VAR(Dio_PortLevelType,memclass) Level);

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
************************************************************************************/
extern FUNC(Dio_PortLevelType,memclass) Dio_ReadChannelGroup(P2CONST(Dio_ChannelGroupType,memclass,ptrclass) ChannelGroupIdPtr);


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
extern FUNC(void,memclass) Dio_WriteChannelGroup(P2CONST(Dio_ChannelGroupType,memclass,ptrclass) ChannelGroupIdPtr, VAR(Dio_PortLevelType,memclass) Level);


/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the level of a channel and return the level of the channel after flip.*/
extern FUNC(Dio_LevelType, memclass) Dio_FlipChannel(VAR(Dio_ChannelType, memclass) ChannelId);

#endif /* DIO_DIO_H_ */
