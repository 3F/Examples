// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
// Distributed under the MIT License

#pragma once

namespace examples::dllexport::basicExport
{
    class LibraryException: public std::exception
    {
    public:

        explicit LibraryException()
            : error(GetLastError()), sysMsg(NULL) { }

        virtual ~LibraryException();

        DWORD getError() const;

        virtual const char* what() const;

    private:

        DWORD error;
        LPSTR sysMsg;

    };
}