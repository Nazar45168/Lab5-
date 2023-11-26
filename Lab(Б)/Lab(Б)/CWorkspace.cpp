#include "CWorkspace.h"
#include <fstream>

CWorkspace::CWorkspace(CDataChain& data) : m_refChain(data) {}

CWorkspace::~CWorkspace() {}

void CWorkspace::Init(int nDepth, int nLength)
{
	m_refChain.Generate(nDepth, nLength);
}

const char* CWorkspace::GetChainString()
{
	return m_refChain.GetFullString();
}

bool CWorkspace::Save(const std::string& sFilepath)
{
	std::ofstream outFile(sFilepath);
	if (!outFile.is_open())
	{
		return false; // Помилка відкриття файлу для запису
	}

	const char* chainString = m_refChain.GetFullString();
	outFile << chainString;
	outFile.close();
	return true;
}

bool CWorkspace::Load(const std::string& sFilepath)
{
	std::ifstream inFile(sFilepath);
	if (!inFile.is_open())
	{
		return false; // Помилка відкриття файлу для читання
	}

	std::string loadedData;
	inFile >> loadedData;
	inFile.close();

	// Оновлюємо послідовність в об'єкті CDataChain
	m_refChain.Generate(0); // Очищаємо існуючу послідовність
	m_refChain.m_sChain = loadedData; // Завантажуємо зчитану послідовність

	return true;
}
