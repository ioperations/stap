#!/bin/bash 

#  stap -gu -c ./cc_deref cc_deref.stp -gu参数，这个参数是嵌入C代码必须的参数
sudo bpftrace -e 'usdt:'${PWD}'/multi_pointer_deref:prov:mark {printf("value %s addr %p\n",str(arg0), arg1)}'
