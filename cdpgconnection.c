#include<libpq-fe.h>


void CDPGclose_connection(PGconn* conn)
{
    PQfinish(conn);
}


PGconn* CDPGget_connection(char* connstring)
{
    PGconn *conn = PQconnectdb(connstring);

    if (PQstatus(conn) == CONNECTION_BAD)
    {
        fprintf(stderr, "CONNECTION_BAD %s\n", PQerrorMessage(conn));

        CDPGclose_connection(conn);

        return NULL;
    }
    else if (PQstatus(conn) == CONNECTION_OK)
    {
        puts("CONNECTION_OK");

        return conn;
    }
}
