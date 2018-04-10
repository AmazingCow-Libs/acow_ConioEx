#pragma once

// AmazingCow Libs
#include "acow/cpp_goodies.h"
// acow_ConioEx
#include "Conio.h"


namespace acow { namespace conio { namespace ex { 
    
u16 GetTerminalWidth () noexcept;
u16 GetTerminalHeight() noexcept;

} // namespace ex
} // namespace conio
} // namespace acow