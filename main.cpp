#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// global variables

const int MAX_TASKS = 100;

struct Task {
    int id;
    string course;
    string name;
    int daysLeft;
    double hours;
    string priority;
};

Task tasks[MAX_TASKS];
int taskCount = 0;


// FUNCTIONS
// Member 2
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

void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "Task storage is full!" << endl;
        return;
    }

    int newID;
    cout << "Enter Task ID: ";

    while (!(cin >> newID)) {
        cout << "Invalid Task ID! Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == newID) {
            cout << "Task ID already exists!" << endl;
            return;
        }
    }

    string newCourse;
    cout << "Enter Course Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newCourse);

    string newName;
    cout << "Enter Task Name: ";
    getline(cin, newName);

    int newDaysLeft;
    cout << "Enter Days Left Until Deadline: ";

    while (!(cin >> newDaysLeft) || newDaysLeft < 0) {
        cout << "Invalid days! Enter a non-negative number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double newHours;
    cout << "Enter Estimated Hours: ";

    while (!(cin >> newHours) || newHours <= 0) {
        cout << "Invalid hours! Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    tasks[taskCount].id = newID;
    tasks[taskCount].course = newCourse;
    tasks[taskCount].name = newName;
    tasks[taskCount].daysLeft = newDaysLeft;
    tasks[taskCount].hours = newHours;
    tasks[taskCount].priority = determinePriority(newDaysLeft);

    taskCount++;

    cout << "Task added successfully!" << endl;
}

void displayTasks() {
    if (taskCount == 0) {
        cout << "No tasks available!" << endl;
        return;
    }

    cout << "\n===== TASK LIST =====\n";

    for (int i = 0; i < taskCount; i++) {
        cout << "\nTask " << i + 1 << endl;
        cout << "Task ID: " << tasks[i].id << endl;
        cout << "Course: " << tasks[i].course << endl;
        cout << "Task Name: " << tasks[i].name << endl;
        cout << "Days Left: " << tasks[i].daysLeft << endl;
        cout << "Estimated Hours: " << tasks[i].hours << endl;
        cout << "Priority: " << tasks[i].priority << endl;
        cout << "------------------------------" << endl;
    }
}


// Member 3
void calculateSummary() {
	if (taskCount == 0) {
		cout << "No tasks available!" << endl;
		return;
	}
	
	double total = 0;
	double average = 0;
	
	for (int i = 0;i < taskCount;i++) {
		total = total + tasks[i].hours;
	}
	
	average = total / taskCount;
	
	cout << fixed << setprecision(2);
	cout << "Total task: " << taskCount << endl;
	cout << "Total estimated hours: " << total << endl;
	cout << "Average estimated hours: " << average << endl;
	cout.unsetf(ios::fixed);
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
	
	cout << "=== PRIORITY STATISTICS ===" << endl;
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
	if (taskCount == 0) {
		cout << "No tasks available!" << endl;
		return;
	}
	
	double total = recursiveTotal(taskCount);
	
	cout << "Total study hours: " << total << endl;
}



// Member 4
void sortTasks() {
    if (taskCount == 0) {
        cout << "No tasks available!" << endl;
        return;
    }

    int sortChoice, sortOrder;

    cout << "\nSort tasks by:";
    cout << "\n1. Days Until Deadline";
    cout << "\n2. Estimated Hours";
    cout << "\nEnter your choice: ";
    if (!(cin >> sortChoice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        sortChoice = 0;
    }

    if (sortChoice != 1 && sortChoice != 2) {
        cout << "Invalid sorting choice!" << endl;
        return;
    }

    cout << "\nSorting Order:";
    cout << "\n1. Ascending";
    cout << "\n2. Descending";
    cout << "\nEnter your choice: ";
    if (!(cin >> sortOrder)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        sortOrder = 0;
    }

    if (sortOrder != 1 && sortOrder != 2) {
        cout << "Invalid sorting order!" << endl;
        return;
    }

    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = 0; j < taskCount - i - 1; j++) {

            bool shouldSwap = false;

            if (sortChoice == 1) {
                // Sort by daysLeft
                if (sortOrder == 1) {
                    if (tasks[j].daysLeft > tasks[j + 1].daysLeft) {
                        shouldSwap = true;
                    }
                } else {
                    if (tasks[j].daysLeft < tasks[j + 1].daysLeft) {
                        shouldSwap = true;
                    }
                }
            } else {
                // Sort by estimated hours
                if (sortOrder == 1) {
                    if (tasks[j].hours > tasks[j + 1].hours) {
                        shouldSwap = true;
                    }
                } else {
                    if (tasks[j].hours < tasks[j + 1].hours) {
                        shouldSwap = true;
                    }
                }
            }

            if (shouldSwap == true) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    cout << "\nTasks sorted successfully!" << endl;
    displayTasks();
}



void searchTasks() {
    if (taskCount == 0) {
        cout << "No tasks available!" << endl;
        return;
    }

    int searchChoice;
    bool found = false;

    cout << "\nSearch Tasks By:";
    cout << "\n1. Task ID";
    cout << "\n2. Course Name";
    cout << "\nEnter your choice: ";
    if (!(cin >> searchChoice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        searchChoice = 0;
    }

    if (searchChoice == 1) {
        int searchID;

        cout << "Enter Task ID: ";
        while (!(cin >> searchID)) {
            cout << "Invalid Task ID! Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        for (int i = 0; i < taskCount; i++) {
            if (tasks[i].id == searchID) {
                cout << "\nTask ID: " << tasks[i].id << endl;
                cout << "Course: " << tasks[i].course << endl;
                cout << "Task: " << tasks[i].name << endl;
                cout << "Days Left: " << tasks[i].daysLeft << endl;
                cout << "Hours: " << tasks[i].hours << endl;
                cout << "Priority: " << tasks[i].priority << endl;

                found = true;
                break;
            }
        }
    }
    else if (searchChoice == 2) {
        string searchCourse;

        cout << "Enter Course Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, searchCourse);

        for (int i = 0; i < taskCount; i++) {
            if (tasks[i].course == searchCourse) {
                cout << "\nTask ID: " << tasks[i].id << endl;
                cout << "Course: " << tasks[i].course << endl;
                cout << "Task: " << tasks[i].name << endl;
                cout << "Days Left: " << tasks[i].daysLeft << endl;
                cout << "Hours: " << tasks[i].hours << endl;
                cout << "Priority: " << tasks[i].priority << endl;

                found = true;
            }
        }
    }
    else {
        cout << "Invalid search choice!" << endl;
        return;
    }

    if (found == false) {
        cout << "Task not found!" << endl;
    }
}


void studyPlanner() {
    if (taskCount == 0) {
        cout << "No tasks available!" << endl;
        return;
    }

    double availableHours;

    cout << "\n===TODAY'S STUDY PLANNER ===" << endl;
    cout << "Enter available study hours today: ";
    
    while (!(cin >> availableHours) || availableHours <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Enter hours greater than 0: ";
    }

    double remainingHours = availableHours;
    int completedTasks = 0;

    bool selected[MAX_TASKS] = {false};

    cout << "\nRecommended Tasks:" << endl;

    // Priority order: URGENT, HIGH, MEDIUM, LOW
    for (int priorityLevel = 0; priorityLevel < 4; priorityLevel++) {

        for (int i = 0; i < taskCount; i++) {

            bool matchesPriority = false;

            if (priorityLevel == 0 && tasks[i].priority == "URGENT") {
                matchesPriority = true;
            }
            else if (priorityLevel == 1 && tasks[i].priority == "HIGH") {
                matchesPriority = true;
            }
            else if (priorityLevel == 2 && tasks[i].priority == "MEDIUM") {
                matchesPriority = true;
            }
            else if (priorityLevel == 3 && tasks[i].priority == "LOW") {
                matchesPriority = true;
            }

            if (matchesPriority && tasks[i].hours <= remainingHours) {

                cout << "\nTask ID: " << tasks[i].id << endl;
                cout << "Course: " << tasks[i].course << endl;
                cout << "Task: " << tasks[i].name << endl;
                cout << "Priority: " << tasks[i].priority << endl;
                cout << "Estimated Hours to complete: " << tasks[i].hours << endl;

                remainingHours -= tasks[i].hours;
                selected[i] = true;
                completedTasks++;
            }
        }
    }

    if (completedTasks == 0) {
        cout << "No tasks fit your available study hours." << endl;
    }

    cout << "\n==== STUDY SUMMARY ====" << endl;
    cout << "Available Hours: " << availableHours << endl;
    cout << "Planned Hours: " << availableHours - remainingHours << endl;
    cout << "Remaining Hours: " << remainingHours << endl;
    cout << "Number of Planned Tasks: " << completedTasks << endl;

    cout << "\nTasks Not Selected:" << endl;

    bool hasUnselected = false;

    for (int i = 0; i < taskCount; i++) {
        if (!selected[i]) {
            cout << "- " << tasks[i].name
                 << " (" << tasks[i].hours << " hours, "
                 << tasks[i].priority << ")" << endl;

            hasUnselected = true;
        }
    }

    if (!hasUnselected) {
        cout << "All tasks have been scheduled!" << endl;
    }
}



int main() {
    int choice = -1;

    do {
        cout << "\n====================================\n";
        cout << " SMART ASSIGNMENT & STUDY PLANNER\n";
        cout << "====================================\n";
        cout << "1. Add Task\n";
        cout << "2. Display All Tasks\n";
        cout << "3. Study Time Statistics\n";
        cout << "4. Priority Statistics\n";
        cout << "5. Sort Tasks\n";
        cout << "6. Search Tasks\n";
        cout << "7. Total Study Time\n";
        cout << "8. Today's Study Planner\n";
        cout << "0. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                displayTasks();
                break;

            case 3:
                calculateSummary();
                break;

            case 4:
                countPriority();
                break;

            case 5:
                sortTasks();
                break;

            case 6:
                searchTasks();
                break;

            case 7:
                displayRecursiveTotal();
                break;

            case 8:
                studyPlanner();
                break;

            case 0:
                cout << "Thank you for using the program!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
