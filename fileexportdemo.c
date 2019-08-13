#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include"cdpgconnection.h"
#include"cdpgfileexport.h"


int main(int argc, char* argv[])
{
    puts("--------------------------");
    puts("| codedrome.com          |");
    puts("| PostgreSQL with libpq  |");
    puts("| File Exports           |");
    puts("--------------------------\n");

    PGconn* conn = CDPGget_connection("user=user password=password dbname=codedrome");

    if(conn != NULL)
    {
        char* sql = "SELECT galleryname, gallerydescription, phototitle, photodescription FROM public.galleriesphotos";

        PGresult* res = PQexec(conn, sql);

        result_to_terminal(res);

        result_to_html(res, "galleriesphotos.html");

        result_to_csv(res, "galleriesphotos.csv");

        PQclear(res);

        CDPGclose_connection(conn);
    }

    return EXIT_SUCCESS;
}
