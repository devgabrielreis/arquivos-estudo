#pragma once

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILD_MY_DLL
#define SHARED_LIB __declspec(dllexport)
#else
#define SHARED_LIB __declspec(dllimport)
#endif

void SHARED_LIB dizer(std::string frase);

#ifdef __cplusplus
}
#endif
