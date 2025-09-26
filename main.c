// Made by Mitch Walker

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void div_convert(uint32_t n, int base, char *out);
void sub_convert(uint32_t n, int base, char *out);
void print_tables (uint32_t n);

// made a test change
int main(void) {
    void oct_to_bin(const char *oct, char *out);
    void oct_to_hex(const char *oct, char *out);

    char octIn[] = "156\0";

    char binOut[256];
    char hexOut[256];

    oct_to_bin(octIn, binOut);
    oct_to_hex(octIn, hexOut);

    printf("Entered %s for oct to bin conversion and got %s\n", octIn, binOut);
    printf("Entered %s for oct to hex conversion and got %s", octIn, hexOut);

    /*
    FILE *file = fopen("a1_test_file.txt", "r");    // File object containing tests
    if (file == NULL) { // Verifies the file can be opened
        perror("Error opening file\n");
        return 1;
    }

    // Variables needed to run tests
    char line[256];         // Buffer/string to read each line from the test file
    char *command;          // Pointer pointing to the command from the buffer
    char *input1_str;       // Pointer pointing to the first input from the buffer
    char *input2_str;       // Pointer pointing to the second input from the buffer
    int input1_int;         // Int to store converted input 1
    int input2_int;         // Int to store converted input 2
    char *expectedOutput;   // Pointer pointing to the expected output from the buffer
    char output[256];       // String to contain the actual output from the tests
    int successCount = 0;   // Counter to track the number of successful tests
    int testCount = 0;      // Counter to track the number of tests
    char *result;           // Pointer to point to the PASS/FAIL string

    // Loops through each line in the file. Each iteration reads the next line
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\n') { // Ignores the line and moves to the next iteration if the line starts with a new line or a '#'
            continue;
        }

        testCount++;    // Increment the test counter
        command = strtok(line, " \t\r\n");  // Read the command from the buffer
        if (strcmp(command, "div_convert") == 0) {  // Fires if the command is "div"Convert"
            // Read inputs and expected output
            input1_str = strtok(NULL, " \t\r\n");
            input2_str = strtok(NULL, " \t\r\n");
            expectedOutput = strtok(NULL, " \t\r\n");

            // Converts inputs to integers
            input1_int = atoi(input1_str);
            input2_int = atoi(input2_str);

            // Run appropriate function
            div_convert (input1_int, input2_int, output);

            // Check results
            if (strcmp(expectedOutput, output) == 0) {
                result = "PASS\0";
                successCount++;
            } else {
                result = "FAIL\0";
            }

            // Outputs the test results
            printf("Test %d: %s(%d, %d) -> Expected: \"%s\", Got: \"%s\" [%s]\n", testCount, command, input1_int, input2_int, expectedOutput, output, result);

        } else if (strcmp(command, "sub_convert") == 0) {
            // Read inputs and expected output
            input1_str = strtok(NULL, " \t\r\n");
            input2_str = strtok(NULL, " \t\r\n");
            expectedOutput = strtok(NULL, " \t\r\n");

            // Converts inputs to integers
            input1_int = atoi(input1_str);
            input2_int = atoi(input2_str);

            // Run appropriate function
            sub_convert (input1_int, input2_int, output);

            // Check results
            if (strcmp(expectedOutput, output) == 0) {
                result = "PASS\0";
                successCount++;
            } else {
                result = "FAIL\0";
            }

            // Outputs the test results
            printf("Test %d: %s(%d, %d) -> Expected: \"%s\", Got: \"%s\" [%s]\n", testCount, command, input1_int, input2_int, expectedOutput, output, result);

        } else if (strcmp(command, "print_tables") == 0) {
            // printf("Printing tables\n");
            input1_str = strtok(NULL, " \t\r\n");
            input1_int = atoi(input1_str);

            // Runs the appropriate test
            print_tables (input1_int);
            // successCount++; // I thought about assuming the formatting was correct but didn't think that would be fair/honest
            result = "UNKNOWN\0";   // Sets the result to UNKNOWN becuase I wasn't sure how to verify the formatting of a print statement

            // Outputs the test results
            printf("Test %d: %s(%d) -> [FORMATTED OUTPUT CHECK] [%s]\n", testCount, command, input1_int, result);
        }
    }

    fclose(file);   // Closes the file object
    printf("Summary: %d/%d tests passed", successCount, testCount); // Prints the overall testing results
    */


    return 0;
}