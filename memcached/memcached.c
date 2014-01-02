#include<stdio.h>
#include<libmemcached/memcached.h>

int main (int argc, char ** argv)
{
    memcached_st *memc;
    memcached_return_t rc;

    // connect to server
    const char *config_string= "--SERVER=127.0.0.1:11211";
    memc= memcached(config_string, strlen(config_string));


    const char *key = "a";// memcached key or queue key
    const char *value = "hahahahahahahaha";// datamining  php execute file
    size_t lenval, rtv;
    uint32_t rtf;
    lenval = strlen(value);

    // save value to memcached
    rc = memcached_set(memc, key, strlen(key), value, lenval, (time_t)0, (uint32_t)0);
    if(rc == MEMCACHED_SUCCESS)
        fprintf(stdout, "save success!\n");
    else
        fprintf(stdout, "save failed!\n");

    memcached_free(memc);

    return 0;
}