#include <iostream>
#include <vector>
#include <string>

// 할 일 항목을 나타내는 구조체
struct TodoItem {
    std::string task; // 할 일 내용
    bool completed = false; // 완료 여부
};

// 할 일 목록을 관리하는 클래스
class TodoList {
    private:
        std::vector<TodoItem> items;
    
    public:
        void addTask(const std::string& task) {
            TodoItem newItem;
            newItem.task = task;
            items.push_back(newItem);
        }

        void deleteTask(int index) {
            if (index >= 0 && index < items.size()){
                items.erase(items.begin() + index);
            } else {
                std::cout << "Invalid task index." << std::endl;
            }
        }

        void toggleCompletion(int index){
            if (index >= 0 && index < items.size()) {
                items[index].completed = !items[index].completed;
            } else {
                std::cout << "Invalid task index." << std::endl;
            }
        }

        void displayTasks() const {
            for  (size_t i = 0; i < items.size(); ++i) {
                std::cout << "[" << (items[i].completed ? "x" : " ") << "] ";
                std::cout << i << ": " << items[i].task << std::endl;
            }
        }

        void searchTasks(const std::string& keyword) {
            bool found = false;
            for (size_t i = 0; i < items.size(); ++i){
                if(items[i].task.find(keyword) != std::string::npos) {
                    std::cout << "[" << (items[i].completed ? "x" : " ") << "]";
                    std::cout << i << items[i].task << std::endl;
                    found = true;
                }
            }
            if(!found) {
                std::cout << "No tasks found containg '" << keyword << "'." << std::endl;
            }
        }

};

int main() {
    TodoList todoList;
    int choice;
    std::string newTask;

    while (true) {
        std::cout << "\nToDoList Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Delete Task" << std::endl;
        std::cout << "3. Toggle Completion" << std::endl;
        std::cout << "4. Display Tasks" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "6. Search Tasks" << std::endl;
        std::cout << "Enter your choice: ";
        
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                std::cout << "Enter task: ";
                std::getline(std::cin, newTask);
               
                todoList.addTask(newTask);
                break;
            case 2:
                std::cout << "Enter task index to delete: ";
                
                std::cin >> choice;
                std::cin.ignore();
                todoList.deleteTask(choice);
                break;
            case 3:
                std::cout << "Enter task index to toggle completion: ";
               
                std::cin >> choice;
                std::cin.ignore();
                todoList.toggleCompletion(choice);
                break;
            case 4:
                todoList.displayTasks();
                break;
            case 5:
                return 0; // 프로그램 종료
            case 6:
                std::cout << "Enter keyword to search: ";
                std::getline(std::cin, newTask);
                todoList.searchTasks(newTask);
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
            
        }
    }

    return 0;
}