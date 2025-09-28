# String Transformation Utilities

**Submitted By:** Akash Ranjan Saikia <br>
**Roll Number:** 230710007003
#

This project implements three simple string transformation utilities in **C++**.  
Each program is standalone and demonstrates basic operations on strings and digits.

---

## 1. Files Overview

| File | Description |
|------|-------------|
| `string_reversal.cpp` | Reverses the characters of a given string. |
| `case_conversion.cpp` | Converts uppercase letters to lowercase and vice versa. |
| `digit_to_word.cpp`   | Converts digits (0–9) into their English word representation. |

---

## 2. Prerequisites

Before running the programs, ensure that the following tools are available on your system:

* A Linux distribution.  
* A C++ compiler, for example `g++`.  
* **Anaconda** or **Miniconda** – a Python distribution that includes `conda` for package and environment management.  
* **Graphviz** – useful for generating and viewing program visualizations.  

---

## 🚀 Installation and Setup

Follow these steps to set up the environment and dependencies.

### 1. Clone the Repository
First, clone this repository to your local machine:
```bash
git clone [https://github.com/BK2918110/FLAT-assignment.git](https://github.com/BK2918110/FLAT-assignment.git)
cd FLAT-assignment
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
