// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
// Distributed under the MIT License

#pragma once

#include "PEModule.h"

namespace examples::dllexport::basicExport
{
    class AlgVB: public PEModule
    {
    public:

        /* Wrapper of the exported `SuperPow()` function from .NET library */
        double superPow(int x, int y);

        AlgVB(const TCHAR* pemodule) : PEModule(pemodule) { }
    };
}