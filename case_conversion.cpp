#include <fst/fstlib.h>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void saveFSTArtifacts(const fst::StdVectorFst &fst, const std::string &basename) {
    std::string folder = "output";

    if (!fs::exists(folder)) {
        fs::create_directory(folder);
    }

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

void caseConversion(const std::string &input) {
    fst::StdVectorFst fst;
    fst.AddState();
    fst.SetStart(0);

    int prev_state = 0, state_id = 1;

    for (char c : input) {
        fst.AddState();

        int ilabel = static_cast<int>(c);
        int olabel;

        // Convert lowercase a-z (97-122) to uppercase A-Z (65-90)
        if (c >= 'a' && c <= 'z') {
            olabel = c - ('a' - 'A');
        } else {
            olabel = ilabel;
        }

        fst.AddArc(prev_state, fst::StdArc(ilabel, olabel, fst::TropicalWeight::One(), state_id));

        prev_state = state_id;
        ++state_id;
    }

    fst.SetFinal(prev_state, fst::TropicalWeight::One());

    saveFSTArtifacts(fst, "case_conversion");

    // Print converted string
    std::string converted;
    for (char c : input) {
        if (c >= 'a' && c <= 'z') {
            converted += c - ('a' - 'A');
        } else {
            converted += c;
        }
    }

    std::cout << "🔠 Converted string: " << converted << std::endl;
}

int main() {
    std::string input;
    std::cout << "Enter string to convert case: ";
    std::getline(std::cin, input);

    caseConversion(input);

    return 0;
}
