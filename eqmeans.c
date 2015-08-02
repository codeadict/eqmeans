/** =========================================================================
    EQMeans - PostgreSQL Kmeans Algorithm with same size clusters.
    -------------------------------------------------------------------------
    @author Dairon Medina <dairon.medina@gmail.com>
    @copyright Copyright (c) 2015, Dairon Medina
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published
    by the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    For Support, please visit http://codeadict.github.com/
    -------------------------------------------------------------------------
*/

#include "postgres.h"

#include <float.h>
#include <math.h>

#include <fmgr.h>
#include <miscadmin.h>
#include <windowapi.h>
#include <lib/stringinfo.h>
#include <utils/array.h>

PG_MODULE_MAGIC;

typedef float8 *thevector;
#define SIZEOF_V(dim) (sizeof(float8) * dim)


typedef struct{
    bool is_done;
    bool is_null;
    int result[1];
} eqmeans_context;


static Datum kmeans_do(PG_FUNCTION_ARGS, bool initial_mean_suplied, bool use_equal__clusters) {
    WindowObject winobj = PG_WINDOW_OBJECT();
    eqmeans_context *context;
    int64 curpos, rows;

    // get rows count
    rows = WinGetPartitionRowCount(winobj);

}
