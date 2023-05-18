#include "command_decoder.h"
#include <string>
#include <cstdlib>

//--------------------------------- DEKODOWANIE KOMUNIKAT�W ----------------------------------

unsigned char ucTokenNr;										// LICZNIK TOKENOW
struct Token asToken[MAX_TOKEN_NR];								// TABLICA Z TOKENAMI
enum Result{OK, ERROR};

struct Keyword asKeywordList[MAX_KEYWORD_NR] = 
{
	{STEP, "step"},
	{ID, "id"},
	{GOTO, "goto"},
	{CALIB, "calib"}
};

unsigned char ucFindTokensInString(char *pcString)
{
    unsigned char ucTokenNumber = 0;
    const char delimiter = DELIMITER_CHAR;
    char * pcTokenStr = std::strtok(pcString, &delimiter);

    while(pcTokenStr != NULL  &&  ucTokenNumber < MAX_TOKEN_NR)
    {
        asToken[ucTokenNumber].uValue.pcString = pcTokenStr;
        ucTokenNumber++;
        pcTokenStr = std::strtok(NULL, &delimiter);
    }
	return ucTokenNumber;
}


enum Result eStringToKeyword (char pcStr[], enum KeywordCode *peKeywordCode)
{
	unsigned char ucKeywordCounter;
	
	for(ucKeywordCounter = 0; ucKeywordCounter < MAX_KEYWORD_NR; ucKeywordCounter++)
	{
		if(0 == std::strcmp(pcStr, asKeywordList[ucKeywordCounter].cString))
		{
			*peKeywordCode = asKeywordList[ucKeywordCounter].eCode;
			return OK;
		}
	}
	return ERROR;
}


void DecodeTokens(void)
{
	unsigned char ucTokenCounter;
	struct Token * psCurrentToken;
	unsigned int uiTokenValue;
	enum KeywordCode eTokenCode;
	
	for(ucTokenCounter = 0; ucTokenCounter < ucTokenNr; ucTokenCounter++)
	{
		psCurrentToken = &asToken[ucTokenCounter];
		
		if(OK == eStringToKeyword(psCurrentToken->uValue.pcString, &eTokenCode))
		{
			psCurrentToken->eType = KEYWORD;
			psCurrentToken->uValue.eKeyword = eTokenCode;
		}
		else if(uiTokenValue = std::strtoul(psCurrentToken->uValue.pcString, NULL, 16))
		{
			psCurrentToken->eType = NUMBER;
			psCurrentToken->uValue.uiNumber = uiTokenValue;
		}
		else
		{
			psCurrentToken->eType = STRING;
		}
	}
}


void DecodeMsg(char *pcString)
{
	ucTokenNr = ucFindTokensInString(pcString);
	DecodeTokens();
}
