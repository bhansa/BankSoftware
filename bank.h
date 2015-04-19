/* Bank Header
 * 
 * Copyright (c) 2015 Mihail Feraru (mihailferaru2000@gmail.com).
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * Contains the bank structure and its functions for manipulate accounts,
 * write to database, read from database and keep tracks of transactions.
 *
 * TODO: when accout header is ready use it in bank structure to load accounts
 */

#ifndef _BANK_H
#define _BANK_H

/*
 * This structure stores all data about a transaction.
 */
typedef struct transaction_log {
	char *sender_name;         // The name of user who sends the money
	int sender_id;             // The ID of user who sends the money
	char *sender_bank_name;    // The name of the bank where is registered account of user who send money
	char *sender_bank_ip;      // The IP of the bank where is registered account of user who send money
	 
	char *receiver_name;       // The name of user who receive the money
	int receiver_id;           // The ID of user who receive the money
	char *receiver_bank_name;  // The name of the bank where is registered account of user who receive money
	char *receiver_bank_ip;    // The IP of the bank where is registered account of user who receive money
	
	int amount;                // The amount of money
	int status;                // 0 - public , 1 - private , 2 - blocked
	char *comments;            // Other specifications for transaction
} transaction_log_t;
 
/*
 * This is the bank server structure that stores info about all accounts,
 * about all transactions and about available money of bank. 
 */
typedef struct bank {
	char *name;              // The name of the bank   
	char *key;               // The key for login
	transaction_log_t *logs; // All transactions logs
	int real_money;          // Real money of the bank (self_funds + accounts_money)
	int self_funds;          // The funds of bank without accounts money
	int accounts_money;      // The money of all accounts
	// TODO: add array of users when user struct is ready
} bank_t;

/* Initialize bank 
 *
 * Alloc memeory for a 'bank_t' variable with specified name. After it search for
 * database of bank, if it doesn't exist create one and generate a random key for
 * it, else it reads data from database file and writes to the new allocated 'bank_t'
 * variable. At last, it returns the 'bank_t' variable.
 * 
 * Parameters: name of bank (string)
 * Return: bank variable (bank_t) - ERROR: return NULL
 */
bank_t *init_bank(char *name);

/* Load bank database
 * 
 * Search for a database file with specified name (bank->name) and load it in memory,
 * in the bank structure. If the database wasn't found or any error occur in time of
 * loading, the return value will be 1.
 *
 * Parameters: bank structure (bank_t)
 * Return: 0 - SUCCESS, 1 - ERROR
 */
int load_db(bank_t *bank);

/* Create bank database
 *
 * Create a database file with bank name (bank->name) and generates a key for database
 * which will be loaded into bank key (bank->key). If any error occur, function will
 * return 1.
 *
 * Parameters: bank structure (bank_t)
 * Return: 0 - SUCCESS, 1 - ERROR
 */
int create_db(bank_t *bank);

/* Calculate all bank funds
 *
 * Take a bank structure and calculate real money (bank->real_money), self funds (bank->self_funds)
 * and accounts funds (bank->accounts_money). If any error occur return 1;
 *
 * Parameters: bank structure (bank_t)
 * Return: 0 - SUCCESS, 1 - ERROR
 */
int calculate_funds(bank_t *bank);

#endif // _BANK_H
