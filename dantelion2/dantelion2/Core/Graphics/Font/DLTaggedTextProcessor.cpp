#include "DLTaggedTextProcessor.h"
#include <Call.h>

namespace DLGR
{
	DLTaggedTextProcessor::~DLTaggedTextProcessor()
	{
		CALL(Destructor_t, 0xf3d4f0, this);
	}
}