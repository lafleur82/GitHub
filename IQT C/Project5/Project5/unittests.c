#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "machine.h"


void unit_tests(){
    fprintf(stdout,"Running tests...\n");

    // ------------------
    // Machine Item Tests
    // ------------------
    // -- Test bad input on item creation
    Machine_item * item;
    item = item_new(0,0,NULL);
    assert(item == NULL);
    // -- Test item creation with good inputs and get functions
    item = item_new(10,10.00,"Chips");
    assert(item);
    assert(item_get_inventory(item) == 10);
    assert(item_get_cost(item) == 10.00);
    assert(strcmp("Chips",item_get_name(item)) == 0);
    /* -- Test Item Free
    item_free(item);
	assert(item_get_name(item) == NULL);
	assert(item_get_cost(item) == 0);
	assert(item_get_inventory(item) ==0);*/

    // ------------------
    // Vending Machine Tests
    // ------------------
    // -- Test machine creation with bad input
    Machine * machine;
    machine = machine_new(1,0);
    assert(machine == NULL);
    machine = machine_new(0,1);
    assert(machine == NULL);

    // -- Test machine creation with good input
    machine = machine_new(2,2);
	assert(machine != NULL);
	assert(machine->rows == 2);
	assert( machine->cols == 2);

    // -- Test fetching unset items in machine
    item = machine_get_item(machine, 0,0);
    assert(item == NULL);

    // -- Test setting and fetching item
    item = item_new(1,1.00,"Test");
    machine_set_item(machine, item, 1, 1);
    Machine_item * item2 = machine_get_item(machine,1,1);
    assert(item_compare(item, item2));

    // -- Test replacing item
    item = item_new(2,2.00,"Test2");
    machine_replace_item(machine,item,1,1);
    item = machine_get_item(machine,1,1);
    assert(item != NULL);
    assert(item_get_inventory(item) == 2);
    assert(item_get_cost(item) == 2.00);
    assert(strcmp(item_get_name(item), "Test2") == 0);

    // -- Test buying from machine
    double money = 5.00;
    int bought = machine_buy(machine,"Test2",1,&money);
    assert(bought == 1);
    assert(money == 3.00);
    assert(machine_get_item(machine,1,1)->inventory == 1);

    // -- Test removing item by replacing with null
    machine_replace_item(machine, NULL, 1, 1);
    item = machine_get_item(machine, 1, 1);
    assert(item == NULL);

    /* -- Test freeing freeing machine
    machine_free(machine);
	assert(machine->cols == 0); 
	assert(machine->rows == 0); 
	assert(machine->slots == NULL);*/
}


