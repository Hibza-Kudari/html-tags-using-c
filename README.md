
# 🖥️ Checking HTML Tags Using C  

## 🌟 Introduction  

The **HTML Tag Checker** is a mini-project in **C** that verifies whether HTML tags are properly **balanced** using a stack-based approach. It helps demonstrate the application of **data structures** (stack) for parsing and validating simple markup. This project is developed as part of academic coursework to showcase programming fundamentals and clean coding practices.  

---  

## 🎯 Objectives  

- **📑 Validate HTML Structure**: Check if opening and closing tags match correctly.  
- **📦 Apply Stack Data Structure**: Use stack operations for parsing nested tags.  
- **⚡ Lightweight & Fast**: Minimal overhead with simple C implementation.  
- **🎓 Academic Demonstration**: Serve as a learning tool for stack-based parsing.  

---  

## ⚙️ System Overview  

### 🔌 Components Used:  
- C Language (GCC Compiler)  
- Standard I/O & String Libraries  
- Stack Implementation in C  

---

### 🚀 Workflow:  
1. **Input**: Read HTML code (from file or standard input).  
2. **Tag Extraction**: Identify tags enclosed in `< >`.  
3. **Stack Processing**: Push opening tags, pop when closing tags are found.  
4. **Validation**: Check if all tags are matched and stack ends empty.  
5. **Output**: Print result — either *balanced* or *not balanced*.  

---    

## 📜 Algorithm Outline  

1. **Input Handling**: Read the HTML content from a file or standard input (e.g., using `fgets`).  
2. **Tag Detection**: Loop through the input string to find `<` and `>` that denote tags.  
3. **Stack Usage**: Push opening tags onto the stack. On encountering a closing tag, check if it matches the top of the stack. If yes, pop; otherwise, flag an error.  
4. **Error Handling**: If the stack is not empty at the end, it indicates unclosed tags → invalid structure.  
5. **Output**: Print feedback on whether the tags are balanced and well-formed.  

---

## 🗃️ Repository Structure  

| File/Folder               | Description                                |
|----------------------------|--------------------------------------------|
| `src/check_html_tags.c`   | Main C program for HTML tag validation      |
| `examples/sample_valid.html` | Example HTML file with balanced tags      |
| `examples/sample_invalid.html` | Example HTML file with missing tags     |
| `Makefile`                | Build script for compiling the project      |
| `.gitignore`              | Ignored files (executables, temp files)     |
| `README.md`               | Project documentation                      |
| `LICENSE`                 | MIT License file                           |  

---  

## 📈 Features and Benefits  

- ✅ **Stack-Based Parsing**: Demonstrates core data structure concepts.  
- 🔄 **Simple CLI Tool**: Easy to compile and run on any system.  
- 📊 **Educational Use**: Perfect for showcasing in academic projects.  
- 🧩 **Extendable**: Can be enhanced to handle attributes, self-closing tags, etc.  

---  

## 🔮 Future Scope  

- 📱 Handle **self-closing tags** (`<br/>`, `<img />`, etc.).  
- 🛠️ Support for **HTML attributes** inside tags.  
- 📝 Improved error reporting (line/position of mismatched tag).  
- 🌐 Extend to partial HTML parsing beyond tag validation.  

---  

## 📜 License  

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.  

---

## 👨‍💻 Developed for  

**DSA (Data Structures and Algorithms Laboratory)**  
