#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CFCOREADAPTER_LIB)
#  define CFCOREADAPTER_EXPORT Q_DECL_EXPORT
# else
#  define CFCOREADAPTER_EXPORT Q_DECL_IMPORT
# endif
#else
# define CFCOREADAPTER_EXPORT
#endif
