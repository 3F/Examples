// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
// Distributed under the MIT License

#pragma once

namespace examples::dllexport::basicExport
{
    class StdDevTool
    {
    public:

        COORD getCursor();
        void setCursor(SHORT x = -1, SHORT y = -1);

        void write(const TCHAR* str, SHORT x = -1, SHORT y = -1);

        explicit StdDevTool(DWORD device = STD_OUTPUT_HANDLE);
        virtual ~StdDevTool();

    private:

        HANDLE hstd;
    };
}