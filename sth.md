# Specification （温度传感器）
Sensor Chip Model: LM35  
Supply Voltage: 3.3~5.0V  
Sensor Chip Sensitivity: 10mV/℃  
Measuring Range: 0~150℃  
Precision: ±1℃  
Connector Type: PH2.0-3P  
Dimension: 30*22 mm  

![DFR0023_Diagram](./img/DFR0023_Diagram.png)

```
void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
}

void loop()
{
    uint16_t val;
    double dat;
    val=analogRead(A0);//Connect LM35 on Analog 0
    dat = (double) val * (5/10.24);
    Serial.print("Tep:"); //Display the temperature on Serial monitor
    Serial.print(dat);
    Serial.println("C");
    delay(500);
}
```  

# DFR0063 I2C/TWI LCD1602 Module 液晶显示屏  
# [I2C LCD与Arduino接口](https://zhuanlan.zhihu.com/p/349791145)  

![DFR0063 I2C/TWI LCD1602 Module](./img/v2-255a557eba4e4614000d9328d482d42c_720w.webp)  
地线 是接地引脚，应连接到Arduino的地面。  
VCC为模块和LCD供电。将其连接到Arduino的5V输出或单独的电源。  
SDA是串行数据引脚。这条线用于发送和接收。连接到Arduino上的SDA引脚。  
SCL是串行时钟引脚。这是总线主设备提供的定时信号。连接到Arduino上的SCL引脚。  

# 接线方式  
![DFR0063 I2C/TWI LCD1602 Module wire](./img/v2-d4bf7557aafe14e5c7c1d8e579f4d02e_720w.webp)

`home()` –将光标放置在LCD的左上角而不清除显示。  
`cursor()` –显示LCD光标，在要打印的下一个字符的位置带有下划线（行）。  
`noCursor()` –隐藏LCD光标。  
`blink()` –创建闪烁的块样式LCD光标：在要打印的下一个字符的位置，闪烁的5×8像素矩形。  
`noBlink()` –禁用闪烁的块样式LCD光标。  
`display()` –打开LCD屏幕并显示以前在显示屏上打印的字符。  
`noDisplay()`–关闭液晶显示屏。仅关闭LCD屏幕并不会清除LCD存储器中的数据。这意味着将在调用display（）函数时再次显示它。  
`scrollDisplayLeft()`–将显示内容向左滚动一个空格。如果要连续滚动文本，则需要在循环内使用此功能。  
`scrollDisplayRight()` –将显示内容向右滚动一个空格。  
`autoscroll()`–打开LCD的自动滚动。如果当前文本方向是从左到右（默认），则显示向左滚动；如果当前方向是从右到左，则显示向右滚动。  
`noAutoscroll()` –关闭自动滚动。  

# CGROM和CGRAM自定义字符生成器  
![char](./img/char.webp)  

包含库并创建LCD对象后，将定义自定义字符数组。每个阵列由8个字节组成，对于5×8 led矩阵的每一行为1个字节。在此草图中，创建了8个自定义字符。  
让我们以Heart[8]数组为例。您会看到位如何形成实际上为0和1的心脏形状。0将关闭像素，而1将打开像素。  
```
byte Heart[8] = {
0b00000,
0b01010,
0b11111,
0b11111,
0b01110,
0b00100,
0b00000,
0b00000
};
```  
在设置中，使用该createChar()功能创建自定义字符。该函数有两个参数。第一个是0到7之间的数字，以保留8个受支持的自定义字符之一。第二个参数是字节数组的名称。  
```
lcd.createChar(0, Heart);
```  
在循环的下一步中，要显示自定义字符，请使用write()function，并作为参数使用要显示的字符号。  
```
lcd.setCursor(0, 1);
lcd.write(0);
```