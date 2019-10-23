#include "fdd_patterns.h"

unsigned char NUMBERS[15][7] = {
  {
    0b00001000,
    0b00011000,
    0b00101000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00111110
  },

  {
    0b00011000,
    0b00100100,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b00111100
  },

  {
    0b00011100,
    0b00100010,
    0b00000010,
    0b00001100,
    0b00000010,
    0b00100010,
    0b00011100
  },

  {
    0b00100010,
    0b00100010,
    0b00100010,
    0b00111111,
    0b00000010,
    0b00000010,
    0b00000010
  },

  {
    0b01111111,
    0b01000000,
    0b01011100,
    0b01100010,
    0b00000001,
    0b01000010,
    0b00111100
  },

  {
    0b00001000,
    0b00010000,
    0b00100000,
    0b00101100,
    0b00110010,
    0b00100010,
    0b00011100
  },

  {
    0b01111111,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b01000000
  },

  {
    0b00011100,
    0b00100010,
    0b00100010,
    0b00011100,
    0b00100010,
    0b00100010,
    0b00011100
  },

  {
    0b00111111,
    0b00100001,
    0b00100001,
    0b00111111,
    0b00000001,
    0b00000001,
    0b00111111
  },

  {
    0b00001000,
    0b00010100,
    0b00100010,
    0b00111110,
    0b00100010,
    0b00100010,
    0b00100010
  },

  {
    0b00111100,
    0b00100010,
    0b00100010,
    0b00111100,
    0b00100010,
    0b00100010,
    0b00111100
  },

  {
    0b00011100,
    0b00100010,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100010,
    0b00011100
  },

  {
    0b00111100,
    0b00100010,
    0b00100010,
    0b00100010,
    0b00100010,
    0b00100010,
    0b00111100
  },

  {
    0b00111110,
    0b00100000,
    0b00100000,
    0b00111100,
    0b00100000,
    0b00100000,
    0b00111110
  },

  {
    0b00111110,
    0b00100000,
    0b00100000,
    0b00111100,
    0b00100000,
    0b00100000,
    0b00100000
  }
};

void FDDpattern_speed() {
  unsigned char zeros[7] = { 0 };
  FDDdisplay_draw(zeros, NUMBERS[0]);

  for (int i=1; i<15; ++i) {
    FDDdisplay_draw(NUMBERS[i-1], NUMBERS[i]);
  }
}

void FDDpattern_count() {
  unsigned char zeros[7] = { 0 };
  FDDdisplay_draw(zeros, NUMBERS[0]);
  for (int j=0;j<500000;++j);

  for (int i=1; i<15; ++i) {
    FDDdisplay_draw(NUMBERS[i-1], NUMBERS[i]);
    for (int j=0;j<500000;++j);
  }
}

void FDDpattern_full() {
  unsigned char zeros[7] = { 0 };
  FDDdisplay_draw_full(zeros, NUMBERS[0]);

  for (int i=1; i<15; ++i) {
    FDDdisplay_draw_full(NUMBERS[i-1], NUMBERS[i]);
  }
}

void FDDpattern_ccol_lr() {
  unsigned char prev[7] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
  unsigned char next[7] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

  for (int j=0; j<7; ++j) { // col
    for (int i=0; i<7; ++i) { // row
      FDDunset_pixel(prev, next, j, i);
    }
    FDDdisplay_draw(prev, next);
    for (int i=0; i<7; ++i) { // row
      FDDunset_pixel(next, prev, j, i);
    }
  }
}

/*
void FDDpattern_crow_tb(uint8_t* prev, uint8_t* next) {
  for (int i=0; i<7; ++i) { // row
    for (int j=0; j<7; ++j) { // col
      FDDunset_pixel(prev, next, j, i);
    }
    FDDdisplay_draw(prev, next);
  }
}
*/

void FDDpattern_wcol_lr() {
  unsigned char prev[7] = { 0 };
  unsigned char next[7] = { 0 };

  for (int j=0; j<7; ++j) {
    for (int i=0; i<7; ++i) {
      FDDset_pixel(prev, next, j, i);
    }
    FDDdisplay_draw(prev, next);
    for (int i=0; i<7; ++i) {
      FDDset_pixel(next, prev, j, i);
    }
  }
}

/*
void FDDpattern_wcol_lr(uint8_t* prev, uint8_t* next) {
  for (int j=0; j<7; ++j) { // col
    for (int i=0; i<7; ++i) { // row
      FDDset_pixel(prev, next, j, i);
    }
    FDDdisplay_draw(prev, next);
  }
}
*/

/*
void FDDpattern_wrow_lr(uint8_t* prev, uint8_t* next) {
  for (int i=0; i<7; ++i) { // row
    for (int j=0; j<7; ++j) { // col
      FDDset_pixel(prev, next, j, i);
    }
    FDDdisplay_draw(prev, next);
  }
}
*/
