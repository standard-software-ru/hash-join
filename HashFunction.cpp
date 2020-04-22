#include "HashFunction.hpp"

int HashFunction::run(int value)
{
	return value % 10;
}
