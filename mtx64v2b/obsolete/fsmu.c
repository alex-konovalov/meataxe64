// Copyright (C) Richard Parker   2017
// Meataxe64 Nikolaus version
// fsmu.c  Scalar multiplication may be obsolete

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "field.h"
#include "io.h"
#include "funs.h"
 
void fsmu(TLS * tls, const char * fn1, int s1, const char * fn2, int s2,
         FELT sc)
{
    EFIL *e1,*e2;
    uint64_t hdr[5];
    uint64_t nor,noc;
    DSPACE ds;
    Dfmt *v1;
    uint64_t i;

    e1=ERHdr(fn1,hdr);

    nor=hdr[2];
    noc=hdr[3];

    e2 = EWHdr(fn2,hdr);
    DSSet(tls->f,noc,&ds);

    v1=malloc(ds.nob);

/******  Do them one row at a time  */
    for(i=0;i<nor;i++)
    {
	ERData(e1,ds.nob,v1);
        DSMul(&ds,sc,1,v1);
        EWData(e2,ds.nob,v1);
    }
    free(v1);
    ERClose1(e1,s1);
    EWClose1(e2,s2);
    return;
}

/******  end of fsmu.c    ******/
