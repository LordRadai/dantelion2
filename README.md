Dantelion2 Class Library for Dark Souls II Scholar of the First Sin version 1.03
To correctly compile and use this library without issues, you should download VisualStudio 2013.
Custom containers such as DLVector and DLString rely on VS toolset v120.
It is possible to compile this library with newer toolsets, however doing so will have the game break upon deallocating a custom container due to the constructor and destructor not having access to the custom allocator.