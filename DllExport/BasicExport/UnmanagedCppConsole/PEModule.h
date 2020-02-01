// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
// Distributed under the MIT License

#pragma once

namespace examples::dllexport::basicExport
{
    class PEModule
    {
    public:

        /* 
            TODO: the linker together with C++17 still can't 
            resolve external symbols at least for template when using variadic arguments 
            (e.g. typename...)
        */
        template<typename Tret, typename... TArgs>
        inline Tret call(LPCSTR lpProcName, TArgs... args)
        {
            typedef Tret(*vargs)(TArgs...);
            return ((vargs)getProc(lpProcName))(args...);
        }

        explicit PEModule(const TCHAR* pemodule);
        virtual ~PEModule();

    protected:

        FARPROC getProc(LPCSTR lpProcName);

    private:
        HMODULE lnk;
    };
}


