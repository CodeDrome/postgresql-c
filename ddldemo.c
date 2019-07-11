#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include"cdpgconnection.h"
#include"cdpgddl.h"


int main(int argc, char* argv[])
{
    puts("---------------------------");
    puts("| codedrome.com           |");
    puts("| PostgreSQL with libpq   |");
    puts("| DDL: Creating Databases |");
    puts("---------------------------\n");

    CDPGcreatedb();

    return EXIT_SUCCESS;
}
