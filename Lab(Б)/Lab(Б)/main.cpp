#include <iostream>
#include "DataChain.h"
#include "CWorkspace.h"
#include "CDlgCommand.h"
#include "CDialogManager.h"

void InitSequence(CWorkspace& ws)
{
	int depth, length;
	std::cout << "Enter depth: ";
	std::cin >> depth;
	std::cout << "Enter length: ";
	std::cin >> length;
	ws.Init(depth, length);
}

void ShowFullSequence(CWorkspace& ws)
{
	std::cout << "Generated Data: " << ws.GetChainString() << std::endl;
}

void SaveWorkspace(CWorkspace& ws)
{
	std::string filename;
	std::cout << "Enter filename to save: ";
	std::cin >> filename;
	if (ws.Save(filename))
	{
		std::cout << "Workspace saved to file." << std::endl;
	}
	else
	{
		std::cout << "Error saving workspace to file." << std::endl;
	}
}

void LoadWorkspace(CWorkspace& ws)
{
	std::string filename;
	std::cout << "Enter filename to load: ";
	std::cin >> filename;
	if (ws.Load(filename))
	{
		std::cout << "Workspace loaded from file." << std::endl;
	}
	else
	{
		std::cout << "Error loading workspace from file." << std::endl;
	}
}

int main()
{
	CDataSimple data;
	CWorkspace ws(data);
	CDialogManager mgr(ws);

	mgr.RegisterCommand("Init sequence", InitSequence);
	mgr.RegisterCommand("Show sequence", ShowFullSequence);
	mgr.RegisterCommand("Save", SaveWorkspace);
	mgr.RegisterCommand("Load", LoadWorkspace);

	mgr.Run();

	return 0;
}
