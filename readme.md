# Saleae SPI Analyzer With CS Results Field

This project is a fork of Saleae's SimpleAnalyzer which copies the [SpiAnalyzer](http://downloads.saleae.com/betas/1.1.32/SaleaeAnalyzerSdk-1.1.32.zip) 
and adds the functionality of a new result field. This modified analyzer adds 
a Chip Select (CS) field to the result file which is used as a CS active delimiter. 
When CS goes active, a "1" is written to the first frame and a "0" is added to all 
subsiquent frames results for that active period. This added field is used to help 
with the reconstruction of an SPI command, since most write operations and read 
opperations are terminated by CS going to an inactive state.

# Build Instructions

To build on Windows, open the visual studio project in the Visual Studio folder, and build. The Visual Studio solution has configurations for 32 bit and 64 bit builds. You will likely need to switch the configuration to 64 bit and build that in order to get the analyzer to load in the Windows software.

To build on Linux or OSX, run the build_analyzer.py script. The compiled libraries can be found in the newly created debug and release folders.

	python build_analyzer.py

To debug on Windows, please first review the article here:

[How do I develop custom analyzers for the Logic software on Windows?](http://support.saleae.com/hc/en-us/articles/208666946)

On Windows, it is not possible to attach a debugger to the latest software. In order to debug custom analyzers on Windows, you need to use an older version of the Windows software.
Specifically, you will need the Saleae Logic 1.1.18 Windows 32 bit standalone release. You can find it here:

[Older Saleae Logic Beta Downloads](http://support.saleae.com/hc/en-us/articles/210245603)

You will also need the 1.1.14 SDK, the last SDK release to support software versions 1.1.14-1.1.18. That is available on a separate branch of the Saleae AnalyzerSDK Github repository. Simply change the submodule configuration to point to that branch, and the existing visual studio project will just work. Be sure to only compile for 32 bit, since the 1.1.14 SDK was released before Saleae began targeting 64 bit Windows. This is also why the 32 bit standalone version of the 1.1.18 software is required.
It's also worth noting that you should use a #define and #ifdef to remove the contents of your Analyzer's GenerateFrameTabularText methods, because the methods ClearTabularText and AddTabularText were not yet present in the 1.1.14 SDK.

