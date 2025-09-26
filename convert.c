// Created by Mitch Walker on 9/25/2025.

#ifndef CONVERT_C
#define CONVERT_C

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

// Function #1
void oct_to_bin(const char *oct, char *out) {
    // Handle edge case
    if (strcmp(oct, "0") == 0) {
        out[0] = '0';
        out[1] = '\0';
        return;
    }

    const char* octLookup[] = {"000", "001", "010", "011", "100", "101", "110", "111"}; // Lookup table to convert octal digit directly to binary
    int digit;      // Will store octal digit converted to base 10. Digit will be used to index octLookup
    out[0] = '\0';  // Set the first character of the output to the null operator. Allows strcat to acknowledge out as a string

    // Loop through every character in oct
    for (int i = 0; oct[i] != '\0'; i++) {
        digit = oct[i] - '0';           // Convert the current digit to an int
        strcat(out, octLookup[digit]);  // Use the int to index octLookup and append the string to the back of out
    }
}

// ================ Start of Helper Functions for Function 2 ================

// Lookup table for converting a binary nibble to hexadecimal
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

// ================ End of Helper Functions for Function 2 ================

// Function #2
void oct_to_hex(const char *oct, char *out) {
    char bin[256];
    oct_to_bin(oct, bin);       // Convert oct to binary

    int len = (int)strlen(bin); // Find the length of bin (casting to an int to make CLion stop yelling at me)
    int buff = len % 4;         // The number of '0' to prepend to bin to make the length of min a multiple of 4

    // Prepend the necessary number of '0's to bin
    for (int i = 0; i < (4-buff); i++) {
        prepend_char(bin, '0');
    }

    len = (int)strlen(bin); // Find the new length of bin

    out[0] = '\0';  // Terminate the start of the output string to allow for proper appending
    char nibble[5]; // String to store nibble
    int idx;        // Starting index of the current char

    // Loop through each nibble in bin
    for (int i = 0; i < (len/4); i++) {
        idx = i*4;
        nibble[0] = bin[idx+0];
        nibble[1] = bin[idx+1];
        nibble[2] = bin[idx+2];
        nibble[3] = bin[idx+3];
        nibble[4] = '\0';

        // Convert nibble to hexadecimal digit and append it to the output
        char c = bin4_lookup(nibble);
        append_char(out, c);
    }
}

// Function #3
void hex_to_bin(const char *hex, char *out) {
    // Handle edge case
    if (strcmp(hex, "0") == 0) {
        out[0] = '0';
        out[1] = '\0';
        return;
    }

    const char* hexLookup[] = { // Lookup table to convert hex digit directly to binary
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
    };
    int digit;      // Int to store hex digit converted to base 10. Digit will be used to index hexLookup
    out[0] = '\0';  // Set the first character of the output to the null operator. Allows strcat to acknowledge out as a string

    // Loop through every character in hex
    for (int i = 0; hex[i] != '\0'; i++) {
        // Convert the current digit to an int
        if ((hex[i] - '0') < 10) {
            digit   = hex[i] - '0';
        } else {
            digit   = toupper(hex[i]) - 'A' + 10; // toupper() forces the current character to be upper case. Allows the input to be case independent
        }

        strcat(out, hexLookup[digit]);  // Use digit to index hexLookup and append the string to the back of out
    }
}

// Function #4.5 Helper function for function 4
void to_32bit_binary(const uint32_t num, char *out) {
    for (int i = 31; i >= 0; i--) { // Convert to 32 bit binary
        out[31-i] = ((num >> i) & 1) ? '1' : '0';
    }

    out[32] = '\0'; // Null terminate the string
}

// Function #4
void to_sign_magnitude(const int32_t num, char *out) {
    if (num >= 0) { // If num is positive, convert to binary normally
        to_32bit_binary(num, out);
    } else { // If num is negative, make positive then convert to binary normally
        to_32bit_binary(abs(num), out);
        out[0] = '1';
    }
}

// Function #5
void to_ones_complement(const int32_t num, char *out) {
    if (num >= 0) { // If num is positive, convert to binary normally
        for (int i = 31; i >= 0; i--) {
            out[31-i] = ((num >> i) & 1) ? '1' : '0';
        }
    } else { // If num is negative, make positive then convert to inverted binary
        int32_t absNum = abs(num);
        for (int i = 31; i >= 0; i--) {
            out[31-i] = ((absNum >> i) & 1) ? '0' : '1';
        }
    }

    out[32] = '\0'; // Null terminate the string
}

// Function #6.5 Adds 1 to a 32bit binary number represented as a string
void add1_32bit_binary (char *num) {
        if (num[31] == '0') { // If the LSB is 0, make it a 1
        num[31] = '1';
    } else { // Otherwise, loop backwards through the string making every character 0 until a 0 is reached
        int idx = 31;
        while (num[idx] != '0' & idx >= 0) {
            num[idx--] = '0';
        }
        num[idx] = '1'; // Make the 0 a 1 for the carry
    }
}

// Function #6
void to_twos_complement(const int32_t num, char *out) {
    if (num >= 0) { // If num is positive, convert to binary normally
        for (int i = 31; i >= 0; i--) {
            out[31-i] = ((num >> i) & 1) ? '1' : '0';
        }
        out[32] = '\0'; // Null terminate the string
    } else { // If num is negative, make positive, convert to inverted binary, then add 1 to make 2's complemment
        int32_t absNum = abs(num);
        for (int i = 31; i >= 0; i--) {
            out[31-i] = ((absNum >> i) & 1) ? '0' : '1';
        }
        out[32] = '\0'; // Null terminate the string
        add1_32bit_binary(out);
    }
}

#endif