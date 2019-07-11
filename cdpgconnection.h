#include<libpq-fe.h>


PGconn* CDPGget_connection(char* connstring);
void CDPGclose_connection(PGconn*);
