#include "PatternBuilder.h"

//-------------------------------------------------------------------------
pcCPU * BuilderDELL::buildCPU()
{
	pcCPU * cpu = new pcCPU;
	cpu->id = 1;
	cpu->name = "core i7 3700";
	return cpu;
}

pcGPU * BuilderDELL::buildGPU()
{
	pcGPU * gpu = new pcGPU;
	gpu->id = 1;
	gpu->name = "gtx 1080";
	return gpu;
}

pcKeyboard * BuilderDELL::buildKeyboard()
{
	pcKeyboard * keyboard = new pcKeyboard;
	keyboard->language = "jap";
	return keyboard;
}

pcRAM * BuilderDELL::buildRAM()
{
	pcRAM * ram = new pcRAM;
	ram->size = 4;
	return ram;
}

//-------------------------------------------------------------------------
pcCPU * BuilderASUS::buildCPU()
{
	pcCPU * cpu = new pcCPU;
	cpu->id = 1;
	cpu->name = "core i7 8700";
	return cpu;
}

pcGPU * BuilderASUS::buildGPU()
{
	pcGPU * gpu = new pcGPU;
	gpu->id = 1;
	gpu->name = "gtx 1080ti";
	return gpu;
}

pcKeyboard * BuilderASUS::buildKeyboard()
{
	pcKeyboard * keyboard = new pcKeyboard;
	keyboard->language = "eng";
	return keyboard;
}

pcRAM * BuilderASUS::buildRAM()
{
	pcRAM * ram = new pcRAM;
	ram->size = 32;
	return ram;
}

//-------------------------------------------------------------------------

void Director::setBuilder(Builder * b)
{
	this->builder = b;
}

pcDesktop * Director::getDesktopPC()
{
	pcDesktop * pc = new pcDesktop();

	pc->cpu = builder->buildCPU();
	pc->gpu = builder->buildGPU();
	pc->keyboard = builder->buildKeyboard();
	pc->ram = builder->buildRAM();

	return pc;
}