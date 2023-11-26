#ifndef CDIALOGMANAGER_H
#define CDIALOGMANAGER_H

#include "CDlgCommand.h"
#include <vector>

class CDialogManager
{
public:
	CDialogManager(CWorkspace& ws);
	~CDialogManager();

	void RegisterCommand(const char* sName, ptDlgCommandFunc pFunc);
	void Run();

private:
	std::vector<CDlgCommand*> m_aCommands;
	CWorkspace& m_refWorkspace;
};

#endif // CDIALOGMANAGER_H
