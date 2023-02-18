#include "SemAnaliz.h"
#include <map>

namespace Semantic {
    bool Parse(LexAnal::Lex lex, Log::LOG log)
    {
        bool answer = true;
        int j = 0;
        int d = 0;
        for (int i = 0; i < lex.lextab.size; i++)
        {
           
            switch (lex.lextab.table[i].lexema)
            {
            case LEX_ID:
                if (lex.idtab.table[lex.lextab.table[i].idxTI].idtype == IT::F && lex.lextab.table[i - 1].lexema != LEX_FUNCTION)
                {
                    j = i + 1;
                    int count = 0;
                    if (lex.lextab.table[i + 1].lexema != '(')
                    {
                        throw ERROR_THROW_IN(315, lex.lextab.table[i].sn, i);
                    }
                    while (lex.lextab.table[j].lexema != LEX_RIGHTHESIS) {
                        if (lex.lextab.table[j].lexema == LEX_ID || lex.lextab.table[j].lexema == 'l')
                        {
                            count++;
                        }
                        j++;
                    }
                    if (lex.idtab.table[lex.lextab.table[i].idxTI].params.count != count)
                    {
                        answer = false;
                        throw ERROR_THROW_IN(315, lex.lextab.table[i].sn, i);
                    }
                }
                if (lex.idtab.table[lex.lextab.table[i].idxTI].idtype == IT::F && lex.lextab.table[i - 1].lexema != LEX_FUNCTION)
                {
                    j = i + 1;
                    int count = 0;
                    while (lex.lextab.table[j].lexema != LEX_RIGHTHESIS) {
                        if (lex.lextab.table[j].lexema == LEX_ID || lex.lextab.table[j].lexema == 'l')
                        {
                            if (lex.idtab.table[lex.lextab.table[i].idxTI].params.type[count] != lex.idtab.table[lex.lextab.table[j].idxTI].iddatatype)
                            {
                                answer = false;
                                throw ERROR_THROW_IN(309, lex.lextab.table[i].sn, i);
                            }
                            count++;
                        }
                        j++;
                    }
                }
                break;
            case LEX_FUNCTION:
                
                j = i;
                d = i + 2;
                while (lex.lextab.table[j].lexema != LEX_RETURN)
                {
                    j++;
                }
                if (lex.idtab.table[lex.lextab.table[i + 1].idxTI].iddatatype != lex.idtab.table[lex.lextab.table[j + 1].idxTI].iddatatype)
                {
                    answer = false;
                    throw ERROR_THROW_IN(314, lex.lextab.table[j + 1].sn, j);
                }
                while (lex.lextab.table[d].lexema != LEX_RETURN) {
                    if (lex.lextab.table[d].lexema == LEX_ID)
                    {
                        if (strcmp(lex.idtab.table[lex.lextab.table[i + 1].idxTI].id,lex.idtab.table[lex.lextab.table[d].idxTI].id) == 0)
                        {
                            throw ERROR_THROW(320);
                        }
                    }
                    d++;
                }
                break;
            case LEX_RAV:
                j = i + 1;
                for (j; lex.lextab.table[j].lexema != LEX_SEMICOLON; j++)
                {
                    switch (lex.lextab.table[j].lexema)
                    {
                    case LEX_ID:
                    case LEX_LITERAL:
                        if (lex.idtab.table[lex.lextab.table[i - 1].idxTI].iddatatype == IT::STR ||
                            lex.idtab.table[lex.lextab.table[i - 1].idxTI].iddatatype == IT::BOOL) {
                            int b = i + 1;
                            while (lex.lextab.table[b].lexema != LEX_SEMICOLON)
                            {
                                if (lex.lextab.table[b].lexema == LEX_OPERATOR)
                                {
                                    throw ERROR_THROW_IN(310, lex.lextab.table[j].sn, j);
                                }
                                b++;
                            }
                        }
                        if ((lex.idtab.table[lex.lextab.table[j].idxTI].iddatatype !=
                            lex.idtab.table[lex.lextab.table[i - 1].idxTI].iddatatype))
                        {
                            answer = false;
                            throw ERROR_THROW_IN(312, lex.lextab.table[j].sn, j);
                        }
                        if (lex.lextab.table[j - 1].op == LT::ODIV && lex.idtab.table[lex.lextab.table[j].idxTI].value.vuint == 0 && 
                            lex.idtab.table[lex.lextab.table[j].idxTI].idtype == IT::L)
                        {
                            answer = false;
                            throw ERROR_THROW_IN(319, lex.lextab.table[j].sn, j);
                        }
                        continue;
                    case LEX_LEFTHESIS:
                        if (lex.lextab.table[j - 1].lexema == LEX_ID)
                        {
                            while (lex.lextab.table[j].lexema != LEX_RIGHTHESIS) {
                                j++;
                           }
                        }
                        continue;
                    }
                }
                continue;
            case LEX_CYCLE:
                
                j = i + 2;
                if (lex.idtab.table[lex.lextab.table[j].idxTI].iddatatype != IT::UINT)
                {
                    throw ERROR_THROW(311);
                }
                break;
            
          

            default:
                break;
            }
        }
        return answer;
    }
}