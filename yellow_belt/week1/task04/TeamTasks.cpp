#include <algorithm>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include "main.cpp"

using namespace std;

TaskStatus NextStatus(const TaskStatus &task_status) {
    return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

void RemoveZeros(TasksInfo &tasks_info) {
    vector <TaskStatus> statuses_to_remove;
    for (const auto &task_item : tasks_info) {
        if (task_item.second == 0) {
            statuses_to_remove.push_back(task_item.first);
        }
    }
    for (const TaskStatus status : statuses_to_remove) {
        tasks_info.erase(status);
    }
}


class TeamTasks {
public:
    const TasksInfo &GetPersonTasksInfo(const string &person) const;

    void AddNewTask(const string &person);

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string &person, int task_count);

private:
    map<string, TasksInfo> personal_tasks;

};

const TasksInfo &TeamTasks::GetPersonTasksInfo(const string &person) const {
    return personal_tasks.at(person);
}

void TeamTasks::AddNewTask(const string &person) {
    ++personal_tasks[person][TaskStatus::NEW];
}

tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const string &person, int task_count) {

    TasksInfo updated_tasks, untouched_tasks;

    TasksInfo &tasks = personal_tasks[person];

    for (TaskStatus status = TaskStatus::NEW;
         status != TaskStatus::DONE;
         status = NextStatus(status)) {
        updated_tasks[NextStatus(status)] = min(task_count, tasks[status]);
        task_count -= updated_tasks[NextStatus(status)];
    }

    for (TaskStatus status = TaskStatus::NEW;
         status != TaskStatus::DONE;
         status = NextStatus(status)) {
        untouched_tasks[status] = tasks[status] - updated_tasks[NextStatus(status)];
        tasks[status] += updated_tasks[status] - updated_tasks[NextStatus(status)];
    }
    tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];
    RemoveZeros(updated_tasks);
    RemoveZeros(untouched_tasks);

    return {updated_tasks, untouched_tasks};
}
