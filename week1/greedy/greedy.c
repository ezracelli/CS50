#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void) {
    
    // define coins
    int coin[4] = {25, 10, 5, 1};
    
    // set current coin
    int n = 0;
    int current_coin = coin[n];
    
    // define and initalize counter
    int counter = 0;
    
    // get a value from the user
    float input = 0;
    int value = 0;
    do {
        printf("Change owed: ");
        input = GetFloat();
        value = (int) round(input * 100);
    } while (value < 0);
    
    // do things
    while (value > 0) {
        
        // subtract
        while (value / current_coin >= 1) {
            value = value - current_coin;
            counter++;
        }
        
        // set new coin
        n++;
        current_coin = coin[n];
        
    }
    
    printf("%d\n", counter);
    return 0;
}
