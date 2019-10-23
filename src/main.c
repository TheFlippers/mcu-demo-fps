/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */


#include "stm32f4xx.h"
#include "main.h"

int main(void) {
  unsigned char clear_p[7] = {0};
  unsigned char clear_n[7] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  unsigned char prev[7] = {0};
  unsigned char next[7] = {0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40};
  FDDdisplay_init();
  FDDdisplay_draw(clear_p, clear_n);
  FDDdisplay_draw(clear_n, clear_p);

  for (;;) {
    // pix_address();

    FDDdisplay_draw(clear_p, clear_n);
    for (int i=0; i<25000; ++i);
    FDDdisplay_draw(clear_n, clear_p);
    for (int i=0; i<25000; ++i);

    /*
    for(int i=0; i<8; ++i) {
      FDDdisplay_draw(prev, next);
      pix_copy(prev, next);
      for (int k=0; k<8; ++k) {
        next[k] >>= 1;
        if (next[k] == 0) {
          next[k] = 0x80;
        }
      }
      for(int j=0; j<10000; ++j);
    }
    */

    /*
    FDDdisplay_draw(prev, next);
    for(int i=0; i<50000; ++i);
    FDDdisplay_draw(next, prev);
    for(int i=0; i<50000; ++i);
    FDDpattern_count();
    for(int i=0; i<5000000; ++i);
    FDDpattern_speed();
    for(int i=0; i<5000000; ++i);
    FDDpattern_full();
    for(int i=0; i<5000000; ++i);
    */
  }
}

void pix_copy(uint8_t* prev, uint8_t* next) {
  for (int i=0; i<7; ++i) {
    prev[i] = next[i];
  }
}

void pix_address() {
  for (int i=0; i<7; ++i) {
    for (int j=0; j<7; ++j) {
      GPIOC->BSRRL = (i<<10) | (j<<5);
      TIM2->CR1 |= TIM_CR1_CEN;
      while((TIM2->CR1 & TIM_CR1_CEN) || (TIM5->CR1 & TIM_CR1_CEN));
      for(int k=0; k<50000; k++);
      GPIOC->BSRRH = 0xffff;
    }
    for (int j=0; j<7; ++j) {
      GPIOC->BSRRL = (i<<10) | (j<<5);
      TIM5->CR1 |= TIM_CR1_CEN;
      while((TIM2->CR1 & TIM_CR1_CEN) || (TIM5->CR1 & TIM_CR1_CEN));
      for(int k=0; k<50000; k++);
      GPIOC->BSRRH = 0xffff;
    }
  }
}
