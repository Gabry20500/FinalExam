#ifndef DLL_H
#define DLL_H

#ifdef DllExport
#define DECLSPEC __declspec(dllexport)
#else 
#define DECLSPEC __declspec(dllimport)
#endif


#endif // !DLL_H