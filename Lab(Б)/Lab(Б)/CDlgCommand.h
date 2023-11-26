#ifndef CDLGCOMMAND_H
#define CDLGCOMMAND_H

#include <string>
#include "CWorkspace.h"

typedef void(*ptDlgCommandFunc)(CWorkspace& ws);

class CDlgCommand
{
public:
	CDlgCommand(const char* sName, ptDlgCommandFunc pFunc = nullptr);
	~CDlgCommand();

	const char* GetName() { return m_sName.c_str(); }
	void Run(CWorkspace& ws);

private:
	std::string m_sName;
	ptDlgCommandFunc m_pFunc;
};

#endif // CDLGCOMMAND_H
