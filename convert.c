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

// Function #2
void oct_to_hex(const char *oct, char *out) {
    const char* hexLookup[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"}; // Lookup table to convert octal digit directly to hexedecimal
    int digit;      // Will store octal digit converted to base 10. Digit will be used to index octLookup
    out[0] = '\0';  // Set the first character of the output to the null operator. Allows strcat to acknowledge out as a string

    for (int i = 0; oct[i] != '\0'; i++) {
        // Convert next 2 digits to base ten and add them together
        digit  = oct[i++] - '0';
        digit += oct[i]   - '0';

        strcat(out, hexLookup[digit]);
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