#include "stdafx.h"
#include "Polish.h"

int _tmain(int argc, _TCHAR* argv[])
{

	setlocale(LC_ALL, "RU");
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		
		LexAnal::Lex lex = LexAnal::LexAnaliz(parm, in);
		cout << "����������� ������ �������� �������\n";
		Log::WriteLexTableLog(lex.lextab, *log.stream);

		MFST::SyntaxCheck(lex, log, *log.stream);
		cout << "�������������� ������ �������� �������\n";
		
		Semantic::Parse(lex, log);
		cout << "������������� ������ �������� �������\n";
		
		Polish::startPolish(lex);
		LexAnal::Synchronization(lex);
		
		Log::WriteLexTableLog(lex.lextab, *log.stream);
		IT::ShowTable(lex.idtab, *log.stream);
		LT::ShowTable(lex.lextab, *log.stream);
		
		Gen::Generator Gener(lex.lextab, lex.idtab, "D:\\����2\\��������\\NRV-2022\\ASM\\asm.asm");
		cout << "��������� ���� ��������� �������\n\n";
		Log::Close(log);
		
	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << "\nC�����: " << e.inext.line << "\n�������: " << e.inext.col << endl;
		Log::WriteError(log, e);
	};
	

	system("pause");
	return 0;
}