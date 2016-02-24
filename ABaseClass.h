#ifndef __ABASECLASS_H__
#define __ABASECLASS_H__

#include "Factory_alt.h"
#include "test_export.h"

class ABase
{
public:
	ABase(unsigned int) {};
	virtual ~ABase() {};
	virtual void doWork() const = 0;
};

/** Declare datatype for finder factory */
TEST_EXPORT typedef Util::GenericFactory<ABase, LOKI_TYPELIST_1(unsigned int)> ABaseFact;
/** This singleton represents the only instance of the factory */
class TEST_EXPORT ABaseFactory : public Loki::SingletonHolder<ABaseFact> {};

#endif
