#pragma once

#include "PLNet.h"

namespace plnet
{

#define ID_BYTE_SIZE 20

	class Id
	{
	public:
		Id();
		Id(byte_t*);

		bool operator< (const Id& o);
		Id distance(const Id& o);

		byte_t data[ID_BYTE_SIZE];
	};

	
}

