#pragma once
#include "Instance.h"
class Script : public Instance
{
public:
	Script();
	Script::~Script();
	void Script::run();
	std::string Source;
};