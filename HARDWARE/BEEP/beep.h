#ifndef __BEEP_H
#define __BEEP_H

#include "sys.h"

#define BEEP PBout(8)
#define true 1
#define false 0

void BeepInit(void);

#endif