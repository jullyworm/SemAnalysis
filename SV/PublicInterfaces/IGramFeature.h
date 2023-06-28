// ‘айл интерфейса дл€ класса грамматической характеристики

#ifndef IGramFeatureH
#define IGramFeatureH

#include "IGramFeatureValue.h"

class IGramFeature {
public:
	// ¬озвращает им€ грамматической характеристики
	virtual const char* GetName() const = 0;
	// ¬озвращает колличество возможных значений характеристики
	virtual int GetFeatureValueCount() const = 0;
	// —оздаЄт новой значение грамматической характеристики,
	// возвращает индекс созданной;
	// если указанное значение уже существует в таблице,
	// то возвращает еЄ индекс, не создава€ новой
	virtual int CreateNewFeatureValue(char* sFeatureValue) = 0;
	// ”дал€ет значение грамматической характеристики,
	// возвращает код при ошибке
	// 0 - операци€ прошла успешно
	// 1 - значение хранитс€ во внешнем словаре
	// 2 - значение используетс€ в словарной статье
	virtual short DeleteFeatureValue(int Index) = 0;
	// ¬озвращает значение по его индексу
	virtual IGramFeatureValue* GetGramFeatureValue(int Index) const = 0;
	// »щет значение характеристики
	// сравнивает строки, возвращает индекс
	// -1 если значение не найдено
	virtual int FindFeatureValue(const char* sValue) const = 0;
	// ¬озвращает тип грамматической характеристики
	// 0 - морфологический аттрибут
	// 1 - часть речи
	// 2 - предлог
	virtual short GetGramFeatureType() const = 0;
	// »змен€ет значение, возвращает код при ошибке
	// 0 - операци€ прошла успешно
	// 1 - значение аттрибута хранитс€ во внешнем словаре
	// 3 - такое значение уже есть
	// (значение остаЄтс€ прежним)
	virtual short SetValue(int Index, char* sNewValue) = 0;
};

#endif
