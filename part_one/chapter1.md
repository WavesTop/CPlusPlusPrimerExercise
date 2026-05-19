# Chapter 1 代码中遇到的一些问题总结

## EOF（End Of File）

### 什么是 EOF

EOF 是一个信号，表示输入流已经没有更多数据可读。在 C++ 中，当 `std::cin` 遇到 EOF 时，流状态会被置为失败（`failbit`），后续读取操作将直接返回 false。

### 如何触发 EOF

| 平台 | 快捷键 |
|------|--------|
| Windows | `Ctrl + Z` 然后回车 |
| Linux / macOS | `Ctrl + D` |

### 典型用法

```cpp
int val;
while (std::cin >> val) {
    // 循环读取直到遇到 EOF 或非法输入
}
```

### 注意事项

- `Ctrl+Z`（Windows）必须在**行首**输入才能生效
- EOF 触发后，流进入失败状态，若需重新读取必须调用 `std::cin.clear()` 重置状态
- EOF 和输入非法数据（类型不匹配）都会导致循环退出，但原因不同：EOF 设置 `eofbit`，非法输入设置 `failbit`

---

## 控制台输入缓冲

### 工作机制

控制台输入是**行缓冲**的：用户输入的字符先存入缓冲区，按下回车后才交给程序处理。`std::cin >>` 会跳过前导空白字符（空格、换行、制表符），从缓冲区中提取下一个有效 token。

### 缓冲区残留问题

```cpp
int a;
char c;
std::cin >> a;  // 输入 "42\n"，读走 42，'\n' 留在缓冲区
std::cin.get(c); // 直接读到 '\n'，不会等待新输入
```

### 清空缓冲区的方法

```cpp
// 方法 1：忽略缓冲区中剩余字符直到换行符
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// 方法 2：sync（不保证所有平台有效）
std::cin.sync();
```

### 注意事项

- `std::cin >>` 和 `std::getline()` 混用时，缓冲区中残留的 `\n` 会导致 `getline` 读到空行，需要在中间加 `cin.ignore()`
- 多次输入之间如果缓冲区未清空，前次残留数据会被后续读取操作消费
- `std::cin.get()` 和 `std::cin.getline()` 不跳过空白，与 `>>` 行为不同
