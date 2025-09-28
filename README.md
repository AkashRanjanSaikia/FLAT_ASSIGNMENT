# FLAT Assignment — Mini FST-based String Transducers

This repository implements a few simple string transformations using **OpenFST**, with each transformation constructed as an FST and visualized as a graph.

---

## Transformations Implemented

- **String Reversal** — reverse the characters of a string  
- **Case Conversion** — convert lowercase letters to uppercase  
- **Digit‑to‑Word Conversion** — convert digits (0–9) to their English words (with spaces)  

Each program builds an FST for the transformation, saves the `.fst`, `.dot`, and `.png` outputs in an `output/` folder, and prints the transformed string.

---

## Getting Started

### Prerequisites

- C++17 compiler (g++)  
- OpenFST library installed (development headers + shared libs)  
- Graphviz (`dot`) for generating `.png` from `.dot`  
- `ascii.syms` symbol table file in project root  

### Building

Compile each transformation program separately. For example:

```bash
g++ -std=c++17 string_reversal.cpp -lfst -lstdc++fs -o string_reversal
g++ -std=c++17 case_conversion.cpp -lfst -lstdc++fs -o case_conversion
g++ -std=c++17 digit_to_word.cpp -lfst -lstdc++fs -o digit_to_word
