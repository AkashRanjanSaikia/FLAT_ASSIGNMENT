# String Transformation Utilities

**Submitted By:** Akash Ranjan Saikia <br>
**Roll Number:** 230710007003
#

This project implements three simple string transformation utilities in **C++**.  
Each program is standalone and demonstrates basic operations on strings and digits.

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

Before running the programs, ensure that the following tools are available on your system:

* A Linux distribution.  
* A C++ compiler, for example `g++`.  
* **Anaconda** or **Miniconda** – a Python distribution that includes `conda` for package and environment management.  
* **Graphviz** – useful for generating and viewing program visualizations.  

---

## Installation and Setup

Follow these steps to set up the environment and dependencies.

### 1. Clone the Repository
First, clone this repository to your local machine:
```bash
git clone https://github.com/AkashRanjanSaikia/FLAT_ASSIGNMENT.git
cd FLAT_ASSIGNMENT
```

### 2. Set Up the Conda Environment
We will use a dedicated Conda environment to manage the OpenFST dependency.

**a. Create and activate the environment:**
```bash
conda create -n fstenv
conda activate fstenv
```

**b. Install OpenFST:**
This command installs the OpenFST library and its dependencies from the `conda-forge` channel.
```bash
conda install -c conda-forge openfst -y
```

**c. Install Graphviz:**
Graphviz is required to generate `.png` diagrams from the `.dot` files created by the application.
```bash
sudo apt update
sudo apt install graphviz -y
```
Your environment is now ready!

---
## 🛠️ Building and Running the Programs

Make sure your `fstenv` Conda environment is active before proceeding. All commands should be run from the project root directory.

---

### 1. String Reversal

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
```bash
Enter a string to reverse: Hello World
✅ FST saved to: 'output/string_reversal.fst'
🖼️  Diagram saved to: 'output/string_reversal.png'
🔁 Reversed string: dlroW olleH

```
---
### 2. Case Conversion

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
```bash
Enter a string to convert case: hello world
✅ FST saved to: 'output/case_conversion.fst'
🖼️  Diagram saved to: 'output/case_conversion.png'
🔠 Converted string: HELLO WORLD

```
---
### 3.Digit-to-Word Conversion

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
```bash
Enter string with digits to convert: 1234
✅ FST saved to: 'output/digit_to_word.fst'
🖼️  Diagram saved to: 'output/digit_to_word.png'
🔢 Converted string: one two three four


```
