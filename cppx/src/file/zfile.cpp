#include <windows.h>
#include <stdio.h>
#include "file/zfile.h"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

extern "C" IMAGE_DOS_HEADER __ImageBase;

namespace zfile {

    BOOL GetCurrentModuleDir(CString& fdir) {

        TCHAR szFull[_MAX_PATH] = { 0 };
        if (!GetModuleFileName((HMODULE)&__ImageBase, szFull, _MAX_PATH)) {
            return FALSE;
        }

        CString temp = szFull;
        int pos = temp.ReverseFind(L'\\');
        if (pos <= 0) {
            return FALSE;
        }
        fdir = temp.Left(pos);
        return TRUE;
    }

    CString PathJoin(const WCHAR* rootdir, const WCHAR* xfile) {
        if (rootdir == NULL || xfile == NULL) {
            return L"";
        }
        CString value = rootdir;
        if (value.Right(1) == L"\\") {
            value.Append(xfile);
        }
        else {
            value.AppendChar(L'\\');
            value.Append(xfile);
        }
        return value;
    }

    BOOL ListDir(const WCHAR* lpPath, std::vector<CString>& fileList) {

        WCHAR szFind[MAX_PATH];
        wcscpy(szFind, lpPath);
        wcscat(szFind, L"\\*.*");

        WIN32_FIND_DATA findFileData;
        HANDLE hFind = ::FindFirstFile(szFind, &findFileData);
        if (INVALID_HANDLE_VALUE == hFind)
            return FALSE;

        while (TRUE)
        {
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if (findFileData.cFileName[0] != '.')
                {
                    TCHAR szFile[MAX_PATH];
                    wcscpy(szFile, lpPath);
                    wcscat(szFile, L"\\");
                    wcscat(szFile, findFileData.cFileName);
                }
            }
            else
            {
                fileList.push_back(findFileData.cFileName);
            }
            if (!FindNextFile(hFind, &findFileData))
                break;
        }
        FindClose(hFind);
        return TRUE;
    }

};
