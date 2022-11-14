#pragma once

#ifndef _DLL_H_
#define _DLL_H_

#ifdef BRUHNIELIB_EXPORTS
#define BRUHNIELIB_API __declspec(dllexport)
#else
#define BRUHNIELIB_API __declspec(dllimport)
#endif

// printfInput
//
// This function gets an input from the user and then printf it back to him, unicode oriented.
BRUHNIELIB_API void printInput(void);
