SetConsoleColours
-----------------
A simple toolkit to customise the colours in a console application. Also simplifies resizing of the console output buffer.

Note: Remove #include preprocessor directives if they're already included elsewhere.


**Instructions:**
 - Call SetConsoleColour(size_t, 0x00RRGGBB), inputting the desired values to modify individual colours.
   - size_t should be between 0 and 15 (inclusive) and designates which of the 16 colours to modify.
 - This will have no effect until ApplyConsoleColours() is called.
 - RevertConsoleColours() will revert the colour scheme to its original state before the program ran.
 - SetConsoleSize(short, short) adjusts the size of the output buffer.
 - The standard windows colour designations are listed at the top for ease of use.
 - Make sure to RevertConsoleColours() at the end of the program, otherwise the console will retain your custom theme!
   - Of course, this does mean the console remains affected if the program is ended prematurely, so bear that in mind.
 
 
 Enjoy, hope someone gets some use out of it!
