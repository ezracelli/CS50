#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char *argv[]) {
	printf("pass: ");
	char *pass = GetString();
	char *salt;
	do {
		printf("salt: ");
		salt = GetString();
	} while (strlen(salt) != 2);
	char *crypted = crypt(pass, salt);
	printf("%s\n", crypted);
}
