#ifndef _TIMINGS_HXX_
#define _TIMINGS_HXX_

#include <chrono>
#include <functional>

struct Timings
{
    static std::chrono::steady_clock::time_point Now ()
    {
        return std::chrono::steady_clock::now();
    }

    template <class Period, size_t Iterations = 1>
    static std::chrono::duration<double, Period> TimeSpan ( std::function<void()> func )
    {
        auto start = Now();
        for ( size_t i = 0; i < Iterations; ++i )
            func();
        auto end = Now();
        return std::chrono::duration<double, Period>( end - start );
    }
};

#endif