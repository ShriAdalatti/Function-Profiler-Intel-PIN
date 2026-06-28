# Function Profiler & Call Graph Generator using Intel Pin

A function-level profiler developed using Intel Pin Dynamic Binary Instrumentation (DBI) to analyze runtime program execution, collect instruction-level statistics, and generate graphical call graphs for performance analysis.

---

## Project Overview 

This project was developed as part of my Computer Architecture course to understand how runtime program profiling works using Intel Pin.

The profiler dynamically instruments a target program during execution without modifying its source code. It records the number of instructions executed by each function, tracks caller-callee relationships, and generates both a profiling report and a graphical call graph. The project helped me explore dynamic binary instrumentation, function profiling, and software performance analysis.

---

## Features

- Dynamic function instrumentation using Intel Pin
- Function-wise instruction counting
- Function call counting
- Caller–callee relationship tracking
- Graphviz-based call graph generation
- Performance hotspot identification
- Profiling report similar to GNU gprof

---

## Technologies Used

- **Language:** C++
- **Framework:** Intel Pin
- **Visualization:** Graphviz
- **Compiler:** GCC
- **Operating System:** Ubuntu (WSL)

---

## How It Works

```text
Target Program
      │
      ▼
 Intel Pin
      │
      ▼
Function Instrumentation
      │
      ▼
Instruction Counting
      │
      ▼
Call Tracking
      │
      ▼
Generate Reports
      │
      ▼
Graphviz Call Graph
```

---

## Project Structure

```text
Function-Profiler-Intel-PIN
│
├── src/
│   └── funccount.cpp
│
├── sample_programs/
│   ├── hello.c
│   └── heavy.c
│
├── outputs/
│   ├── funccount.out
│   ├── graph.png
│   └── final.png
│
├── docs/
├── README.md
└── LICENSE
```

---

## Sample Output

The profiler generates a graphical call graph showing function hierarchy, instruction counts, execution percentages, and performance hotspots.

<p align="center">
<img src="outputs/callgraph.dot" width="90%">
</p>

From the generated output:

- `matrix_multiply()` accounts for most of the executed instructions, making it the primary performance hotspot.
- The call graph clearly shows caller-callee relationships.
- Recursive functions such as `fib()` and `factorial()` are also captured correctly.

---

## Generated Files

### funccount.out

Contains:

- Function name
- Instruction count
- Number of function calls
- Percentage of total instructions

### callgraph.dot

Graphviz representation of the generated call graph.

### callgraph.png

Graphical visualization of function execution and call relationships.

---

## How to Run

```bash
cd ~/pin_kit/source/tools/ManualExamples

gcc -O0 -g -o hello hello.c -lm

make PIN_ROOT=~/pin_kit obj-intel64/funccount.so

~/pin_kit/pin -t obj-intel64/funccount.so -- ./hello

cat funccount.out

dot -Tpng callgraph.dot -o callgraph.png
```

---

## Applications

- Software performance analysis
- Performance hotspot detection
- Program execution analysis
- Software optimization
- Compiler and Operating Systems research

---

