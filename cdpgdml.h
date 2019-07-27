#include<libpq-fe.h>


void CDPGinsert_galleries(PGconn* conn);
void CDPGinsert_photos(PGconn* conn);
void CDPGupdate_photo(PGconn* conn);
void CDPGdelete_photo(PGconn* conn);
void CDPGquery_galleriesphotos(PGconn* conn);
