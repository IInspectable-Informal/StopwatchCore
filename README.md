# StopwatchCore

## 简介

本项目是秒表的WinRT版实现，使用C++/WinRT编写。
###### 更新：解除了对Windows.UI.Xaml.DispatcherTimer的依赖，意味着Win32应用也可以使用这个项目

## 使用方法

转到[示例代码](https://github.com/IInspectable-Informal/StopwatchCore/tree/main/samples)，然后根据自己的项目主要编程语言选择查看。

## 编译

建议不要自己编译，直接用[Releases](https://github.com/IInspectable-Informal/StopwatchCore/releases)里提供的二进制文件，然后在自己的项目里添加引用即可。

如果确实需要，你可以下载源代码或用git克隆，然后用 Visual Studio 2022 打开，首先还原 nuget 包，然后按照自己的需要修改源代码，接着选择合适的体系架构编译即可。

## 注意事项

若在UWP/WinAppSDK项目中使用，请注意：Stopwatch.Working事件由后台线程触发，如果要通过该事件操作UI控件，请切换到相应的UI线程进行操作！！！
