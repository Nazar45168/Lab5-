#ifndef DATACHAIN_H
#define DATACHAIN_H

#include <string>

class CDataChain
{
public:
	CDataChain();
	virtual ~CDataChain();
	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;
	size_t GetLength();
	int Find(const char* sSubStr, int nPos = 0);
	std::string GetSubStr(int nPos, int nLength = -1);
	const char* GetFullString();

protected:
	std::string m_sChain;
};

class CDataSimple : public CDataChain
{
public:
	CDataSimple();
	~CDataSimple();
	void Generate(int nDepth, int nMaxLength = 0);
};

#endif // DATACHAIN_H
