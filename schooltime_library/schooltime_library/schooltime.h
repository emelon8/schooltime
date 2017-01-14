#include <vector>
#include <string>

class SchoolTime
{
	std::vector<unsigned int> arrivaltime;
	std::vector<unsigned int> departuretime;
	int lastmonth = 0;
	int lastday = 0;
	std::vector<bool> issameday;

public:
	void readArrivalTime(std::string filename);
	void addArrivalTime(unsigned int at);
	void readDepartureTime(std::string filename);
	void addDepartureTime(unsigned int dt);
	std::vector<unsigned int> getArrivalTimes();
	std::vector<unsigned int> getDepartureTimes();
	double avgArrivalTime();
	double avgDepartureTime();
	double stdArrivalTime();
	double stdDepartureTime();
	double steArrivalTime();
	double steDepartureTime();
	std::vector<unsigned int> schooltime();
	std::vector<unsigned int> dailyschooltime();
	double avgdailyschooltime();
	double stddailyschooltime();
	double stedailyschooltime();
	int schoolhours(unsigned int totalschoolseconds);
	int schoolminutes(unsigned int totalschoolseconds);
};