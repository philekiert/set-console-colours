#include <windows.h>

/* Standard Colour scheme
-------------------------
0 Black            Background
1 Dark Blue
2 Dark Green
3 Dark Cyan
4 Dark Red
5 Dark Magenta
6 Dark Yellow
7 Bright Grey      Foreground (text)
8 Dark Grey
9 Bright Blue
10 Bright Green
11 Bright Cyan
12 Bright Red
13 Bright Magenta
14 Bright Yellow
15 White               */


bool initialisedColChange;   // Set to true on first Initialise().
COLORREF oldColourTable[16];

HANDLE outputBuff;
CONSOLE_SCREEN_BUFFER_INFOEX bufferInfo;

void Initialise()
{
  // -11 here gets the output buffer. -10 would be input buffer, -12 would be error buffer.
  outputBuff = GetStdHandle(-11);
  bufferInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
  GetConsoleScreenBufferInfoEx(outputBuff, &bufferInfo);

  // Store the current colour scheme.
  for (size_t n = 0; n < 16; ++n)
    oldColourTable[n] = bufferInfo.ColorTable[n];

  // Set true so this only runs the first time the function is called.
  initialisedColChange = true;
}

void SetConsoleColour(size_t index, COLORREF hexColour)
{
  if (!initialisedColChange)
    Initialise();

  bufferInfo.ColorTable[index] = hexColour;
}

void SetConsoleColour(size_t index)
{
  if (!initialisedColChange)
    Initialise();

  bufferInfo.ColorTable[index] = oldColourTable[index];
}

void ApplyConsoleColours()
{
  SetConsoleScreenBufferInfoEx(outputBuff, &bufferInfo);
}

void RevertConsoleColours()
{
  if (initialisedColChange)
  {
    for (size_t n = 0; n < 16; ++n)
      bufferInfo.ColorTable[n] = oldColourTable[n];

    SetConsoleScreenBufferInfoEx(outputBuff, &bufferInfo);
  }
}


// Other Useful Tools
// ------------------

void SetConsoleSize(short x, short y)
{
  if (!initialisedColChange)
    Initialise();

  bufferInfo.dwSize.X = x;
  bufferInfo.dwSize.Y = y;

  SetConsoleScreenBufferInfoEx(outputBuff, &bufferInfo);
}
