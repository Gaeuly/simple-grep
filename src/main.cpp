#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Function to display usage instructions to the user
void show_usage(const std::string& program_name) {
    std::cerr << "Usage: " << program_name << " <keyword> <file_path>" << std::endl;
}

int main(int argc, char* argv[]) {
    // The program requires exactly 3 arguments:
    // argv[0]: program name (e.g., ./bin/simplegrep)
    // argv[1]: the keyword to search for
    // argv[2]: the file path
    if (argc != 3) {
        show_usage(argv[0]);
        return 1; // Exit with error code 1
    }

    // Get arguments from the command line
    std::string search_term = argv[1];
    std::string file_path = argv[2];

    // Create ifstream object to read the file
    std::ifstream input_file(file_path);

    // Check if the file was successfully opened
    if (!input_file.is_open()) {
        std::cerr << "Error: Failed to open file '" << file_path << "'" << std::endl;
        return 1; // Exit with error
    }

    std::string line;
    int line_number = 0;
    bool found = false;

    // Loop to read the file line by line
    while (std::getline(input_file, line)) {
        line_number++;
        // Search for search_term in the current line
        // std::string::npos means "not found"
        if (line.find(search_term) != std::string::npos) {
            std::cout << line_number << ": " << line << std::endl;
            found = true;
        }
    }

    // Close the file after reading
    input_file.close();

    if (!found) {
        std::cout << "Keyword '" << search_term << "' was not found in the file." << std::endl;
    }

    return 0; // Success
}