#include<time.h>
#include<string.h>

#include<libpq-fe.h>

#include"gallery.h"
#include"photo.h"


void CDPGinsert_photo(PGconn* conn, photo p);
void CDPGinsert_gallery(PGconn* conn, gallery g);
void printdata(PGresult*);


void CDPGinsert_galleries(PGconn* conn)
{
    gallery galleries[4];

    galleries[0] = (gallery){.name = "Edinburgh", .description = "Photos of Edinburgh"};
    galleries[1] = (gallery){.name = "Jersey", .description = "Photos of Jersey"};
    galleries[2] = (gallery){.name = "Canterbury", .description = "Photos of Canterbury"};
    galleries[3] = (gallery){.name = "Cambridge", .description = "Photos of Cambridge"};

    for(int c = 0; c < 4; c++)
    {
        CDPGinsert_gallery(conn, galleries[c]);
    }
}


void CDPGinsert_gallery(PGconn* conn, gallery g)
{
    char* sql = "INSERT INTO public.galleries(name, description) VALUES ($1, $2)";
    const char* params[2];

    params[0] = g.name;

    params[1] = g.description;

    PGresult* res = PQexecParams(conn, sql, 2, NULL, params, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "%s\n", PQerrorMessage(conn));
    }
    else
    {
        puts("gallery inserted");
    }

    PQclear(res);
}


void CDPGinsert_photos(PGconn* conn)
{
    photo photos[6];
    struct tm time;
    char datestring[11];

    time = (struct tm){.tm_sec = 0, .tm_min = 0, .tm_hour = 0, .tm_mday = 22, .tm_mon = 7 - 1, .tm_year = 2019 - 1900};
    strftime(datestring, 11, "%Y-%m-%d", &time);
    photos[0] = (photo){.galleryid = 1,
                        .title = "Edinburgh 1",
                        .description = "First photo of Edinburgh",
                        .photographer = "Chris"};
    strncpy(photos[0].datetaken, datestring, 11);

    time = (struct tm){.tm_sec = 0, .tm_min = 0, .tm_hour = 0, .tm_mday = 22, .tm_mon = 7 - 1, .tm_year = 2019 - 1900};
    strftime(datestring, 11, "%Y-%m-%d", &time);
    photos[1] = (photo){.galleryid = 1,
                        .title = "Edinburgh 2",
                        .description = "Second photo of Edinburg",
                        .photographer = "Chris"};
    strncpy(photos[1].datetaken, datestring, 11);

    time = (struct tm){.tm_sec = 0, .tm_min = 0, .tm_hour = 0, .tm_mday = 15, .tm_mon = 7 - 1, .tm_year = 2019 - 1900};
    strftime(datestring, 11, "%Y-%m-%d", &time);
    photos[2] = (photo){.galleryid = 3,
                        .title = "Canterbury 1",
                        .description = "First photo of Canterbury",
                        .photographer = "Chris"};
    strncpy(photos[2].datetaken, datestring, 11);

    time = (struct tm){.tm_sec = 0, .tm_min = 0, .tm_hour = 0, .tm_mday = 15, .tm_mon = 7 - 1, .tm_year = 2019 - 1900};
    strftime(datestring, 11, "%Y-%m-%d", &time);
    photos[3] = (photo){.galleryid = 3,
                        .title = "Canterbury 2",
                        .description = "Second photo of Canterbury",
                        .photographer = "Chris"};
    strncpy(photos[3].datetaken, datestring, 11);

    time = (struct tm){.tm_sec = 0, .tm_min = 0, .tm_hour = 0, .tm_mday = 8, .tm_mon = 7 - 1, .tm_year = 2019 - 1900};
    strftime(datestring, 11, "%Y-%m-%d", &time);
    photos[4] = (photo){.galleryid = 4,
                        .title = "Cambridge 1",
                        .description = "First photo of Cambridge",
                        .photographer = "Chris"};
    strncpy(photos[4].datetaken, datestring, 11);

    time = (struct tm){.tm_sec = 0, .tm_min = 0, .tm_hour = 0, .tm_mday = 8, .tm_mon = 7 - 1, .tm_year = 2019 - 1900};
    strftime(datestring, 11, "%Y-%m-%d", &time);
    photos[5] = (photo){.galleryid = 4,
                        .title = "Cambridge 2",
                        .description = "Second photo of Cambridge",
                        .photographer = "Chris"};
    strncpy(photos[5].datetaken, datestring, 11);

    for(int c = 0; c < 6; c++)
    {
        CDPGinsert_photo(conn, photos[c]);
    }
}


void CDPGinsert_photo(PGconn* conn, photo p)
{
    char* sql = "INSERT INTO public.photos(galleryid, title, description, photographer, datetaken) VALUES ($1, $2, $3, $4, $5)";
    const char* params[5];
    char galleryid[8];

    snprintf(galleryid, 8, "%d", p.galleryid);

    params[0] = galleryid;
    params[1] = p.title;
    params[2] = p.description;
    params[3] = p.photographer;
    params[4] = p.datetaken;

    PGresult* res = PQexecParams(conn, sql, 5, NULL, params, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "%s\n", PQerrorMessage(conn));
    }
    else
    {
        puts("photo inserted");
    }

    PQclear(res);
}


void CDPGupdate_photo(PGconn* conn)
{
    char* sql = "UPDATE public.photos SET description=$1 WHERE photoid=$2";

    const char* params[2];

    params[0] = "Second photo of Edinburgh";
    params[1] = "2";

    PGresult* res = PQexecParams(conn, sql, 2, NULL, params, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "%s\n", PQerrorMessage(conn));
    }
    else
    {
        puts("photo updated");
    }

    PQclear(res);
}


void CDPGdelete_photo(PGconn* conn)
{
    char* sql = "DELETE FROM public.photos WHERE photoid=$1";

    const char* params[1];

    params[0] = "2";

    PGresult* res = PQexecParams(conn, sql, 1, NULL, params, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "%s\n", PQerrorMessage(conn));
    }
    else
    {
        puts("photo deleted");
    }

    PQclear(res);
}


void CDPGquery_galleriesphotos(PGconn* conn)
{
    char* sql = "SELECT galleryname, gallerydescription, phototitle, photodescription FROM public.galleriesphotos";

    PGresult* res = PQexec(conn, sql);

    printdata(res);

    PQclear(res);
}


void printdata(PGresult* res)
{
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        printf("No data\n");
    }
    else
    {
        int ncols = PQnfields(res);
        int nrows = PQntuples(res);

        for(int r = 0; r < nrows; r++)
        {
            for (int c = 0; c < ncols; c++)
            {
                char* colname = PQfname(res, c);
                printf("%s: ", colname);
                printf("%s\n", PQgetvalue(res, r, c));
            }

            puts("");
        }
    }
}
