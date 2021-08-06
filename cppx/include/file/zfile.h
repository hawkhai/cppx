#ifndef __ZFILE_H__
#define __ZFILE_H__

#include <windows.h>
#include <atlstr.h>
#include <vector>

namespace zfile {

    BOOL GetCurrentModuleDir(CString& fdir);

    BOOL ListDir(const WCHAR* lpPath, std::vector<CString>& fileList);

    CString PathJoin(const WCHAR* rootdir, const WCHAR* xfile);
};

#endif
