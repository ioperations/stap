
## systemtap & bpftrace use case

```sh 

```

- software requirement 
    - linux instead of archlinux: recommand ubuntu/debian
    - [bpftrace ](https://github.com/iovisor/bpftrace)
    - [systemtap](https://sourceware.org/git/systemtap.git)
    - [clayout](https://github.com/hidva/clayout)

- 纸上得来终觉浅，绝知此事要躬行
    - 网络上对于systemtap和bpftrace的介绍已经很多了，brendangregg已经写了两本书来介绍bcc和bpftrace，但自己能熟练使用他是另外一回事。书籍可以给你框架，分析问题的思路，当实践过程还是必须的。

- 本repo 的目的
    本repo放的是我在使用bpftrace和systemtap过程当中的一些脚本，可能参考于agentzh/brendangregg 或者其他人的一些脚本。本repo当中文件的组织逻辑没有规定，但是会过一段实践整理一次。

- 工具链
    - 目前来看好像gcc生成的dwarf格式不如clang生成的好,
    比如[这个stap脚本](./multi_pointer_deref.sh),在gcc编译下就不能解析成功，但是在clang编译下就可以
