# Arch Install Helper
[![Build Status](https://cloud.drone.io/api/badges/ALKALiKong233/arch-install-helper/status.svg)](https://cloud.drone.io/ALKALiKong233/arch-install-helper)
## 欢迎使用！

这个小程序将会协助你安装 Arch Linux 并进行配置

目前已支持 UEFI 和传统启动两种引导方式

欢迎进行 PR 提交新功能！

这个程序目前写得很烂，因为我刚开始学习 C Language，所以有写的烂的地方请多批评指正！

## 如何使用？

首先，在你的 live 环境中安装 wget 

然后输入如下指令（看一眼最新的release用版本号替换掉(release-version)）  
```wget https://github.com/ALKALiKong233/arch-install-helper/releases/download/(release-version)/helper```   
```chmod a+x helper```  
```./helper```  
即可开始运行安装

进入 chroot 环境后，输入以下指令  
```wget https://github.com/ALKALiKong233/arch-install-helper/releases/download/(release-version)/chroot```   
```chmod a+x chroot```  
```./chroot```  
即可开始运行配置

## Enjoy!
