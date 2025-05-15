# 🚀 Lancey Software Engineering Challenge

## 📌 Problem 1: First Non-Repeating Character

### 🧠 Problem Statement

Given a string, return the **index** of the **first non-repeating character**.  
If no such character exists, return `-1`.

---

### ✅ Constraints

- Input: A lowercase alphabetic string (`a-z`)
- No use of built-in or standard library features beyond basic syntax
- No external libraries
- Time efficiency is preferred (`O(n)` if possible)

---

### 📈 Approach: Frequency + First Index Tracking

We use two arrays:
- `freq[26]` to count how many times each character appears.
- `firstIndex[26]` to store the **first index** where each character appeared.

#### 🔁 Steps:

1. Initialize both arrays:  
   - Set `freq` to all 0s  
   - Set `firstIndex` to all `-1`s

2. Iterate over the string:
   - For each character, increment its frequency.
   - If it's the first time we're seeing it, record its index.

3. After the loop, scan `freq` for all characters that appeared **only once**.  
   Track the **smallest first index** among them.

4. Return that index, or `-1` if none are found.

---

### 🧮 Time & Space Complexity

| Metric        | Complexity |
|---------------|------------|
| Time          | O(n)       |
| Space         | O(1) (Fixed size for alphabet) |

---

### 🧪 Example

```txt
Input:  "leetcode"
Output: 0
Explanation: 'l' appears only once and is the first such character.
