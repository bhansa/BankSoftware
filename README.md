Bank Software
====================
It is a simulation of a real bank. It can done a lot of functions with accounts and its database. 
Account functions:
	- deposit money
	- loan money
	- withdraw money
	- send money to other account (even from another bank)
	- receive money from other accounts
	- create more deposits
	- keep track of transactions
Bank functions:
	- register new accounts
	- delete accounts
	- communicate with other banks
	- keep track of all transactions (or not if the user want)
	- offer loans to users

The bank software will have two parts:
	- user mode
	- server mode

I. User mode
It is used by normal users. They must enter IP of server bank and connect to it and now, they have access to their accounts. It will have a console interface with all functions of an account. Accounts are password protected (and crypted), so user need to use access key.

II. Server mode
It used by bank to create a server where users connect and access bank software. Administrator of bank server can't delet or access accounts only if user doesn't respect Termens&Conditions. Administrator doesn't know password of an account, but when account user don't respect T&C, the bank software gives access for administrator to account without password.

Coding style
====================
I. Variables - use lowercase and '_' to separe the words: `int test_var;`

II. Pointers - use '*' near pointer name: `int *pointer name;`

III. Structures and unions - naming same as for variables:
 
`struct test_struct {
	int test;
	int *pointer;
};`

IV. Typedefs: use '_t' postfix: `typedef test_struct test_struct_t;` ('_t' minds that it is a type)

V. Functions - C Standard Style: 

```
size_t strlen(char *str)
{
	... FUNCTION BODY ...
}
```

VI. Code blocks - code block like for, while, do, if:

```
if (...) {
	...
} else if (...) {
	...
} else {
	...
}

do {
	...
} while (...);

for (...; ...; ...;) {
	...
}

switch (...) {
	case ...:
		...
		break;
	case ...:
		...
		break;
		
	....
	
	default:
		...
		break;
}
```

VII. Commenting - there are 3 situatuions:

a) on file start: You must write copyright and license and file description

```
/* ... name ...
 * 
 * Copyright (c) 2015 ...name... (...mail...).
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * ... description ...
 */
```

b) in header files before function declaration

```
/*
 * ... description ...
 */
int test_func();
```

c) inside source file - use '//' comments

Build
===================
For linux users: make
For windows users: build.bat

