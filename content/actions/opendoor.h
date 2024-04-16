//
// Created by anova on 4/15/2024.
//

#pragma once

#include "action.h"

//forward declaration
class Door;

class OpenDoor : public Action{
    OpenDoor(Door& door);
};