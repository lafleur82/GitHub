#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define RUN_TESTS // Needs to be defined before the machine header is included.
#include "machine.h"

#define SLOT_ROWS 6
#define SLOT_COL 4


int main() {
    #ifdef RUN_TESTS
        unit_tests();
    #else
        Machine * machine = machine_new(SLOT_ROWS, SLOT_COL);
        //machine_fill(machine, item_new(3,1.00,"Chips"));
        double my_money = 20000.00;
        int ret = machine_buy(machine, "Chips", 200, &my_money);
        printf("Bought %d chips, have %.2lf left\n", ret, my_money);
        machine_print(machine);
        machine_free(machine);
    #endif

	getchar();
    return 0;
}



