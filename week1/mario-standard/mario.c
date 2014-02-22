#include <stdio.h>
#include <cs50.h>

int main(void) {
    // declare var height
    int height;
    
    // do this until height is between 0 and 23
    do {
    
        // ask for height
        printf("Height: ");
        
        // store height in var "height"
        height = GetInt();
        
    } while (height < 0 || height > 23);
        
    
    // loop for each row
    for (int i = 1; i < height + 1; i++) {
        
        // initialize bangs to 0
        int crunch = 0;
        
        //initialize spaces to height - 1
        int space = height;
        
        // print height - i spaces
        while (space > i) {
            printf(" ");
            space--;
        }
        
        // print some crunches idk
        while (crunch < i + 1) {
            printf("#");
            crunch++;
        }
        
        printf("\n");
        
    }
    
    return 0;
}
