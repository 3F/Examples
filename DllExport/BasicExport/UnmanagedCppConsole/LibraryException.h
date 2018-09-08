// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < entry.reg@gmail.com > :: github.com/3F
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

        DWORD getError();

        virtual const char* what() const;

    private:

        DWORD error;
        LPSTR sysMsg;

    };
}