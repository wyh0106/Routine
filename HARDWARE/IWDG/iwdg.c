#include "iwdg.h"


void IwdgInit(u8 Prer, u16 Rlr){
	IWDG->KR = WrtEnr;
	IWDG->PR = Prer;
	IWDG->RLR = Rlr;
	IwdgRld;
	IWDG->KR = ENR;
}