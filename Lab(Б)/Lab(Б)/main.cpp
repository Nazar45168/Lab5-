#include <iostream>
#include "DataChain.h"

int main()
{
	CDataSimple dataSimple;
	dataSimple.Generate(3, 5);

	std::cout << "Generated Data: " << dataSimple.GetFullString() << std::endl;
	std::cout << "Length: " << dataSimple.GetLength() << std::endl;
	std::cout << "Find '23' at position: " << dataSimple.Find("23") << std::endl;
	std::cout << "Substr from position 5: " << dataSimple.GetSubStr(5) << std::endl;

	return 0;
}
