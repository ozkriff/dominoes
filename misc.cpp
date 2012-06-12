// See LICENSE file for copyright and license details.

#include "misc.h"
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

void die(const char *errstr, ...) {
   va_list ap;
   va_start(ap, errstr);
   vfprintf(stderr, errstr, ap);
   va_end(ap);
   exit(EXIT_FAILURE);
}



