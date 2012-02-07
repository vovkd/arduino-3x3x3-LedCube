#include <Cube3x3x3.h>

#define SIZE 3
#define COLS (SIZE*SIZE)

byte levelPins[SIZE] = {11,12,13};
byte colPins[COLS] = {2,3,4,5,6,7,8,9,10};

LedCube cube(SIZE, levelPins, colPins);
int r = 0;
void setup (){}

void loop ()
{

    for (byte j = 0; j < SIZE; j++){
        for (byte i = 1; i < COLS; i++){
          cube.lightOne(j,i, false);
          if (j != SIZE && i != COLS){
            delay(30);
          }
        }
    }

    for (byte j = 0; j < SIZE; j++){
        cube.lightPerimetr(j);
        delay(30);
    }
    
    for (byte k = 0; k < SIZE; k++){
        cube.lightOne(k,0, false);
        delay(50);
    }

    for (byte i = 1; i < SIZE; i++){
      for (byte j = 2; j < COLS; j+=i*j){
        cube.lightCol(j, 30, true);
      }
    }

    for (byte i = 0; i < COLS * SIZE; i++){
      cube.lightOne(random(0, SIZE), random(0, COLS), false);
      delay(60);
    }
    
    for (byte j = SIZE; j > 0; j--){
        for (byte i = COLS; i > 1; i--){
          cube.lightOne(j,i, false);
          if (j != SIZE){
            delay(15);
          }
        }
    }

    for (byte i = 0; i < COLS; i++){
      for (byte j = 0; j < SIZE; j++){
          cube.lightPerimetr(j);
          delay(30);
      }
    }


    cube.lightOne(random(0, SIZE), random(0, COLS), false);
    for (byte j = 0; j < SIZE; j++){
        for (byte i = 0; i < COLS; i++){
          r = random(j, random(j, j+i));
          int d = random(30, 80);
          for (byte k = 0; k < SIZE; k++){
              cube.lightOne(k,r, false);
              delay(d);
          }
        }
        cube.pulsePerimetr(j, 5, 30);
        cube.lightRow(j, 100);
    }

    for (byte i = 0; i < 100; i++){
      cube.lightOne(random(0, SIZE), random(0, COLS), false);
      delay(20);
    }
    cube.lightOne(random(0, SIZE), random(0, COLS), false);
    for (byte k = 0; k < SIZE; k++){
        cube.lightOne(k,r, false);
        delay(50);
    }
    for (byte i = 0; i < COLS * SIZE; i++){
      cube.lightOne(random(0, SIZE), random(0, COLS), false);
      delay(60);
    }
   
    for (byte i = 1; i < COLS; i++){
      cube.lightCol(i, 60, true);
    }


    for (byte i = 1; i < SIZE; i++){
      for (byte j = 2; j < COLS; j+=i*j){
        cube.lightCol(j, 30, true);
      }
    }

}

