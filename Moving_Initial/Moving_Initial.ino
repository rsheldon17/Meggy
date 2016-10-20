#include <MeggyJrSimple.h>

int x[] = {1,2,3,4,5,6,6,6,5,4,3,2,1,1,1,1,1,1,1,2,3,4,5};
int y[] = {7,7,7,7,7,7,6,5,4,4,4,4,4,5,6,1,0,2,3,3,2,1,0};

void setup() 
{
  MeggyJrSimpleSetup();
}

void DrawR()
{
    for (int i = 0; i < 23; i++)
    {
      DrawPx(x[i],y[i],White);
    } 
}

void loop() 
{
  DrawR();
  DisplaySlate();
  delay(1000);
  CheckButtonsPress();
  if (Button_Left)
  {
    for (int i = 0; i < 23; i++)
    {
        //if  x > 0 then subtract 1; otherwise, make x 7
              if (x[i] > 0)
                x[i] = x[i]-1;
              else x[i] = 7;
    }
  }
}
      
// Check Buttons
// If left button is pressed
// Update all x values
// Wrap the x values that need to be wrapped

