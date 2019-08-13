#include<stdbool.h>

#include<libpq-fe.h>


void result_to_terminal(PGresult* result)
{
    if (PQresultStatus(result) != PGRES_TUPLES_OK)
    {
        printf("No data\n");
    }
    else
    {
        PQprintOpt pqpo = (PQprintOpt){.header = true,
                                       .align = true,
                                       .standard = false,
                                       .html3 = false,
                                       .expanded = false,
                                       .pager = 0,
                                       .fieldSep = "|",
                                       .tableOpt = "",
                                       .caption = "",
                                       .fieldName = NULL};

        PQprint(stdout, result, &pqpo);
    }
}


void result_to_html(PGresult* result, char* filepath)
{
    if (PQresultStatus(result) != PGRES_TUPLES_OK)
    {
        puts("No data\n");
    }
    else
    {
        FILE* fp;

        fp = fopen(filepath, "w");

	    if(fp != NULL)
        {
            PQprintOpt pqpo = (PQprintOpt){.header = true,
                                           .align = false,
                                           .standard = false,
                                           .html3 = true,
                                           .expanded = false,
                                           .pager = 0,
                                           .fieldSep = "",
                                           .tableOpt = "",
                                           .caption = "",
                                           .fieldName = NULL};

            PQprint(fp, result, &pqpo);

            fclose(fp);
        }
        else
        {
            printf("Cannot open %s for writing", filepath);
        }
    }
}


void result_to_csv(PGresult* result, char* filepath)
{
    if (PQresultStatus(result) != PGRES_TUPLES_OK)
    {
        printf("No data\n");
    }
    else
    {
        FILE* fp;

        fp = fopen(filepath, "w");

	    if(fp != NULL)
        {
            PQprintOpt pqpo = (PQprintOpt){.header = false,
                                           .align = false,
                                           .standard = false,
                                           .html3 = false,
                                           .expanded = false,
                                           .pager = 0,
                                           .fieldSep = "|",
                                           .tableOpt = "",
                                           .caption = "",
                                           .fieldName = NULL};

            PQprint(fp, result, &pqpo);

            fclose(fp);
        }
        else
        {
            printf("Cannot open %s for writing", filepath);
        }
    }
}
