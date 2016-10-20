//Moving_Dot by Rose Sheldon

#include <MeggyJrSimple.h> 
int x = 7;
int y = 7;
int yapple = random(8);
int xapple = random(8);
//boolean gotApple = false;

void setup() 
{
  MeggyJrSimpleSetup();
  

}

void loop() 
{
  DrawPx(0,7, Red);
  DrawPx(0,6, Red);
  DrawPx(0,5, Red);
  DrawPx(0,4, Red);

  DrawPx(1,2, Red);
  DrawPx(1,7, Red);
  DrawPx(2,7, Red);
  DrawPx(2,6, Red);

  DrawPx(2,4, Red);
  DrawPx(2,3, Red);
  DrawPx(2,2, Red);
  DrawPx(2,1, Red);
  
  DrawPx(3,6, Red);
  DrawPx(3,1, DimRed);
  DrawPx(3,4, DimRed);

  DrawPx(4,6, DimRed);
  DrawPx(4,7, DimRed);
  DrawPx(4,4, DimRed);
  DrawPx(4,3, DimRed);
  DrawPx(4,1, DimRed);

  DrawPx(5,1, DimRed);

  DrawPx(6,1, DimRed);
  DrawPx(6,7, DimRed);
  DrawPx(6,6, DimRed);
  DrawPx(6,5, DimRed);
  DrawPx(6,4, DimRed);
  DrawPx(6,3, DimRed);

  DrawPx(7,1, DimRed);
  DrawPx(7,0, Red);

  DrawPx(x,y,White);             // Draw a dot at x=3 
  DrawPx(xapple, yapple, Green);
  DisplaySlate();                 // Write the drawing to the screen
  //Check to see if a button was pressed.
  CheckButtonsPress(); 
  //If the right arrow was pressed, add one to x.
  if (Button_Right && ReadPx(x + 1, y) == 0)
  {
    if (x < 7)
   { 
    x = x + 1;
   }
  }
  ClearSlate();
  //If the left arrow was pressed, take one away from x.
   if (Button_Left)
  {
    if (x > 0)
   {
    x = x - 1;
   }
  }
  ClearSlate();
  //If the up arrow was pressed, add one to y.
   if (Button_Up)
  {
    if (y < 7)
   {
    y = y + 1;
   }
  }
  ClearSlate();
  //If the down arrow was pressed, take one away from y.
    if (Button_Down)
 {
    if (y > 0)
   {
    y = y - 1;
   }

   if (ReadPx(x,y) == 1)
   {
    Tone_Start(18182,50);
    xapple = random(8);
    yapple - random(8);
   }
   if (y > 7)
    y = 7;
   if (y < 0)
    y = 0;
   if (x > 7)
    x = 7;
   if (x < 0)
    x = 0;

  ClearSlate();
 }
}
