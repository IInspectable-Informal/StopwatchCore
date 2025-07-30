#include "pch.h"
#include "Stopwatch.h"
#if __has_include("Stopwatch.g.cpp")
#include "Stopwatch.g.cpp"
#endif

using ns winrt;
using ns Windows::Foundation;
using ns std;
using ns std::chrono;

namespace winrt::StopwatchCore::implementation
{
    Stopwatch::Stopwatch()
    {

    }

    bool Stopwatch::Start()
    {
        if (_State == local::StopwatchState::Stopped)
        {
            _State = local::StopwatchState::Working;
            if (_Duration.count() == -1)
            {
                PausedTime = steady_clock::now();
            }
            _Action = std::thread(&Stopwatch::Looper, this);
            return true;
        } return false;
    }

    bool Stopwatch::Pause()
    {
        if (_State == local::StopwatchState::Working)
        {
            _State = local::StopwatchState::Paused;
            return true;
        }
        return false;
    }

    bool Stopwatch::Resume()
    {
        if (_State == local::StopwatchState::Paused)
        {
            _State = local::StopwatchState::Working;
            return true;
        }
        return false;
    }

    bool Stopwatch::Stop()
    {
        if (_State != local::StopwatchState::Stopped)
        {
            _State = local::StopwatchState::Stopped;
            _Action.join();
            return true;
        }
        return false;
    }

    bool Stopwatch::Reset()
    {
        if (_Duration.count() != -1)
        {
            Stop();
            _Duration = nanoseconds(-1);
            return true;
        }
        return false;
    }

    //Private
    void Stopwatch::Looper()
    {
        while (_State != local::StopwatchState::Stopped)
        {
            if (_State == local::StopwatchState::Working)
            {
                _Duration = steady_clock::now() - PausedTime;
                _Working(*this, nullptr);
            }
            else
            {
                PausedTime = steady_clock::now() - _Duration;
            }
            std::this_thread::sleep_for(_Interval);
        }
    }

    //Destructor
    Stopwatch::~Stopwatch()
    {
        Reset();
        _Working.clear();
    }
}
