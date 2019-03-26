/*
 * Platform_Types.h
 *
 *  Created on: Mar 25, 2019
 *      Author: AVE-LAP-062
 */

#ifndef DIO_PLATFORM_TYPES_H_
#define DIO_PLATFORM_TYPES_H_

/*
* CPU register type width
*/
#define CPU_TYPE_8                                  (8U)
#define CPU_TYPE_16                                 (16U)
#define CPU_TYPE_32                                 (32U)

/*
* Bit order definition
*/
#define MSB_FIRST                   (0u)        /* Big endian bit ordering        */
#define LSB_FIRST                   (1u)        /* Little endian bit ordering     */

/*
* Byte order definition
*/
#define HIGH_BYTE_FIRST             (0u)        /* Big endian byte ordering       */
#define LOW_BYTE_FIRST              (1u)        /* Little endian byte ordering    */

/*
* Platform type and endianess definitions
*/

#define CPU_TYPE            CPU_TYPE_8
#define CPU_BIT_ORDER       LSB_FIRST
#define CPU_BYTE_ORDER      LOW_BYTE_FIRST

/*
* Boolean Values
*/
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

typedef unsigned char         boolean;        /*                  TRUE / FALSE                       */
typedef unsigned char         uint8;          /*           0 .. 255                                  */
typedef signed char           sint8;          /*        -128 .. +127                                 */
typedef unsigned short        uint16;         /*           0 .. 65535                                */
typedef signed short          sint16;         /*      -32768 .. +32767                               */
typedef unsigned long         uint32;         /*           0 .. 4294967295                           */
typedef signed long           sint32;         /*  -2147483648 .. +2147483647                         */
typedef signed long long      sint64;         /*  0x8000000000000000..0x7FFFFFFFFFFFFFFF             */
typedef float                 float32;        /*  -3.4028235e+38..+3.4028235e+38                     */
typedef double                float64;        /*  1.7976931348623157e+308..+1.7976931348623157e+308  */
typedef unsigned int          uint8_least;
typedef unsigned int          uint16_least;
typedef unsigned int          uint32_least;
typedef signed int            sint8_least;
typedef signed int            sint16_least;
typedef signed int            sint32_least;


#endif /* DIO_PLATFORM_TYPES_H_ */
