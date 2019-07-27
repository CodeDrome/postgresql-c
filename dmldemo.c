#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include"cdpgconnection.h"
#include"cdpgdml.h"


int main(int argc, char* argv[])
{
    puts("--------------------------");
    puts("| codedrome.com          |");
    puts("| PostgreSQL with libpq  |");
    puts("| DML: Manipulating Data |");
    puts("--------------------------\n");

    PGconn* connpg = CDPGget_connection("user=chris password=chris dbname=codedrome");

    PGresult* res;

    if(connpg != NULL)
    {
        // CDPGinsert_galleries(connpg);
        // CDPGinsert_photos(connpg);
        // CDPGupdate_photo(connpg);
        // CDPGdelete_photo(connpg);
        // CDPGquery_galleriesphotos(connpg);

        CDPGclose_connection(connpg);
    }

    return EXIT_SUCCESS;
}
