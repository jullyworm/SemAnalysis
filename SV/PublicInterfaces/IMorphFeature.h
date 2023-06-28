// Файл интерфейса для класса конъюнкции морфологических признаков
// Класс описывает элемент морфологической состовляющей актанта
// Принадлежит конкретному семантичскому элементу

#ifndef IMorphFeatureH
#define IMorphFeatureH

#include "IGramFeature.h"
#include "IGramFeatureValue.h"

class IMorphFeature {
public:
	// Добавляет аттрибут в конъюнкцию
	// возвращает false, если аттрибут с таким именем уже есть,
	// иначе true
	virtual bool AddMorphAttr(int uAttrGramTableIndex, int uValueIndex) = 0;
	// Предоставляет дотсуп к аттрибуту по индексу
	virtual IGramFeature* GetGramFeature(int Index) const = 0;
	// Возвращает имя аттрибута
	virtual const char* GetGramFeatureName(int Index) const = 0;
	// Возвращает значение аттрибута
	virtual const char* GetGramFeatureValue(int Index) const = 0;
	// Предоставляет доступ к значению аттрибута
	virtual IGramFeatureValue* GetGramFeatureValueObj(int Index) const = 0;
	// Удаляет аттрибут
	virtual void DeleteMorphAttr(int Index) = 0;
	// Возвращает кооличество аттрибутов в конъюнкции
	virtual int GetMorphAttrCount() const = 0;
	// Проверяет наличае аттрибута типа предлог
	// true - если в конъюнкцию входит предлог
	virtual bool IsWithPreText() const = 0;
	// Проверяет наличае аттрибута типа часть речи
	// true - если в конъюнкцию входит часть речи
	virtual bool IsWithPartOfSpeach() const = 0;
};

#endif
