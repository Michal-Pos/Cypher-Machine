#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a single word (array of chars)
void reverse_word(char str[], int start, int end) {
    if (end - start > 30) {
        printf("The input text contains a word with more than 30 characters, terminating the process \n");
        exit(2);
    }
    char temp;
    // Swapping characters from both ends until they meet in the middle, resulting in reversed order of letters
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to reverse the whole text
void reverse_text(char str[]) {
    int start = 0, end = 0;
    // Reversing whole word if a character from the (2) group is detected
    while (str[end]) {
        for (end = start; str[end] && str[end] != ' ' && str[end] != ',' && str[end] != '.' && str[end] != '?' && str[end] != '\n'; end++);
        reverse_word(str, start, end - 1);
        start = end + 1;
    }
}

// Function to encode a line of text
void encode_line(char str[], int k) {
    int j, len = strlen(str);
    // Ciphering and deciphering capital letters
    for (int i = j = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += k;
            if (str[i] > 'Z') {
                str[i] -= 26;
            }
            str[j++] = str[i];
        } else if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '\n') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    // Reversing all words in the text
    reverse_text(str);
}

// Function to process the input file line by line
void process(FILE* input_file, FILE* output_file, int k) {
    char str[1000]; // Assuming a maximum line length of 1000 characters
    while (fgets(str, sizeof(str), input_file) != NULL) {
        encode_line(str, k);
        fprintf(output_file, "%s", str);
    }
}

// Function to read the input file
FILE* read_input(char* input_file) {
    FILE* file;
    printf("Enter the input file name, remember to add the appropriate extension: \n");
    fgets(input_file, 300, stdin);
    input_file[strcspn(input_file, "\n")] = 0; // Removing the newline character from the input
    if (strlen(input_file) > 300) {
        printf("The input file name exceeds 300 characters, terminating the process");
        exit(5);
    }
    file = fopen(input_file, "r");
    if (file == NULL) {
        printf("Error. Can't open the file for reading: %s. Terminating the process.\n", input_file);
        exit(3);
    }
    return file;
}

// Function to read the output file
FILE* read_output(char* output_file) {
    FILE* file;
    printf("Enter the output file name: \n");
    fgets(output_file, 300, stdin);
    output_file[strcspn(output_file, "\n")] = 0; // Removing the newline character from the input
    if (strlen(output_file) > 300) {
        printf("The output file name exceeds 300 characters, terminating the process");
        exit(6);
    }
    file = fopen(output_file, "w");
    if (file == NULL) {
        printf("Error. Can't open the file for writing: %s. Terminating the process.\n", output_file);
        exit(4);
    }
    return file;
}

int main(void) {
    char input_file[300], output_file[300];
    int choice, k;
    FILE* input;
    FILE* output;

    printf("This is a program for encrypting and decrypting text.\n");
    input = read_input(input_file);
    output = read_output(output_file);

    printf("Choose decryption or encryption [1/2]: \n");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("No operation selected, terminating the process \n");
        exit(7);
    }
    printf("Enter the key you want to use, it must be greater than or equal to 0 and less than 25 \n");
    scanf("%d", &k);
    if ((k < 0) || (k > 25)) {
        printf("The key is out of the required range, terminating the process \n");
        exit(8);
    }
// decyphering is the came function as cyphering, but the argument is equal to lenght of the alphabet minus value of the key 
    if (choice == 1) {
        process(input, output, 26 - k);
    } else {
        process(input, output, k);
    }

    fclose(input);
    fclose(output);
    return 0;
}
