// Compile for 64-bit: x86_64-w64-mingw32-gcc -shared -o /dev/shm/legit.dll win_dll.c
// Compile for 32-bit: i686-w64-mingw32-gcc -shared -o /dev/shm/legit32.dll win_dll.c

// Run exported function: rundll32.exe \\host\share\legit.dll,test
// * DllMain runs first, when DLL is loaded.
// * The name after the comma is the name of the exported function to run

#include <windows.h>

BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved )  {
    // Perform actions based on the reason for calling.
    switch( fdwReason )   { 
        case DLL_PROCESS_ATTACH:
            // Initialize once for each new process.
            // Return FALSE to fail DLL load.

            MessageBoxA(NULL,"DllMain","DllMain",0);

            break;

        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
         // Perform any necessary cleanup.
            break;
    }

    return TRUE;  // Successful DLL_PROCESS_ATTACH.

}

extern __declspec (dllexport) BOOL test(){
    MessageBoxA(NULL,"test?","test!",0);
    return TRUE;
}