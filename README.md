# Project 1

 - Name:        Peter Massarello
 - Date:        October 20th 2021
 - Class:       CMPSCI 4280
 - Professor:   Mark Hauschild
 - Assignment:  P1 (written in C++)

# Project Option:
    - I am going with option 3 the FSA table + driver.
    - Both can be found under scanner.cpp, FSA is found on line 5. I went with a slightly different method and making all FINAL states actually be what their
    token would be. This was done for my own sake with readability when trying to construct the code to use the table.
    - The main driver function is shown on line 276 but the core of it is under another function called buildTokenFromLine on line 207. I moved it because of
    how I ended up tackling this problem by creating a vector of strings that contains each line of the file or the keyboard input. So I iterate through the 
    vector of lines and then build the tokens from those lines. The function on line 207 is what looks most similar to the driver function given from the notes.

# How to build:
    - run make file to compile all files (command: make)

# How to run:

    - ./scanner [filename] 
        - Contains optional argument "filename". If run without optional arg, takes input from stdin, otherwise reads from "filename"
    
    - ./scanner
        - Acts the name as the no argument implementation except the stdin input is taken from the files contents instead of the keyboard

# How to cleanup:
    - run make clean to remove all program created files (command: make clean)

# Notes:
    - Instructions given said that all input would be clean and deal with only alphanumeric characters. So there is no validation on reading other symbols.
    - A test file for the optional argument is supplied but if the grader wants to they can use their own.
    - The only way I could get single and multiline comments to work was to remove them as I read from the file or the keyboard.
