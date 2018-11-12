#include "Location.h"

bool Location::operator==(const Location& rhs) const{
	return this->xCoord == rhs.xCoord&&this->yCoord == rhs.yCoord;
}

bool Location::operator!=(const Location& rhs) const{
	return this->xCoord != rhs.xCoord||this->yCoord != rhs.yCoord;
}