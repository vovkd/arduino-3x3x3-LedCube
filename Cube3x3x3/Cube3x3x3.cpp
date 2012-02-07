/*
  Cube3x3x3.cpp - Library for controlling a LED cube.
  Donets Vladimir 2012
  mail: donets.vladimir@gmail.com
  www: jetfix.ru
*/


#include "Cube3x3x3.h"

LedCube::LedCube(byte size, byte lp[], byte cp[]) : levels(size), cols(size*size)
{
       
    for (byte i= 0; i < levels; i++)
    {
        levelPins[i] = lp[i];
        pinMode(levelPins[i], OUTPUT);
    }
    
    for (byte i= 0; i < cols; i++)
    {
        colPins[i] = cp[i];
        pinMode(colPins[i], OUTPUT);
    }
    
}

byte LedCube::getCols()
{
    return cols;
}

byte LedCube::getLevels()
{
    return levels;
}

void LedCube::clear()
{
    for (byte i = 0; i < levels; i++)
    {
        digitalWrite(levelPins[i], HIGH);
    }
    for (byte i = 0; i < cols; i++)
    {
        digitalWrite(colPins[i], LOW);
    }
}

int LedCube::getLevelPin(int lv)
{
    return lv && lv <= levels ? levelPins[lv] : 0;
}

int LedCube::getColPin(int col)
{
    return col && col <= cols ? colPins[col] : 0;
}

void LedCube::toggleRows(byte lv){
    for (byte i = 0; i < levels; i++)
    {
        if (i != lv){
            digitalWrite(levelPins[i], HIGH);
        }
        else{
            digitalWrite(levelPins[i], LOW);
        }
    }
}

void LedCube::toggleCols(byte col, boolean clean){
    for (byte i = 0; i < cols; i++)
    {
        if (i != excluded ){
            if (i != col){
                digitalWrite(colPins[i], clean ? HIGH : LOW);
            }
            else{
                digitalWrite(colPins[i], HIGH);
            }
        }
        else{
            digitalWrite(colPins[i], LOW);
        }
    }
}

void LedCube::lightOne(byte lv, byte col, boolean clean)
{
    if (clean==false){
        excluded = 255;
    };
    if(lv<levels && col<cols){
        toggleCols(col, clean);
        toggleRows(lv);
    }
}

void LedCube::lightPerimetr(byte row){
    if(row <= levels){
        excluded = 0;
        lightOne(row, 1, true);
    }
}

void LedCube::pulsePerimetr(byte row, byte count, int pause){
    for (byte i = 0; i < count; i++)
    {   
        clear();
        delay(pause/2);
        lightPerimetr(row);
        delay(pause/2);
    }
}

void LedCube::lightRow(byte row, int ms)
{
    if(row <= levels){
        excluded = 255;
        for (byte i = 0; i < cols; i++){
            lightOne(row, i, true);
        }
        delay(ms);
    }
}


void LedCube::lightCol(byte col, int pause, boolean clean)
{
    if(col<=cols){
        if (clean==true){
            clear();
        }
        for (byte k = 0; k < levels; k++){
                digitalWrite(levelPins[k], LOW);
                digitalWrite(colPins[col], HIGH);
        }
    }
    delay(pause);
}



byte LedCube::seq()
{
    byte seq[cols * levels];
    
}


