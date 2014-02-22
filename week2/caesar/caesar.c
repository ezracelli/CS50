#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char caesar(char p, int k);

int main(int argc, char *argv[]) {
    
    // error checking
    if (argc != 2) {
        printf("Please specify only one command line argument.\n");
        return 1;
    } else if (atoi(argv[1]) < 0) {
        printf("Please specify only a non-negative integer.\n");
        return 1;
    }
    
    // collect user-inputted values
    int k = atoi(argv[1]);
    char *plaintext = GetString();
    int len = strlen(plaintext);
    
    // create buffer
    char cipherchar;
    
    // iterate over each character in plaintext
    for (int i = 0; i < len; i++) {
        
        // perform caesar into buffer
        if (isupper(plaintext[i])) {
            cipherchar = caesar(plaintext[i] - 'A', k) + 'A';
        } else if (islower(plaintext[i])) {
            cipherchar = caesar(plaintext[i] - 'a', k) + 'a';
        } else {
            cipherchar = plaintext[i];
        }
        
        // print buffer
        printf("%c", cipherchar);
    }
    
    printf("\n");
    return 0;
}

/* * * * * * * *
 * takes a char p and int k and returns a char c that has been rotated 26 letters
 * caesar assumes that the alphabet goes from 0 to 25
 * * * * * * * */
char caesar(char p, int k) {
    
    // string in which to store ciphertext
    char c;
    
    // perform caesar cipher on p
    c = (p + k) % 26;
    
    // return ciphertext
    return c;
}
