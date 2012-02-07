/*
  Cube3x3x3.h - Library for controlling a LED cube.
  Donets Vladimir 2012
  mail: donets.vladimir@gmail.com
  www: jetfix.ru
*/

#ifndef LedCube_h
#define LedCube_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class LedCube
{
  public:
    LedCube(byte size, byte levelPins[], byte colPins[]);
    
    byte getCols();
    byte getLevels();
    int getColPin(int r);
    int getLevelPin(int lv);
    
    void lightOne(byte level, byte col, boolean clean );
    void lightPerimetr(byte row);
    void pulsePerimetr(byte row, byte count, int pause);
    void lightOneOff(byte col);
    void lightRow(byte row, int ms);
    void lightCol(byte col, int pause, boolean clean);
    
    byte seq();


  private:
    byte cols;
    byte levels;

    byte colPins[9];
    byte levelPins[3];
    byte buffer[3][9];
    boolean bufferEnabled;
    boolean bufferInverted;
    byte excluded;
    
    void toggleRows(byte row);
    void toggleCols(byte col, boolean clean);
    void clear();
    
    
};

#endif

