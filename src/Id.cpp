
#include "Id.h"

namespace plnet
{
	Id::Id()
	{}

	Id::Id(byte_t* buf)
	{
		for (int i = 0; i < ID_BYTE_SIZE; i++) {
			data[i] = buf[i];
		}
	}

	bool Id::operator< (const Id& o)
	{
		for (int i = ID_BYTE_SIZE-1; i >= 0; i--) {
			if (data[i] < o.data[i]) {
				return true;
			}
		}
		return false;
	}

	Id Id::distance(const Id& o)
	{
		Id retval;
		for (int i = 0; i < ID_BYTE_SIZE; i++) {
			retval.data[i] = data[i] ^ o.data[i];
		}
		return retval;
	}

}