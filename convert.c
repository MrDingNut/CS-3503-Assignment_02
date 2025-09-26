// Created by Mitch Walker on 9/25/2025.

#ifndef CONVERT_C
#define CONVERT_C

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Function #1
void oct_to_bin(const char *oct, char *out) {
    const char* octLookup[] = {"000", "001", "010", "011", "100", "101", "110", "111"}; // Lookup table to convert octal digit directly to binary
    int digit;      // Will store octal digit converted to base 10. Digit will be used to index octLookup
    out[0] = '\0';  // Set the first character of the output to the null operator. Allows strcat to acknowledge out as a string

    // Loop through every character in oct
    for (int i = 0; oct[i] != '\0'; i++) {
        digit = oct[i] - '0';           // Convert the current digit to an int
        strcat(out, octLookup[digit]);  // Use the int to index octLookup and append the string to the back of out
    }
}

// ================ Helper Functions for Function 2 ================

// Function #2.5 (Reminds me of coding in VHDL)
char bin4_lookup(const char *bin) {
    if      (strcmp(bin, "0000") == 0) return '0';
    else if (strcmp(bin, "0001") == 0) return '1';
    else if (strcmp(bin, "0010") == 0) return '2';
    else if (strcmp(bin, "0011") == 0) return '3';
    else if (strcmp(bin, "0100") == 0) return '4';
    else if (strcmp(bin, "0101") == 0) return '5';
    else if (strcmp(bin, "0110") == 0) return '6';
    else if (strcmp(bin, "0111") == 0) return '7';
    else if (strcmp(bin, "1000") == 0) return '8';
    else if (strcmp(bin, "1001") == 0) return '9';
    else if (strcmp(bin, "1010") == 0) return 'A';
    else if (strcmp(bin, "1011") == 0) return 'B';
    else if (strcmp(bin, "1100") == 0) return 'C';
    else if (strcmp(bin, "1101") == 0) return 'D';
    else if (strcmp(bin, "1110") == 0) return 'E';
    else if (strcmp(bin, "1111") == 0) return 'F';
    return 'Q'; // Handle invalid case
}

// Function #2.5.5 (Assumes character array has enough extra allocated space to include the new character)
void prepend_char(char* str, char c) {
    int length = strlen(str);

    // Shift every character one to the right
    for (int i = length + 1; i > 0; i--) {
        str[i] = str[i-1];
    }

    str[0] = c; // Insert new character
}

// Function 2.5.5.5
void append_char(char *str, char c) {
    int length = strlen(str);  // Find the length of the string
    str[length] = c;           // Put character at the end
    str[length + 1] = '\0';    // Terminate the string
}

// Function #2
void oct_to_hex(const char *oct, char *out) {
    char bin[256];
    oct_to_bin(oct, bin);       // Convert oct to binary

    int len = (int)strlen(bin); // Find the length of bin (casting to an int to make CLion stop yelling at me)
    int buff = len % 4;         // The number of '0' to prepend to bin to make the length of min a multiple of 4

    // Prepend the necessary number of '0's to bin
    for (int i = 0; i < buff; i++) {
        prepend_char(bin, '0');
    }

    len = (int)strlen(bin); // Find the new length of bin

    out[0] = '\0';
    char nibble[5];
    int idx; // Index of the current char
    for (int i = 0; i < (len/4); i++) {
        idx = i*4;
        nibble[0] = bin[idx+0];
        nibble[1] = bin[idx+1];
        nibble[2] = bin[idx+2];
        nibble[3] = bin[idx+3];
        nibble[4] = '\0';

        char c = bin4_lookup(nibble);
        append_char(out, c);
    }
}

// Function #3
void hex_to_bin(const char *hex, char *out) {}

// Function #4
void to_sign_magnitude(int num, char *out) {}

// Function #5
void to_ones_complement(int num, char *out) {}

// Function #6
void to_twos_complement(int num, char *out) {}

#endif