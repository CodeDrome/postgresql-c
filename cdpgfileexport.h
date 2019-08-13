#include<libpq-fe.h>


void result_to_terminal(PGresult* result);
void result_to_html(PGresult* result, char* filepath);
void result_to_csv(PGresult* result, char* filepath);
