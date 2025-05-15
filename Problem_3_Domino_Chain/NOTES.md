# 🎲 Domino Chain Validator and Builder

This program determines whether it's possible to form a **valid domino chain** from a set of domino tiles and outputs the chain if one exists.

A domino is validly chained if:
- Adjacent tiles match (i.e., `[a|b]` next to `[b|c]`)
- The chain is **circular**, meaning the first and last numbers match.
- You can use **duplicate tiles** if needed.

---

## 💡 Problem Statement

Given `n` domino tiles where each tile is a pair of integers from 0 to 6 (like `[2|3]`), determine if they can be arranged in a chain such that:
1. Each tile is used exactly once.
2. Adjacent dominoes share the same number.
3. The chain ends with the same number it starts with.

If possible, print the sequence of dominoes in order. Else, print `NO`.

---

## 🧠 Approach

This is a **graph problem** disguised as dominoes.

- Think of each number (0–6) as a **node**.
- Each domino is an **undirected edge** between two nodes.
- To form a valid chain:
  - All degrees must be even (Eulerian circuit), or
  - Exactly 2 nodes have odd degree (Eulerian path).
  - The chain must also be **connected**.

### Algorithm Steps:

1. **Graph Building:**
   - Store each domino and track degrees.
   - Build an adjacency list and mark each edge with a unique ID.

2. **Check Degree Conditions:**
   - Count nodes with odd degree.
   - If not 0 or 2 → `NO`.

3. **DFS (Hierholzer’s Algorithm):**
   - Use DFS to construct an Eulerian path or circuit.
   - Visit unused edges and record the path.

4. **Validate Output:**
   - If the number of dominoes used ≠ `n` → `NO`.
   - If first and last value of the path don’t match → `NO`.

5. **Print Chain:**
   - Reverse the DFS result.
   - Carefully print the domino in the correct direction using the multiset.

---

## 📦 Example Input

6
1 2
2 3
3 1
3 4
4 2
2 1

### Possible Output
1 2
2 4
4 3
3 2
2 1
1 3


---

## 🧪 Edge Cases

- Tiles with same numbers: `[2|2]`, `[2|2]`
- Impossible chain due to unmatched degrees
- Multiple tiles between the same pair (multiedges)
- All tiles form disconnected pieces → invalid
- Exactly 2 nodes with odd degree → Eulerian path

---

## ⏱️ Time and Space Complexity

### Time Complexity:
- `O(n)` for reading input and building the graph.
- `O(n)` for DFS traversal (Eulerian path/circuit).
- `O(n log n)` for multiset operations during output.

### Space Complexity:
- `O(n)` for edge list and multiset.
- Fixed size `N = 7` for nodes.

---

## ✅ Final Notes

- Uses `fastio` for faster input/output.
- Code handles duplicate dominoes using `multiset`.
- Edge ID tracking ensures we don’t revisit the same domino.

Great example of applying **Eulerian path/circuit** logic to a real-world toy problem.
