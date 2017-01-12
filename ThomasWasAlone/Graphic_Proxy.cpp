#include "stdafx.h"

#include <iostream>

#include "Graphic.h"
#include "Graphic_Proxy.h"

using namespace std;

GraphicProxy::GraphicProxy()
{

}

GraphicProxy::~GraphicProxy()
{
	if (graphic)
		delete graphic;
}

Graphic * GraphicProxy::getInstance(void)
{
	if (!graphic)
		graphic = new Graphic();

	return graphic;
}

void GraphicProxy::Draw()
{
	getInstance()->Draw();
}