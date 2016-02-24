#ifndef TEST_EXPORT_H
#define TEST_EXPORT_H

// $Id: foo_export.h 760 2006-10-17 20:36:13Z syntheticpp $
#include "LokiExport.h"

#if (defined(TEST_MAKE_DLL) && defined(TEST_DLL)) || \
    (defined(TEST_MAKE_DLL) && defined(TEST_STATIC)) || \
    (defined(TEST_DLL) && defined(TEST_STATIC))
#error export macro error: you could not build AND use the library
#endif

#ifdef TEST_MAKE_DLL
#define TEST_EXPORT LOKI_EXPORT_SPEC //__declspec(dllexport)
#endif

#ifdef TEST_DLL
#define TEST_EXPORT LOKI_IMPORT_SPEC //__declspec(dllimport)
#endif

#ifdef TEST_STATIC
#define TEST_EXPORT
#endif

#if !defined(TEST_EXPORT) && !defined(EXPLICIT_EXPORT)
#define TEST_EXPORT
#endif

#ifndef TEST_EXPORT
#error export macro error: TEST_EXPORT was not defined, disable EXPLICIT_EXPORT or define a export specification
#endif

#endif
