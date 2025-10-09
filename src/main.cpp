#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

// Fungsi untuk mengubah string menjadi lowercase
std::string to_lower(const std::string& str) {
    std::string lower_str = str;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return lower_str;
}

// --- PERUBAHAN DI SINI ---
// Fungsi pencarian sekarang menerima argumen 'count_only'
void search_in_file(const std::string& file_path, const std::string& search_term, bool case_sensitive, bool count_only) {
    std::ifstream input_file(file_path);

    if (!input_file.is_open()) {
        std::cerr << "Error: Gagal membuka file '" << file_path << "'" << std::endl;
        exit(1);
    }

    std::string line;
    int line_number = 0;
    int match_count = 0; // Variabel untuk menghitung jumlah kecocokan

    std::string term_to_find = case_sensitive ? search_term : to_lower(search_term);

    while (std::getline(input_file, line)) {
        line_number++;
        
        std::string line_to_search = case_sensitive ? line : to_lower(line);
        
        if (line_to_search.find(term_to_find) != std::string::npos) {
            // Jika mode count aktif, kita hanya increment counter
            if (count_only) {
                match_count++;
            } else {
                // Jika tidak, kita print barisnya seperti biasa
                std::cout << line_number << ": " << line << std::endl;
            }
        }
    }

    input_file.close();

    // --- PERUBAHAN OUTPUT ---
    // Setelah loop selesai, cek apakah kita harus print total count
    if (count_only) {
        std::cout << match_count << std::endl;
    } else if (match_count == 0) {
        // Pesan 'tidak ditemukan' hanya muncul jika bukan mode count
        std::cout << "Kata kunci '" << search_term << "' tidak ditemukan di dalam file." << std::endl;
    }
}

// Fungsi untuk menampilkan cara penggunaan program
void show_usage(const std::string& program_name) {
    std::cerr << "Penggunaan: " << program_name << " [FLAG] <kata_kunci> <path_file>" << std::endl;
    std::cerr << "FLAG (opsional):" << std::endl;
    std::cerr << "  -i: Pencarian case-insensitive" << std::endl;
    std::cerr << "  -c: Hanya menampilkan jumlah baris yang cocok" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        show_usage(argv[0]);
        return 1;
    }

    bool case_sensitive = true;
    bool count_only = false; // Flag baru untuk mode count
    std::string search_term;
    std::string file_path;

    // --- PERUBAHAN PARSING ARGUMEN ---
    if (argc == 4) {
        std::string flag = argv[1];
        if (flag == "-i") {
            case_sensitive = false;
        } else if (flag == "-c") { // Cek apakah flag-nya -c
            count_only = true;
        } else {
            show_usage(argv[0]);
            return 1;
        }
        search_term = argv[2];
        file_path = argv[3];
    } else { // argc == 3
        search_term = argv[1];
        file_path = argv[2];
    }

    // Panggil fungsi dengan flag yang sudah di-parsing
    search_in_file(file_path, search_term, case_sensitive, count_only);

    return 0;
}
