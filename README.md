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
> signup
Username(Username must be at least 3 symbols): user123 
Password(Password must be at least 8 symbols): 12345678
Registered successfully!

// Log in as the new user
> login user123 12345678
Welcome back user123!

// Add a new task
> add-task OOP_HW 2024-03-17 "oop hw desc"
Task added successfully!
    
// Add a new task
> add-task OOP_HW 2024-03-24 "oop oop"
Task added successfully!

// List all tasks for the current user
> list-all-tasks
Task Name: OOP_HW
Task ID: 26678
Due Date: Sun Mar 17 00:00:00 2024
Task Status: ON_HOLD
Task Description: oop hw desc
-------------------------
Task Name: OOP_HW
Task ID: 3228
Due Date: Sun Mar 24 00:00:00 2024
Task Status: ON_HOLD
Task Description: oop oop
-------------------------
    
// Retrieve task details by name
> get-task OOP_HW
Task Name: OOP_HW
Task ID: 3228 (same name, but with a smaller index)
Due Date: Sun Mar 17 00:00:00 2024
Task Status: ON_HOLD
Task Description: oop oop

// Update the task name
> update-task-name 26678 OOP_PR
Task with ID 26678 has new name: OOP_PR

// Mark the task as in process
> start-task 26678
Task started successfully!

// Retrieve task details by ID
> get-task 26678
Task name: OOP_PR
Task ID: 26678
Due date: Thu Mar 14 00:00:00 2024
Status: IN_PROCESS
Task desc: oop hw desc 

// Create a new collaboration
> add-collaboration collab
Collaboration added successfully!

// Add a user to the collaboration
> add-user collab user567
User added to collaboration!

// Assign a task to a user within the collaboration
> assign-task collab user567 Group_project 2024-03-17 "example desc"
Task assigned successfully to user567!

// Log out
> logout
Logged out! Goodbye!

// Log in as the new user
> login user567 66666666
Welcome back user567!

// List all collaborations the user is part of
> list-collaborations
Collaborations for user user567:
Collaboration name: collab

// List all tasks within a collaboration
> list-tasks-by-collabName collab
Collaboration name: collab
Task Name: Group_project
Task ID: 27570
Due Date: Sun Mar 17 00:00:00 2024
Description: example desc
Assignee: user567
-------------------------

// Add another task
> add-task OOP_test 2024-03-17 "test desc"
Task added successfully!

// Retrieve task details by name
> get-task OOP_test
Task name: OOP_test
Task ID: 21191
Due date: Sun Mar 17 00:00:00 2024
Status: ON_HOLD
Task desc: test desc

// Mark a task as completed
> finish-task 21191
Task finished successfully!
    
>get-task 21191
Task name: OOP_test
Task ID: 21191
Due date: Sun Mar 17 00:00:00 2024
Status: DONE
Task desc: oop test

// Delete a task
> delete-task 21191
Task deleted successfully!
    
>get-task 21191
Task with ID 21191 not found!

// Log out
> logout
Logged out! Goodbye!

// Exit the program
> exit
```

These examples cover all the options of the Task Manager, providing a clear understanding of the user input, program output, and real-world scenarios where the tool can be applied.