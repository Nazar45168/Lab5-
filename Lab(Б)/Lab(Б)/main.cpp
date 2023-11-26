#include <iostream>
#include "DataChain.h"
#include "CWorkspace.h"

int main()
{
	CDataSimple data;
	CWorkspace ws(data);

	// Ініціалізуємо послідовність у робочому просторі
	ws.Init(3, 5);

	// Виводимо послідовність
	std::cout << "Generated Data: " << ws.GetChainString() << std::endl;

	// Зберігаємо стан робочого простору у файл
	if (ws.Save("workspace.txt"))
	{
		std::cout << "Workspace saved to file." << std::endl;
	}
	else
	{
		std::cout << "Error saving workspace to file." << std::endl;
	}

	// Завантажуємо стан робочого простору із файлу
	if (ws.Load("workspace.txt"))
	{
		std::cout << "Workspace loaded from file." << std::endl;
		std::cout << "Loaded Data: " << ws.GetChainString() << std::endl;
	}
	else
	{
		std::cout << "Error loading workspace from file." << std::endl;
	}

	return 0;
}
