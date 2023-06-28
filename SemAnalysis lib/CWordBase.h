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
	// Получить нормальную форму лексемы
	const char* GetWordNormalForm() const override;
	// Возвращает колличество лексических характеристик лексемы (ЧР, имя собств. и т.д.)
	int GetLexikalFeatureCount() const override;
	// Возвращает имя конкретной лексической характеристики
	const char* GetLexikalFeatureName(int Index) const  override;
	// Возвращает значение конкретной лексической характеристики
	const char* GetLexikalFeatureValue(int Index) const override;
	//-----------------------------------------------------------
	// Функции возвращают значения для конкретной словоформы
	// Возвращает колличество семантических характеристик
	int GetSemanticFeatureCount() const override;
	// Возвращает конкретную семантическую характеристику
	const char* GetSemanticFeature(int Index) const override;
	// Возвращает колличество групп морфологических характеристик
	int GetMorphFeatureGroupCount() const  override;
	// Возвращает колличество морфологических характеристик
	int GetMorphFeatureCount(int uGroupIndex) const override;
	// Возвращаеь имя морфологической характеристики
	const char* GetMorphFeatureName(int uGroupIndex, int Index) const override;
	// Возвращаеь значение морфологической характеристики
	const char* GetMorphFeatureValue(int uGroupIndex, int Index) const override;
	// Возвращает часть речи
	const char* GetPartOfSpeech() const override;
	// Возвращает предлог
	const char* GetPreText() const override;
	// Поиск предлога
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


