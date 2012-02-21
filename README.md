# Cube3x3x3 

Cube3x3x3 is a simple arduino library for driving 
a 3x3x3 led cube.

**Goals**: Make this library drive not only 3x3x3
led cube, but any NxNxN cube (of course there must be 
hardware for interaction with cubes bigger than 3x3x3)

## Installation and usage

To use library do:

1.  git@github.com:jetfix/arduino-3x3x3-LedCube.git

2.  Than place Cube3x3x3 in /usr/share/arduino/libraries/
or place where you store arduino libraries

3.  Run Arduino IDE and load Cube3x3x3 example

Sample usage:

```cpp
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
        cube.lightPerimetr(j);
        delay(30);
    }
}
```

## Documentation

There is several API methods available. You can you use it 
to compose more complex sequences for lighting leds
    
```cpp
    // returns arduino pin number corresponding to column
    int getColPin(int r); 

    // returns arduino pin number corresponding to row
    int getLevelPin(int lv);
    
    // lights one LED diode
    void lightOne(byte level, byte col, boolean clean );
    
    // lights leds by perimter on the given raw
    void lightPerimetr(byte row);
    
    // makes _blink_ leds in perimetr of the given raw,
    // with _pause_ between blinking, _count_ times
    void pulsePerimetr(byte row, byte count, int pause);
    
    void lightOneOff(byte col);
    
    // lights on row of leds
    void lightRow(byte row, int ms);
    
    // lights one column of leds
    void lightCol(byte col, int pause, boolean clean);
```
    
## Meta

- Version: 0.1.0
- URL: https://github.com/jetfix/arduino-3x3x3-LedCube
- author : https://github.com/jetfix/

## TODO

- Make API more simple, for know some of the API calls has _delay_ argument and
  some note (you need manually call delay() function) 
  
- Add sequence API method. For creating sequences of API calls. This can help
  for creating more fun effects =)
  
- Make library drive N x N x N led cube.

