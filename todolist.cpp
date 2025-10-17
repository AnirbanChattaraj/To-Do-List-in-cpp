#include <iostream>
#include <vector>
#include <string>
using namespace std;

void showMenu() {
    cout << "\n====== TO-DO LIST MENU ======\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void addTask(vector<string>& tasks) {
    cin.ignore(); // Clear input buffer
    string task;
    cout << "Enter task description: ";
    getline(cin, task);
    tasks.push_back(task);
    cout << "✅ Task added successfully!\n";
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "📌 No tasks available.\n";
        return;
    }
    cout << "\nYour Tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "❌ No tasks to delete.\n";
        return;
    }
    int taskNum;
    viewTasks(tasks);
    cout << "Enter the task number to delete: ";
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "🗑️ Task deleted successfully!\n";
    } else {
        cout << "⚠️ Invalid task number.\n";
    }
}

int main() {
    vector<string> tasks;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "✅ Exiting... Thank you!\n";
                return 0;
            default:
                cout << "⚠️ Invalid choice. Try again.\n";
        }
    }
}
