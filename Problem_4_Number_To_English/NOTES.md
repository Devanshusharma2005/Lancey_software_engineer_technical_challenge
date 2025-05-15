# 🗣️ Number to English Words (0 to 999,999,999,999)

Welcome to the number spell-out project!  
Given a number between **0 and 999,999,999,999**, our goal is to convert it into plain English.

Example:


---

## 🚀 What’s the Plan?

This might sound complicated, but we break it into small, manageable parts.

### Step 1: Handle Numbers Below 1000

We create a helper that can convert any number from 0–999 into words. For example:

- `14` → `fourteen`
- `50` → `fifty`
- `98` → `ninety-eight`
- `100` → `one hundred`

We use predefined arrays:
- For numbers from 0 to 19 (`one[]`)
- For tens like 20, 30, … 90 (`ten[]`)

We also handle things like hyphens (`twenty-one`), spacing, etc.

---

### Step 2: Split Into Chunks of Thousands

We break the number into groups of 3 digits (like how you'd write big numbers with commas).

Example:

We process each chunk and add a scale like:
- thousand
- million
- billion
- trillion

Each chunk gets passed to our below-1000 helper.

---

### Step 3: Combine the Chunks

Once each chunk is converted to English, we stitch them back together from left to right (most significant to least significant), skipping any `000` chunks.

Example:

---

## 💻 Code Output Examples

| Input | Output |
|-------|--------|
| `0` | `zero` |
| `1` | `one` |
| `14` | `fourteen` |
| `100` | `one hundred` |
| `101` | `one hundred one` |
| `12345` | `twelve thousand three hundred forty-five` |
| `1000010` | `one million ten` |
| `999999999999` | `nine hundred ninety-nine billion nine hundred ninety-nine million nine hundred ninety-nine thousand nine hundred ninety-nine` |

---

## ⚠️ Edge Cases We Handle

- ✅ `0` → `zero`
- ✅ Clean spacing between chunks (no double spaces)
- ✅ Skips `000` chunks cleanly
- ✅ Adds hyphen in words like `twenty-one`
- ✅ Handles maximum allowed input
- ✅ Rejects negative or out-of-range numbers with a message

---

## ⏱️ Time and Space Complexity

- **Time:** `O(1)`  
  Why? We're only processing up to **4 chunks** (billions, millions, thousands, units), and each chunk is ≤ 999.
  
- **Space:** `O(1)`  
  We use a few fixed-size arrays and strings—no extra memory proportional to input.

So yes, it’s super fast. 🚀

---

