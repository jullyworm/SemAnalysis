#ifndef SemanticVocLibrary_H
#define SemanticVocLibrary_H
//===================================================================
  #ifdef  __SemanticVocLibrary
	#define SemanticVocLibrary_API     __declspec(dllexport)
  #else
	#define SemanticVocLibrary_API     __declspec(dllimport)
  #endif

#include "ISVLManager.h"

extern "C" SemanticVocLibrary_API ISVLManager * CreateAPIManager();

#endif
