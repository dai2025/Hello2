// Define a function to clean up the thread data and release it from TLS
void CleanupThreadData()
{
    // Get the thread data pointer from TLS
    PTHREADDATA pThreadData = (PTHREADDATA) TlsGetValue(dwTlsIndex);
    if (pThreadData != NULL)
    {
        // Free the GDI objects and device context created by the current thread
        DeleteObject(pThreadData->hbr);
        DeleteObject(pThreadData->hpen);
        ReleaseDC(NULL, pThreadData->hdc);

        // Deallocate the memory for the thread data structure
        HeapFree(GetProcessHeap(), 0, pThreadData);

        // Reset the TLS value to NULL
        TlsSetValue(dwTlsIndex, NULL);
    }
}

// Define a function to draw a line using the current thread's GDI objects
void DrawLine()
{
    // Get the thread data pointer from TLS
    PTHREADDATA pThreadData = (PTHREADDATA) TlsGetValue(dwTlsIndex);
    if (pThreadData != NULL)
    {
        // Use the brush and pen created by the current thread in the device context
        SelectObject(pThreadData->hdc, pThreadData->hbr);
        SelectObject(pThreadData->hdc, pThreadData->hpen);

        // Draw a line from the current coordinates to a random point
        MoveToEx(pThreadData->hdc, pThreadData->xPos, pThreadData->yPos, NULL);
        pThreadData->xPos = rand() % 300;
        pThreadData->yPos = rand() % 300;
        LineTo(pThreadData->hdc, pThreadData->xPos, pThreadData->yPos);
    }
}
