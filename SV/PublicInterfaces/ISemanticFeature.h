// Файл интерфейса для класса конъюнкции семантческих признаков
// Класс описывает элемент семантической составляющей актанта

#ifndef ISemanticFeatureH
#define ISemanticFeatureH

#include "ISemanticAttr.h"
#include "IMorphFeature.h"

class ISemanticFeature {
public:
	// Добавляет семантический аттрибут в конъюнкцию
	// Используется индекс аттрибута из таблицы
	// возвращает:
	// false - указанный аттрибуту уже есть в конъюнкции
	// true - успешно добавлен новый аттрибут
	virtual bool AddSemanticAttr(int uAttrTableIndex) = 0;
	// Удаляет семантический аттрибут из конъюнкции
	virtual void DeleteSemanticAttr(int Index) = 0;
	// Прдоставляет доступ к семантическому аттрибуту по индексу
	virtual ISemanticAttr* GetSemanticAttr(int Index) const = 0;
	// Возвращает кол-во семантических аттрибутов в конъюнкции
	virtual int GetSemanticAttrCount() const = 0;
	// Создаёт новый объект конъюнкции морфологических признаков
	virtual IMorphFeature* CreateMorphFeature() = 0;
	// Возвращает конъюнкцию морфологических признаков
	virtual IMorphFeature* GetMorphFeature(int Index) const = 0;
	// Удаляет конъюнкцию морфологических признаков
	virtual void DeleteMorphFeature(int Index) = 0;
	// Возвращает кол-во конъюнкций морфологических признаков
	virtual int GetMorphFeatureCount() const = 0;
};

#endif
