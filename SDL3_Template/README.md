Simple SDL3 template for Visual Studio 2022.

Properties Configuration (Both Debug and Release)

* Include all the needed folders and files of SDL3 (Located in "C:\GameDevLib\SDL3-devel-3.2.0-VC\SDL3-3.2.0" in my local PC. If the package is not located in that folder -or a different version needs to be used-, check SDL3 package files for visual studio README. Additionally, add SDL3.dll to the Path in System Environment Variables.
* In "Configuration Properties -> General -> General Properties -> C++ Languaje Standard" C++ 2020 is selected.
* In Configuration Properties -> General -> Advanced Properties -> Copy Content to OutDit" Yes is selected. This way if project assets are selected as "Included In project" and "Content", it will be copied in the Output folder when building.
* Default and Intermediate Directories were modified:
** Output Directory -> Output\$(Platform)\$(Configuration)\
** Intermediate Directory -> Intermediate\$(Platform)\$(Configuration)\
