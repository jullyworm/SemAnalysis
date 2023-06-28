// ‘айл интерфейса дл€ класса лексемы

#ifndef ILexemaH
#define ILexemaH

#include "ICaseFrame.h"
#include "ISemanticAttr.h"
#include "IGramFeature.h"
#include "IGramFeatureValue.h"

class ILexema {
public:
	// ¬озвращает уникальный идентификатор лексемы
	virtual int GetID() const = 0;
	// ¬озвращает колличество моделей управлени€ соответствующее данной лексеме
	virtual int GetCaseFrameCount() const = 0;
	// ѕредоставл€ет доступ к моделе управлени€ по индексу в списке
	virtual ICaseFrame* GetCaseFrame(int Index) const = 0;
	// ¬озвращает нормальную форму лексемы
	virtual const char* GetNormForm() const = 0;
	// ”станавливает новое значение нормальной формы, возвращает код при ошибке
	// 0 - операци€ прошла успешно
	// 1 - значение нормальной формы хранитс€ во внешнем словаре
	// (значение остаЄтс€ прежним)
	virtual short SetNormForm(char* sValue) = 0;

	// –абота с семантическими ограничени€ми
	//--------------------------------------------------------------------------
	// ƒобавл€ет семантическое ограничение
	// возвращает false, если такое ограничение уже есть,
	// иначе true
	virtual bool AddSemanticLimit(int uAttrSemanticTableIndex) = 0;
	// ”дал€ет семантическое ограничение
	virtual void DeleteSemanticLimit(int Index) = 0;
	// ѕредоставл€ет доступ к семантическому ограничению
	virtual ISemanticAttr* GetSemanticLimit(int Index) const = 0;
	// ¬озвращает кол-во семантических ограничений
	virtual int GetSemanticLimitCount() const = 0;
	//--------------------------------------------------------------------------

	// –абота с морфологическими ограничени€ми
	//--------------------------------------------------------------------------
	// ƒобавл€ет морфологическое ограничение
	// возвращает false, если оганичение с таким именем уже есть,
	// иначе true
	virtual bool AddMorphLimit(int uAttrGramTableIndex, int uValueIndex) = 0;
	// ѕредоставл€ет доступ к аттрибуту ограничени€
	virtual IGramFeature* GetMorphLimitGramFeature(int Index) const = 0;
	// ¬озвращает значение аттрибута ограничени€
	virtual IGramFeatureValue* GetMorphLimitGramValue(int Index) const = 0;
	// ”дал€ет ограничение
	virtual void DeleteMorphLimit(int Index) = 0;
	// ¬озвращает кол-во морфологических ограничений
	virtual int GetMorphLimitCount() const = 0;
	//--------------------------------------------------------------------------

	// –абота с лексическими признаками
	//--------------------------------------------------------------------------
	// ƒобавл€ет лексический признак
	// возвращает false, если признак с таким именем уже есть,
	// иначе true
	virtual bool AddLexikalFeature(int uAttrGramTableIndex, int uValueIndex) = 0;
	// ѕредоставл€ет доступ к признаку
	virtual IGramFeature* GetLexikalFeature(int Index) const = 0;
	// ¬озвращает значение признака
	virtual IGramFeatureValue* GetLexikalFeatureGramValue(int Index) const = 0;
	// ”дал€ет лексический признак
	virtual void DeleteLexikalFeature(int Index) = 0;
	// ¬озвращает кол-во лексических признаков
	virtual int GetLexikalFeatureCount() const = 0;
	// »щет лексический признак по имени, сравнивает строки
	virtual	int FindLexikalFeature(const char* sName) const = 0;
	//--------------------------------------------------------------------------

	// ”станавливает предлог дл€ лексемы
	virtual void SetPreText(char* sPreText) = 0;
	// ”бирает предлог из лексемы
	virtual void ClearPreText() = 0;
	// ¬озвращает предлог
	virtual const char* GetPreText() const = 0;
};

#endif
