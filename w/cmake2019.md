
- cl.exe is a command-line tool that compiles C and C++ source files
- cmake.exe is a cross-platform tool that generates build files for various compilers
- To use cl.exe with cmake.exe, you need to set the CMAKE_C_COMPILER and CMAKE_CXX_COMPILER variables to point to the cl.exe executable
- You can also use the Visual Studio generator option (-G "Visual Studio") to create a Visual Studio solution file that uses cl.exe
- Alternatively, you can use the Ninja generator option (-G "Ninja") to create a Ninja build file that invokes cl.exe


In this blog post, I will show you how to use cl.exe and cmake.exe together to build C and C++ projects on Windows. cl.exe is a command-line tool that compiles C and C++ source files into executable binaries, libraries, or DLLs. cmake.exe is a cross-platform tool that generates build files for various compilers, including cl.exe.

To use cl.exe with cmake.exe, you need to set the CMAKE_C_COMPILER and CMAKE_CXX_COMPILER variables to point to the cl.exe executable. You can do this by passing them as arguments to cmake.exe, for example:

cmake -DCMAKE_C_COMPILER="C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64\cl.exe" -DCMAKE_CXX_COMPILER="C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64\cl.exe" ..

Alternatively, you can set these variables in your CMakePresets.json file, which allows you to configure and build your project with CMake Presets in Visual Studio.

You can also use the Visual Studio generator option (-G "Visual Studio") to create a Visual Studio solution file that uses cl.exe as the compiler. For example:

cmake -G "Visual Studio 16 2019" ..

This will generate a .sln file and a .vcxproj file for each target in your project. You can then open the solution file in Visual Studio and build it from there.

Alternatively, you can use the Ninja generator option (-G "Ninja") to create a Ninja build file that invokes cl.exe as the compiler. For example:

cmake -G "Ninja" ..

This will generate a build.ninja file that contains all the commands to build your project. You can then run ninja from the command line to build it.

I hope this blog post has helped you understand how to use cl.exe and cmake.exe together to build C and C++ projects on Windows. If you have any questions or feedback, please leave a comment below.
