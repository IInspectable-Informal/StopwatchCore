#pragma once
//Windows
#include <unknwn.h>

//WinRT
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.UI.Xaml.h>

//Self
#include <winrt/StopwatchCore.h>

#define ns namespace

ns winrt
{ ns local = StopwatchCore; }