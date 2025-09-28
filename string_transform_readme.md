# String Transformation Utilities

**Submitted By:** Akash Ranjan Saikia  
**Roll Number:** 230710007003

This project implements three standalone **C++** programs that perform basic string transformations. Each program demonstrates simple operations on strings or digits using finite-state transducers (FSTs).

---

## 1. Files Overview

| File / Folder        | Description |
|---------------------|-------------|
| `string_reversal.cpp` | Reverses the characters of a given string. |
| `case_conversion.cpp` | Converts uppercase letters to lowercase and vice versa. |
| `digit_to_word.cpp`   | Converts digits (0–9) into their English word representation. |
| `ascii.syms`          | Symbol table used by the FST programs for input/output mapping. |
| `output/`             | Folder where the generated `.fst` and `.png` diagram files are saved. |

---

## 2. Prerequisites

Before running the programs, make sure the following tools are installed:

* A Linux-based system (Ubuntu 24.04 recommended).  
* A C++ compiler, e.g., `g++`.  
* **Anaconda** or **Miniconda** – provides `conda` for package and environment management.  
* **Graphviz** – required to generate and view program visualizations.  

---

## 3. Installation and Setup

### 3.1 Clone the Repository
```bash
git clone https://github.com/AkashRanjanSaikia/FLAT_ASSIGNMENT.git
cd FLAT_ASSIGNMENT
```

### 3.2 Set Up the Conda Environment

**Create and activate a dedicated environment:**
```bash
conda create -n fstenv
conda activate fstenv
```

**Install OpenFST from conda-forge:**
```bash
conda install -c conda-forge openfst -y
```

**Install Graphviz:**
```bash
sudo apt update
sudo apt install graphviz -y
```

✅ Your environment is now ready.

---

## 4. 🛠️ Building and Running the Programs

Ensure the `fstenv` Conda environment is active and run all commands from the project root.

---

### 4.1 String Reversal

**Compile the program:**
```bash
g++ -std=c++17 -I$CONDA_PREFIX/include -L$CONDA_PREFIX/lib string_reversal.cpp -lfst -lstdc++fs -o string_reversal
```

**Set library path:**
```bash
export LD_LIBRARY_PATH=$CONDA_PREFIX/lib:$LD_LIBRARY_PATH
```

**Run the program:**
```bash
./string_reversal
```

**Example Interaction:**
```
Enter a string to reverse: Hello World
✅ FST saved to: 'output/string_reversal.fst'
🖼️  Diagram saved to: 'output/string_reversal.png'
🔁 Reversed string: dlroW olleH
```

---

### 4.2 Case Conversion

**Compile the program:**
```bash
g++ -std=c++17 -I$CONDA_PREFIX/include -L$CONDA_PREFIX/lib case_conversion.cpp -lfst -lstdc++fs -o case_conversion
```

**Set library path:**
```bash
export LD_LIBRARY_PATH=$CONDA_PREFIX/lib:$LD_LIBRARY_PATH
```

**Run the program:**
```bash
./case_conversion
```

**Example Interaction:**
```
Enter a string to convert case: hello world
✅ FST saved to: 'output/case_conversion.fst'
🖼️  Diagram saved to: 'output/case_conversion.png'
🔠 Converted string: HELLO WORLD
```

---

### 4.3 Digit-to-Word Conversion

**Compile the program:**
```bash
g++ -std=c++17 -I$CONDA_PREFIX/include -L$CONDA_PREFIX/lib digit_to_word.cpp -lfst -lstdc++fs -o digit_to_word
```

**Set library path:**
```bash
export LD_LIBRARY_PATH=$CONDA_PREFIX/lib:$LD_LIBRARY_PATH
```

**Run the program:**
```bash
./digit_to_word
```

**Example Interaction:**
```
Enter string with digits to convert: 1234
✅ FST saved to: 'output/digit_to_word.fst'
🖼️  Diagram saved to: 'output/digit_to_word.png'
🔢 Converted string: one two three four
```

---