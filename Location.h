#ifndef LOCATION_H
#define LOCATION_H


class Location {
public:
   unsigned	int xCoord;
   unsigned	int yCoord;
   bool operator==(const Location& rhs) const;
   bool operator!=(const Location& rhs) const;
};

#endif // !LOCATION_H