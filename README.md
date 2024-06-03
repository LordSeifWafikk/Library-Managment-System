# Library Management System

This is a simple Library Management System implemented in C++. It allows users to manage books, customers, and book issues. The system provides functionalities to add, delete, search, and display records.

## Features

- **User Management**:
  - Create a new user
  - Display existing user info
  - Remove customer by ID

- **Book Management**:
  - Add book to library
  - Remove a book from the library by ID
  - Display all books
  - Display book info by title
  - Display books of a certain category
  - Display books of a certain author

- **Issue Management**:
  - Allow a customer to borrow a book
  - Allow a customer to return a book

## Getting Started

### Prerequisites

To run this project, you need to have the following installed on your machine:

- A C++ compiler (GCC, Clang, MSVC, etc.)
- Makefile (optional, for ease of compilation)

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/LordSeifWafikk/Library-Managment-System
    ```

2. Navigate to the project directory:

    ```bash
    cd library-management-system
    ```

3. Compile the project:

    If you're using a Makefile, simply run:

    ```bash
    make
    ```

    Alternatively, you can compile the `main.cpp` file directly:

    ```bash
    g++ main.cpp -o library_management_system
    ```

### Usage

After compiling the project, run the executable:

```bash
./library_management_system
