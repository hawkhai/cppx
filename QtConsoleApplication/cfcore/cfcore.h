#ifdef CFCORE_EXPORTS
#define CFCORE_API __declspec(dllexport)
#else
#define CFCORE_API __declspec(dllimport)
#endif

#include "../cfcoreAdapter/cfcoreAdapter.h"

class CFCORE_API QCoreApplication {
public:
    QCoreApplication(int&, char**, int);
    static int __cdecl exec(void);
    virtual __thiscall ~QCoreApplication(void);
    virtual void* __thiscall qt_metacast(char const*);
private:
    CfCoreApplication* cfp = nullptr;
};
