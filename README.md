# dantelion2
Dantelion2 Class Library for Dark Souls II Scholar of the First Sin version 1.03.

To correctly compile and use this library without issues, you should download VisualStudio 2013 (2012 is recommended since the game uses toolset v110).
Custom containers such as DLUT::DLVector and DLTX::DLString rely on VS toolset <= v120.
It's possible to compile this library with newer toolsets, however doing so will have the game break upon deallocating a custom container due to the constructor and destructor not having access to the custom allocator.
