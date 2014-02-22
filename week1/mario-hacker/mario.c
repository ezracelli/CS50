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
    for (int i = 1; i <= height; i++) {
        
        // initialize crunches to 0
        int crunch_left = 0;
        int crunch_right = 0;
        
        //initialize spaces to height
        int space = height;
        
        // print height - i spaces
        while (space > i) {
            printf(" ");
            space--;
        }
        
        // print left pyramid
        while (crunch_left < i) {
            printf("#");
            crunch_left++;
        }
        
        printf("  ");
        
        // print right pyramid
        while (crunch_right < i) {
            printf("#");
            crunch_right++;
        }
        
        printf("\n");
        
    }
    
    return 0;
}
