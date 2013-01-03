//
//  RegionObject.cpp
//  PointInRegion
//
//  Created by Iker Mendilibar Fernandez on 02/01/13.
//
//

#include "RegionObject.h"
#include "PathObject.h"

USING_NS_CC;

RegionObject::RegionObject(CCArray *aPathArray)
{
    pathArray = CCArray::createWithCapacity(aPathArray->count());
    pathArray->retain();
    pathArray->addObjectsFromArray(aPathArray);
    
    pointArray = CCArray::create();
    pointArray->retain();
    
    PathObject *pObj = (PathObject*) aPathArray->objectAtIndex(0);
    pointArray->addObject(pObj->startPosition);
    pointArray->addObject(pObj->endPosition);
    
    lineNum = aPathArray->count();
    
    for (int i = 1; i < lineNum - 1; i++) {
        PathObject *pObjTmp = (PathObject*) aPathArray->objectAtIndex(i);
        pointArray->addObject(pObjTmp->endPosition);
    }  
}

RegionObject::~RegionObject()
{
    CC_SAFE_RELEASE(pathArray);
    CC_SAFE_RELEASE(pointArray);
}

