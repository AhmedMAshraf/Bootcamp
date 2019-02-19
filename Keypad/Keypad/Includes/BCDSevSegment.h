/*
 * BCDSevSegment.h
 *
 * Created: 2/18/2019 12:47:54 PM
 *  Author: AVE-LAP-062
 */ 


#ifndef BCDSEVSEGMENT_H_
#define BCDSEVSEGMENT_H_

#include "../Includes/DIO.h"
#include "../Includes/BCDSevSegment_cfg.h"

void BCDSevegments_enable(void);
void BCDSevegments_disable(void);
void BCDSevegments_displayNo(uint16 no);



#endif /* BCDSEVSEGMENT_H_ */