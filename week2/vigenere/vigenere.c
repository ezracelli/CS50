#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char vigenere(char p, char k);

int main(int argc, char *argv[]) {
    
    // error checking
    if (argc != 2) {
        printf("Please specify only one command line argument.\n");
        return 1;
    }
    
    // collect user-inputted values
    char *k = argv[1];
    char *plaintext = GetString();
    
    // get lengths of strings
    int klen = strlen(k);
    int plen = strlen(plaintext);
    
    // make k useful + more error checking
    for (int i = 0; i < klen; i++) {
        if (isupper(k[i])) {
            k[i] = k[i] - 'A';
        } else if (islower(k[i])) {
            k[i] = k[i] - 'a';
        } else if (isdigit(k[i])) {
            k[i] = k[i] - '0';
        } else {
            printf("Please specify only alphanumeric characters.\n");
            return 1;
        }
    }
    
    // create buffer
    char cipherchar;
    
    // iterate over each character in plaintext
    for (int i = 0, j = 0; i < plen; i++) {
        
        // perform caesar into buffer
        if (isupper(plaintext[i])) {
            cipherchar = vigenere(plaintext[i] - 'A', k[j]) + 'A';
            j++;
        } else if (islower(plaintext[i])) {
            cipherchar = vigenere(plaintext[i] - 'a', k[j]) + 'a';
            j++;
        } else {
            cipherchar = plaintext[i];
        }
        
        // print buffer
        printf("%c", cipherchar);
        
        // make j wrap around
        j = j % klen;
    }
    
    printf("\n");
    return 0;
}

/* * * * * * * *
 * takes a char p and int k
 * returns a char c that has been rotated k letters from p
 * vigenere assumes p and k goes from 0 to 25
 * * * * * * * */
char vigenere(char p, char k) {
    
    // string in which to store ciphertext
    char c;
    
    // perform caesar cipher on p
    c = (p + k) % 26;
    
    // return ciphertext
    return c;
}
