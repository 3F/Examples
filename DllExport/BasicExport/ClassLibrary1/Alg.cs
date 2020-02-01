// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
// Distributed under the MIT License

using System;

namespace ClassLibrary1
{
    public class Alg
    {
        /// <summary>
        /// Power of ~love~ 2,718281828459...
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        [DllExport]
        public static double SuperPow(int x, int y)
        {
            return Math.Exp(Math.Log(x) * y);
        }

        /// <summary>
        /// Amazing thing through sin ...
        /// sinus with a shift.
        /// </summary>
        /// <param name="ofs"></param>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns>possible #IND (indeterminate) –INF / +INF</returns>
        [DllExport]
        public static double AmazingSin(int ofs, double x, double y)
        {
            return y / 2 * Math.Sin(ofs * 2 * Math.PI / x);
        }
    }
}
