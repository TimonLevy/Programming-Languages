#pragma once

#ifndef BRUHNIEL_H
#define BRUHNIEL_H

#ifdef _EXPORTING
#define BRUHNIELIB_API __declspec( dllexport )
#else
#define BRUHNIELIB_API __declspec( dllimport )
#endif

// printfInput
//
// This function gets an input from the user and then printf it back to him, unicode oriented.
BRUHNIELIB_API void printInput(void);

//printWelcome
//
// This function prints "WELCOME DUDESSSSS\n".
BRUHNIELIB_API void printWelcome(void);

#endif