// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
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