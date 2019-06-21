#include "Configuration.h"
#include<iostream>

Configuration::Configuration()
{
}

Configuration::~Configuration()
{
}

void Configuration::Init(Platform * platform, GameStateManager *manager)
{
	std::cout << " Configuration Init" << std::endl;
}

void Configuration::Draw()
{
	std::cout << " Configuration Draw" << std::endl;
}

bool Configuration::Input(std::vector<int> *, std::vector<int> *)
{
	std::cout << " Configuration Input" << std::endl;
	return false;
}

void Configuration::Update()
{
	std::cout << " Configuration Update" << std::endl;
}

void Configuration::Close()
{
	std::cout << " Close Init" << std::endl;
}