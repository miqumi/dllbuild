﻿#include "Client.h"

void Client::initialize()
{
    HooksManager = new class HooksManager();
    FrontendManager = new class FrontendManager();
    ModulesManager = new class ModulesManager();
}