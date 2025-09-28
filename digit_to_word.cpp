#include <fst/fstlib.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <unordered_map>

namespace fs = std::filesystem;

void saveFSTArtifacts(const fst::StdVectorFst &fst, const std::string &basename) {
    std::string folder = "output";
    if (!fs::exists(folder)) fs::create_directory(folder);

    std::string fst_file = folder + "/" + basename + ".fst";
    std::string dot_file = folder + "/" + basename + ".dot";
    std::string png_file = folder + "/" + basename + ".png";

    fst.Write(fst_file);

    std::string draw_cmd =
        "cd " + folder + " && "
        "fstdraw --isymbols=../ascii.syms --osymbols=../ascii.syms "
        + basename + ".fst > " + basename + ".dot && "
        "dot -Tpng " + basename + ".dot -o " + basename + ".png";

    system(draw_cmd.c_str());

    std::cout << "✅ FST saved to: '" << fst_file << "'\n";
    std::cout << "🖼️  Diagram saved to: '" << png_file << "'\n";
}

void digitToWordConversion(const std::string &input) {
    fst::StdVectorFst fst;
    fst.AddState();
    fst.SetStart(0);

    int state_id = 1;
    int current_state = 0;

    std::unordered_map<char, std::string> digit_words = {
        {'0', "zero"},
        {'1', "one"},
        {'2', "two"},
        {'3', "three"},
        {'4', "four"},
        {'5', "five"},
        {'6', "six"},
        {'7', "seven"},
        {'8', "eight"},
        {'9', "nine"},
    };

    for (char c : input) {
        if (digit_words.find(c) != digit_words.end()) {
            // Expand states for each letter in the word output
            const std::string &word = digit_words[c];
            int prev_state = current_state;

            for (size_t i = 0; i < word.size(); ++i) {
                fst.AddState();
                // Input label is digit char, only on first arc; others have input label = 0 (epsilon)
                int ilabel = (i == 0) ? static_cast<int>(c) : 0;
                int olabel = static_cast<int>(word[i]);
                fst.AddArc(prev_state, fst::StdArc(ilabel, olabel, fst::TropicalWeight::One(), state_id));
                prev_state = state_id;
                ++state_id;
            }

            current_state = prev_state;

        } else {
            // Just copy char (input=output)
            fst.AddState();
            fst.AddArc(current_state, fst::StdArc(static_cast<int>(c), static_cast<int>(c), fst::TropicalWeight::One(), state_id));
            current_state = state_id;
            ++state_id;
        }
    }

    fst.SetFinal(current_state, fst::TropicalWeight::One());

    saveFSTArtifacts(fst, "digit_to_word");

    // Create output string for display (digits replaced with words)
    std::string converted;
    for (char c : input) {
        if (digit_words.find(c) != digit_words.end()) {
            converted += digit_words[c] + " ";
        } else {
            converted += c;
        }
    }

    std::cout << "🔢 Converted string: " << converted << std::endl;
}

int main() {
    std::string input;
    std::cout << "Enter string with digits to convert: ";
    std::getline(std::cin, input);

    digitToWordConversion(input);

    return 0;
}
