#ifndef _USERTYPE_H_
#define _USERTYPE_H_

#include "boolean.h"

typedef struct {
	char id[10];
	char name[20];
	unsigned char math; 
} Item; /* Write data Type*/;

/****************Write rule of saving****************/
boolean IsToLeft(Item *x, Item *element);
boolean IsToRight(Item *x, Item *element);
/****************Write rule of saving****************/

#endif 