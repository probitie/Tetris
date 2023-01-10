#pragma once

#include <string.h>

// to make shorter names in debug log, (for Windows - \\, for linux/mac - /)
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

// dont forget to include <iostream>
// you can use it like this "debuglog("Hello " << user->name)"
#define debuglog(message) std::cout << __FILENAME__ << "::" << __LINE__ \
<< "::" << __FUNCTION__ << ":: " << message << std::endl


// DISCONNECTED LOGGER

// in .h
inline std::ostream devnull(0);

// in .cpp
#define debuglog(message) devnull<<message
