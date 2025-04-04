﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x804 上介绍了“空白页”项模板

namespace SampleApp
{
    /// <summary>
    /// 可用于自身或导航至 Frame 内部的空白页。
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private StopwatchCore.Stopwatch Stopwatch = new StopwatchCore.Stopwatch();

        public MainPage()
        {
            this.InitializeComponent();
            Stopwatch.Working += ShowTime;
        }

        private void Start(object sender, RoutedEventArgs e)
        {
            Stopwatch.Start();
        }

        private void Pause(object sender, RoutedEventArgs e)
        {
            Stopwatch.Pause();
        }

        private void Resume(object sender, RoutedEventArgs e)
        {
            Stopwatch.Resume();
        }

        private void Stop(object sender, RoutedEventArgs e)
        {
            Stopwatch.Stop();
        }

        private void Reset(object sender, RoutedEventArgs e)
        {
            Stopwatch.Reset();
            timeshow.Text = "";
        }

        private void ShowTime(StopwatchCore.Stopwatch sender, object e)
        {
            timeshow.Text = TimeSpan.FromMilliseconds(sender.Duration).ToString();
        }
    }
}
