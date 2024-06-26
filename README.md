# TaskManager

## Introduction

The Task Manager is a software system designed to help users create, edit, view, and manage various types of tasks. It provides user registration and login functionalities, allowing both personal and shared task management, as well as tracking and modifying the status of tasks.

## Features

### Task Management

- **Create Task**: Users can add new tasks with attributes such as task ID, name, due date (optional), status (ON_HOLD, IN_PROCESS, DONE, OVERDUE), and description.
- **Edit Task**: Users can update task names and descriptions.
- **Start Task**: Mark tasks as in process.
- **Complete Task**: Mark tasks as completed.
- **Delete Task**: Remove tasks from the system.
- **Task Dashboard**: View and manage tasks due today or tasks added by the user. Automatically updates tasks based on their due dates.

### User Management

- **Registration**: New users can register with a unique username and password.
- **Login/Logout**: Users can log in and out of the system.

### Collaboration

- **Create Collaboration**: Users can create shared projects (collaborations) and add tasks visible to all participants.
- **Manage Collaboration**: Add or remove users, assign tasks within collaborations, and delete collaborations.
- **Assignee**:  The assignee is responsible for managing and completing the task assigned to them within the collaboration.

## Command List

### User Commands

- `register <username> <password>`: Register a new user.
- `login <username> <password>`: Log in as an existing user.
- `logout`: Log out of the current user session.
- `exit`: Exit the program.

### Task Commands

- `add-task <name> <due_date> <description>`: Add a new task.
- `update-task-name <id> <name>`: Change the name of a task.
- `update-task-description <id> <description>`: Change the description of a task.
- `start-task <id>`: Mark a task as in process.
- `finish-task <id>`: Mark a task as completed.
- `delete-task <id>`: Delete a task.
- `get-task <name | id>`: Retrieve task details by name or ID.
- `list-tasks <date>`: List all tasks due on a specific date.
- `list-tasks`: List all tasks for the current user.
- `list-completed-tasks`: List all completed tasks for the current user.
- `list-dashboard`: List all tasks in the dashboard for today.
- `remove-task-from-dashboard <id>`: Remove a task from the dashboard.
- `add-task-to-dashboard <id>`: Add a task to the dashboard (if not overdue).

### Collaboration Commands

- `add-collaboration <name>`: Create a new collaboration.
- `delete-collaboration <name>`: Delete a collaboration (only by the creator).
- `list-collaborations`: List all collaborations the user is part of.
- `add-user <collaboration name> <username>`: Add a user to a collaboration.
- `assign-task <collaboration name> <username> <name> <due_date> <description>`: Assign a task to a user within a collaboration.
- `list-tasks <collaboration name>`: List all tasks within a collaboration.

## Example Usage

```c++
// Register a new user
> register user123 123
Registered successfully!

// Log in as the new user
> login user123 123
Welcome back user123!

// Add a new task
> add-task OOP_HW 2024-03-14 "oop hw desc"
Task added successfully!

// Retrieve task details by name
> get-task OOP_HW
Task name: OOP_HW
Task ID: 1
Due date: Thu Mar 14 00:00:00 2024
Status: ON HOLD
Task desc: oop hw desc

// Update the task name
> update-task-name 1 OOP_PR
Task name updated successfully!

// Mark the task as in process
> start-task 1
Task started successfully!

// Retrieve task details by ID
> get-task 1
Task name: OOP_PR
Task ID: 1
Due date: Thu Mar 14 00:00:00 2024
Task desc: oop hw desc 
Status: IN PROCESS

// Create a new collaboration
> add-collaboration collab
Collaboration added successfully!

// Add a user to the collaboration
> add-user collab user567
User added successfully to collab!

// Assign a task to a user within the collaboration
> assign-task collab user567 Group_project 2024-03-15 "example desc"
Task assigned successfully to user567!

// Log out
> logout
Logged out successfully!

// Log in as the new user
> login user567 567
Welcome back user567!

// List all tasks for the current user
> list-tasks
Task name: Group_project
Task ID: 1287
Due date: Fri Mar 15 00:00:00 2024
Task desc: example desc
Status: ON HOLD

// List all collaborations the user is part of
> list-collaborations
collab

// List all tasks within a collaboration
> list-tasks collab
Tasks for collab:
Task name: Group_project
Task ID: 1287
Due date: Fri Mar 15 00:00:00 2024
Task desc: example desc
Status: ON HOLD
Assignee: user567

// Add another task
> add-task OOP_test 2024-03-15 "test desc"
Task added successfully!

// Retrieve task details by name
> get-task OOP_test
Task name: OOP_test
Task ID: 1299
Due date: Fri Mar 15 00:00:00 2024
Task desc: test desc
Status: ON HOLD

// Add a task to the dashboard
> add-task-to-dashboard 1287
Task added to dashboard successfully!

// List all tasks in the dashboard for today
> list-dashboard
Dashboard:
Task name: Group_project
Task ID: 1287
Due date: Fri Mar 15 00:00:00 2024
Task desc: example desc
Status: ON HOLD
Assignee: user567

// List all tasks due on a specific date
> list-tasks 2024-03-15
Task name: Group_project
Task ID: 1287
Due date: Fri Mar 15 00:00:00 2024
Task desc: example desc
Status: ON HOLD
Assignee: user567

Task name: OOP_test
Task ID: 1299
Due date: Fri Mar 15 00:00:00 2024
Task desc: test desc
Status: ON HOLD

// Mark a task as completed
> finish-task 1299
Congratulations on completing the task!

// Delete a task
> delete-task 1299
Task deleted successfully!

// Log out
> logout
Logged out successfully!

// Exit the program
> exit
Exited successfully!
```

These examples cover all the options of the Task Manager, providing a clear understanding of the user input, program output, and real-world scenarios where the tool can be applied.