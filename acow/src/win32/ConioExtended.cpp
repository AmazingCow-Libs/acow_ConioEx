// Header
#include "include/ConioExtended.h"

#if (ACOW_OS_IS_WINDOWS || 1)

// Windows
#define WIN32_LEAN_AND_MEAN
#define _WINSOCKAPI_
#include <Windows.h>

// Usings 
using namespace acow;


//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
acow_internal_function bool 
TryGetConsoleScreenBufferInfo(CONSOLE_SCREEN_BUFFER_INFO *pCSBI) noexcept
{
    ACOW_ASSERT_NOT_NULL(pCSBI); 
    acow::Memory::Clear(*pCSBI);

    //--------------------------------------------------------------------------
    // Reference:
    //   https://docs.microsoft.com/en-us/windows/console/getconsolescreenbufferinfo           
    auto ret_val = GetConsoleScreenBufferInfo(
        GetStdHandle(STD_OUTPUT_HANDLE), 
        pCSBI
    );

    return (ret_val != 0);
}

//------------------------------------------------------------------------------
u16 
conio::ex::GetTerminalWidth() noexcept
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(TryGetConsoleScreenBufferInfo(&csbi)) { 
        return csbi.dwSize.X;
    } else {
        return 0;
    }
}

//------------------------------------------------------------------------------
u16 
conio::ex::GetTerminalHeight() noexcept
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(TryGetConsoleScreenBufferInfo(&csbi)) { 
        return csbi.dwSize.Y;
    } else {
        return 0;
    }
}

#endif // #if (ACOW_OS_IS_WINDOWS)