#ifndef __SUBCLASS1_H__
#define __SUBCLASS1_H__

#include "ABaseClass.h"

#include <iostream>

class SubClass1 : public ABase
{
public:
	SubClass1(unsigned int i) : ABase(i) {};
	
	virtual void doWork(void) const;
};

#endif
