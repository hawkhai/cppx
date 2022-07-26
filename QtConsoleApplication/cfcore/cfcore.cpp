#include "pch.h"
#include "framework.h"
#include "cfcore.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\debug\\cfcoreAdapterd.lib")
#else
#pragma comment(lib, "..\\release\\cfcoreAdapter.lib")
#endif

QCoreApplication::QCoreApplication(int& a, char** b, int c) {
    cfp = new CfCoreApplication(a, b, c);
}

int QCoreApplication::exec(void) {
    return CfCoreApplication::exec();
}

QCoreApplication::~QCoreApplication(void) {
    if (cfp) {
        delete cfp;
        cfp = nullptr;
    }
}

void* QCoreApplication::qt_metacast(char const*) {
    return nullptr;
}
