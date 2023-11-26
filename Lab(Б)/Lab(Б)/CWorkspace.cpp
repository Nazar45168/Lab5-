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
		return false; // ������� �������� ����� ��� ������
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
		return false; // ������� �������� ����� ��� �������
	}

	std::string loadedData;
	inFile >> loadedData;
	inFile.close();

	// ��������� ����������� � ��'��� CDataChain
	m_refChain.Generate(0); // ������� ������� �����������
	m_refChain.m_sChain = loadedData; // ����������� ������� �����������

	return true;
}
