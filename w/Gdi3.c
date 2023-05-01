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
        // Handle memory allocation failure
        return;
    }

    // Obtain a device context for the entire screen
    pThreadData->hdc = GetDC(NULL);
    if (pThreadData->hdc == NULL)
    {
        // Handle device context acquisition failure
        HeapFree(GetProcessHeap(), 0, pThreadData);
        return;
    }

    // Create a random brush and pen for the current thread
    pThreadData->hbr = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
    pThreadData->hpen = CreatePen(PS_SOLID, 1, RGB(rand() % 256, rand() % 256, rand() % 256));
    if (pThreadData->hbr == NULL || pThreadData->hpen == NULL)
    {
        // Handle GDI object creation failure
        ReleaseDC(NULL, pThreadData->hdc);
        HeapFree(GetProcessHeap(), 0, pThreadData);
        return;
    }

    // Set the initial coordinates for drawing to a random position
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

        // Draw a line from the current coordinates to a random position
        MoveToEx(pThreadData->hdc, pThreadData->x, pThreadData->y, NULL);
        pThreadData->x = rand() % GetSystemMetrics(SM_CXSCREEN);
        pThreadData->y = rand() % GetSystemMetrics(SM_CYSCREEN);
        LineTo(pThreadData->hdc, pThreadData->x, pThreadData->y);
    }
}
