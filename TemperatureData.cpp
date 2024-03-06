# include "TemperatureData.h"
using std::string;

TemperatureData::TemperatureData() : id(""), year(0), month(0), temperature(0.0) {
	// TODO: implement this function
}

TemperatureData::TemperatureData(string id, int year, int month, double temperature) : id(id), year(year), month(month), temperature(temperature) {
	// TODO: implement this function
}

TemperatureData::~TemperatureData() {}

bool TemperatureData::operator<(const TemperatureData& b) {
	// TODO: implement this function
	if (this->id != b.id) {
        return this->id < b.id;
    } else if (this->year != b.year) {
        return this->year < b.year;
    } else {
        return this->month < b.month;
    }
}

