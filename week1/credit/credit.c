#include <stdio.h>
#include <math.h>
#include <cs50.h>

int digit(long long input, int n);
int num_length(long long input);

int main(int argc, char *argv[]) {
    
    // get user's input
    printf("Number: ");
    long long input = GetLongLong();
    
    //initialize values
    int total = 0;
    int to_add = 0;
    
    // find length of string
    int length = num_length(input);
    
    // do for length of string for every other digit
    for (int i = 1; i <= length; i = i + 2) {
        
        // find the ith digit in string
        to_add = (digit(input, i) * 2);
        
        // if digit is ten or more, add sum of digits of digit to total
        if ( to_add / 10 >= 1) {
            for (int j = 0; j < 2; j++) {
                total = total + digit((long long) to_add, j);
            }
        }
        
        // else (digit is less than ten), add digit to total
        else {
            total = total + to_add;
        }
    }
    
    // do for length of string for the opposite digits
    for (int i = 0; i <= length; i = i + 2) {
        
        // add the ith digit in string to total
        total = total + digit(input, i);
    }
    
    // if total is not divisible by 10, not a valid card
    if (total % 10 != 0) {
        printf("INVALID\n");
        return 0;
    }
    
    // get first and second (from left) digits of input
    int first = digit(input, length - 1);
    int second = digit(input, length - 2);
    
    // check for card types
    if (length == 15 && first == 3 && (second == 4 || second == 7)) {
        printf("AMEX\n");
    } else if (length == 16 && first == 5 && (1 <= second <= 5)) {
        printf("MASTERCARD\n");
    } else if ((length == 13 || length == 16) && first == 4) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
    
    // peace sign emoji
    return 0;
}


/* MODIFIED FROM SOURCE CODE BY STACKOVERFLOW USER HWLAU
 * http://stackoverflow.com/questions/4736732/printing-a-char-with-printf
 * Takes "input" and "n" and returns value at input's nth digit
 */

int digit(long long input, int n) {
    return (int) ((long long)(input/pow(10, n)) % 10);
}


/* MODIFIED FROM SOURCE CODE BY STACKOVERFLOW USER ZED_0XFF
 * http://stackoverflow.com/questions/3068397/c-how-to-find-the-length-of-an-integer
 * Takes "input" and returns the number of input's digits
 */

int num_length(long long input) {
    int len = 1;
    long long value = input;
    while (value > 9) {
        value /= 10;
        len++;
    }
    return len;
}
