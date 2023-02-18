#include "stdafx.h"
#include "Parm.h"

namespace Parm
{
	PARM getparm(int argc, _TCHAR* argv[])
	{
		bool rc = 0, rb = 0, rl = 0;
		PARM f;
		for (int l = 0; l < argc; l++)
		{
			if (wcsstr(argv[l], PARM_IN))	///Поиск подстроки "-in:"
			{
				rc = 1;
			}
			if (wcsstr(argv[l], PARM_OUT))
			{
				rb = 1;
			}
			if (wcsstr(argv[l], PARM_LOG))
			{
				rl = 1;
			}
		}
		if (rc == 0)
		{
			throw ERROR_THROW(100)		///Параметр -in должен быть задан
		}
		for (int i = 0; i < argc; i++)
		{
			if (wcslen(argv[i]) > PARM_MAX_SIZE)
				throw ERROR_THROW(104);		///Превышена длина входного параметра
			
			if (wcsstr(argv[i], PARM_IN))
			{
				wchar_t* h = wcsstr(argv[i], L":") + 1;
				wcscpy_s(f.in, h);
			}
			if (wcsstr(argv[i], PARM_OUT))
			{
				wchar_t* h = wcsstr(argv[i], L":") + 1;
				wcscpy_s(f.out, h);
			}
			if (wcsstr(argv[i], PARM_LOG))
			{
				wchar_t* h = wcsstr(argv[i], L":") + 1;
				wcscpy_s(f.log, h);
			}

		}
		if (rb == 0)
		{
			wcscpy_s(f.out, f.in);
			wcscat_s(f.out, PARM_OUT_DEFAULT_EXT);
		}
		if (rl == 0)
		{
			wcscpy_s(f.log, f.in);
			wcscat_s(f.log, PARM_LOG_DEFAULT_EXT);
		}
		return f;
	}
};