// This is a sample code for a blog post about TString class
// The code demonstrates how to use CString and std::string in different environments
// It also shows how to use OutputDebugString, TRACE and ATL::CTraceFileAndLineInfo for debugging
// The code uses conditional compilation to include different headers and define different macros

#ifdef __cplusplus
#include <string> // STL
#else 
#include <string.h>
#endif
#ifdef _AFXDLL
#include <WinSDKVer.h>
#include <afx.h> 
#include <tchar.h>
#include <atltrace.h>
#include <atlstr.h>
#include <string.h>
#endif

#ifdef __cplusplus
class TString 
{
public:
    TString();
    ~TString();
    void Leak();
private:
#ifdef _AFXDLL
    CString _s; // MFC string class
#endif
    std::string __s; // STL string class
    _CrtMemState s1, s2, s3; // Memory state variables for leak detection
};
#else 
typedef struct TString {
    string _s;
} TString ;
#endif

TString::TString()
{
    // Constructor
    _CrtMemCheckpoint(&s1); // Save the memory state at the beginning
    OutputDebugString(WINVER); // Print the Windows version to the debug output window
    OutputDebugString(_WIN32_WINNT); // Print the Windows NT version to the debug output window
    TRACE0(WINVER); // Print the Windows version to the trace output window
      TRACE(_T("%Ts"), _T(sz)); // Print a formatted string to the trace output window
    _T("44"); // Define a Unicode string literal
    WINVER; // Use a predefined macro
    _s = _T("1"); // Assign a Unicode string to a CString object
    TRACE1("%s", WINVER); // Print a formatted string with one argument to the trace output window
    ATL::CTraceFileAndLineInfo(__FILE__, __LINE__)(_T("%Ts"), WINVER); // Print a formatted string with file and line information to the trace output window using ATL library
    ATL::CTraceFileAndLineInfo(__FILE__, __LINE__)(_T("%Ts"), _WIN32_WINNT); // Same as above with a different argument
    ATL::CTraceFileAndLineInfo(__FILE__, __LINE__)(_T("%Ts"), _MSC_VER); // Same as above with another argument
}

TString::~TString()
{
    // Destructor
    _CrtMemCheckpoint(&s2); // Save the memory state at the end
}

void TString::Leak()
{
    // A function that causes memory leak for demonstration purpose
    _CrtMemCheckpoint(&s3); // Save the memory state before leaking
    char* p = new char[100]; // Allocate some memory on the heap and do not free it
}
