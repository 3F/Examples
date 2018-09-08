// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < entry.reg@gmail.com > :: github.com/3F
// Distributed under the MIT License

#include "pch.h"
#include "AlgVB.h"

namespace examples::dllexport::basicExport
{
    double AlgVB::superPow(int x, int y)
    {
        return call<double>("SuperPow", x, y);
    }
}