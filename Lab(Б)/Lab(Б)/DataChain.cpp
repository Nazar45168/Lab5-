#include "DataChain.h"

CDataChain::CDataChain() {}
CDataChain::~CDataChain() {}

size_t CDataChain::GetLength()
{
	return m_sChain.length();
}

int CDataChain::Find(const char* sSubStr, int nPos)
{
	size_t found = m_sChain.find(sSubStr, nPos);
	if (found != std::string::npos)
	{
		return static_cast<int>(found);
	}
	return -1;
}

std::string CDataChain::GetSubStr(int nPos, int nLength)
{
	if (nLength == -1)
	{
		return m_sChain.substr(nPos);
	}
	else
	{
		return m_sChain.substr(nPos, nLength);
	}
}

const char* CDataChain::GetFullString()
{
	return m_sChain.c_str();
}

CDataSimple::CDataSimple() {}
CDataSimple::~CDataSimple() {}

void CDataSimple::Generate(int nDepth, int nMaxLength)
{
	m_sChain.clear();
	for (int i = 0; i < nDepth; ++i)
	{
		for (int j = 0; j < nMaxLength; ++j)
		{
			m_sChain += std::to_string(i * nMaxLength + j);
		}
	}
}
