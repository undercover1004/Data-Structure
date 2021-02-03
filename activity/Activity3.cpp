#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Job {
	int id;
	string name;
	int page;
	
	static int count;

public:
	Job(const string& u, int p) : name(u), page(p), id(++count){}

	friend ostream& operator<<(ostream& os, const Job& j) 
	{
		os << "id: " << j.id << "사용자: " << j.name << "페이지 수: " << j.page << "장";
		return os;
	}
};

int Job::count = 0;

template <size_t n>

class Printer {
	queue<Job> jobs;

public:


	bool addNewJob(const Job job) {
		if (jobs.size() == n) {
			cout << "대기열이 꽉 찼습니다!" << endl;
			return false;
		}
		else {
			jobs.push(job);
			cout << job << "이 추가 되었습니다" << endl;
			return true;
		}

	}

	void printing() {
		while (!jobs.empty()) {
			cout << jobs.front() << "가 인쇄중입니다." << endl;
			jobs.pop();
		}
	}

};

int main() {
	Printer<5> printer;

	Job j1("광희", 10);
	Job j2("정다", 4);
	Job j3("현수", 5);
	Job j4("유미", 7);
	Job j5("채원", 8);
	Job j6("시원", 10);

	printer.addNewJob(j1);
	printer.addNewJob(j2);
	printer.addNewJob(j3);
	printer.addNewJob(j4);
	printer.addNewJob(j5);
	printer.addNewJob(j6);
	printer.printing();

	printer.addNewJob(j6);
	printer.printing();
	system("PAUSE");
}