Pro Android C++ with the NDK
《Android C++ 高级编程--使用NDK》
书本代码


书本提供的原仓库地址是：
https://github.com/Apress/pro-android-c-w-ndk.git

chap02的jni代码来自
https://github.com/android/ndk-samples
https://github.com/android/ndk-samples/blob/main/hello-jni/app/src/main/cpp/hello-jni.c
https://github.com/android/ndk-samples/blob/main/hello-jni/app/src/main/cpp/CMakeLists.txt

--
Android模拟器与主机之间的通信：
需要设置端口转发：
telnet localhoast 5554;
--
然后在新的终端中 进行认证：
auth <auth_token>
这个auth_token在
'/Users/***/.emulator_console_auth_token'之中，不包括最后一个%号；
然后就可以增加规则 对socket tcp 的端口号(如1234)进行转发了
for tcp:
redir add tcp:1234:1234
for udp
redir add udp:1234:1234


