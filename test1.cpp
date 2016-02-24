
#include "Factory_alt.h"
#include "ABaseClass.h"

int main( int argc, const char* argv[] )
{
	ABase *one = ABaseFactory::Instance().createPtr("SubClass1", 0);
	if(one)
		one->doWork();

	return 0;
}
