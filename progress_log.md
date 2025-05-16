# 📘 Progress Log – Student Data Management System
---

## 📅 2/5/25 – Day 1

- Started working on the Student Data Management System (SMS) project.
- Realized I needed to learn `struct` and file handling in C++, so I decided to learn as I build.
- Felt really confused and unclear at the beginning, but gradually started gaining clarity and confidence.
- Focused on understanding how things work instead of copying code.
- Researched and asked questions to figure out how to implement the logic I needed.
- Implemented:
  - ✅ `Add Student` feature using `struct` and file handling
  - ✅ Input validation for correct entry
  - ✅ Re-entry logic if incorrect details are entered
- Feeling more confident now.

---

## 📅 3/5/25 – Day 2

- Continued development of the Student Data Management System (SMS).
- Faced an issue with input validation:
  - `std::cin.fail()` was used to detect non-integer inputs when integers were expected.
  - Realized it doesn’t work the same when integers are entered where characters are expected (e.g., names).
- Researched and found a more reliable solution using:
  - `std::all_of()` for iterating over characters
  - `std::isalpha()` and `std::isspace()` to validate names
- Implemented a reusable `isValidName()` function to cleanly handle name input validation.
- Learned how STL algorithms and character handling functions improve input reliability.
- Felt proud of solving a real bug through self-research and understanding.

---

## 8/5/25 – Day 3 

- Took a short break from the project due to internal exams.
- Implemented the `display_student()` functionality successfully.
- Learned how to use `ifstream()` for file input and `setw()` for formatted output.
- Faced an issue where student data wasn't being displayed in a proper table format.
- Investigated the issue and discovered that the `>>`operator fails when reading strings with  whitespaces.
- Resolved it by using `getline()` to read the full line, and then used stringstream to parse individual elements.

---

## 9/5/25 - Day 4

- Successfully implemented the `search_student()` functionality.
- Through some quick surface-level searching, I identified the logic: use `getline()` to extract   lines from the file, and `find()` to check for a matching registration number.
- If a match is found, the line is treated as a stream using `std::stringstream`, and the individual   fields are parsed to display the student’s details.
- Faced a bug where the output always showed`“match not found.”`
- I was able to debug it myself and discovered the issue: I had declared `searchkey` as an int when it should have been a string.

---

## 13/5/25 - Day 5

- Due to ongoing semester exams, couldn't check in regularly.
- Implemented the `update_student()` functionality successfully.
- Learned that C++ file handling doesn't support in-place editing of text files.
- Worked around it by writing updated content to a temporary file `temp.txt` and replacing the original using `remove()` and `rename()`.
- Faced several bugs during implementation (e.g., incorrect parsing of CGPA), but was able to resolve them through trial and intuition.
- Felt that prior knowledge is compounding — many logical steps came naturally, which feels rewarding.

---

## 16/5/25 - Day 6

- Successfully implemented the `delete_student()` functionality.
- Reused the core logic from the `update_student()` function:
reading from `student.txt`, conditionally writing to a `temp.txt`, and replacing the original file.
- Encountered a bug where the `regNo` was getting replaced by 0 during iteration.

- Traced the issue to an incorrect use of `stoi()` — conversion from string to int was happening only in the matching block, not in all cases.Fixed it by ensuring the regNo is parsed at the correct stage regardless of match.

- Faced difficulty in managing the control flow with a flag variable.Initially used an int flag, which led to confusion.

- Switching it to a bool made the logic much cleaner and more intuitive.

- Overall, I was able to debug and fix all issues on my own, which gave me more confidence in applying what I've learned so far.

