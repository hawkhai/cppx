#pragma once

//#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CFCOREADAPTER_LIB)
#  define CFCOREADAPTER_EXPORT __declspec(dllexport)
# else
#  define CFCOREADAPTER_EXPORT __declspec(dllimport)
# endif
#else
# define CFCOREADAPTER_EXPORT
#endif
