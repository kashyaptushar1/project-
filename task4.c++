// Hello Neha i am tushar kashyap ,
// jb code ko github pr dalte hai tho usme comment add krte hai.
#include <iostream>
#include <vector>
#include <algorithm>

// Define a struct to represent individual tasks
struct Task {
    std::string description; // Description of the task
    bool completed; // Flag indicating whether the task is completed or not

    // Constructor to initialize a task with a description
    Task(const std::string& desc) : description(desc), completed(false) {}
};

// Define a class to manage a to-do list
class ToDoList {
public:
    // Function to add a new task to the list
    void addTask(const std::string& description);
    
    // Function to view all tasks in the list
    void viewTasks() const;
    
    // Function to mark a task as completed
    void markAsCompleted(int taskIndex);
    
    // Function to remove a task from the list
    void removeTask(int taskIndex);

private:
    std::vector<Task> tasks; // Vector to store tasks
};

// Implementation of the addTask function
void ToDoList::addTask(const std::string& description) {
    tasks.emplace_back(description); // Add a new task to the vector
    std::cout << "Task added: " << description << "\n"; // Print a message indicating the task was added
}

// Implementation of the viewTasks function
void ToDoList::viewTasks() const {
    std::cout << "Task List:\n"; // Print header for the task list
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "[" << i + 1 << "] "; // Print task number
        std::cout << (tasks[i].completed ? "[Completed] " : "[Pending] "); // Print task status
        std::cout << tasks[i].description << "\n"; // Print task description
    }
    std::cout << "\n"; // Print newline for better formatting
}

// Implementation of the markAsCompleted function
void ToDoList::markAsCompleted(int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks[taskIndex - 1].completed = true; // Mark the selected task as completed
        std::cout << "Task marked as completed: " << tasks[taskIndex - 1].description << "\n"; // Print a message indicating the task was marked as completed
    } else {
        std::cout << "Invalid task index.\n"; // Print an error message for invalid task index
    }
}

// Implementation of the removeTask function
void ToDoList::removeTask(int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        std::cout << "Task removed: " << tasks[taskIndex - 1].description << "\n"; // Print a message indicating the task was removed
        tasks.erase(tasks.begin() + taskIndex - 1); // Remove the selected task from the vector
    } else {
        std::cout << "Invalid task index.\n"; // Print an error message for invalid task index
    }
}

// Main function
int main() {
    ToDoList todo; // Create an instance of the ToDoList class

    // Main program loop
    while (true) {
        // Print menu options
        std::cout << "==== To-Do List Manager ====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice; // Read user choice from input

        switch (choice) {
            case 1: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description); // Read task description from input
                todo.addTask(description); // Add the task to the to-do list
                break;
            }
            case 2:
                todo.viewTasks(); // View all tasks in the to-do list
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter the task index to mark as completed: ";
                std::cin >> taskIndex; // Read index of the task to mark as completed
                todo.markAsCompleted(taskIndex); // Mark the selected task as completed
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter the task index to remove: ";
                std::cin >> taskIndex; // Read index of the task to remove
                todo.removeTask(taskIndex); // Remove the selected task from the to-do list
                break;
            }
            case 5:
                std::cout << "Exiting the program.\n"; // Print exit message
                return 0; // Exit the program
            default:
                std::cout << "Invalid choice. Please choose a valid option.\n"; // Print error message for invalid choice
        }
    }

    return 0;
}
// Add comment for understanding the code.
