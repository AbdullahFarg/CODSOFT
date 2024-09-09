#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a Task
struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

// Function prototypes
void displayTasks(const vector<Task>& tasks);
void addTask(vector<Task>& tasks);
void markTaskAsCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);
void displayMenu();
void handleUserInput(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    handleUserInput(tasks);
    return 0;
}

void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void handleUserInput(vector<Task>& tasks) {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline character left in the buffer

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: displayTasks(tasks); break;
            case 3: markTaskAsCompleted(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: return;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);
    tasks.emplace_back(description);
    cout << "Task added successfully!" << endl;
}

void displayTasks(const vector<Task>& tasks) {
    cout << "\nTo-Do List:\n";
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [ " << (tasks[i].isCompleted ? "Completed" : "Pending") << " ]" << endl;
    }
}

void markTaskAsCompleted(vector<Task>& tasks) {
    displayTasks(tasks);
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    cin.ignore(); // Ignore newline character left in the buffer

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks[taskNumber - 1].isCompleted = true;
    cout << "Task marked as completed!" << endl;
}

void removeTask(vector<Task>& tasks) {
    displayTasks(tasks);
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    cin.ignore(); // Ignore newline character left in the buffer

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task removed successfully!" << endl;
}
