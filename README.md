# Control-computer-by-Wifi-Android
### 通过WiFi连接，使用安卓手机遥控电脑，如音乐播放，PPT遥控，音量控制，关机等操作

### 演示视频展示了该项目的效果
### 已提供编译好的安装包，可参照部署文档安装软件试用

## 项目由两部分组成，Windows服务器和Android客户端
### Android客户端
用于发送遥控消息，界面如下图所示
![](https://github.com/Bond-SYSU/Control-computer-by-Wifi-Android-/blob/master/Android.png)

### Windows服务器
时刻监听等待Android端发送的消息，并作出响应，响应函数通过调用模拟按下快捷键实现
### 通讯协议
Android客户端和Windows服务器通过TCP连接发送消息

