// Файл интерфейса для класса варианта значения грамматической
// характеристики

#ifndef IGramFeatureValueH
#define IGramFeatureValueH

class IGramFeatureValue {
public:
	// Возвращает значение
	virtual const char* GetValue() const = 0;
};

#endif
