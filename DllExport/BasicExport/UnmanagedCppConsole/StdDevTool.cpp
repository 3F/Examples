// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
// Distributed under the MIT License

#include "pch.h"
#include "StdDevTool.h"
#include "LibraryException.h"

namespace examples::dllexport::basicExport
{
    COORD StdDevTool::getCursor()
    {
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        if(!GetConsoleScreenBufferInfo(hstd, &csbi)) {
            throw LibraryException();
        }
        return csbi.dwCursorPosition;
    }

    void StdDevTool::setCursor(SHORT x, SHORT y)
    {
        if(x < 0 || y < 0)
        {
            COORD c0 = getCursor();

            if(x < 0) {
                x = c0.X;
            }

            if(y < 0) {
                y = c0.Y;
            }
        }

        COORD c = { x, y };
        SetConsoleCursorPosition(hstd, c);
    }

    void StdDevTool::write(const TCHAR* str, SHORT x, SHORT y)
    {
        setCursor(x, y);
        if(!WriteConsole(hstd, str, lstrlen(str), NULL, NULL)) {
            throw LibraryException();
        }
    }

    StdDevTool::StdDevTool(DWORD device)
    {
        hstd = GetStdHandle(device);

        if(hstd == INVALID_HANDLE_VALUE) {
            throw LibraryException();
        }

        if(hstd == NULL) {
            throw std::exception("An application does not have associated standard handle");
        }
    }

    StdDevTool::~StdDevTool()
    {

    }
}