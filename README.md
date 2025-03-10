![标题图](https://github.com/Floatkyun/2024TI_C/blob/main/img/NUEDC.png)
## 整体方案概述   
系统通过 STM32F407ZGT6 单片机，控制 DDS 产生四路频率、相位相对独立的信号，分别为直达与多径传输 AM 信号的载波和调制信号，并可以独立控制其幅值和相移；单片机 DAC 提供直流偏置，通过加法器和乘法器得到调幅信号；之后通过运放电路将其放大到题目要求的幅值范围，多径传输信号外加 PE4302 程控衰减器调节额外衰减，最后通过加法器合路输出，整体结构框图如下    

![整体结构框图](https://github.com/Floatkyun/2024TI_C/blob/main/img/%E7%A1%AC%E4%BB%B6%E7%BB%93%E6%9E%84%E5%9B%BE.png)   

### 调幅波生成   
使用模拟乘法器、加法器，利用独立的载波和调制信号产生调幅波，使用单片机的DAC端口产生直流偏置，与DDS产生的调制信号经过加法器相加后，
通过 AD835 乘法器与 DDS 产生的载波相乘，即可得到调幅波。   
### 改变输出波形幅度   
对于直达传输信号，可以通过 DDS 直接产生幅度不同的直流偏置、
调制信号和载波来控制输出波形的幅度；对于多径传输信号，再通过程控衰减器PE4302 来控制其相对衰减；

## 系统软件设计分析   
软件系统结构框图如下图：   
![软件系统结构框图](https://github.com/Floatkyun/2024TI_C/blob/main/img/%E8%BD%AF%E4%BB%B6%E7%BB%93%E6%9E%84%E5%9B%BE.png)   

### 显示与交互界面     
由于本题需要修改的参数量多，不宜再用按键进行调整。所以我们为STM32F4移植了 8.3.10 版本的 LVGL 库，实现了操作界面的渲染与触控界面将在下面介绍，题目中的所有参数修改均可以通过下拉列表和滚轮控件进行设置，为人机交互提供了巨大的便利。   
[点击查看交互界面的GUI_Guider工程](https://github.com/Floatkyun/2024TI_C/tree/main/GUI-Guider%E5%B7%A5%E7%A8%8B)

#### CW波形设置界面   
通过此界面可以修改CW信号波形的幅度、频率和多径传输相关设置，点击`CHART0`或`CHART1`按钮来更换打表数据，长按`DEBUG`按钮进入开发者模式，此时可以对数据进行二次拟合。   
![CW波形设置界面](https://github.com/Floatkyun/2024TI_C/blob/main/img/LVGL_CW.png)    

#### AM波形设置界面   
通过此界面可以修改AM信号波形的幅度、频率和多径传输相关设置，点击`CHART0`或`CHART1`按钮来更换打表数据，长按`DEBUG`按钮进入开发者模式，此时可以对数据进行二次拟合。   
![AM波形设置界面](https://github.com/Floatkyun/2024TI_C/blob/main/img/LVGL_AM.png)  

#### 开发者模式界面   
长按`DEBUG`按钮进入开发者模式，在这里可以根据示波器等测量仪器型号的变化来进一步对数据进行拟合，使得输出结果精确到小数点后多位。   
![开发者模式界面](https://github.com/Floatkyun/2024TI_C/blob/main/img/LVGL_Debug.png)        

### 模拟算法   
为了控制 DDS 发生符合要求的载波和调制波，实现多径传输中的衰减、时延、初相调整等功能，我们建立了一套模拟算法，下面将对算法的具体实现进行介绍。   
#### 幅度值调整   
在连续波发生模式下，调制波需置零，只有直流偏置和载波信号进入乘法器。实际测试时发现通过下调载波或者偏置来控制输出幅度值都会引起CW波形质量的降低。这里利用模拟乘法器的乘法本质，将下降倍数的0.3 次方加到载波上，将下降倍数的0.7次方加到偏置上，维持最后输出信号的下降倍数为目标值。    
#### 调制度调整   
根据调幅波的定义，调制度可表示为$M_a=2(V_1/V_0)$，其中$V_1$为调制信号幅值，$V_0$为载波幅值。为了调整AM波的调制度，这里采用改变调制波幅度值的方式，随着调制度的上升，算法将控制调制波的幅度值下降。   
#### 载波频率调整
算法直接控制 DDS 的输出频率来控制载波频率。   
#### 多径信号衰减  
模拟算法通过控制程控衰减器PE4302来实现对多径信号的衰减。  
#### 多径信号时延  
模拟算法通过将时延转换为不同频率信号对应的相位差并控制DDS对相位进行调整来实现。时延与相位的换算满足$\varphi_{eq}=-2\pi t/T$，其中t为时延时长，T为要时延波形的周期，$\varphi_{eq}$为等效相移。   
#### 多径信号初相
模拟算法通过控制DDS对载波的相位进行调整来实现对多径信号初相（$\varphi_0$）的控制。所以综合来看，发生载波的初相应为 $\varphi_0+\varphi_{eq}$而调制波的初
相为$\varphi_{eq}$。   

## 拓展指标   
- 使用LVGL图形库编写图形界面，提升人机交互体验；
- 调制度可调范围扩大至10%~90%；   
- 时延步进缩小至15ns； 
- 初相设置范围扩大至-180°到+180°。


## 成品展示   
连接实物图（封箱前）如下图所示   
![连接实物图](https://github.com/Floatkyun/2024TI_C/blob/main/img/real.jpg)   
### 测试数据   
在未经过开发者模式二次拟合时（经过二次拟合后，误差可以接近0），测量得到的关键数据指标如下表，格式为`目标值/实际值/误差`  

类型| 幅度（mVrms） |频率(MHz)| 调制度（%） |衰减(dB) |时延(ns) |初相（°）
-------- | -------- | -------- | -------- | -------- |-------- |-------- |
CW | 1000/999.7/0.3 | 30/29.99/0.01 | - | 10/10.06/-0.06 | - | 150/153/-3 |
CW | 300/295/5 | 40/39.99/0.01 | - | 20/20.4/-0.4 | - | 180/178.3/-1.7 |
AM | 1000/997/3 | 30/29.99/0.01 | 90/89.97/0.03 | 10/9.7/0.29 | 80/79/1 | 60/54/6 |
AM | 100/99.36/0.64 | 40/39.99/0.01 | 30/30.96/-0.96 | 0/0/0 | 200/206/-6 | 0/0/0 |

在实际验题前的准备时间内，幅度数据经过重新拟合，所以测评过程中幅度指标误差在0.1%以内，另外调制度误差在1%以内，相移和频率基本无误差，衰减误差在3%以内，时延误差在2ns以内。    
