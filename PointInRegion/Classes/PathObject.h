//
//  PathObject.h
//  PointInRegion
//
//  Created by Iker Mendilibar Fernandez on 02/01/13.
//
//

#ifndef __TouchPolygon__PathObject__
#define __TouchPolygon__PathObject__

#include "cocos2d.h"

class PathObject : public cocos2d::CCObject
{
public:
	cocos2d::CCPoint *startPosition;
	cocos2d::CCPoint *endPosition;
    
    PathObject(cocos2d::CCPoint astartPosition, cocos2d::CCPoint aendPosition);
    virtual ~PathObject();
};


#endif
