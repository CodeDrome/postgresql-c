#include<libpq-fe.h>

#include"cdpgconnection.h"
#include"cdpgddl.h"


void CDPGcreatedb()
{
    char* sql = "CREATE DATABASE codedrome";

    PGconn* connpg = CDPGget_connection("user=chris password=chris dbname=postgres");

    PGresult* res;

    if(connpg != NULL)
    {
        res = PQexec(connpg, sql);

        if (PQresultStatus(res) != PGRES_COMMAND_OK)
        {
            fprintf(stderr, "%s\n", PQerrorMessage(connpg));
        }
        else
        {
            CDPGcreateDBobjects();
        }

        PQclear(res);

        CDPGclose_connection(connpg);
    }
}


void CDPGcreateDBobjects()
{
    const char* sql[5];

    sql[0] = "CREATE TABLE galleries(galleryid serial PRIMARY KEY, name varchar(64) NOT NULL, description varchar(256))";

    sql[1] = "CREATE TABLE photos(photoid serial PRIMARY KEY, galleryid smallint REFERENCES galleries(galleryid) NOT NULL, title varchar(64) NOT NULL, description varchar(256) NOT NULL, photographer varchar(64) NOT NULL, datetaken date)";

    sql[2] = "CREATE TABLE typesdemo(serialid serial PRIMARY KEY, intcolumn integer, realcolumn real, varcharcolumn varchar(64), datecolumn date, booleancolumn boolean)";

    sql[3] = "CREATE VIEW galleriesphotos AS SELECT galleries.name AS galleryname, galleries.description AS gallerydescription, photos.title AS phototitle, photos.description AS photodescription FROM galleries LEFT JOIN photos ON photos.galleryid = galleries.galleryid";

    PGconn* connpg = CDPGget_connection("user=chris password=chris dbname=codedrome");

    PGresult* res;

    if(connpg != NULL)
    {
        for(int i = 0; i <= 3; i++)
        {
            res = PQexec(connpg, sql[i]);

            if (PQresultStatus(res) != PGRES_COMMAND_OK)
            {
                fprintf(stderr, "%s\n", PQerrorMessage(connpg));

                break;
            }

            PQclear(res);
        }

        CDPGclose_connection(connpg);
    }
}
