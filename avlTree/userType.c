#include <stdio.h>
#include <string.h>

#include "./include/userType.h"
#include "./include/boolean.h"


/****************Write rule of saving****************/
boolean IsToLeft(Item *x, Item *element) {
	return  strcmp(x->id,element->id) < 0;
}

boolean IsToRight(Item *x, Item *element) {
	return strcmp(x->id,element->id) > 0;
}/****************Write rule of saving****************/

