#define _CRT_SECURE_NO_WARNINGS 1
#ifndef MACHINE_H
#define MACHINE_H
#define MACHINE_NULL_PTR -1
#define MACHINE_BAD_ARGS -2

typedef struct Machine_item {
    unsigned int inventory;
    double cost;
    char *name;
} Machine_item;

Machine_item *item_new(unsigned int inv, double cost, char *name);

Machine_item *item_clone(Machine_item * item);

void item_free(Machine_item *item);

int item_set_cost(Machine_item *item, double cost);

double item_get_cost(Machine_item *item);

int item_set_inventory(Machine_item *item, unsigned int inv);

unsigned int item_get_inventory(Machine_item *item);

int item_set_name(Machine_item *item, char *name);

char *item_get_name(Machine_item *item);

// 1 match; 0 for not matched or error
int item_compare(Machine_item *item1, Machine_item *item2);


typedef struct Machine {
    unsigned int rows;
    unsigned int cols;
    Machine_item ***slots;
} Machine;

Machine *machine_new(unsigned int row, unsigned int col);

void machine_free(Machine *machine);

Machine_item *machine_get_item(Machine *machine, int row, int col);

void machine_print(Machine *machine);

Machine_item * machine_set_item(Machine *machine, Machine_item *item, int row, int col);

int machine_replace_item(Machine *machine, Machine_item *item, int row, int col);

int machine_buy(Machine *machine, char *name, unsigned int num, double *money);

int machine_fill(Machine * machine, Machine_item * item);


#ifdef RUN_TESTS
void unit_tests();
#endif

#endif