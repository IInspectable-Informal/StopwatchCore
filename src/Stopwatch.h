#pragma once

#include "Stopwatch.g.h"

namespace winrt::StopwatchCore::implementation
{
    typedef Windows::Foundation::TypedEventHandler<local::Stopwatch, Windows::Foundation::IInspectable> WorkingEventHandler;

    struct Stopwatch : StopwatchT<Stopwatch>
    {
    public:
        Stopwatch();

        double Duration()
        {
            return std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(_Duration).count();
        }

        void Interval(Windows::Foundation::TimeSpan const& interval)
        { _Interval = interval; }
        Windows::Foundation::TimeSpan Interval()
        { return _Interval; }

        local::StopwatchState State() { return _State; }

        bool Start();
        bool Pause();
        bool Resume();
        bool Stop();
        bool Reset();

        event_token Working(WorkingEventHandler const& handler)noexcept
        { return _Working.add(handler); }
        void Working(event_token const token)noexcept
        { _Working.remove(token); }

        ~Stopwatch();

    private:
        local::StopwatchState _State = local::StopwatchState::Stopped;
        Windows::Foundation::TimeSpan _Interval = std::chrono::milliseconds(95);
        std::chrono::steady_clock::time_point PausedTime;
        std::chrono::nanoseconds _Duration{ -1 };
        event<WorkingEventHandler> _Working;
        std::thread _Action;

        void Looper();
    };
}

namespace winrt::StopwatchCore::factory_implementation
{
    struct Stopwatch : StopwatchT<Stopwatch, implementation::Stopwatch>
    {
    };
}
