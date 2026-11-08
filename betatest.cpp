#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

const int MAX_TASKS = 100;

struct Task{
	int id;
	string course;
	string name;
	int daysLeft;
	double hours;
	string priority;
};

Task tasks[MAX_TASKS];
int taskCount = 0;

string determinePriority(int daysLeft);
void addTask();
void displayTasks();
void calculateSummary();
void countPriority();
void sortTasks();
void searchTasks();
double recursiveTotal(int n);
void displayRecursiveTotal();
void studyPlanner();
void mainProgram();

string determinePriority(int daysLeft)
{
	if (daysLeft <= 1)
	{
		return "URGENT";
	}
	else if (daysLeft <= 3)
	{
		return "HIGH";
	}
	else if (daysLeft <= 6)
	{
		return "MEDIUM";
	}
	else
	{
		return "LOW";
	}
}

void addTask()
{
	if (taskCount >= MAX_TASKS)
	{
		cout << "Task storage is full!\n";
		return;
	}

	int newID;
	cout << "Enter Task ID: ";
	cin >> newID;

	for (int i = 0; i < taskCount; i++)
	{
		if (tasks[i].id == newID)
		{
			cout << "Task ID already exists";
			return;
		}
	}

	string newCourse;
	cout << "Enter Course Name: ";
	cin >> newCourse;

	string newName;
	cout << "Enter Task Name: ";
	cin >> newName;

	int newDaysLeft;
	cout << "Enter Days Left Until Deadline: ";
	cin >> newDaysLeft;

	while (newDaysLeft < 0)
	{
		cout << "Days cannot be negative! \n";
		cin >> newDaysLeft;
	}

	double newHours;
	cout << "Enter Estimated Hours: ";
	cin >> newHours;

	while (newHours <= 0)
	{
		cout << "Hours must be greater than zero! \n";
		cin >> newHours;
	}

	tasks[taskCount].id = newID;
	tasks[taskCount].course = newCourse;
	tasks[taskCount].name = newName;
	tasks[taskCount].daysLeft = newDaysLeft;
	tasks[taskCount].hours = newHours;

	tasks[taskCount].priority = determinePriority(newDaysLeft);
	taskCount = taskCount + 1;

	cout << "Task Added Succesfully" << endl;
}

void calculateSummary() {
	if (taskCount == 0) {
		cout << "No task available!";
		return;
	}
	
	int total = 0;
	double average = 0;
	
	for (int i = 0;i < taskCount;i++) {
		total = total + tasks[i].hours;
	}
	
	average = total/taskCount;
	
	cout << "Total task: " << taskCount << endl;
	cout << "Total estimated hours: " << total << endl;
	cout << "Average estimated hours: " << average << endl;
}

void countPriority () {
	int urgent = 0;
	int high = 0;
	int medium = 0;
	int low = 0;
	
	for (int i = 0;i < taskCount;i++) {
		if (tasks[i].priority == "URGENT") {
			urgent = urgent + 1;
		}
		else if (tasks[i].priority == "HIGH") {
			high = high + 1;
		}
		else if (tasks[i].priority == "MEDIUM") {
			medium = medium + 1;
		}
		else if (tasks[i].priority == "LOW") {
			low = low + 1;
		}
	}
	
	cout << "========== PRIORITY STATISTICS ==========" << endl;
	cout << "URGENT: " << urgent << endl;
	cout << "HIGH: " << high << endl;
	cout << "MEDIUM: " << medium << endl;
	cout << "LOW: " << low << endl;
}

double recursiveTotal(int n) {
	if (n == 0) {
		return 0;
	}
	return tasks[n-1].hours + recursiveTotal(n-1);
}

void displayRecursiveTotal() {
	int total = recursiveTotal(taskCount);
	
	cout << "Total study hours: " << total;
}



int main()
{
	addTask();
	cout << "ID: " << tasks[0].id << endl;
	cout << "Course: " << tasks[0].course << endl;
	cout << "Name: " << tasks[0].name << endl;
	cout << "Priority: " << tasks[0].priority << endl;

	return 0;
}
