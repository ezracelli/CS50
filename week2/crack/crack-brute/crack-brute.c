/* * * * * * * * * * * * * * * * * * * *
 * crack-brute.c is a tool for brute force cracking a password.
 * The password must be between zero and eight characters, inclusive.
 * 
 * USAGE
 * crack-brute hash
 * "hash" must be output from crypt(3).
 *
 * OUTPUT:
 * If pass, is blank, "pass is blank" will be printed.
 * Else, "pass: [pass]" will be printed.
 * Be careful of trailing spaces in pass.
 * 
 * Ezra Celli
 * ezraandrewcelli@gmail.com
 *
 * * * * * * * * * * * * * * * * * * * */

#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void cracking(char *pass, char *salt, char *hash);

int main(int argc, char *argv[])
{
    // error checking
    if (argc != 2)
    {
        printf("USAGE: crack-brute hash\n");
        return 1;
    }
    
    // collect user-inputted values
    char *hash = argv[1];
    char salt[2] = {argv[1][0], argv[1][1]};
    
    // iterate through each possible string length
    for (int i = 1; i < 10; i++)
    {
        
        // declare a string of length i
        // length of pass will go from 1 to 8 + \0
        char pass[i];
        pass[i - 1] = '\0';
        
        // check for blank pass
        if (strcmp(crypt(pass, salt), hash) == 0)
        {
            printf("pass is blank\n");
            return 0;
        }
        
        // BEGIN BRUTE FORCE
        // character number will go from 0 to length of pass
        for (int j = 0; j < i; j++)
        {
            
            // for character 0
            // if (j == 0)
            for (int k = ' '; k < 127; k++)
            {
                
                // set pass to every possible character
                pass[0] = k;
                
                // for character 1
                if (j > 0)
                {
                    for (int l = ' '; l < 127; l++)
                    {
                        pass[1] = l;
                        
                        // for character 2
                        if (j > 1)
                        {
                            for (int m = ' '; m < 127; m++)
                            {
                                pass[2] = m;
                                
                                // for character 3
                                if (j > 2)
                                {
                                    for (int n = ' '; n < 127; n++)
                                    {
                                        pass[3] = n;
                                        
                                        // for character 4
                                        if (j > 3)
                                        {
                                            for (int o = ' '; o < 127; o++)
                                            {
                                                pass[4] = o;
                                                
                                                // for character 5
                                                if (j > 4)
                                                {
                                                    for (int p = ' '; p < 127; p++)
                                                    {
                                                        pass[5] = p;
                                                        
                                                        // for character 6
                                                        if (j > 5)
                                                        {
                                                            for (int q = ' '; q < 127; q++)
                                                            {
                                                                pass[6] = q;
                                                                
                                                                // for character 7
                                                                if (j > 6)
                                                                {
                                                                    for (int r = ' '; r < 127; r++)
                                                                    {
                                                                        pass[7] = r;
                                                                        
                                                                        // will execute if length is 8 (i == 8)
                                                                        if (strcmp(crypt(pass, salt), hash) == 0)
                                                                        {
                                                                            printf("pass: %s\n", pass);
                                                                            return 0;
                                                                        }
                                                                    }
                                                                }
                                                                
                                                                // execute if length is 7
                                                                if (i == 7)
                                                                {
                                                                    if (strcmp(crypt(pass, salt), hash) == 0)
                                                                    {
                                                                        printf("pass: %s\n", pass);
                                                                        return 0;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        
                                                        // execute if length is 6
                                                        if (i == 6)
                                                        {
                                                            if (strcmp(crypt(pass, salt), hash) == 0)
                                                            {
                                                                printf("pass: %s\n", pass);
                                                                return 0;
                                                            }
                                                        }
                                                    }
                                                }
                                                
                                                // execute if length is 5
                                                if (i == 5)
                                                {
                                                    if (strcmp(crypt(pass, salt), hash) == 0)
                                                    {
                                                        printf("pass: %s\n", pass);
                                                        return 0;
                                                    }
                                                }
                                            }
                                        }
                                        
                                        // execute if length is 4
                                        if (i == 4)
                                        {
                                            if (strcmp(crypt(pass, salt), hash) == 0)
                                            {
                                                printf("pass: %s\n", pass);
                                                return 0;
                                            }
                                        }
                                    }
                                }
                                
                                // execute if length is 3
                                if (i == 3)
                                {
                                    if (strcmp(crypt(pass, salt), hash) == 0)
                                    {
                                        printf("pass: %s\n", pass);
                                        return 0;
                                    }
                                }
                            }
                        }
                        
                        // execute if length is 2
                        if (i == 2)
                        {
                            if (strcmp(crypt(pass, salt), hash) == 0)
                            {
                                printf("pass: %s\n", pass);
                                return 0;
                            }
                        }
                    }
                }
                
                // execute if length is 1
                if (i == 1)
                {
                    if (strcmp(crypt(pass, salt), hash) == 0)
                    {
                        printf("pass: %s\n", pass);
                        return 0;
                    }
                }
            }
        }
    }
}
