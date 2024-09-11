This program is a 2D recreation of Mario created by Drew Floyd
collaborator Nataniel Farzan. Nataniel helped with debugging.

CLASSES
The Level Class constructs a 2D char array level based on inputs from spec.txt
The Simulator class turns these levels into a world array of levels and has mario play through them
The Mario class controls marios actions and holds all his data
The main executes Simulator after taking in spec.txt as a command line arguement



JOURNAL
Problems I encountered while coding. Segmentation fault.

Currently dealing with random segmentation faults in getCell calling row 4 col 3 or other working values

When I run the program in the terminal I get zsh: bus error
When I run the progrma in Docker, I get a segmentation fault or error with Mario interacting with the boss
Running on the server I found a segmentation fault in getCell but unsure how to solve it

September 21st: Ive narrowed down the problem to the calling of the functions getCell and toString in the Simulator loop
I dont beleive its an out of bounds error because I print out what does into the function before it goes in

September 22nd: The problem was in the currLevel variable and created a segmentation fault right before mario won the game, the currLevel increased and was accessed by the getCell command before the game ended