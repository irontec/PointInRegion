//
//  RegionObject.h
//  PointInRegion
//
//  Created by Iker Mendilibar Fernandez on 02/01/13.
//
//

#ifndef __TouchPolygon__RegionObject__
#define __TouchPolygon__RegionObject__

#include "cocos2d.h"

class RegionObject : public cocos2d::CCObject
{
public:
	cocos2d::CCArray *pathArray;
	cocos2d::CCArray *pointArray;
    int lineNum;
    
    RegionObject(cocos2d::CCArray *aPathArray);
    virtual ~RegionObject();
};

#endif /* defined(__TouchPolygon__RegionObject__) */
