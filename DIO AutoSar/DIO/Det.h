/*
 * Det.h
 *
 *  Created on: Mar 25, 2019
 *      Author: AVE-LAP-062
 */

#ifndef DIO_DET_H_
#define DIO_DET_H_

#define DIO_E_PARAM_INVALID_CHANNEL_ID  0x0Au
#define DIO_E_PARAM_INVALID_PORT_ID     0x14u
#define DIO_E_PARAM_INVALID_GROUP       0x1Fu
#define DIO_E_PARAM_POINTER             0x20u

extern FUNC(Std_ReturnType,memclass) Det_ReportError( VAR(uint16,memclass) ModuleId,VAR(uint8,memclass) InstanceId, VAR(uint8,memclass) ApiId, VAR(uint8,memclass) ErrorId);

#endif /* DIO_DET_H_ */
