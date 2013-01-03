#include "HelloWorldScene.h"
#include "PathObject.h"
#include "GeometryUtil.h"
#include "RegionObject.h"

USING_NS_CC;

HelloWorld::~HelloWorld()
{
    CC_SAFE_RELEASE(pathArray);
    CC_SAFE_DELETE(region);
}

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    this->setTouchEnabled(true);
    
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    PathObject *p01 = new PathObject(ccp(100, 50), ccp(240, 50));
    PathObject *p02 = new PathObject(ccp(240, 50), ccp(400, 200));
    PathObject *p03 = new PathObject(ccp(400, 200), ccp(200, 150));
    PathObject *p04 = new PathObject(ccp(200, 150), ccp(350, 280));
    PathObject *p05 = new PathObject(ccp(350, 280), ccp(150, 300));
    PathObject *p06 = new PathObject(ccp(150, 300), ccp(100, 50));
    
    pathArray = CCArray::create();
    pathArray->retain();
    
    pathArray->addObject(p01);
    pathArray->addObject(p02);
    pathArray->addObject(p03);
    pathArray->addObject(p04);
    pathArray->addObject(p05);
    pathArray->addObject(p06);
    
    region = new RegionObject(pathArray);
    
    //Add a label to show the position
    CCLabelTTF *label = CCLabelTTF::create("", "Verdana-BoldItalic", 15);
    label->setColor(ccWHITE);
    label->setTag(999);
    
    this->addChild(label);
    
    return true;
}

void HelloWorld::draw()
{
    glLineWidth( 1.0f );
    ccDrawColor4F(1.0f, 0.0f, 0.0f, 1.0f);
	for (int i = 0; i < pathArray->count(); i++) {
		PathObject *pO = (PathObject*) pathArray->objectAtIndex(i);
		ccDrawLine(*pO->startPosition, *pO->endPosition);
	}
}

void HelloWorld::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool HelloWorld::ccTouchBegan(CCTouch *touch, CCEvent *event)
{
    CCPoint touchLocation = touch->getLocation();
    
    char posString [50];
    sprintf (posString, "%0.1f - %0.1f", touchLocation.x, touchLocation.y);
    CCLabelTTF *label = (CCLabelTTF *)this->getChildByTag(999);
    label->setPosition(touchLocation);
    
    if (GeometryUtil::pointInRegion(touchLocation, region)) {
        label->setColor(ccGREEN);
    }
    else {
        label->setColor(ccRED);
    }
    
    label->setString(posString);
    
	return true;
}

void HelloWorld::ccTouchMoved(CCTouch *touch, CCEvent *event)
{
    CCPoint touchLocation = touch->getLocation();
    
    char posString [50];
    sprintf (posString, "%0.1f - %0.1f", touchLocation.x, touchLocation.y);
    CCLabelTTF *label = (CCLabelTTF *)this->getChildByTag(999);
    label->setPosition(touchLocation);
    
    if (GeometryUtil::pointInRegion(touchLocation, region)) {
        label->setColor(ccGREEN);
    }
    else {
        label->setColor(ccRED);
    }
    
    label->setString(posString);
}

void HelloWorld::ccTouchEnded(CCTouch *touch, CCEvent *event)
{
	CCLabelTTF *label = (CCLabelTTF *)this->getChildByTag(999);
	label->setString("");
}

