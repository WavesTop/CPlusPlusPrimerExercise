# C++ Primer 练习及课后作业

本项目用于完成《C++ Primer》的练习及课后作业。

## 项目结构

- `part_one/` — 第一部分：C++ 基础
- `part_two/` — 第二部分：C++ 标准库
- `part_three/` — 第三部分：类设计者的工具
- `part_four/` — 第四部分：高级主题

## 构建方式

本项目使用 Ninja 作为构建系统，更加轻量快速。

### Windows (MSVC + Ninja)

在 "Developer Command Prompt for VS" 或 PowerShell 中先激活 VS 环境，再构建：

```cmd
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -B build -S .
cmake --build build
```

或使用 CMake Presets：

```cmd
cmake --preset default
cmake --build --preset default
```

Debug 模式：

```cmd
cmake --preset debug
cmake --build --preset debug
```

