# 简介-Introduction: 

A Ramdom Number Builder, It could help you build some ramdom value.
For example,
U can use it to match some rewards for your partner, family, workmate...


---

# 代码原理-There is a CODE AXIOM:


### Algorithm Analysis of "Random Number Builder" (English Version)

The provided code is a C++ program designed to generate random numbers with various modes and configurations. Below is a detailed analysis of the algorithm and its components.

---

### **1. Program Overview**
The program, named **Random Number Builder**, is a lightweight tool for generating random numbers. It operates in a console environment and provides several functionalities, including:
- **Random number generation** (with or without repetition).
- **Quick generation mode** for rapid random number generation.
- **Customizable settings** for delay, username, and range limits.
- **Help and algorithm display** for user guidance.

---

### **2. Key Components**

#### **2.1. Random Number Generation**
The core of the program relies on the `rand()` function from the C++ standard library. To ensure different random sequences each time the program runs, the `srand(time(0))` function is used to seed the random number generator with the current time.

- **`srand(time(0))`**: Initializes the random number generator with a seed based on the current time.
- **`rand()`**: Generates a pseudo-random number based on the seed.

#### **2.2. Modes of Operation**
The program supports two main modes for random number generation:
1. **Repetition Mode**:
   - Allows duplicate numbers in the output.
   - Users can specify an upper limit for the random numbers.
2. **Unique Mode**:
   - Ensures each number appears only once.
   - Users can specify both upper and lower limits for the random numbers.

#### **2.3. Quick Generation Mode**
This mode allows users to generate a large number of random values quickly. The program ensures that no duplicates are generated in this mode.

---

### **3. Algorithm Workflow**

#### **3.1. Initialization**
- The program starts by initializing various variables, including:
  - `memory[1000]`: An array to track generated numbers (used in unique mode).
  - `delays`: Controls the delay between displaying each random number.
  - `maxx`, `minx`: Define the range for random numbers in unique mode.
  - `Rapid_mode_Max`, `Rapid_mode_Min`: Define the range for quick generation mode.

#### **3.2. Main Loop**
The program enters a loop where users can select different functionalities:
- **Help (`\h`)**: Displays help information and usage tips.
- **Algorithm Display (`\c`)**: Shows the internal algorithm used for random number generation.
- **Random Number Generation (`\r`)**: Initiates the random number generation process.
- **Settings (`\s`)**: Allows users to modify settings such as delay time and username.
- **Quick Generation (`\1`)**: Enables rapid random number generation.
- **Exit (`\e`)**: Exits the program.

#### **3.3. Random Number Generation Process**
1. **User Input**:
   - The user specifies the number of random values to generate (up to 500).
   - The user chooses whether to allow duplicates (repetition mode) or enforce uniqueness (unique mode).
   - In unique mode, the user can also specify upper and lower limits for the random numbers.

2. **Random Number Generation**:
   - The program uses `rand()` to generate random numbers within the specified range.
   - In unique mode, the program checks the `memory` array to ensure no duplicates are generated.
   - In repetition mode, duplicates are allowed, and the program generates numbers within the specified upper limit.

3. **Output**:
   - The generated numbers are displayed in the console with a specified delay between each number.
   - The program provides feedback on the number of values generated and whether duplicates were allowed.

#### **3.4. Quick Generation Mode**
- This mode is optimized for speed and does not allow duplicates.
- The program generates random numbers within a predefined range (`Rapid_mode_Min` to `Rapid_mode_Max`).
- Users can reset the generation process or modify the number of random values to generate.

---

### **4. Settings and Customization**
The program allows users to customize certain parameters:
- **Delay Time**: Controls the delay between displaying each random number.
- **Username**: Allows users to set a custom username displayed in the console.

---

### **5. Error Handling**
The program includes basic error handling to ensure valid user input:
- Users must enter valid options (e.g., `Y` or `N` for yes/no questions).
- The program checks that the number of random values requested does not exceed the maximum limit (500).
- In unique mode, the program ensures that the range of numbers is sufficient to generate the requested number of unique values.

---

### **6. Algorithm Summary**
1. **Seed the random number generator** using `srand(time(0))`.
2. **Prompt the user** for the number of random values and the generation mode (repetition or unique).
3. **Generate random numbers**:
   - In repetition mode, allow duplicates and generate numbers within the specified range.
   - In unique mode, ensure no duplicates by tracking generated numbers in the `memory` array.
4. **Display the results** with a customizable delay.
5. **Provide options** to reset the generation process, modify settings, or exit the program.

---

### **7. Key Features**
- **Flexibility**: Supports both repetition and unique modes for random number generation.
- **Customization**: Allows users to modify settings such as delay time and username.
- **Quick Generation**: Optimized for rapid generation of random numbers without duplicates.
- **User-Friendly**: Provides clear prompts and error messages to guide users.

---

### **8. Example Workflow**
1. The user selects the random number generation mode (`\r`).
2. The user specifies the number of random values (e.g., 10) and chooses unique mode.
3. The program generates 10 unique random numbers within the specified range and displays them with a delay.
4. The user can choose to generate more numbers, modify settings, or exit the program.

---

### **9. Conclusion**
The **Random Number Builder** is a versatile and user-friendly tool for generating random numbers. Its modular design and customizable settings make it suitable for a variety of use cases, from simple random number generation to more complex scenarios requiring unique values or rapid generation.

### “随机数生成器”的算法分析（中文版）

所提供的代码是一个用 C++ 编写的程序，旨在生成具有多种模式和配置的随机数。以下是该算法及其组件的详细分析。

---

### **1. 程序概述**
该程序名为**随机数生成器**，是一款用于生成随机数的轻量级工具。它在控制台环境中运行，并提供了多种功能，包括：
- **随机数生成**（可重复或不重复）。
- **快速生成模式**，用于快速生成随机数。
- **可自定义设置**，包括延迟、用户名和范围限制。
- **帮助和算法显示**，为用户提供指导。

---


### 2. 关键组件

#### 2.1. 随机数生成
程序的核心依赖于 C++ 标准库中的 `rand()` 函数。为了确保每次运行程序时生成不同的随机序列，使用 `srand(time(0))` 函数以当前时间作为种子来初始化随机数生成器。

- **`srand(time(0))`**：使用当前时间作为种子来初始化随机数生成器。
- **`rand()`**：基于该种子生成一个伪随机数。

#### 2.2. 运行模式
该程序支持两种主要的随机数生成模式：1. **重复模式**：
- 允许输出中出现重复的数字。
- 用户可以指定随机数的上限。2. **独特模式**：
- 确保每个数字仅出现一次。
- 用户可以指定随机数的上限和下限。

#### **2.3. 快速生成模式**
此模式允许用户快速生成大量随机值。程序确保在此模式下不会生成重复值。

---


### 3. 算法工作流程

#### 3.1. 初始化
程序启动时会初始化各种变量，包括：
- `memory[1000]`：一个用于追踪生成数字的数组（在唯一模式下使用）。
- `delays`：控制显示每个随机数之间的延迟。
- `maxx`、`minx`：定义唯一模式下随机数的范围。
- `Rapid_mode_Max`、`Rapid_mode_Min`：定义快速生成模式下随机数的范围。

#### 3.2. 主循环
程序进入一个循环，在此循环中用户可以选择不同的功能：
- **帮助（`\h`）**：显示帮助信息和使用提示。
- **算法显示（`\c`）**：展示用于随机数生成的内部算法。
- **随机数生成（`\r`）**：启动随机数生成过程。
- **设置（`\s`）**：允许用户修改诸如延迟时间和用户名之类的设置。
- **快速生成（`\1`）**：启用快速随机数生成。
- **退出（`\e`）**：退出程序。

#### 3.3. 随机数生成过程1. 用户指定要生成的随机值的数量（最多 500 个）。
用户选择是否允许重复（重复模式）或强制唯一（唯一模式）。
在唯一模式下，用户还可以指定随机数的上限和下限。

2. **随机数生成**：
- 该程序使用 `rand()` 函数在指定范围内生成随机数。
- 在唯一模式下，程序会检查 `memory` 数组以确保不生成重复的数字。
- 在重复模式下，允许出现重复数字，程序会在指定的上限范围内生成数字。

3. - 生成的数字会在控制台中显示，且每个数字之间有指定的延迟。
- 程序会提供生成值的数量以及是否允许重复的反馈。

#### 3.4. 快速生成模式
- 此模式针对速度进行了优化，不允许出现重复数字。
- 程序在预定义的范围内（`Rapid_mode_Min` 至 `Rapid_mode_Max`）生成随机数。
- 用户可以重置生成过程或修改要生成的随机值数量。

---


### **4. 设置与自定义**
该程序允许用户自定义某些参数：
- **延迟时间**：控制显示每个随机数之间的延迟。
- **用户名**：允许用户设置在控制台中显示的自定义用户名。

---


### 5. 错误处理
该程序包含基本的错误处理机制，以确保用户输入有效：
- 用户必须输入有效的选项（例如，对于是/否问题，输入 `Y` 或 `N`）。
- 程序会检查请求的随机值数量是否未超过最大限制（500）。
- 在唯一模式下，程序会确保数字范围足够生成所请求数量的唯一值。

---


### 6. 算法总结1. 使用 `srand(time(0))` 来**初始化随机数生成器**。2. 提示用户输入随机值的数量以及生成模式（可重复或唯一）。3. **生成随机数**：
- 在重复模式下，允许重复并生成指定范围内的数字。
- 在唯一模式下，通过跟踪已生成的数字来确保无重复。
