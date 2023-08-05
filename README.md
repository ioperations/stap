## systemtap & bpftrace use case

<img align="right" src="./known_unknown.png">

- software requirement

- linux instead of archlinux: recommand ubuntu/debian
- [bpftrace ](https://github.com/iovisor/bpftrace)
- [systemtap](https://sourceware.org/git/systemtap.git)
- [clayout](https://github.com/hidva/clayout)

- 纸上得来终觉浅，绝知此事要躬行

  - 网络上对于 systemtap 和 bpftrace 的介绍已经很多了，brendangregg 已经写了两本书来介绍 bcc 和 bpftrace，但自己能熟练使用他是另外一回事。书籍可以给你框架，分析问题的思路，当实践过程还是必须的。

- 本 repo 的目的
  本 repo 放的是我在使用 bpftrace 和 systemtap 过程当中的一些脚本，可能参考于 agentzh/brendangregg 或者其他人的一些脚本。本 repo 当中文件的组织逻辑没有规定，但是会过一段实践整理一次。

- 工具链
  - 目前来看好像 gcc 生成的 dwarf 格式不如 clang 生成的好,
    比如[这个 stap 脚本](./multi_pointer_deref.sh),在 gcc 编译下就不能解析成功，但是在 clang 编译下就可以
