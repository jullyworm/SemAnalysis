#pragma once
#pragma comment(lib, "klan_core.lib")
#pragma comment(lib, "SV lib.lib")

#include <IWordBase.h>
#include "IKNWordShell.h"
#include "IKNParsedText.h"
#include <vector>
class CWordBase : public IWordBase
{
public:
	CWordBase(IKNWordShell* pWordShell, int ThemeCount, char* sPretext = 0);
	~CWordBase();
	// �������� ���������� ����� �������
	const char* GetWordNormalForm() const override;
	// ���������� ����������� ����������� ������������� ������� (��, ��� ������. � �.�.)
	int GetLexikalFeatureCount() const override;
	// ���������� ��� ���������� ����������� ��������������
	const char* GetLexikalFeatureName(int Index) const  override;
	// ���������� �������� ���������� ����������� ��������������
	const char* GetLexikalFeatureValue(int Index) const override;
	//-----------------------------------------------------------
	// ������� ���������� �������� ��� ���������� ����������
	// ���������� ����������� ������������� �������������
	int GetSemanticFeatureCount() const override;
	// ���������� ���������� ������������� ��������������
	const char* GetSemanticFeature(int Index) const override;
	// ���������� ����������� ����� ��������������� �������������
	int GetMorphFeatureGroupCount() const  override;
	// ���������� ����������� ��������������� �������������
	int GetMorphFeatureCount(int uGroupIndex) const override;
	// ���������� ��� ��������������� ��������������
	const char* GetMorphFeatureName(int uGroupIndex, int Index) const override;
	// ���������� �������� ��������������� ��������������
	const char* GetMorphFeatureValue(int uGroupIndex, int Index) const override;
	// ���������� ����� ����
	const char* GetPartOfSpeech() const override;
	// ���������� �������
	const char* GetPreText() const override;
	// ����� ��������
	const char* FindPretext() override;
	const char* GetForm() const override;
	static void SetParsedText( IKNParsedText* pParsedText);
	static void ClearWordVec();
	void SetPreText(char* sPretext);
	IKNWordShell* GetWordShell();
private:
	const char* m_sForm;
	IKNWord* m_pWord;
	IKNWordShell* m_pWordShell;
	char* m_Pretext;
	int m_ThemeCount;
	static IKNParsedText* m_pParsedText;
	static std::vector <IWordBase*> m_WordVec;
};


