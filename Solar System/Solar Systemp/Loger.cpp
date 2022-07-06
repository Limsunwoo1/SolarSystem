#include "Loger.h"
#include "UtilLog.h"
#include <Windows.h>
#include <mutex>
std::mutex logMutex;

static bool WaitEndThread = true;
static bool RunLogThread = true;

CLoger::CLoger()
	: LogThread(nullptr)
{

}

CLoger::~CLoger()
{
	logMutex.lock();
	logMutex.unlock();
	ThreadPtr endThread = new Thread(ThreadEnd);
	if (endThread)
		endThread->join();


	if(LogThread)
		delete LogThread;

	if(endThread)
		delete endThread;

	LogThread = nullptr;
}

void CLoger::Init()
{
	LogThread = new Thread(CLoger::LogUpdate);

	if (LogThread)
		LogThread->detach();
}

void CLoger::AddLogMessage(const LogMessage& InLogMessage)
{
	logMutex.lock();

	LogStack.push(InLogMessage);

	logMutex.unlock();
}

LogMessage CLoger::PopLogMessage()
{
	logMutex.lock();

	LogMessage message = LogStack.front();
	LogStack.pop();

	logMutex.unlock();
	return message;
}

// LogUpdate 는 스태틱 함수기 때문에 멤버변수 바로 접근이 안된다
void CLoger::LogUpdate()
{
	while (RunLogThread)
	{
		if (LOG_STACK.size() == 0)
			continue;

		LogMessage message = LOGER->PopLogMessage();
		if (message.LogType == ELogType::Max)
			continue;

		String typeMessage = String(" [ ETC ] ");
		ELogColor logColorType = ELogColor::BLACK;
		if (message.LogType == ELogType::None)
		{
			typeMessage = String(" [ LOG ] ");
			logColorType = ELogColor::BLACK;
		}
		else if (message.LogType == ELogType::Warn)
		{
			typeMessage = String(" [ WARN ] ");
			logColorType = ELogColor::LIGHTRED;
		}
		else if (message.LogType == ELogType::Error)
		{
			typeMessage = String(" [ ERROR ] ");
			logColorType = ELogColor::RED;
		}
		else if (message.LogType == ELogType::Custom1)
		{
			logColorType = ELogColor::LIGHTBLUE;
		}
		else if (message.LogType == ELogType::Custom2)
		{
			logColorType = ELogColor::LIGHTGREEN;
		}
		else // ELogType::Custom3 || ELogType::Max
		{
			logColorType = ELogColor::LIGHTGRAY;
		}

		int logColor = (int)ELogColor::WHITE + (int)logColorType * 16;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), logColor);
		std::cout << message.FunctionName << "() :: line : " << message.LineNumber << typeMessage;
		std::cout << message.Message << "\n";
	}

	WaitEndThread = false;
	std::cout << "Log Thread End" << "\n";
}

void CLoger::ThreadEnd()
{
	RunLogThread = false;
	while (WaitEndThread)
	{
		std::cout << "WaitEndThread" << "\n";
	}
	std::cout << "ThreadEnd" << "\n";
}