#include "CGResource.h"
#include "Call.h"

namespace DLCG2
{
	CGResource::~CGResource()
	{
		CALL(Destructor_t, 0xf330d0, this);
	}
}