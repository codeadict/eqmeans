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
