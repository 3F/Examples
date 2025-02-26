// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018,2020  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
// Distributed under the MIT License

using System;
using com.github._3F.DllExport;

namespace DotNetCoreLibrary3
{
    public class Alg
    {
        /// <summary>
        /// Amazing thing through cos ...
        /// cosine with a shift.
        /// </summary>
        /// <param name="ofs"></param>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns>possible #IND (indeterminate) –INF / +INF</returns>
        [DllExport]
        public static double AmazingCos(int ofs, double x, double y)
        {
            return y / 2 * Math.Cos(ofs * 2 * Math.PI / x);
        }
    }
}
