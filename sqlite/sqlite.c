#include "sqlite3.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{
     sqlite3 *db ;

     char * errMsg ;
     int rc;
     rc = sqlite3_open("sqlite.sqlite3", &db);

    if(rc) {
        fprintf(stderr, "打开失败%s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
    }else {
        printf("成功\n");
        char *sql = "CREATE TABLE IF NOT EXISTS test(\
                    id INTEGER PRIMARY KEY,\
                    uid INTEGER,\
                    nickname VARCHAR(12),\
                    latitude FLOAT\
        )";
        query(db, sql);
        sql = "INSERT INTO test(uid,nickname,latitude)VALUES(1,'abcdefg',1.234)";
        query(db, sql);
        sql = "SELECT * FROM test";
        query(db, sql);
    }

     return 0;
}