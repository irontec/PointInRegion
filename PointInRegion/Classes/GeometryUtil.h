//
//  GeometryUtil.h
//  PointInRegion
//
//  Created by Iker Mendilibar Fernandez on 02/01/13.
//
//

#ifndef __TouchPolygon__GeometryUtil__
#define __TouchPolygon__GeometryUtil__

#include "cocos2d.h"
#include "RegionObject.h"

USING_NS_CC;

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

class GeometryUtil : public CCObject
{   
public:
	static bool pointInRegion(CCPoint pt, RegionObject *rObj)
    {
        int nCross = 0;
        
        for (int i = 0; i < rObj->pointArray->count(); i++) {
            
            CCPoint *p1;
            CCPoint *p2;
            
            p1 = (CCPoint*) rObj->pointArray->objectAtIndex(i);
            p2 = (CCPoint*) rObj->pointArray->objectAtIndex((i + 1) % rObj->pointArray->count());
            
            
            if ( p1->y == p2->y )
                continue;
            
            if ( pt.y < min(p1->y, p2->y))
                continue;
            
            if ( pt.y >= max(p1->y, p2->y))
                continue;
            
            double x = (double)(pt.y - p1->y) * (double)(p2->x - p1->x) / (double)(p2->y - p1->y) + p1->x;
            
            if ( x > pt.x )
                nCross++;
        }
        
        if (nCross % 2 == 1) {
            
            return true;
        }
        else {
            
            return false;
        }
    }
};

#endif /* defined(__TouchPolygon__GeometryUtil__) */
