// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
// Distributed under the MIT License

#include "pch.h"
#include "LibraryException.h"

namespace examples::dllexport::basicExport
{
    DWORD LibraryException::getError() const
    {
        return error;
    }

    const char* LibraryException::what() const
    {
        DWORD sz = FormatMessageA(
            FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
            NULL,
            error,
            0,
            (LPSTR)&sysMsg,
            0,
            NULL
        );

        if (sz < 1) {
            return "Failed with system error: " + error;
        }
        return sysMsg;
    }

    LibraryException::~LibraryException()
    {
        LocalFree(sysMsg);
    }
}