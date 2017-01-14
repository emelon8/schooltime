#include "schooltime.h"
#include <fstream>
#include <time.h>

using namespace std;

void SchoolTime::readArrivalTime(string filename) {
	vector<string> times_temp;
	ifstream arrivalfile;
	arrivalfile.open(filename);
	string line;

	if (arrivalfile.is_open()) {
		while (arrivalfile.good()) {
			getline(arrivalfile, line);
			times_temp.push_back(line);
		}
	}

	arrivalfile.close();

	string year, month, day, hour, minute, halfofday;

	for (vector<string>::iterator i = times_temp.begin() + 2; i <= times_temp.end() - 3; i += 4)
	{
		if ((*i).find("January", 0) == 0) {
			month = "01";
			int monthnum = 6;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("February", 0) == 0) {
			month = "02";
			int monthnum = 7;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("March", 0) == 0) {
			month = "03";
			int monthnum = 4;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("April", 0) == 0) {
			month = "04";
			int monthnum = 4;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("May", 0) == 0) {
			month = "05";
			int monthnum = 2;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("June", 0) == 0) {
			month = "06";
			int monthnum = 3;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("July", 0) == 0) {
			month = "07";
			int monthnum = 3;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("August", 0) == 0) {
			month = "08";
			int monthnum = 5;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("September", 0) == 0) {
			month = "09";
			int monthnum = 8;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("October", 0) == 0) {
			month = "10";
			int monthnum = 6;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("November", 0) == 0) {
			month = "11";
			int monthnum = 7;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("December", 0) == 0) {
			month = "12";
			int monthnum = 7;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}

		struct tm arrivaltimestructure;

		arrivaltimestructure.tm_year = stoi(year) - 1900;
		arrivaltimestructure.tm_mon = stoi(month) - 1;
		arrivaltimestructure.tm_mday = stoi(day);
		if ((halfofday == "AM" && stoi(hour) < 12) || (halfofday == "PM" && stoi(hour) == 12))
			arrivaltimestructure.tm_hour = stoi(hour);
		else if (halfofday == "AM" && stoi(hour) == 12)
			arrivaltimestructure.tm_hour = 0;
		else
			arrivaltimestructure.tm_hour = stoi(hour) + 12;
		arrivaltimestructure.tm_min = stoi(minute);
		arrivaltimestructure.tm_sec = 0;
		arrivaltimestructure.tm_isdst = 1;

		arrivaltime.push_back(mktime(&arrivaltimestructure) - 21600);

		// make a vector of bools of the same size telling whether this arrival was the same day as the last arrival
		if ((arrivaltimestructure.tm_mon == lastmonth) && (arrivaltimestructure.tm_mday == lastday))
			issameday.push_back(true);
		else
			issameday.push_back(false);
		lastmonth = arrivaltimestructure.tm_mon;
		lastday = arrivaltimestructure.tm_mday;
	}


	vector<string>::iterator i = times_temp.end() - 2;
	if ((*i).find("January", 0) == 0) {
		month = "01";
		int monthnum = 6;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("February", 0) == 0) {
		month = "02";
		int monthnum = 7;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("March", 0) == 0) {
		month = "03";
		int monthnum = 4;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("April", 0) == 0) {
		month = "04";
		int monthnum = 4;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("May", 0) == 0) {
		month = "05";
		int monthnum = 2;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("June", 0) == 0) {
		month = "06";
		int monthnum = 3;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("July", 0) == 0) {
		month = "07";
		int monthnum = 3;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("August", 0) == 0) {
		month = "08";
		int monthnum = 5;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("September", 0) == 0) {
		month = "09";
		int monthnum = 8;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("October", 0) == 0) {
		month = "10";
		int monthnum = 6;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("November", 0) == 0) {
		month = "11";
		int monthnum = 7;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("December", 0) == 0) {
		month = "12";
		int monthnum = 7;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}

	struct tm arrivaltimestructure;

	arrivaltimestructure.tm_year = stoi(year) - 1900;
	arrivaltimestructure.tm_mon = stoi(month) - 1;
	arrivaltimestructure.tm_mday = stoi(day);
	if ((halfofday == "AM" && stoi(hour) < 12) || (halfofday == "PM" && stoi(hour) == 12))
		arrivaltimestructure.tm_hour = stoi(hour);
	else if (halfofday == "AM" && stoi(hour) == 12)
		arrivaltimestructure.tm_hour = 0;
	else
		arrivaltimestructure.tm_hour = stoi(hour) + 12;
	arrivaltimestructure.tm_min = stoi(minute);
	arrivaltimestructure.tm_sec = 0;
	arrivaltimestructure.tm_isdst = 1;

	arrivaltime.push_back(mktime(&arrivaltimestructure) - 21600);

	// make a vector of bools of the same size telling whether this arrival was the same day as the last arrival
	if ((arrivaltimestructure.tm_mon == lastmonth) && (arrivaltimestructure.tm_mday == lastday))
		issameday.push_back(true);
	else
		issameday.push_back(false);
	lastmonth = arrivaltimestructure.tm_mon;
	lastday = arrivaltimestructure.tm_mday;
}

void SchoolTime::readDepartureTime(string filename) {
	vector<string> times_temp;
	ifstream departurefile;
	departurefile.open(filename);
	string line;

	if (departurefile.is_open()) {
		while (departurefile.good()) {
			getline(departurefile, line);
			times_temp.push_back(line);
		}
	}

	departurefile.close();

	string year, month, day, hour, minute, halfofday;

	for (vector<string>::iterator i = times_temp.begin() + 2; i <= times_temp.end() - 3; i += 4)
	{
		if ((*i).find("January", 0) == 0) {
			month = "01";
			int monthnum = 6;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("February", 0) == 0) {
			month = "02";
			int monthnum = 7;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("March", 0) == 0) {
			month = "03";
			int monthnum = 4;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("April", 0) == 0) {
			month = "04";
			int monthnum = 4;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("May", 0) == 0) {
			month = "05";
			int monthnum = 2;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("June", 0) == 0) {
			month = "06";
			int monthnum = 3;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("July", 0) == 0) {
			month = "07";
			int monthnum = 3;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("August", 0) == 0) {
			month = "08";
			int monthnum = 5;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("September", 0) == 0) {
			month = "09";
			int monthnum = 8;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("October", 0) == 0) {
			month = "10";
			int monthnum = 6;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("November", 0) == 0) {
			month = "11";
			int monthnum = 7;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}
		else if ((*i).find("December", 0) == 0) {
			month = "12";
			int monthnum = 7;
			day = (*i).substr(monthnum + 2, 2);
			year = (*i).substr(monthnum + 6, 4);
			hour = (*i).substr(monthnum + 14, 2);
			minute = (*i).substr(monthnum + 17, 2);
			halfofday = (*i).substr(monthnum + 19, 2);
		}

		struct tm departuretimestructure;

		departuretimestructure.tm_year = stoi(year) - 1900;
		departuretimestructure.tm_mon = stoi(month) - 1;
		departuretimestructure.tm_mday = stoi(day);
		if ((halfofday == "AM" && stoi(hour) < 12) || (halfofday == "PM" && stoi(hour) == 12))
			departuretimestructure.tm_hour = stoi(hour);
		else if (halfofday == "AM" && stoi(hour) == 12)
			departuretimestructure.tm_hour = 0;
		else
			departuretimestructure.tm_hour = stoi(hour) + 12;
		departuretimestructure.tm_min = stoi(minute);
		departuretimestructure.tm_sec = 0;
		departuretimestructure.tm_isdst = 1;

		departuretime.push_back(mktime(&departuretimestructure) - 21600);
	}


	vector<string>::iterator i = times_temp.end() - 2;
	if ((*i).find("January", 0) == 0) {
		month = "01";
		int monthnum = 6;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("February", 0) == 0) {
		month = "02";
		int monthnum = 7;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("March", 0) == 0) {
		month = "03";
		int monthnum = 4;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("April", 0) == 0) {
		month = "04";
		int monthnum = 4;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("May", 0) == 0) {
		month = "05";
		int monthnum = 2;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("June", 0) == 0) {
		month = "06";
		int monthnum = 3;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("July", 0) == 0) {
		month = "07";
		int monthnum = 3;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("August", 0) == 0) {
		month = "08";
		int monthnum = 5;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("September", 0) == 0) {
		month = "09";
		int monthnum = 8;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("October", 0) == 0) {
		month = "10";
		int monthnum = 6;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("November", 0) == 0) {
		month = "11";
		int monthnum = 7;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}
	else if ((*i).find("December", 0) == 0) {
		month = "12";
		int monthnum = 7;
		day = (*i).substr(monthnum + 2, 2);
		year = (*i).substr(monthnum + 6, 4);
		hour = (*i).substr(monthnum + 14, 2);
		minute = (*i).substr(monthnum + 17, 2);
		halfofday = (*i).substr(monthnum + 19, 2);
	}

	struct tm departuretimestructure;

	departuretimestructure.tm_year = stoi(year) - 1900;
	departuretimestructure.tm_mon = stoi(month) - 1;
	departuretimestructure.tm_mday = stoi(day);
	if ((halfofday == "AM" && stoi(hour) < 12) || (halfofday == "PM" && stoi(hour) == 12))
		departuretimestructure.tm_hour = stoi(hour);
	else if (halfofday == "AM" && stoi(hour) == 12)
		departuretimestructure.tm_hour = 0;
	else
		departuretimestructure.tm_hour = stoi(hour) + 12;
	departuretimestructure.tm_min = stoi(minute);
	departuretimestructure.tm_sec = 0;
	departuretimestructure.tm_isdst = 1;

	departuretime.push_back(mktime(&departuretimestructure) - 21600);
}

void SchoolTime::addArrivalTime(unsigned int at) {
	arrivaltime.push_back(at);
}

void SchoolTime::addDepartureTime(unsigned int dt) {
	departuretime.push_back(dt);
}

vector<unsigned int> SchoolTime::getArrivalTimes() {
	return arrivaltime;
}

vector<unsigned int> SchoolTime::getDepartureTimes() {
	return departuretime;
}

double SchoolTime::avgArrivalTime() {
	vector<unsigned int>::iterator i = arrivaltime.begin();
	unsigned int arrivalsum = 0;
	for (i; i != arrivaltime.end(); i++)
		arrivalsum += *i;
	return (double)arrivalsum / (double)arrivaltime.size();
}

double SchoolTime::avgDepartureTime() {
	unsigned int departuresum = 0;
	for (vector<unsigned int>::iterator i = departuretime.begin(); i != departuretime.end(); i++)
		departuresum += *i;
	return (double)departuresum / (double)departuretime.size();
}

double SchoolTime::stdArrivalTime() {
	double average = this->avgArrivalTime();
	double sumofsquares = 0.0;
	for (int i = 0; i < arrivaltime.size(); i++)
		sumofsquares += (pow((arrivaltime.at(i) - average), 2));
	return sqrt(sumofsquares / arrivaltime.size());
}

double SchoolTime::stdDepartureTime() {
	double average = this->avgDepartureTime();
	double sumofsquares = 0.0;
	for (int i = 0; i < departuretime.size(); i++)
		sumofsquares += (pow((departuretime.at(i) - average), 2));
	return sqrt(sumofsquares / departuretime.size());
}

double SchoolTime::steArrivalTime() {
	double standarddev = this->stdArrivalTime();
	return standarddev / sqrt(arrivaltime.size());
}

double SchoolTime::steDepartureTime() {
	double standarddev = this->stdDepartureTime();
	return standarddev / sqrt(departuretime.size());
}

vector<unsigned int> SchoolTime::schooltime() {
	vector<unsigned int> differences(departuretime.size());
	for (int i = 0; i < departuretime.size(); i++)
		differences.at(i) = departuretime.at(i) - arrivaltime.at(i);
	return differences;
}

vector<unsigned int> SchoolTime::dailyschooltime() {
	vector<unsigned int> schooltimes = this->schooltime();
	vector<unsigned int> dailytime;
	for (int i = 0; i < issameday.size(); i++) {
		if (issameday.at(i))
			dailytime.at(dailytime.size() - 1) += schooltimes.at(i);
		else
			dailytime.push_back(schooltimes.at(i));
	}
	return dailytime;
}

double SchoolTime::avgdailyschooltime() {
	vector<unsigned int> differences = this->dailyschooltime();
	unsigned int sum = 0;
	for (int i = 0; i < differences.size(); i++)
		sum += differences.at(i);
	return (double)sum / (double)differences.size();
}

double SchoolTime::stddailyschooltime() {
	vector<unsigned int> differences = this->dailyschooltime();
	double average = this->avgdailyschooltime();
	double sumofsquares = 0.0;
	for (int i = 0; i < differences.size(); i++)
		sumofsquares += (pow((differences.at(i) - average), 2));
	return sqrt(sumofsquares / differences.size());
}

double SchoolTime::stedailyschooltime() {
	double standarddev = this->stddailyschooltime();
	return standarddev / sqrt(departuretime.size());
}

int SchoolTime::schoolhours(unsigned int totalschoolseconds) {
	return (totalschoolseconds - (totalschoolseconds % 3600)) / 3600; // returns the number of hours I was at school
}

int SchoolTime::schoolminutes(unsigned int totalschoolseconds) {
	return (totalschoolseconds % 3600) / 60; // returns the number of minutes leftover after the hours
}