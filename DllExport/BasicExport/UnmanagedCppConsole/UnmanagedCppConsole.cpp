// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018,2020  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
// Distributed under the MIT License

#include "pch.h"
#include "PEModule.h"
#include "AlgVB.h"
#include "StdDevTool.h"
#include "LibraryException.h"

using namespace std;
using namespace examples::dllexport::basicExport;

// graph helper for illustration, keep scrolling to PEModule use ...
SHORT _tgraph(PEModule& lib, LPCSTR proc, COORD d = {0, 4})
{
    int r1      = 5,    r2      = (d.X > 0) ? 120 : 70;
    int ofsY    = r1 ,  ofsX    = 60 + d.X;
    int scale   = 1;

    StdDevTool sdt;
    const TCHAR* g1, *g2;
    if(d.X > 0) { g1 = _T("\\"); g2 = _T("/"); }else{ g1 = _T("#"); g2 = _T("*"); }

    COORD cursor = sdt.getCursor();
    for(int y = r1; y < r2; ++y)
    {
        double xi = lib.call<double>(proc, y, 24.781, 27.0);

        sdt.setCursor(0, cursor.Y++);
        printf_s("    \t(%d, 24.781, 27.0) == %e\n", y, xi);

        int ox = (int)(xi / scale) + ofsX;
        int oy = y + d.Y;

        sdt.write(g1, ox, oy - ofsY);
        sdt.write(g2, ox, oy);
    }
    sdt.setCursor(0, cursor.Y);

    return cursor.Y;
}

int main()
{
    cout << ".NET DllExport Examples : https://github.com/3F/Examples :\n";
    cout << "Unmanaged Native C++ and .NET Framework + .NET Core\n\n";

    try
    {
        // ################## .NET ClassLibrary1.dll (netfx; C#) #######################

        PEModule lib(_T("ClassLibrary1.dll"));
        cout << ".NET ClassLibrary1.dll (netfx; C#) is ready for requests:\n\n";        

        /* In the manner of Conari syntax: https://github.com/3F/Conari */

        double x1 = lib.call<double, int, double, double>("AmazingSin", 5, 0, 0);
        printf_s("  AmazingSin(5, 0, 0) == %e\n", x1);

        printf_s("    Is NaN(AmazingSin(5, 0, 0)): %s\n", (_isnan(x1) || !_finite(x1)) ? "yes" : "no");

        double x2 = lib.call<double>("AmazingSin", 5, 24.781, (double)11);
        printf_s("  AmazingSin(5, 24.781, 11) == %e\n", x2);
        
        printf_s("    Is NaN(AmazingSin(5, 24.781, 11)): %s\n", (_isnan(x2) || !_finite(x2)) ? "yes" : "no");

        _tgraph(lib, "AmazingSin");

        
        // ################## C++ Class wrapper of the .NET ClassLibrary2.dll (netfx; visual basic) ##########
        cout << endl;

        AlgVB vb(_T("ClassLibrary2.dll"));
        cout << "C++ Class wrapper of .NET ClassLibrary2.dll (netfx; visual basic) is ready:\n\n";

        printf_s("  AlgVB.superPow(2, 3) == %e\n", vb.superPow(2, 3));

        

        // ################## .NET Core DotNetCoreLibrary3.dll (netstandard2; C#) #######################
        cout << endl;

        PEModule libcore(_T("DotNetCoreLibrary3.dll"));
        cout << ".NET Core DotNetCoreLibrary3.dll (netstandard2; C#) is ready for requests  ~^~^~\n\n";

        printf_s("  AmazingCos(5, 24.781, 11) == %e\n", libcore.call<double>("AmazingCos", 5, 24.781, (double)11));

        _tgraph(libcore, "AmazingCos", { 28, 4});


        // ################## .NET Core ExtDotNetCoreLibrary4.dll (net9.0;net8.0;netstandard2.1; C#) ##########
        cout << endl << "ExtDotNetCoreLibrary4.dll:\n\n";

        PEModule libcor9(_T("net9.0\\ExtDotNetCoreLibrary4.dll"));
        printf_s("  .NET 9.0 -> AmazingCos(147, 32.412, 14) == %e\n", libcor9.call<double>("AmazingCos", 147, 32.412, (double)14));

        PEModule libcor8(_T("net8.0\\ExtDotNetCoreLibrary4.dll"));
        printf_s("  .NET 8.0 -> AmazingCos(231, 8, 62.308, 15) == %e\n", libcor8.call<double>("AmazingCos", 231, 62.308, (double)15));

        PEModule libstd21(_T("netstandard2.1\\ExtDotNetCoreLibrary4.dll"));
        printf_s("  .NET Standard 2.1 -> AmazingCos(904, 9, 4.201, 16) == %e\n", libstd21.call<double>("AmazingCos", 904, 4.201, (double)16));

        cout << endl << endl << endl << endl << endl;

    }
    catch(const LibraryException& ex)
    {
        fprintf_s(stderr, "Error: [ %d ] %s\n", ex.getError(), ex.what());
        return ERROR_INVALID_DATA;
    }
    catch(const exception& ex)
    {
        fprintf_s(stderr, "Error: %s\n", ex.what());
        return ERROR_INVALID_FUNCTION;
    }

    return ERROR_SUCCESS;
}

/*

.NET ClassLibrary1.dll (netfx; C#) is ready for requests:               #                   \
                                                                         #              \
  AmazingSin(5, 0, 0) == -nan(ind)                                       #            \
    Is NaN(AmazingSin(5, 0, 0)): yes                                    #          \
  AmazingSin(5, 24.781, 11) == 5.249363e+00                           #         \
    Is NaN(AmazingSin(5, 24.781, 11)): no                          #    *    \              /
        (5, 24.781, 27.0) == 1.288480e+01                       #        *  \           /
        (6, 24.781, 27.0) == 1.348346e+01                    #           * \          /
        (7, 24.781, 27.0) == 1.321995e+01                 #             *  \       /
        (8, 24.781, 27.0) == 1.211111e+01              #              *     \   /
        (9, 24.781, 27.0) == 1.022785e+01           #              *         /\
        (10, 24.781, 27.0) == 7.690583e+00        #             *           /   \
        (11, 24.781, 27.0) == 4.661560e+00      #            *             /       \
        (12, 24.781, 27.0) == 1.334461e+00     #          *                /           \
        (13, 24.781, 27.0) == -2.077966e+00    #       *                    /            \
        (14, 24.781, 27.0) == -5.357522e+00     #   *                         /             \
        (15, 24.781, 27.0) == -8.294501e+00      #*                             /              \
        (16, 24.781, 27.0) == -1.070110e+01     *   #                              /              \
        (17, 24.781, 27.0) == -1.242344e+01    *       #                               /            \
        (18, 24.781, 27.0) == -1.335139e+01    *          #                              /           \
        (19, 24.781, 27.0) == -1.342560e+01     *           #                               /        \
        (20, 24.781, 27.0) == -1.264134e+01      *              #                              /    \
        (21, 24.781, 27.0) == -1.104875e+01         *              #                              /\
        (22, 24.781, 27.0) == -8.749674e+00            *             #                           \  /
        (23, 24.781, 27.0) == -5.891111e+00               *            #                      \      /
        (24, 24.781, 27.0) == -2.655852e+00                 *            #                 \         /
        (25, 24.781, 27.0) == 7.492310e-01                      *        #              \           /
        (26, 24.781, 27.0) == 4.106406e+00                         *     #           \             /
        (27, 24.781, 27.0) == 7.201003e+00                           * #          \              /
        (28, 24.781, 27.0) == 9.835146e+00                           # *       \              /
        (29, 24.781, 27.0) == 1.184040e+01                         #     *   \             /
        (30, 24.781, 27.0) == 1.308854e+01                     #         *  \           /
        (31, 24.781, 27.0) == 1.349976e+01                  #            * \         /
        (32, 24.781, 27.0) == 1.304775e+01                #            *   \      /
        (33, 24.781, 27.0) == 1.176144e+01            #              *      \  /
        (34, 24.781, 27.0) == 9.723061e+00          #              *         /\
        (35, 24.781, 27.0) == 7.062958e+00       #             *            /    \
        (36, 24.781, 27.0) == 3.951228e+00      #           *              /        \
        (37, 24.781, 27.0) == 5.868432e-01     #          *                /           \
        (38, 24.781, 27.0) == -2.815066e+00    #      *                     /             \
        (39, 24.781, 27.0) == -6.036971e+00     #   *                         /              \
        (40, 24.781, 27.0) == -8.872853e+00      *#                              /              \
        (41, 24.781, 27.0) == -1.114138e+01     *   #                               /             \
        (42, 24.781, 27.0) == -1.269748e+01    *       #                               /            \
        (43, 24.781, 27.0) == -1.344168e+01    *           #                              /          \
        (44, 24.781, 27.0) == -1.332636e+01     *            #                               /       \
        (45, 24.781, 27.0) == -1.235892e+01       *             #                               /   \
        (46, 24.781, 27.0) == -1.060121e+01         *              #                              /\
        (47, 24.781, 27.0) == -8.165623e+00            *              #                         \   /
        (48, 24.781, 27.0) == -5.207901e+00                *            #                    \       /
        (49, 24.781, 27.0) == -1.917169e+00                  *           #                \          /
        (50, 24.781, 27.0) == 1.496152e+00                      *        #              \           /
        (51, 24.781, 27.0) == 4.813805e+00                         *    #           \              /
        (52, 24.781, 27.0) == 7.823648e+00                            *#         \              /
        (53, 24.781, 27.0) == 1.033322e+01                           #  *      \             /
        (54, 24.781, 27.0) == 1.218206e+01                        #      *   \            /
        (55, 24.781, 27.0) == 1.325193e+01                     #         * \            /
        (56, 24.781, 27.0) == 1.347444e+01                  #           *  \        /
        (57, 24.781, 27.0) == 1.283534e+01               #             *   \     /
        (58, 24.781, 27.0) == 1.137552e+01            #              *       \ /
        (59, 24.781, 27.0) == 9.188304e+00         #              *          / \
        (60, 24.781, 27.0) == 6.413562e+00       #             *           /      \
        (61, 24.781, 27.0) == 3.228716e+00      #           *              /         \
        (62, 24.781, 27.0) == -1.625840e-01    #         *                 /            \
        (63, 24.781, 27.0) == -3.543488e+00    #      *                      /            \
        (64, 24.781, 27.0) == -6.697810e+00        *                           /              \
        (65, 24.781, 27.0) == -9.423853e+00      *                                /             \
        (66, 24.781, 27.0) == -1.154731e+01     *                                    /             \
        (67, 24.781, 27.0) == -1.293239e+01    *                                        /           \
        (68, 24.781, 27.0) == -1.349053e+01    *                                          /          \
        (69, 24.781, 27.0) == -1.318604e+01                                                   /      \
                                                                                                /   \
C++ Class wrapper of .NET ClassLibrary2.dll (netfx; visual basic) is ready:                       \/
                                                                                                \   /
  AlgVB.superPow(2, 3) == 8.000000e+00                                                       \       /
                                                                                         \           /
.NET Core DotNetCoreLibrary3.dll (netstandard2; C#) is ready for requests  ~^~^~       \            /
                                                                                    \             /
  AmazingCos(5, 24.781, 11) == 1.641399e+00                                      \              /
        (5, 24.781, 27.0) == 4.028890e+00                                     \              /
        (6, 24.781, 27.0) == 6.680492e-01                                   \            /
        (7, 24.781, 27.0) == -2.735508e+00                                 \           /
        (8, 24.781, 27.0) == -5.964149e+00                                 \        /
        (9, 24.781, 27.0) == -8.811423e+00                                  \    /
        (10, 24.781, 27.0) == -1.109527e+01                                  \/
        (11, 24.781, 27.0) == -1.266964e+01                                 /  \
        (12, 24.781, 27.0) == -1.343388e+01                                /      \
        (13, 24.781, 27.0) == -1.333912e+01                                /         \
        (14, 24.781, 27.0) == -1.239141e+01                                 /           \
        (15, 24.781, 27.0) == -1.065135e+01                                  /             \
        (16, 24.781, 27.0) == -8.230211e+00                                    /              \
        (17, 24.781, 27.0) == -5.282807e+00                                       /              \
        (18, 24.781, 27.0) == -1.997604e+00                                          /             \
        (19, 24.781, 27.0) == 1.415333e+00                                              /           \
        (20, 24.781, 27.0) == 4.737768e+00                                                 /         \
        (21, 24.781, 27.0) == 7.757256e+00                                                    /      \
        (22, 24.781, 27.0) == 1.028072e+01                                                       /  \
        (23, 24.781, 27.0) == 1.214680e+01                                                        \/
        (24, 24.781, 27.0) == 1.323618e+01                                                     \    /
        (25, 24.781, 27.0) == 1.347919e+01                                                  \        /
        (26, 24.781, 27.0) == 1.286030e+01                                               \           /
        (27, 24.781, 27.0) == 1.141909e+01                                            \             /
        (28, 24.781, 27.0) == 9.247697e+00                                         \              /
        (29, 24.781, 27.0) == 6.484980e+00                                      \              /
        (30, 24.781, 27.0) == 3.307592e+00                                    \             /
        (31, 24.781, 27.0) == -8.129350e-02                                 \            /
        (32, 24.781, 27.0) == -3.464981e+00                                \          /
        (33, 24.781, 27.0) == -6.627106e+00                                \       /
        (34, 24.781, 27.0) == -9.365473e+00                                 \   /
        (35, 24.781, 27.0) == -1.150498e+01                                   \
        (36, 24.781, 27.0) == -1.290883e+01                                 /   \
        (37, 24.781, 27.0) == -1.348724e+01                                /       \
        (38, 24.781, 27.0) == -1.320323e+01                                /          \
        (39, 24.781, 27.0) == -1.207497e+01                                 /           \
        (40, 24.781, 27.0) == -1.017460e+01                                   /             \
        (41, 24.781, 27.0) == -7.623631e+00                                     /
        (42, 24.781, 27.0) == -4.585182e+00                                        /
        (43, 24.781, 27.0) == -1.253542e+00                                           /
        (44, 24.781, 27.0) == 2.158253e+00                                              /
        (45, 24.781, 27.0) == 5.432043e+00                                                  /
        (46, 24.781, 27.0) == 8.358491e+00
        ...

ExtDotNetCoreLibrary4.dll:

  .NET 9.0 -> AmazingCos(147, 32.412, 14) == -6.827972e+00
  .NET 8.0 -> AmazingCos(231, 8, 62.308, 15) == -1.984088e+00
  .NET Standard 2.1 -> AmazingCos(904, 9, 4.201, 16) == 3.091151e+00

*/