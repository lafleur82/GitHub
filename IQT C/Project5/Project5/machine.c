#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "machine.h"


/*
* FUNCTION:   Machine_item *item_new(unsigned int inv, double cost, char *name) 
*
* ARGUMENTS:  inv indicates the number of this particular item in inventory
*             cost indicates the price of the item 
*             name indicates the name of the item to be created 
*
* RETURNS:	   On success, return a Machine_item pointer to a newly created Machine_item:
*
* NOTES:      Error Codes:
*                 0 or NULL for an undefined name pointer. 
*/


Machine_item *item_new(unsigned int inv, double cost, char *name)
{
	if (!name)
	{
		return NULL;
	}
	else if (!inv || !cost)
	{
		return 0;
	}
	else
	{
		Machine_item * newItem = (Machine_item *) calloc(1, sizeof(Machine_item));
		newItem->inventory = inv;
		newItem->cost = cost;
		newItem->name = name;

		return newItem;
	}
}


Machine_item *item_clone(Machine_item * item)
{
    if (!item || !item_get_name(item))
	{
        return NULL;
    }

    return item_new(item_get_inventory(item), item_get_cost(item), item_get_name(item));
}


/*
* FUNCTION:   void item_free(Machine_item *item)
*
* ARGUMENTS:  item is a pointer to a Machine_item to be freed 
*
* RETURNS:	  returns void; 
*
* NOTES:      return for any null pointer received
*/
void item_free(Machine_item *item) 
{
	if (item)
	{
		free(item);
	}
}


/*
* FUNCTION:   item_set_cost(Machine_item *item, double cost) 
*
* ARGUMENTS:  item is a pointer to a Machine_item to set the cost for 
*			  cost is a double that contains the cost of an item
*
* RETURNS:	  returns 1 on successfully setting item cost
*			  return MACHINE_NULL_PTR for if item is NULL 
*
* NOTES:      /
*/
int item_set_cost(Machine_item *item, double cost) 
{
	if (!item)
	{
		return MACHINE_NULL_PTR;
	}
	else
	{
		item->cost = cost;
		return 1;
	}
}


/*
* FUNCTION:   item_get_cost(Machine_item *item)
*
* ARGUMENTS:  item is a pointer to a Machine_item to get the cost of
*
* RETURNS:	  returns items cost 
*			  return 0 for if item is NULL
*
* NOTES:     /
*/
double item_get_cost(Machine_item *item) 
{
	if (!item)
	{
		return 0;
	}
	else
	{
		return item->cost;
	}
}


/*
* FUNCTION:   int item_set_inventory(Machine_item *item, unsigned int inv) 
*
* ARGUMENTS:  item is a pointer to a Machine_item to set the quantity for
*			  inv is an inv that contains the inventory quantity of an item
*
* RETURNS:	  returns 1 on successfully setting item inventory
*			  return MACHINE_NULL_PTR for if item is NULL
*
* NOTES:     /
*/
int item_set_inventory(Machine_item *item, unsigned int inv) 
{
	if (!item)
	{
		return MACHINE_NULL_PTR;
	}
	else
	{
		item->inventory = inv;
		return 1;
	}
}


/*
* FUNCTION:   item_get_inventory(Machine_item *item)
*
* ARGUMENTS:  item is a pointer to a Machine_item to get the inventory of of
*
* RETURNS:	  returns items inventory
*			  return 0 for if item is NULL
*
* NOTES:     /
*/
unsigned int item_get_inventory(Machine_item *item) 
{
	if (!item)
	{
		return 0;
	}
	else
	{
		return item->inventory;
	}
}


int item_set_name(Machine_item *item, char *name) 
{
    if (!item) 
	{
        return MACHINE_NULL_PTR;
    } 
	
	else if (item->name)
	{
        free(item->name);
    }
    item->name = name;
    return 1;
}


char *item_get_name(Machine_item *item) 
{
    if (!item) 
	{
        return NULL;
    } 
	
	else if (!item->name)
	{
        return NULL;
    }

    return item->name;
}


/*
* FUNCTION:   int item_compare(Machine_item * item1, Machine_item * item2)
*
* ARGUMENTS:  item1 is a pointer to the first Machine_item used in the comparison
			  item2 is a pointer to the second Machine_item to be used in the comparison
*
* RETURNS:	   returns 0 if any pointer or character string is null
			   returns 0 if any comparison between two items is not equal
			   If two items are equal, return 1;
*
* NOTES:      compare two items, property by property. If any comparison fails, return 0
*/
int item_compare(Machine_item * item1, Machine_item * item2)
{
	if (!item1 || !item2 || !item1->name || !item2->name)
	{
		return 0;
	}
	
	if (item1->cost == item2->cost && item1->inventory == item2->inventory && item1->name == item2->name)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


Machine *machine_new(unsigned int row, unsigned int col) 
{
    if (row == 0 || col == 0) 
	{
        return NULL;
    }

    Machine_item ***rows;
    rows = (Machine_item ***) calloc(row, sizeof(int***));
    for (int i = 0; i < row; i++) 
	{
        rows[i] = (Machine_item **) calloc(col, sizeof(int **));
    }

    Machine *machine = malloc(sizeof(Machine));
    machine->slots = rows;
    machine->rows = row;
    machine->cols = col;

    return machine;
}


void machine_free(Machine *machine) 
{
    if (!machine) 
	{
        return;
    }
    for (int i = 0; i < machine->rows; i++) 
	{
        for (int j = 0; j < machine->cols; j++) 
		{
            Machine_item *item = machine->slots[i][j];
            if (item != NULL) 
			{
                item_free(item);
                machine->slots[i][j] = NULL;
            }
        }
        free(machine->slots[i]);
        machine->slots[i] = NULL;
    }
    free(machine->slots);
    machine->slots = NULL;
    machine->rows = 0;
    machine->cols = 0;
    free(machine);
}


/*
* FUNCTION:   Machine_item *machine_get_item(Machine *machine, int row, int col) 
*
* ARGUMENTS:  machine is a pointer to the vending machine 
*			  int row contains the item at machine row to get 
*			  int col contains the item at machine column to get 
*
* RETURNS:	  the item contained at machine row/col 
*			  returns NULL if machine pointer is nul
*			  return NULL if row/col is <= 0
*			  return NULL if row/col is greater than the machine rows and cols 
*
*
*/


Machine_item *machine_get_item(Machine *machine, int row, int col) 
{
	if (!machine || row <= 0 || col <= 0 || row > machine->rows || col > machine->cols)
	{
		return NULL;
	}
	else
	{
		return machine->slots[row][col];
	}
}


int machine_buy(Machine *machine, char *name, unsigned int num, double *money) {
    if (!machine) {
        return MACHINE_NULL_PTR;
    } else if (!name) {
        return MACHINE_NULL_PTR;
    } else if (num == 0) {
        return MACHINE_BAD_ARGS;
    } else if (!money || *money <= 0) {
        return MACHINE_BAD_ARGS;
    } else if (strlen(name) == 0) {
        return MACHINE_BAD_ARGS;
    }

    int bought = 0, stop = 0;
    for (int i = 0; i < machine->rows && !stop; i++) {
        for (int j = 0; j < machine->cols; j++) {
            if (!machine->slots[i][j] || machine->slots[i][j] == NULL) {
                continue;
            }
            Machine_item *item = machine->slots[i][j];
            if (strcmp(item_get_name(item), name) == 0) {
                if (item_get_inventory(item) > 0) {
                    if (*money >= item_get_cost(item)) {
                        do {
                            *money -= item_get_cost(item);
                            item_set_inventory(item, item_get_inventory(item)-1);
                            num--;
                            bought++;
                        } while (*money >= item_get_cost(item) && item_get_inventory(item) > 0 \
                                && num > 0);
                        if (num == 0) {
                            stop = 1;
                            break;
                        }
                    } else {
                        stop = 1;
                        break;
                    }
                }
            }
        }
    }

    return bought;
}


/*
* FUNCTION:  Machine_item * machine_set_item(Machine *machine, Machine_item *item, int row, int col)
*
* ARGUMENTS: machine is a pointer to a (vending) machine
*			 item is a pointer to a Machine_item to set
*			 row is the row within the vending machine 
*			 col is the col within the vending machine 
*
* RETURNS:	 returns oldItem, a pointer to the item previously at that row/col in the vending machine
*			 return null for any null pointer, or row/col that is <= 0 
*
* NOTES:     Function will replace the item at the current row/col position with the argument item
*			 if an item was previously at this row/col, return that oldItem
*			 Otherwise return NULL
*/
Machine_item * machine_set_item(Machine *machine, Machine_item *item, int row, int col) 
{
	if (machine && row && col && row <= machine->rows && col <= machine->cols)
	{
		if (machine->slots[row][col])
		{
			Machine_item * oldItem = machine->slots[row][col];
			machine->slots[row][col] = item;
			return oldItem;
		}
		else
		{
			machine->slots[row][col] = item;
		}
	}

	return NULL;
}


/*
* FUNCTION:  machine_replace_item(Machine *machine, Machine_item *item, int row, int col)
*
* ARGUMENTS: machine is a pointer to a (vending) machine
			 item is a pointer to a Machine_item to set
			 row is the row within the vending machine that contains the item to be replaced
			 col is the col within the vending machine that contains the item to be replaced
*
* RETURNS:	 returns 1 if an old item was replaced
*			 return 0 if no item was replaced 
*
* NOTES:     Function will replace the item at the current row/col position with the argument item
*			 if an item was previously at this row/col, return that oldItem
*			 This function should make use of the machine_set_item() function
*/
int machine_replace_item(Machine *machine, Machine_item *item, int row, int col)
{
	if (machine && row && col && row <= machine->rows && col <= machine->cols)
	{
		if (machine->slots[row][col])
		{
			machine_set_item(machine, item, row, col);
			return 1;
		}
		machine_set_item(machine, item, row, col);
	}

	return 0;
}

void machine_print(Machine *machine)
{
    if (!machine)
	{
        return;
    }

    fprintf(stdout,"|{\n");
    for (int i=0; i < machine->rows; i++){
        for (int j=0; j < machine->cols; j++){
            Machine_item * item = machine->slots[i][j];
            if (!item || !item_get_name(item)){
                fprintf(stdout,"0;0.00;%-10s", "Empty");
            } else {
                fprintf(stdout,"%d;%.2lf;%-10s", item_get_inventory(item), \
                        item_get_cost(item), item_get_name(item));
            }
        }
        fprintf(stdout,"\n");
    }
    fprintf(stdout,"|}\n");
    fflush(stdout);
}

int machine_fill(Machine * machine, Machine_item * item)
{
    if (!machine)
	{
        return -1;
    } else if (!item)
	{
        return -2;
    }

    for (int i=0; i< machine->rows; i++)
	{
        for (int j=0; j< machine->cols; j++)
		{
            machine_replace_item(machine,item_clone(item),i,j);
        }
    }
    item_free(item);
    return 1;
}
