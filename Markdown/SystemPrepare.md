# 1 系统下载
1. 下载最新版微软系统
[UUP dump](https://uupdump.net/)

 2. 使用USB3.0，Rufus制作启动盘
 [pbatard/rufus: The Reliable USB Formatting Utility](https://github.com/pbatard/rufus).
 设置创建本地登陆账号，启用超级管理员账户

3. 按照操作指引安装Windows

4. 安装Office
[Office专业版增强版]https://officecdn.microsoft.com/db/492350f6-3a01-4f97-b9c0-c7c6ddf67d60/media/zh-cn/ProPlus2024Retail.img
[Project专业版]https://officecdn.microsoft.com/db/492350f6-3a01-4f97-b9c0-c7c6ddf67d60/media/zh-cn/ProjectPro2024Retail.img
[Visio专业版]https://officecdn.microsoft.com/db/492350f6-3a01-4f97-b9c0-c7c6ddf67d60/media/zh-cn/VisioPro2024Retail.img
[Office小型企业版]https://officecdn.microsoft.com/db/492350f6-3a01-4f97-b9c0-c7c6ddf67d60/media/zh-cn/HomeBusiness2024Retail.img
[Office家庭和学生版]https://officecdn.microsoft.com/db/492350f6-3a01-4f97-b9c0-c7c6ddf67d60/media/zh-cn/Home2024Retail.img

5. 系统和Office激活
[HEU_KMS_Activator]https://github.com/zbezj/HEU_KMS_Activator
Local: ..\Library\ProgramTool

6. 删除环境变量Path路径
%userprofile%\AppData\Local\Microsoft\WindowsApps

7. 进入注册表编辑器，将
计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Appx\PackageVolumes
EnableExternalVolumes的值设为0

8. 系统更新与微软应用商店更新

9. 登录微软账户并进行个性化编辑，重启电脑

# 2 子系统准备
## 2.1 Hyper-V
1. 设置-系统-可选功能-更多Windows功能
启用Hyper-V, Virtual Machine Platform

2. 设置Hyper-V网络
Hyper-V管理器->虚拟交换机管理器

3. 创建虚拟机
打开Hyper-V管理器按照提示操作即可。

4. 嵌套虚拟化以及相关设置
Powershell命令行输入如下内容以查看相关设置以及开启虚拟化
```
Get-VMProcessor -VMName "*" | Format-List
Set-VMProcessor -ExposeVirtualizationExtensions $true -VMName "*"
```

## 2.2 Windows SubSystem for Linux.
1. 启用Hyper-V

2. 设置-系统-可选功能-更多Windows功能
适用于Linux的Windows子系统

3. 开启Steam++加速器加速github

4. 命令行输入如下内容以安装wsl.
```
wsl --install
```

5. 使用wsl命令行查看并下载安装linux发行版
```
wsl --help
wsl --list
wsl --list --online
wsl --install [Distribution]
wsl --unregister
```

6. 编辑配置文件%userprofile%\.wslconfig并重启命令行
配置网络及资源
```
[wsl2]
processors=2
memory=2GB
swap=2GB
networkingMode=bridged
ipv6=true
vmSwitch=WiFi
```

## 2.3 Windows SubSystem for Android
1. 启用Hyper-V

2. 下载WSA的appx包并双击打开安装
[Microsoft Store - Generation Project (v1.2.3) [by @rgadguard & mkuba50]](https://store.rg-adguard.net/)
转到PackageFamilyName搜索MicrosoftCorporationII.WindowsSubsystemForAndroid_8wekyb3d8bbwe

3. 下载Android SDK平台工具并添加到Path路径
[SDK 平台工具版本说明  |  Android Studio  |  Android Developers](https://developer.android.google.cn/tools/releases/platform-tools?hl=zh-cn)

4. 打开WSA高级设置->打开开发人员模式
命令行输入如下内容以连接WSA并安装apk应用.
```
adb connect HOST[:PORT]
adb install *.apk
```

## 2.4 手机连接
1. 电脑端：手机连接

2. 手机端：oppo默认已安装”连接至Windows“应用

## 2.5 Windows沙盒
1. 设置-系统-可选功能-更多Windows功能
启用Windows沙盒

# 3 系统配置
## 3.1 ssh服务


## 3.2 Ubuntu软件源配置
1. [ubuntu | 镜像站使用帮助 | 清华大学开源软件镜像站 | Tsinghua Open Source Mirror](https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/)
制作/etc/apt/sources.list文件并拷贝（24.04Noble）
```
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble-updates main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble-backports main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble-backports main restricted universe multiverse

# 以下安全更新软件源包含了官方源与镜像站配置，如有需要可自行修改注释切换
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble-security main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble-security main restricted universe multiverse

# 预发布软件源，不建议启用
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble-proposed main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ noble-proposed main restricted universe multiverse
```

2. 查找并安装软件包
```
apt update
apt list --installed | grep *
apt install
```

3. python安装pip
```
apt install python3-pip
rm /usr/lib/python3.x/EXTERNALLY-MANAGED
pip install --upgrade pip
```

4. 设置pip源（清华源）
```
pip config set global.index-url https://mirrors.tuna.tsinghua.edu.cn/pypi/web/simple
pip config set global.extra-index-url "https://mirrors.ustc.edu.cn/pypi/simple <url2>..."
```

5. 安装pip包
```
pip install
```

## 3.3 python软件源配置
1. python下载embed版
[Python Releases for Windows | Python.org](https://www.python.org/downloads/windows/)

2. pip脚本安装
下载get-p
ip.py文件至python路径
[get-pip.py]https://pip.pypa.io/en/stable/installation/#get-pip-py

命令行输入如下内容安装pip包
```
python get-pip.py
```

3. 库加载索引修改
编辑 .\python\python*.\_pth 为
```
python*.zip
.

# Uncomment to run site.main() automatically
import site
```

4. 添加Path路径
.\python
.\python\Scripts
.\python\Lib\site-packages

5. 配置pip软件源，新建.\python\pip.ini
```
[global]
index-url = https://mirrors.tuna.tsinghua.edu.cn/pypi/web/simple
[install]
trusted-host=mirrors.tuna.tsinghua.edu.cn
```
