<h4 align="right"><strong><a href="README.md">简体中文</a></strong> | English</h4>

![](img/logo.jpg)

### tianzuo.Kongtong

![](https://img.shields.io/badge/release-2.0.0.0-blue.svg)
![](https://img.shields.io/badge/date-25.5.6-orange.svg)

||||
|--|--|--|
|operating system|![](https://img.shields.io/badge/os-windows_7+-blue.svg) ||
|compiler|![](https://img.shields.io/badge/c++-11-blue.svg) ![](https://img.shields.io/badge/msvc-14.0-blue.svg) ![](https://img.shields.io/badge/msvc-14.1-blue.svg) ![](https://img.shields.io/badge/msvc-14.2-blue.svg) ![](https://img.shields.io/badge/msvc-14.3-blue.svg) ||
|programming language|![](img/C.png) ![](img/C__.png)||
# introduction

![](img/alchemy_tianzuo.Kongtong.jpg)

**tianzuo.Kongtong** When an application crashes on a Windows platform, a crash dump file is generated to analyze the lines of the crashed code and generate information about the system environment.

**legend:**
The protective artifact of the undead dragon clan in Kongtong Sea is carved with the shape of the five heavenly emperors and surrounded by a jade dragon. According to ancient legend, those who get it can own the world, and some people say that it can make people not old and immortal.

# motivation
In the process of development, occasionally encounter the situation of program crash, need to analyze the cause of crash and locate the code line, and need to analyze environmental factors.

![](img_en/tianzuo.Kongtong.png)

# features

- 🧩 simple integration
- 📝 optionally generate dmp and logs
- 🪐 log in multiple languages (simplified chinese / english)
- ⛓  support for in-thread detection

# screenshot

**locate crashed lines of code through dmp file analysis:**

Visual Studio analyze the dmp file

![](img_en/screenshot.png)

WinDbg analyze the dmp file

![](img_en/screenshot3.png)

**environment log:**

![](img_en/screenshot2.png)

## install

enable exception detection in project

### Visual Studio

![](img_en/screenshot4.png)
enable c++ exception detection in Visual Studio

![](img_en/screenshot5.png)
enable generation pdb files in Visual Studio

### Qt Creator

![](img_en/screenshot6.png)
enable generation pdb files in Qt Creator

```cpp
CONFIG += force_debug_info
CONFIG += senarate_debug_info
```

# example

```cpp
#include "tianzuo.KongtongTest.h"
#include "../../include/tianzuo.Kongtong.h"
#include <Windows.h>

void init(int argc, char* argv[]) {
    tianzuo_KongtongTest test;
    test.doSomething();
}

int main(int argc, char* argv[]) {
    HINSTANCE hKongtong = LoadLibrary(L"tianzuo.Kongtong.dll");
    if (!hKongtong) {
        init(argc, argv);
        return(0);
    }

    tianzuo_Kongtong_get_exception getException = (tianzuo_Kongtong_get_exception)GetProcAddress(hKongtong, "Kongtong_get_exception");
    if (!getException) return -1;
    __try {
        init(argc, argv);
    }
    __except (getException(GetExceptionInformation(), Kongtong_create_normal, 0)) {
    }

    if (hKongtong != nullptr) {
        getException = nullptr;
        FreeLibrary(hKongtong);
        hKongtong = nullptr;
    }
    return(0);
}
```

# download

|||||
|--|--|--|--|
|[![download](img/com_btnGitHub.svg)](https://github.com/zhengtianzuo/tianzuo.Kongtong/releases)|[![download](img/com_btnGitee.svg)](https://gitee.com/zhengtianzuo/tianzuo.Kongtong/releases)|[![download](img/down_baidu.svg)](https://pan.baidu.com/s/1TnsGHWpFG_NFRrtkZsQcvA?pwd=1234)|[![download](img/down_weiyun.svg)](https://share.weiyun.com/euPExPUJ)|

# about
## contact

||||
|--|--|--|
|author|zhengtianzuo||
|QQ|278969898||
|mailbox|camelsoft@163.com||
|homepage|[http://www.camelstudio.cn](http://www.camelstudio.cn)||
|blog|[http://blog.csdn.net/zhengtianzuo06](http://blog.csdn.net/zhengtianzuo06)||
|github|[https://github.com/zhengtianzuo](https://github.com/zhengtianzuo)||
|gitee|[https://gitee.com/zhengtianzuo](https://gitee.com/zhengtianzuo)||
|QQ group|199672080||

![](img/allinone.png)

|||||
|--|--|--|--|
|Add QQ Friends|Add WeChat Friends|WeChat Sponsor|Alipay Sponsor|




