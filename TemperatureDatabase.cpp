# include "TemperatureDatabase.h"
# include <fstream>
# include <limits>

using std::cout, std::endl, std::string, std::ofstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	
	std::ifstream dataFile(filename);

    if (!dataFile.is_open()) {
        cout << "Error: Unable to open " << filename << endl;
        exit(1);
    }

    string location;
    int year, month;
    double temperature;



    while (dataFile >> location >> year >> month >> temperature) {
        //error time!


		if (!(dataFile >> year)) {
			cout << "Error: Other invalid input" << endl;

        // Ignore the rest of the line
        	dataFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (!(dataFile >> temperature)) {
			cout << "Error: Other invalid input" << endl;

        // Ignore the rest of the line
        	dataFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (!(dataFile >> month)){
			cout << "Error: Other invalid input" << endl;

        // Ignore the rest of the line
        	dataFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (year < 1800 || year > 2023){
			cout << "Error: Invalid year " << year << endl;

        // Ignore the rest of the line
        	dataFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (month < 1 || month > 12){
			cout << "Error: Invalid month " << month << endl;

        // Ignore the rest of the line
        	dataFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if ((temperature < -50.0 || temperature > 50.0) && temperature != 99.99){
			cout << "Error: Invalid temperature " << temperature << endl;

        // Ignore the rest of the line
        	dataFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}



		// Assuming input is well-formed;
        records.insert(location, year, month, temperature);
    }
	

    dataFile.close();
}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {

}
