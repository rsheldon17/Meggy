/*
  MeggyJr_Blink.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Point
{
  int x;
  int y;
};

Point p1 = {2,4};
Point p2 = {3,4};
Point p3 = {3,4};
Point p4 = {3,4};
Point snakeArray[64] = {p1, p2, p3, p4};

int marker = 4;                                                  // Index of the first empty segment of the array
int direction = 0;
int speed = 250;
int xapple = random(8);
int yapple = random(8);
int binary = 0;
boolean gotApple = true;

void setup()                                                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();                                         // Required code, line 2 of 2.
  SetAuxLEDs(0);
}

void loop()                                                     // Run over and over again
{ 
  updateSnake();                                                // Update snake
  DrawPx(xapple,yapple,Red);
  if (ReadPx(p1.x,p1.y) == Red);
  {
    xapple = random(8);
    yapple = random(8);
    Tone_Start(14152,50);
    binary = binary * 2 + 1;
  }
  drawSnake();                                                 // Draw snake
  DisplaySlate();                                              // Write the drawing to the screen.
  delay(speed);                                                // Waits for 0.3 seconds
  ClearSlate();                                                // Clear Slate
}

void updateSnake()
{
  // Move Body
  for (int marker - 1; i > 0; i--);
  {
    snakeArray[i] = snakeArray[i - 1];                         // Copy the value at i - 1 into i
  } 
  // Move Head
  if (direction == 0)
  {
    snakeArray[0].y = snakeArray[0].y + 1;                    // Updates y
    if (snakeArray[0].y > 7)                                  // Corrects for out-of-bounds.
    {
      snakeArray[0].y = 0;
    }
  }
  
  if (direction == 90)
  {
    snakeArray[0].x = snakeArray[0].x + 1;                    // Updates x
    if (snakeArray[0].x > 7)                                  // Corrects for out-of-bounds.
    {
      snakeArray[0].x = 0;
    }
  }
  
  if (direction == 270)
  {
    snakeArray[0].x = snakeArray[0].x - 1;                      // Updates x
    if (snakeArray[0].x < -1)                                  // Corrects for out-of-bounds.
    {
      snakeArray[0].x = 7;
    }
  }
  
  if (direction == 180)
  {
    // Updates y
    snakeArray[0].y = snakeArray[0].y - 1;
  
    // Corrects for out-of-bounds.
    if (snakeArray[0].y < -1)
    {
      snakeArray[0].y = 7;
    }
  }
  {
    CheckButtonsPress();
    ClearSlate();
   
    if(Button_Up)
      direction = 0;
      
    if(Button_Down)
      direction = 180;
      
    if(Button_Left)
      direction = 270;
      
    if(Button_Right)
      direction = 90;

    if(Button_B)
      speed = speed - 50;

    if(Button_A)
      speed = speed - 50;
      
    DisplaySlate();
  }
}
void drawSnake()
{
  // Iterate through the entire array and draw each segment segment
  for (int i = 0; i < marker; i++)
  DrawPx(p1.x,p1.y,Violet);           // Draw the snake
}

void drawApple()
{
  DrawPx(xapple,yapple,Green);
}
void newApple()
{
  while (!isValid(xapple,yapple));
  gotApple = false;
  drawApple();
  {
  
  do 
  {
      xapple = (int)random(7);
      yapple = (int)random(7);
    }
}
