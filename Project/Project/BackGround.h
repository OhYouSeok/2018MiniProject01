#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include <iostream>
#include <map>
class BackGround : public SDLGameObject
{
public:
	BackGround(const LoaderParams* pParams);
	virtual void draw();

private:
};