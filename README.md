﻿# DP-Project
Oct. 2016, in tjsse

### 选题

题目一：重构大一时c++项目的代码。

### 重构计划

1. 将原本以场景作为类的架构进行重构, 抽出公共的动作(如地图渲染)作为基类, 去掉不必要的类 (使之成为instance; 抽出配置信息, 在初始化时进行赋值)

>其余部分见[/Doc/Presentation01.pdf](https://github.com/1452712/DP-Project/tree/master/Doc)

### 进度说明

1. DP2中题目二的代码基本完成.

2. Umbrella完成重构计划

3. 完成Config - Composition

4. LevelScene - Facotory

5. Fog - Decorator

6. SceneManager - Single Instance

7. Umbrella - Observer

8. MoveController - Strategy

### 说明

- **原创代码在/Umbrella/Classes目录下**
- **由于cocos2，proj.*等文件夹过大并未上传，如果需要请发邮件至[邮箱](nbwjh@126.com)**
- **/DP2目录为题目二的代码**
