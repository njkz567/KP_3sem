#include "load.h"
#include "fun.h"
#include <stdio.h>

#ifdef _WIN32

#include <windows.h>

#elif __linux__

#include <dlfcn.h>

#endif // __linux__

void LoadRun(const char * const s) // ����������� ��������� �� ����������� ��������
{
    void *lib;
    void (*fun)(void);

//�������� ���������� � ������;
#ifdef _WIN32
    lib = LoadLibrary(s);
#elif __linux__
    lib = dlopen(s, RTLD_LAZY);
#endif

    if (!lib)
    {
        printf("cannot open library '%s'\n", s);
        return;
    }

//��������� ��������� �� ������� �� ����������
#ifdef _WIN32
    fun = (void (*)(void))GetProcAddress((HINSTANCE)lib, "change_sign");
#elif __linux__
    fun = (void (*)(void))dlsym(lib, "change_sign");
#endif

    if (fun == NULL)
    {
        printf("cannot load function change_sign\n");
    }
    else
    {
        fun();
    }

//�������� ����������;
#ifdef _WIN32
    FreeLibrary((HINSTANCE)lib);
#elif __linux__
    dlclose(lib);
#endif
}
