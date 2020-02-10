#ifndef _HELPERS_
#define _HELPERS_

#include <string>
#include <vector>
#include "config.h"

extern bool file_exists(const std::string name);
extern void read_config(const std::string path, Config *config);

#endif 