// Made by Mitch Walker

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void oct_to_bin(const char *oct, char *out);
void oct_to_hex(const char *oct, char *out);
void hex_to_bin(const char *hex, char *out);
void to_sign_magnitude(int32_t num, char *out);
void to_ones_complement(int32_t num, char *out);
void to_twos_complement(int32_t num, char *out);

int main(void) {
    FILE *file = fopen("a2_test.txt", "r");    // File object containing tests
    if (file == NULL) { // Verifies the file can be opened
        perror("Error opening file\n");
        return 1;
    }

    // Variables needed to run tests
    char line[256];         // Buffer/string to read each line from the test file
    char *command;          // Pointer pointing to the command from the buffer
    char *input1_str;       // Pointer pointing to the first input from the buffer
    int input1_int;         // Int to store converted input 1
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

        // Read input and expected output
        input1_str = strtok(NULL, " \t\r\n");
        expectedOutput = strtok(NULL, " \t\r\n");

        // Run appropriate function
        if (strcmp(command, "oct_to_bin") == 0) {  // Fires if the command is "div"Convert"
            oct_to_bin(input1_str, output);
        } else if (strcmp(command, "oct_to_hex") == 0) {
            oct_to_hex(input1_str, output);
        } else if (strcmp(command, "hex_to_bin") == 0) {
            hex_to_bin(input1_str, output);
        } else if (strcmp(command, "to_sign_magnitude") == 0) {
            // Converts inputs to integers
            input1_int = atoi(input1_str);
            to_sign_magnitude(input1_int, output);
        } else if (strcmp(command, "to_ones_complement") == 0) {
            // Converts inputs to integers
            input1_int = atoi(input1_str);
            to_ones_complement(input1_int, output);
        } else if (strcmp(command, "to_twos_complement") == 0) {
            // Converts inputs to integers
            input1_int = atoi(input1_str);
            to_twos_complement(input1_int, output);
        } else {
            printf("Unknown command: %s\n", command);
            output[0] = '0'; output[1] = '\0'; // Set the output such that result will be FAIL
        }

        // Check results
        if (strcmp(expectedOutput, output) == 0) {
            result = "PASS\0";
            successCount++;
        } else {
            result = "FAIL\0";
        }

        // Outputs the test results
        printf("Test %d: %s(%s, output) -> Expected: \"%s\", Got: \"%s\" [%s]\n", testCount, command, input1_str, expectedOutput, output, result);
    }

    fclose(file);   // Closes the file object
    printf("Summary: %d/%d tests passed", successCount, testCount); // Prints the overall testing results

    return 0;
}