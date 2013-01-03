//
//  PathObject.cpp
//  PointInRegion
//
//  Created by Iker Mendilibar Fernandez on 02/01/13.
//
//

#include "PathObject.h"

USING_NS_CC;

PathObject::PathObject(CCPoint astartPosition, CCPoint aendPosition)
{
    startPosition = new CCPoint(astartPosition);
	endPosition = new CCPoint(aendPosition);
}

PathObject::~PathObject()
{
    CC_SAFE_DELETE(startPosition);
    CC_SAFE_DELETE(endPosition);
}

