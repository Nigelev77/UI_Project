#pragma once

typedef enum UI_BoxLayoutType {
  UI_Pixels = 0,
  UI_FitParent = 1,
} UI_BoxLayoutType;

typedef struct UI_RangeAxis {
  union {
    float x, y;
    float d[2];
    float l, r;
    float h, w;
  };
} UI_RangeAxis;

typedef struct UI_Box {
  UI_BoxLayoutType type;
  UI_RangeAxis axis[2];

  UI_Box *parent;
  UI_Box *first;
  UI_Box *next;
  UI_Box *prev;
  UI_Box *last;
} UI_Box;


