#ifndef CWORKSPACE_H
#define CWORKSPACE_H

#include "DataChain.h"
#include <string>

class CWorkspace
{
public:
	CWorkspace(CDataChain& data);
	~CWorkspace();
	void Init(int nDepth, int nLength);
	const char* GetChainString();
	bool Save(const std::string& sFilepath);
	bool Load(const std::string& sFilepath);

private:
	CDataChain& m_refChain;
};

#endif // CWORKSPACE_H
