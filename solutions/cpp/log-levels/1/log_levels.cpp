#include <string>
#include <iterator>

namespace log_line {

    std::string LEVELS[3] = {
        "[INFO]: ",
        "[WARNING]: ",
        "[ERROR]: "
    };

    std::string delete_multiple_occurrences(
        std::string line,
        const std::string& word
    ) {
        std::size_t pos;
        while ((pos = line.find(word)) != std::string::npos) {
            line.erase(pos, word.size());
        }
        return line;
    }

    std::string message(std::string line) {
        for (std::size_t i = 0; i < std::size(LEVELS); ++i) {
            std::size_t pos = line.find(LEVELS[i]);
            if (pos != std::string::npos) {
                line.erase(pos, LEVELS[i].size());
                return line;
            }
        }
        return line;
    }

    std::string log_level(std::string line) {
        for (std::size_t i = 0; i < std::size(LEVELS); ++i) {
            if (line.find(LEVELS[i]) != std::string::npos) {
                std::string level = LEVELS[i];
                level = delete_multiple_occurrences(level, "[");
                level = delete_multiple_occurrences(level, "]");
                level = delete_multiple_occurrences(level, ": ");
                return level;
            }
        }
        return "";
    }

    std::string reformat(std::string line) {
        for (std::size_t i = 0; i < std::size(LEVELS); ++i) {
            std::size_t pos = line.find(LEVELS[i]);
            if (pos != std::string::npos) {
                line.erase(pos, LEVELS[i].size());

                std::string level = LEVELS[i];
                level = delete_multiple_occurrences(level, "[");
                level = delete_multiple_occurrences(level, "]");
                level = delete_multiple_occurrences(level, ": ");

                return line + " (" + level + ")";
            }
        }
        return line;
    }
}
