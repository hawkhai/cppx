#include "cfcoreAdapter.h"
#include <QtCore/QCoreApplication>
#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        LoadLibrary(L"E:\\kpdf\\qt\\5.15.0_windows_x86\\bin\\Qt5Cored.dll");
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

class CfCoreApplicationImpl {
public:
    QCoreApplication* p = nullptr;
};

CfCoreApplication::CfCoreApplication(int& a, char** b, int c) {
    cfp = new CfCoreApplicationImpl();
    cfp->p = new QCoreApplication(a, b, c);
}

int CfCoreApplication::exec(void) {
    return QCoreApplication::exec();
}

CfCoreApplication::~CfCoreApplication(void) {
    if (cfp) {
        if (cfp->p) {
            delete cfp->p;
            cfp->p = nullptr;
        }
        delete cfp;
        cfp = nullptr;
    }
}