/* BankSoftware Main File
 * 
 * Copyright (c) 2015 Mihail Feraru (mihailferaru2000@gmail.com).
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * Here starts execution of program. It takes 1 argument from commnad line,
 * it can be: user - for normal user that want to access hit account,
 * bank - for bank server administrator and help - open help menu.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VERSION "0.0.1"
#define LICENSE "GPL v2"

int main(int argc, char **argv)
{
	printf("Welcome to BankSoftware.\n");
	
	if (argc < 2) {
		puts("Not enough arguments.");
	} else {
		if (!strcmp("user", argv[1])) {
			// TODO: go to user mode and prompt for login
		} else if (!strcmp("bank", argv[1])) {
			// TODO: go to bank mode and prompt for bank database name and admin password
		} else if (!strcmp("help", argv[1])) {
			// TODO: print help menu
		} else {
			puts("Unknowed argument 1.");
			return 1;
		}
	}
	
	return 0;
}
