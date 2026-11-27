# MyAlgorithmTemplate

一份面向算法竞赛的 C++ 模板册。内容按数论、图论、字符串和数据结构组织，A4 单栏 PDF 带可点击的目录，可用于赛前复习或打印查阅。

## 文件

- [算法竞赛模板.pdf](./算法竞赛模板.pdf) 是可直接阅读和打印的版本。
- [算法竞赛模板.tex](./算法竞赛模板.tex) 维护章节、公式和说明，并引用 C++ 文件。
- [code/](./code/) 按专题存放 C++ 片段，每个算法对应一个 `.cpp` 文件。
- [模板.md](./模板.md) 是最初整理的算法笔记。

## 重新生成 PDF

准备支持 XeLaTeX 和 CTeX 的 TeX 环境。源码使用 `fvextra` 排版代码，并使用 `DejaVuSansMono.ttf`、`gbsn00lp.ttf` 和 `gkai00mp.ttf` 排印代码与中文。

在仓库根目录执行两次编译，让标题和页码写入目录。

```shell
xelatex -interaction=nonstopmode -halt-on-error "算法竞赛模板.tex"
xelatex -interaction=nonstopmode -halt-on-error "算法竞赛模板.tex"
```

也可以使用 Tectonic，它会在需要时重新运行编译以更新目录。

```shell
tectonic "算法竞赛模板.tex"
```

## 添加算法

将新代码保存到 `code/` 下对应的专题目录。在 `.tex` 中用 `\subsection` 添加条目，再用 `\CppInput{code/graph/tarjan_scc.cpp}` 这样的语句引用代码。按需要补充适用条件、复杂度或调用示例，重新编译并检查目录、分页和代码换行。

代码片段沿用原稿，使用前应单独编译并验证所需片段。当前已知线性基缺少结构体结尾 `};`，网络流 Dinic 的 `INF` 常量超出 `int` 的范围。
