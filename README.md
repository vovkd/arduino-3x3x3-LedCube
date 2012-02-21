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

## Documentation

There is several API methods available. You can you use it 
to compose more complex sequences for lighting leds
    
```cpp
    int getColPin(int r);
    int getLevelPin(int lv);
    void lightOne(byte level, byte col, boolean clean );
    void lightPerimetr(byte row);
    void pulsePerimetr(byte row, byte count, int pause);
    void lightOneOff(byte col);
    void lightRow(byte row, int ms);
    void lightCol(byte col, int pause, boolean clean);
```
    
## Meta

- Version: 0.1.0
- URL: https://github.com/jetfix/arduino-3x3x3-LedCube
- author : https://github.com/jetfix/

