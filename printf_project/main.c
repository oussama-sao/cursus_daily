#include "libft.h"

#include <stdio.h>

int main() {
    char memory[30000] = {0};  // An array to represent memory cells, all initialized to zero
    char *ptr = memory;        // Pointer to the current memory cell

    // Brainfuck: ++++++++++
    // Increment the first memory cell to 10
    *ptr += 10;               

    // Brainfuck: [>+++++++>++++++++++>+++>+<<<<-]
    // Start of loop: Repeat until the first cell is zero
    while (*ptr) {            
        // Brainfuck: >
        // Move to the next memory cell
        ptr++;                

        // Brainfuck: +++++++
        // Increment this cell by 7
        *ptr += 7;            

        // Brainfuck: >
        // Move to the next cell
        ptr++;                

        // Brainfuck: ++++++++++
        // Increment this cell by 10
        *ptr += 10;           

        // Brainfuck: >
        // Move to the next cell
        ptr++;                

        // Brainfuck: +++
        // Increment this cell by 3
        *ptr += 3;            

        // Brainfuck: >
        // Move to the next cell
        ptr++;                

        // Brainfuck: +
        // Increment this cell by 1
        *ptr += 1;            

        // Brainfuck: <<<<
        // Move back to the first cell
        ptr -= 4;             

        // Brainfuck: -
        // Decrement the first cell by 1
        (*ptr)--;             
    }                         

    // Brainfuck: >
    // Move to the second cell
    ptr++;                    

    // Brainfuck: ++
    // Increment this cell by 2
    *ptr += 2;                

    // Brainfuck: .
    // Output the character 'H'
    putchar(*ptr);            

    // Brainfuck: >
    // Move to the third cell
    ptr++;                    

    // Brainfuck: +
    // Increment this cell by 1
    *ptr += 1;                

    // Brainfuck: .
    // Output the character 'e'
    putchar(*ptr);            

    // Brainfuck: +++++++
    // Increment this cell by 7
    *ptr += 7;                

    // Brainfuck: .
    // Output the character 'l'
    putchar(*ptr);            

    // Brainfuck: .
    // Output the character 'l' again
    putchar(*ptr);            

    // Brainfuck: +++
    // Increment this cell by 3
    *ptr += 3;                

    // Brainfuck: .
    // Output the character 'o'
    putchar(*ptr);            

    // Brainfuck: >
    // Move to the fourth cell
    ptr++;                    

    // Brainfuck: ++
    // Increment this cell by 2
    *ptr += 2;                

    // Brainfuck: .
    // Output the space character
    putchar(*ptr);            

    // Brainfuck: <<
    // Move back to the second cell
    ptr -= 2;                 

    // Brainfuck: +++++++++++++++
    // Increment this cell by 15
    *ptr += 15;               

    // Brainfuck: .
    // Output the character 'W'
    putchar(*ptr);            

    // Brainfuck: >
    // Move to the third cell
    ptr++;                    

    // Brainfuck: +++
    // Increment this cell by 3
    *ptr += 3;                

    // Brainfuck: .
    // Output the character 'o'
    putchar(*ptr);            

    // Brainfuck: ------
    // Decrement this cell by 6
    *ptr -= 6;                

    // Brainfuck: .
    // Output the character 'r'
    putchar(*ptr);            

    // Brainfuck: --------
    // Decrement this cell by 8
    *ptr -= 8;                

    // Brainfuck: .
    // Output the character 'l'
    putchar(*ptr);            

    // Brainfuck: >
    // Move to the fourth cell
    ptr++;                    

    // Brainfuck: +
    // Increment this cell by 1
    *ptr += 1;                

    // Brainfuck: .
    // Output the character 'd'
    putchar(*ptr);            

    // Brainfuck: >
    // Move to the fifth cell
    ptr++;                    

    // Brainfuck: .
    // Output the character '!'
    putchar(*ptr);            

    return 0;
}
