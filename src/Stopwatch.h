#pragma once
#include "pch.h"
#include "Stopwatch.g.h"

using ns winrt;
using ns Windows::Foundation;
using ns Windows::UI::Xaml;

using ns std;
using ns std::chrono;

ns winrt::StopwatchCore::implementation
{
    typedef TypedEventHandler<local::Stopwatch, IInspectable> WorkingEventHandler;

    struct Stopwatch : StopwatchT<Stopwatch>
    {
    public:
        Stopwatch();

        double Duration()
        { return duration_cast<duration<double, milli>>(_Duration).count(); }

        void Interval(TimeSpan const& interval)
        { Timer.Interval(interval); }
        TimeSpan Interval()
        { return Timer.Interval(); }

        bool Start();
        bool Pause();
        bool Resume();
        bool Stop();
        bool Reset();

        event_token Working(WorkingEventHandler const& handler)noexcept
        { return _Working.add(handler); }
        void Working(event_token const token)
        {  _Working.remove(token); }

        ~Stopwatch();

    private:
        bool IsRunning, IsWorking = false;
        DispatcherTimer Timer;
        steady_clock::time_point PausedTime;
        nanoseconds _Duration = nanoseconds(-1);
        event<WorkingEventHandler> _Working;
        event_token et;

        void Looper(IInspectable const&, IInspectable const&);
    };
}

ns winrt::StopwatchCore::factory_implementation
{
    struct Stopwatch : StopwatchT<Stopwatch, implementation::Stopwatch>
    {
    };
}
