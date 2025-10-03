# simple-grep

![C++](https://img.shields.io/badge/C%2B%2B-blue)

## Project Description 📝

`simple-grep` is a command-line tool meticulously crafted in C++ that emulates the core functionality of the widely-used `grep` utility. This project provides a streamlined and efficient way to search for patterns within text files. Unlike its full-fledged counterpart, `simple-grep` is designed with simplicity and resource efficiency in mind, making it an excellent choice for embedded systems, environments with limited resources, or as a learning tool to understand the inner workings of text searching algorithms.

This project addresses the need for a lightweight grep alternative. While the standard `grep` is incredibly powerful, its complexity can be overkill for simple search tasks. `simple-grep` offers a faster startup time and a smaller memory footprint, making it ideal for situations where performance and resource constraints are paramount. It's also a valuable resource for developers who wish to delve into the implementation details of text searching algorithms, providing a clear and concise codebase to study and modify.

The target audience for `simple-grep` includes system administrators managing resource-constrained servers, embedded systems developers looking for a lean search tool, and students or hobbyists interested in learning C++ and text processing techniques. Its straightforward design makes it easy to understand and adapt, making it a versatile addition to any developer's toolkit.

## Key Features ✨

*   **Basic Pattern Matching:** Searches for lines in a file that match a given regular expression pattern. This allows users to quickly identify lines containing specific text or adhering to a certain structure.
*   **File Input:** Accepts a filename as an argument, enabling users to specify the file to be searched. This facilitates targeted searches within specific documents or data files.
*   **Case-Sensitive Search:** Performs searches that are sensitive to the case of the characters. This allows for more precise filtering of search results, ensuring that only lines with the exact capitalization are returned.
*   **Line Number Output:** Displays the line number of each matching line. This feature greatly simplifies the process of locating the relevant lines within the file.

## Tech Stack & Tools 🛠️

| Category   | Technology/Tool | Description                                              |
| :--------- | :-------------- | :------------------------------------------------------- |
| Language   | C++             | The primary programming language used for the project.   |
| Build Tool | Make            | Used for automating the build process.                   |
| IDE/Editor | Any             | A text editor or IDE for writing and editing the code.  |
| OS         | Any             | Compatible with any OS that supports C++ compilation.   |
| Other      | .gitignore      | Specifies intentionally untracked files that Git should ignore|

## Installation & Running Locally 🚀

**Prerequisites:**

*   A C++ compiler (e.g., g++)
*   Make

**Steps:**

1.  **Clone the repository:**

    ```bash
    git clone https://github.com/Gaeuly/simple-grep.git
    ```

2.  **Navigate to the project directory:**

    ```bash
    cd simple-grep
    ```

3.  **Build the project using Make:**

    ```bash
    make
    ```

4.  **Run the program. Provide the pattern and the file as arguments:**

    ```bash
    ./simple_grep "pattern" "filename.txt"
    ```

    *Replace `"pattern"` with the search term and `"filename.txt"` with the name of the file you want to search within.* For example:
    ```bash
    ./simple_grep "hello" "example.txt"
    ```

## How to Contribute 🤝

We welcome contributions to `simple-grep`! If you'd like to contribute, please follow these steps:

1.  Fork the repository.
2.  Create a new branch for your feature or bug fix.
3.  Implement your changes, ensuring clean and well-documented code.
4.  Submit a pull request with a detailed description of your changes.