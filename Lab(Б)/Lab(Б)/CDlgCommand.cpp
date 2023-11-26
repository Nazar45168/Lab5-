#include "CDlgCommand.h"

CDlgCommand::CDlgCommand(const char* sName, ptDlgCommandFunc pFunc)
	: m_sName(sName), m_pFunc(pFunc) {}

CDlgCommand::~CDlgCommand() {}

void CDlgCommand::Run(CWorkspace& ws)
{
	if (m_pFunc)
	{
		m_pFunc(ws);
	}
}
