
#include "SubClass1.h"

Util::RegisterInFactory<SubClass1, ABaseFactory> regSubClass1("SubClass1");

void SubClass1::doWork() const
{
	std::cout << "void SubClass1::doWork() const - working..." << std::endl;
}
