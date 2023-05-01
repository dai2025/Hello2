#include <windows.h>
#include <process.h>

int main()
{

// Multiple Threads and GDI Objects
// In this blog post, I will show you how to write sample code that uses multiple threads and graphics device interface (GDI) objects in Windows.
// GDI objects are resources that allow applications to draw graphics on the screen, such as fonts, brushes, pens, bitmaps, etc.
// However, GDI objects are not thread-safe, which means they can cause problems if they are shared or accessed by multiple threads at the same time.
// For example, if one thread deletes a GDI object while another thread is using it, the results are unpredictable and may lead to crashes or memory leaks.
// Therefore, it is recommended to avoid sharing GDI objects among threads, or to use proper synchronization mechanisms if sharing is unavoidable or desirable.
// In this sample code, I will create two threads that each create and use their own GDI objects, without interfering with each other.
// I will also demonstrate how to use thread local storage (TLS) to store and retrieve GDI objects for each thread.

// Define a structure to hold the thread data
typedef struct _THREADDATA {
    HDC hdc; // handle to device context
    HBRUSH hbr; // handle to brush
    HPEN hpen; // handle to pen
    int x; // x coordinate of drawing
    int y; // y coordinate of drawing
} THREADDATA, *PTHREADDATA;

// Define a TLS index to store the thread data pointer
DWORD dwTlsIndex;

// Define a function to initialize the thread data and store it in TLS
void InitThreadData()
{
    // Allocate memory for the thread data structure
    PTHREADDATA pThreadData = (PTHREADDATA) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(THREADDATA));
    if (pThreadData == NULL)
    {
        // Handle allocation failure
        return;
    }

    // Get the current thread's device context
    pThreadData->hdc = GetDC(NULL);
    if (pThreadData->hdc == NULL)
    {
        // Handle device context failure
        return;
    }

    // Create a random brush and pen for the current thread
    pThreadData->hbr = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
    pThreadData->hpen = CreatePen(PS_SOLID, 1, RGB(rand() % 256, rand() % 256, rand() % 256));

    // Set the initial drawing coordinates for the current thread
    pThreadData->x = rand() % GetSystemMetrics(SM_CXSCREEN);
    pThreadData->y = rand() % GetSystemMetrics(SM_CYSCREEN);

    // Store the thread data pointer in TLS
    TlsSetValue(dwTlsIndex, pThreadData);
}

// Define a function to clean up the thread data and release it from TLS
void CleanupThreadData()
{
    // Retrieve the thread data pointer from TLS
    PTHREADDATA pThreadData = (PTHREADDATA) TlsGetValue(dwTlsIndex);
    if (pThreadData != NULL)
    {
        // Delete the brush and pen created by the current thread
        DeleteObject(pThreadData->hbr);
        DeleteObject(pThreadData->hpen);

        // Release the device context obtained by the current thread
        ReleaseDC(NULL, pThreadData->hdc);

        // Free the memory allocated for the thread data structure
        HeapFree(GetProcessHeap(), 0, pThreadData);

        // Set the TLS value to NULL
        TlsSetValue(dwTlsIndex, NULL);
    }
}

// Define a function to draw a line using the current thread's GDI objects
void DrawLine()
{
    // Retrieve the thread data pointer from TLS
    PTHREADDATA pThreadData = (PTHREADDATA) TlsGetValue(dwTlsIndex);
    if (pThreadData != NULL)
    {
        // Select the brush and pen created by the current thread into the device context
        SelectObject(pThreadData->hdc, pThreadData->hbr);
        SelectObject(pThreadData->hdc, pThreadData->hpen);

        // Draw a line from the current coordinates to a
