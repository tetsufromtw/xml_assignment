# XML Assignment
This XML Assignment is designed to determine the validity of XML strings based on specific criteria. The definition of a valid XML string for this project is derived from the guidelines provided at the following link: [Take home coding test (XML)](https://boostdraft.notion.site/Take-home-coding-test-XML-6c2748a51a814111a374e2370d17c772).

## Overview
This XML Validator, developed in **C++**, supports validating XML strings through two methods: **standard input (stdin)** and **file input**. 

This flexibility accommodates various user preferences and testing scenarios.

## XMLValidator
The **`XMLValidator`** is a core component of this project, responsible for assessing the validity of XML strings. It implements specific rules to check whether each XML string is well-formed and correctly structured. The Validator works by:

1. **Parsing the Input**: Depending on the chosen input method (stdin or file), the XML string is read and prepared for validation.
2. **Validating the Structure**: The Validator checks each XML string for correct tag pairing and proper nesting of elements.
3. **Returning the Results**: After validation, the XML Validator outputs whether the XML string is valid(`true`) or not(`false`).

This tool is designed to be simple yet effective, ensuring that XML strings not only adhere to the fundamental principles of XML structure but also comply with the rules defined in [Take home coding test (XML)](https://boostdraft.notion.site/Take-home-coding-test-XML-6c2748a51a814111a374e2370d17c772).

## File Structure
- **main.cpp**: The main program entry, demonstrating how to use the XML Validator.
- **xml_validator.cpp**: Contains the implementation of the XML Validator.
- **xml_validator.hpp**: The header file for the XML Validator, declaring necessary classes and methods.
- **sample.txt**: Contains XML string samples for testing the validator.
## Compilation
Compile the program using the following command:
```
g++ -std=c++17 main.cpp xml_validator.cpp -o <executable-name>
```
This command instructs the compiler to use the C++17 standard to compile the **`main.cpp`** and **`xml_validator.cpp`** files, and to name the resulting executable as **`<executable-name>`**.

Note: If the **`-o`** option is omitted, the compiler will generate an executable named **`a.out`** by default.

### Example
```
g++ -std=c++17 main.cpp xml_validator.cpp -o xml_validator
```

## Execution (standard input)
To run the XML Validator using standard input, execute the compiled program **without** any arguments:

```
./xml_validator
```
After executing this command, you can manually enter the XML string into the terminal. The program will then process this input and display the validation result.

## Execution (file input)
To run the XML Validator with file input, provide the file name as an argument when executing the compiled program:
```
./xml_validator sample.txt
```
In this example, sample.txt is the filename that contains **multiple** XML strings for validation. The program reads each XML string from the file, processes them one by one, and then displays the validation results for each string.



