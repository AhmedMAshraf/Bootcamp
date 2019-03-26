/*
 * Compiler.h
 *
 *  Created on: Mar 25, 2019
 *      Author: AVE-LAP-062
 */

#ifndef DIO_COMPILER_H_
#define DIO_COMPILER_H_

#define AUTOMATIC
#define STATIC static


#define FUNC(returntype , memclass)                  returntype
#define VAR(vartype , memclass)                      vartype
#define P2FUNC(vartype , memclass , funcname)        returntype (*funcname)
#define CONST(consttype , memclass)                  const consttype
#define P2CONST(ptrtype , memclass , ptrclass)       const ptrtype *
#define P2VAR(ptrtype , memclass , ptrclass)         ptrtype *
#define CONSTP2VAR(ptrtype , memclass , ptrclass)    ptrtype * const
#define CONSTP2CONST(ptrtype , memclass , ptrclass)  const ptrtype * const



#endif /* DIO_COMPILER_H_ */
