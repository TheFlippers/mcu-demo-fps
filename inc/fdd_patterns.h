#ifndef __FDD_PATTERNS_H
#define __FDD_PATTERNS_H

#include "stm32f4xx.h"
#include "fdd_display.h"

void FDDpattern_count();
void FDDpattern_speed();
void FDDpattern_full();

void FDDpattern_ccol_lr();
void FDDpattern_wcol_lr();
// void FDDpattern_crow_tb(uint8_t*, uint8_t*);
// void FDDpattern_wcol_lr(uint8_t*, uint8_t*);
// void FDDpattern_wrow_lr(uint8_t*, uint8_t*);

#endif
