#include <fst/fstlib.h>
#include <iostream>
#include <string>
#include <filesystem> // C++17

namespace fs = std::filesystem;

void saveFSTArtifacts(const fst::StdVectorFst &fst, const std::string &basename) {
    std::string folder = "output";

    // Create folder if it doesn't exist
    if (!fs::exists(folder)) {
        fs::create_directory(folder);
    }

    std::string fst_file = folder + "/" + basename + ".fst";
    std::string dot_file = folder + "/" + basename + ".dot";
    std::string png_file = folder + "/" + basename + ".png";

    // Save the FST to the output folder
    fst.Write(fst_file);

    // Create command that runs from inside the output folder
    std::string draw_cmd =
        "cd " + folder + " && "
        "fstdraw --isymbols=../ascii.syms --osymbols=../ascii.syms "
        + basename + ".fst > " + basename + ".dot && "
        "dot -Tpng " + basename + ".dot -o " + basename + ".png";

    system(draw_cmd.c_str());

    std::cout << "✅ FST saved to: '" << fst_file << "'\n";
    std::cout << "🖼️  Diagram saved to: '" << png_file << "'\n";
}


void stringReversal(const std::string &input) {
    fst::StdVectorFst fst;
    fst.AddState();
    fst.SetStart(0);

    int prev_state = 0, state_id = 1;

    for (int i = static_cast<int>(input.size()) - 1; i >= 0; --i) {
        fst.AddState();
        fst.AddArc(prev_state, fst::StdArc(
            static_cast<int>(input[i]),
            static_cast<int>(input[i]),
            fst::TropicalWeight::One(),
            state_id));
        prev_state = state_id;
        ++state_id;
    }

    fst.SetFinal(prev_state, fst::TropicalWeight::One());

    saveFSTArtifacts(fst, "string_reversal");

    std::string reversed(input.rbegin(), input.rend());
    std::cout << "🔁 Reversed string: " << reversed << std::endl;
}

int main() {
    std::string input;
    std::cout << "Enter string to reverse: ";
    std::getline(std::cin, input);

    stringReversal(input);

    return 0;
}
