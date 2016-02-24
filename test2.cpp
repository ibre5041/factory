
#include "Factory_alt.h"
#include "ABaseClass.h"

#include <iostream>
#include <dlfcn.h>

int main( int argc, const char* argv[] )
{
	void *handle = dlopen("./libSubClass1.so", RTLD_NOW | RTLD_GLOBAL);
	if( !handle)
	{
		std::cout << dlerror() << std::endl;
		return 1;
	}
	
	ABase *one = ABaseFactory::Instance().createPtr("SubClass1", 0);
	if( !one)
		return 2;
	
	one->doWork();

	return 0;	
}
