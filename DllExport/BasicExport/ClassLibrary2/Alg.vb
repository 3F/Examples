' This code is part of example that was prepared specially for https://github.com/3F/Examples
' Copyright (c) 2018  Denis Kuzmin < x-3F@outlook.com > GitHub/3F
' Distributed under the MIT License

Public Class Alg

    <DllExport>
    Public Shared Function SuperPow(ByVal x As Integer, ByVal y As Integer) As Double
        Return Math.Exp(Math.Log(x) * y)
    End Function

End Class
