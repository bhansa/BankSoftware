/* Bank functions source
 * 
 * Copyright (c) 2015 Mihail Feraru (mihailferaru2000@gmail.com).
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * All functions of bank database are here.
 */
 
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include "bank.h"

bank_t *init_bank(char *name)
{
	bank_t *new = malloc(sizeof(bank_t));
	new->name = malloc(sizeof(char) * strlen(name));
	strcpy(new->name, name);
	new->real_money = 0;
	new->self_funds = 0;
	new->accounts_money = 0;
	
	int error = load_db(new);
	if (error) {
		error = create_db(new);
	}
	
	if (error) {
		return NULL;
	} else {
		return new;
	}
}

int load_db(bank_t *bank)
{
	int file_found = 0;
	DIR *dir;
	struct dirent *ent;
	
	if ((dir = opendir("data/")) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			if (!strcmp(ent->d_name, bank->name)) {
				file_found = 1;
				break;
			}
		}
	} else {
		return 1;
	}
	
	if (file_found) {
		puts("Database was found!");
		// TODO: implement loading into structure
	} else {
		return 1;
	}
	
	return 0;
}

int create_db(bank_t *bank)
{
	// TODO: must implement database creation
	return 0;
}

int calculate_funds(bank_t *bank)
{
	// TODO: implement when account structure is ready
	return 1;
}
