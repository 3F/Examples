// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
// Distributed under the MIT License

#include "pch.h"
#include "PEModule.h"
#include "LibraryException.h"

namespace examples::dllexport::basicExport
{
    PEModule::PEModule(const TCHAR* pemodule)
    {
        lnk = LoadLibraryEx(pemodule, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);

        if(lnk == NULL) {
            throw LibraryException();
        }
    }

    PEModule::~PEModule()
    {
        if(lnk != NULL) {
            FreeLibrary(lnk);
        }
    }

    FARPROC PEModule::getProc(LPCSTR lpProcName)
    {
        auto addr = GetProcAddress(lnk, lpProcName);
        if(addr == NULL) {
            throw LibraryException();
        }
        return addr;
    }
}