#ifndef HMAPPCONFIG_GLOBAL_H
#define HMAPPCONFIG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HMAPPCONFIG_LIBRARY)
#  define HMAPPCONFIG_EXPORT Q_DECL_EXPORT
#else
#  define HMAPPCONFIG_EXPORT Q_DECL_IMPORT
#endif

#endif // HMAPPCONFIG_GLOBAL_H
