#pragma once

#include "ArgumentParser.hpp"
#include "Mode.hpp"

std::unique_ptr<Mode> createMode(const ArgumentParser& argParser);
