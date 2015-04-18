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

#endif // _BANK_H
