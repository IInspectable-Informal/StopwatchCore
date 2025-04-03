#include "pch.h"
#include "Stopwatch.h"
#if __has_include("Stopwatch.g.cpp")
#include "Stopwatch.g.cpp"
#endif

namespace winrt::StopwatchCore::implementation
{
    Stopwatch::Stopwatch()
    {
        Timer.Interval(milliseconds(95));
        et = Timer.Tick({ this, &Stopwatch::Looper });
    }

    bool Stopwatch::Start()
    {
        if (!IsRunning && !IsWorking)
        {
            IsRunning = IsWorking = true;
            if (_Duration.count() == -1)
            { PausedTime = high_resolution_clock::now(); }
            Timer.Start();
            return true;
        } return false;
    }

    bool Stopwatch::Pause()
    {
        if (IsRunning && IsWorking)
        {
            IsWorking = false;
            return true;
        }
        return false;
    }

    bool Stopwatch::Resume()
    {
        if (IsRunning && !IsWorking)
        {
            IsWorking = true;
            return true;
        }
        return false;
    }

    bool Stopwatch::Stop()
    {
        if (IsRunning)
        {
            IsRunning = IsWorking = false;
            Timer.Stop();
            return true;
        }
        return false;
    }

    bool Stopwatch::Reset()
    {
        if (_Duration.count() != -1)
        {
            if (IsRunning) { Timer.Stop(); }
            IsRunning = IsWorking = false;
            _Duration = nanoseconds(-1);
            return true;
        }
        return false;
    }

    //Private
    void Stopwatch::Looper(IInspectable const&, IInspectable const&)
    {
        if (IsWorking)
        {
            _Duration = high_resolution_clock::now() - PausedTime;
            _Working(*this, nullptr);
        }
        else
        {
            PausedTime = high_resolution_clock::now() - _Duration;
        }
    }

    //Destructor
    Stopwatch::~Stopwatch()
    {
        Timer.Stop();
        Timer.Tick(et);
        _Working.clear();
    }
}
