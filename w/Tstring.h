// This is a blog post about how to use TString class in C++ and C
// The TString class is a wrapper for std::string and CString that can be used in both C++ and C code
// The class has a constructor, a destructor, and a method called Leak that simulates a memory leak
// The class also uses some macros and functions to output debug information

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
    CString _s;
#endif
    std::string __s;
    _CrtMemState s1, s2, s3;
};
#else 
typedef struct TString {
    string _s;
} TString ;
#endif

TString::TString()
{
    // Check the memory state before creating the object
    _CrtMemCheckpoint(&s1);
    // Output some information about the Windows version and compiler version
    OutputDebugString(WINVER);
    OutputDebugString(_WIN32_WINNT);
    TRACE0(WINVER);
    TRACE(_T("%Ts"), _T(sz));
    _T("44");
    WINVER;
    // Initialize the string members with some values
    _s = _T("1");
    __s = "1";
    // Output the string values using different formats
    TRACE1("%s", WINVER);
    ATL::CTraceFileAndLineInfo(__FILE__, __LINE__)(_T("%Ts"), WINVER);
    ATL::CTraceFileAndLineInfo(__FILE__, __LINE__)(_T("%Ts"), _WIN32_WINNT);
    ATL::CTraceFileAndLineInfo(__FILE__, __LINE__)(_T("%Ts"), _MSC_VER);
}

TString::~TString()
{
    // Check the memory state after destroying the object
    _CrtMemCheckpoint(&s2);
}

void TString::Leak()
{
    // Simulate a memory leak by creating a new string and not deleting it
    std::string* s = new std::string("leak");
}

int main()
{
    // Create a TString object and call its methods
    TString t;
    t.Leak();
    
#ifdef __cplusplus
    // Use std::move to transfer ownership of a string to another variable
    std::string s="1";
    std::string s2 = std::move(s);
    
    // Check if the original string is empty after moving
    if (s.empty())
        printf("s is empty\n");
    
    // Try to assign a null pointer to a string and see what happens
    try {
        s = nullptr;
    }
    catch (std::exception& e) {
        printf("Exception: %s\n", e.what());
    }
#endif
    
}
