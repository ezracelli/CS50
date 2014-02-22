#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // error checking
    if (argc != 3 && argc != 2) {
        printf("USAGE: crack-dictionary hash [dictionary]\n");
        return 1;
    }
    
    // set file pointer
    FILE *dict;
    
    // open default dictionary
    if (argc == 2) {
        dict = fopen("words", "r");
        if (dict == NULL) {
            printf("There was an error with fopen().\nYou probably specified a nonexistant dictionary.\n");
            return 1;
        }
    }
    
    // open custom dictionary
    else {
        dict = fopen(argv[2], "r");
        if (dict == NULL) {
            printf("There was an error with fopen().\nYou probably specified a nonexistant dictionary.\n");
            return 1;
        }
    }
    
    // find salt
    char salt[2] = {argv[1][0], argv[1][1]};
    
    // set word buffer
    char word[46];
    
    // set compare buffer
    char cmp[9];
    
    // do for each word in dictionary
    while (fscanf(dict, "%s", word) != EOF) {
        
        // put first eight letters of word into cmp
        for (int i = 0; i < 8; i++) {
            if (word[i] != '\0') {
                cmp[i] = word[i];
            } else {
                cmp[i] = '\0';
                break;
            }
        }
            
        // compare outputput of crypt(cmp, salt) to input
        if (strcmp(crypt(cmp, salt), argv[1]) == 0) {
            printf("pass: %s\n", word);
            break;
        }
    }
    
    // close dictionary
    if (fclose(dict) != 0) {
        printf("There was an error with fclose(). Try again later.\n");
        return 1;
    }
}
