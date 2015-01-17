#ifndef FILTER_H
#define FILTER_H

#include "Arduino.h"

class Filter
{
	public:
		Filter(long distanceCutoff);
		Filter();
		long filterDistance(long newDistance);
		void setDistanceCutoff(long newCutoff);
	
	private:
		long distanceCutoff;
		long distance;
		static const long distanceDev = 10;
};

#endif