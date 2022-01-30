class Task {
public:
    char type;
    int count;
    int running;
    Task(char _type) {
        type = _type;
        count = 1;
        running = 0;
    }
};

class TaskList {
private:
    map<char, Task> taskMap;
    int n;
public:
    TaskList(int _n) {
        n = _n;
    }

    void produce(char type) {
        map<char, Task>::iterator iter = taskMap.find(type);
        if (iter != taskMap.end()) {
            iter->second.count++;
        } else {
            taskMap.insert(pair<char, Task>(type, Task(type)));
        }
    }

    bool hasTask() {
        return !taskMap.empty();
    }

    char consume() {
        Task *max = nullptr;
        for (auto iter = taskMap.begin(); iter != taskMap.end(); iter++) {
            if (iter->second.running == 0 && (!max || iter->second.count > max->count)) {
                max = &(iter->second);
            }
            if (iter->second.running > 0) {
                iter->second.running--;
            }
        }
        if (max) {
            max->count--;
            max->running = n;
            char type = max->type;
            if (max->count == 0) {
                taskMap.erase(max->type);
            }
            return type;
        }
        return ' ';
    }

    void display() {
        map<char, Task>::iterator iter;
        for (iter = taskMap.begin(); iter != taskMap.end(); iter ++) {
            cout << iter->first << iter->second.count << endl;
        }
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        TaskList taskList(n);
        for (auto task : tasks) {
            taskList.produce(task);
        }
        int count = 0;
        while (taskList.hasTask()) {
            // cout << taskList.consume() << endl;
            taskList.consume();
            count++;
        }
        // taskList.display();
        return count;
    }
};
