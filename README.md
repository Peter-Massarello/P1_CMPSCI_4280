# Project 1

 - Name:        Peter Massarello
 - Date:        October 20th 2021
 - Class:       CMPSCI 4280
 - Professor:   Mark Hauschild
 - Assignment:  P1 (written in C++)

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