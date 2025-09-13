#pragma once

// --- C-SUPPORT HEADER ------------------------------------
#include <cstddef>
#include <cstdint>

// --- STL UTILITIES ---------------------------------------
#include <algorithm>
#include <chrono>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

// --- INPUT / OUTPUT --------------------------------------
#include <fstream>
#include <iostream>
#include <sstream>

// --- CONTAINERS ------------------------------------------
#include <array>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// --- PLATFORM RELATED ------------------------------------
#ifdef KRN_PLATFORM_WINDOWS

    #include <Windows.h>

#elif defined(KRN_PLATFORM_LINUX)

    #include <unistd.h>

#endif // KRN_PLATFORM_WINDOWS
