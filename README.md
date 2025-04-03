# StopwatchCore

## 简介

本项目是秒表的UWP版实现，使用C++/WinRT编写。

## 使用方法

转到[示例代码](https://github.com/IInspectable-Informal/StopwatchCore/tree/main/samples)，然后根据自己的项目主要编程语言选择查看。

## 编译

建议不要自己编译，直接用[Releases](https://github.com/IInspectable-Informal/StopwatchCore/releases)里提供的二进制文件，然后在自己的项目里添加引用即可。

如果确实需要，你可以下载源代码或用git克隆，然后用 Visual Studio 2022 打开，首先还原 nuget 包，然后按照自己的需要修改源代码，接着选择合适的体系架构编译即可。

## 注意事项

本项目只能在UWP应用中使用（和使用Windows.UI.Xaml.DispatcherTimer类实现有关，本人确实想不到更好的办法了，如果有意见，欢迎在[Issues](https://github.com/IInspectable-Informal/StopwatchCore/issues)和平讨论。
如果需要WinAppSDK版，可能需要过一段时间才会出（既然是桌面应用，各种Win32API都可以随意调用，还有好多第三方库都可以调用，为什么要等我呢）。
