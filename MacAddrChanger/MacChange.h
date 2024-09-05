#pragma once


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>

typedef unsigned char int8;
typedef unsigned short int16;
typedef unsigned int int32;
typedef unsigned long long int64;

typedef struct 
{
    int64 addr : 48;
}MacAddr_t;


MacAddr_t GenerateRandomAddr();

MacAddr_t GenerateRandomAddr(){

    int64 addr[2];
    MacAddr_t  MacAddr;
    addr[0] = (long)random();
    addr[1] = (long)random();

    MacAddr.addr = (addr[0] << 16) | addr[1];


    return MacAddr;
}
