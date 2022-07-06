#pragma once
#include "Define.h"
#include "Typedef.h"
#include <iostream>
#include <thread>
#include <queue>

enum class ELogType {
	None,		// �Ϲ����� ��Ȳ�� ����ϴ� �α�			( �߿䵵 ���� )
	Warn,		// ��� ��Ȳ�� ����ϴ� �α�				( �߿䵵 �߰� )
	Error,		// ���� ��Ȳ�� ����ϴ� �α�				( �߿䵵 ����, ġ������ ��Ȳ )
	Custom1,	// ���� �߿� Ư���ϰ� Ȯ���� �ʿ��� �α�1	( �߿䵵 ���� )
	Custom2,	// ���� �߿� Ư���ϰ� Ȯ���� �ʿ��� �α�2	( �߿䵵 ���� )
	Custom3,	// ���� �߿� Ư���ϰ� Ȯ���� �ʿ��� �α�3	( �߿䵵 ���� )
	Max,
};

enum class ELogColor {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGRAY = 7,
	DARKGRAY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15,
};

class LogMessage {
public:
	ELogType	LogType;
	String		FunctionName;
	int			LineNumber;
	String		Message;

public:
	LogMessage() : LogType(ELogType::Max), FunctionName(), LineNumber(0), Message() {}
	LogMessage(ELogType InType, String InFunction, int InLineNumber, String InMessage) 
		: LogType(InType), FunctionName(InFunction), LineNumber(InLineNumber), Message(InMessage) {}
	~LogMessage() {}
};

class CLoger
{
	SINGLE(CLoger);

private:
	typedef std::thread				Thread;
	typedef std::thread*			ThreadPtr;
	typedef std::queue<LogMessage>	FLogStack;

private:
	ThreadPtr	LogThread;
	FLogStack	LogStack;

public:
	void Init();

	void AddLogMessage(const LogMessage& InLogMessage);
	LogMessage PopLogMessage();

	const FLogStack& GetLogStack() const { return LogStack; }

	static void LogUpdate();
	static void ThreadEnd();
};
