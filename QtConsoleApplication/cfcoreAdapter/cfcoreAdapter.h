#pragma once

#include "cfcoreadapter_global.h"

class CFCOREADAPTER_EXPORT CfCoreApplication {
public:
    CfCoreApplication(int&, char**, int);
    static int __cdecl exec(void);
    ~CfCoreApplication(void);

private:
    class CfCoreApplicationImpl* cfp = nullptr;
};
