/** JNI */
#include <jni.h>
/** null */
#include <stdio.h>
//stdarg=standard+arguments,让函数接收可变参数
/** va_list , vsnprintf*/
#include <stdarg.h>
/** error */
#include <errno.h>
/** strerror_r,memset */
#include <string.h>
/** socket,bind,getsockname,listen,accept,recv,send,connect */
#include <sys/types.h>
#include <sys/socket.h>
/** sockaddr_un*/
#include <sys/un.h>
/** htons,sockaddr_in */
#include <netinet/in.h>
/** inet_ntop */
#include <arpa/inet.h>
/** close,unlink*/
#include <unistd.h>
/** offsetof */
#include <stddef.h>


#include "com_shenby_pacwth_echo_EchoServerActivity.h"
#include "com_shenby_pacwth_echo_EchoClientActivity.h"



//最大日志消息长度
#define MAX_LOG_MESSAGE_LENGTH 256
//最大数据缓冲区大小
#define MAX_BUFFER_SIZE 80


/**
 * 将给定的消息记录到应用数据
 * @param env JNIEnv interface.
 * @param obj object instance.
 * @param format message format and arguments.
 * @param ...
 */
static void LogMessage(JNIEnv *env,
                       jobject obj,
                       const char *format, ...);

/**
 * 用给定的异常类和异常消息抛出新的异常
 *
 * @param env JNIEnv interface.
 * @param className class name.
 * @param message exception message.
 */
static void ThrowException(JNIEnv *env,
                           const char *className,
                           const char *message);

/**
 * 用给定异常类和基于错误号的错误消息抛出新异常
 * @param env JNIEnv interface.
 * @param className class name.
 * @param errNum error number.
 */
static void ThrowErrnoException(JNIEnv *env,
                                const char *className,
                                int errNum);

/**
 * 创建新的TCP socket
 * @param env JNIEnv interface.
 * @param obj object instance.
 * @return socket descriptor.
 * @throws IOException
 */
static int NewTcpSocket(JNIEnv *env, jobject obj);

/**
 * 将socket绑定到某一端口号
 * @param env JNIEnv interface.
 * @param obj object instance.
 * @param sd socket descriptor. socket描述符
 * @param port port number or zero for random port.
 * @throws IOException
 */
static void BindSocketToPort(JNIEnv *env,
                             jobject obj,
                             int sd,
                             unsigned short port);

/**
 * 获取当前socket绑定的端口号
 * Gets the port number socket is currently binded.
 *
 * @param env JNIEnv interface.
 * @param obj object instance.
 * @param sd socket descriptor.
 * @return port number.
 * @throws IOException
 */
static unsigned short GetSocketPort(
        JNIEnv *env,
        jobject obj,
        int sd);

/**
 * 监听指定的待处理连接backlog的socket，当backlog已满时拒绝新的连接
 * Listens on given socket with the given backlog for
 * pending connections. When the backlog is full, the
 * new connections will be rejected.
 *
 * @param env JNIEnv interface.
 * @param obj object instance.
 * @param sd socket descriptor.
 * @param backlog backlog size.
 * @throws IOException
 */
static void ListenOnSocket(
        JNIEnv *env,
        jobject obj,
        int sd,
        int backlog);

/**
 * 记录给定地址的ip地址和端口号
 * Logs the IP address and the port number from the
 * given address.
 *
 * @param env JNIEnv interface.
 * @param obj object instance.
 * @param message message text.
 * @param address adress instance.
 * @throws IOException
 */
static void LogAddress(
        JNIEnv *env,
        jobject obj,
        const char *message,
        const struct sockaddr_in *address);

/**
 * 在给定的socket上阻塞和等待进来的客户连接
 * Blocks and waits for incoming client connections on the
 * given socket.
 *
 * @param env JNIEnv interface.
 * @param obj object instance.
 * @param sd socket descriptor.
 * @return client socket.
 * @throws IOException
 */
static int AcceptOnSocket(
        JNIEnv *env,
        jobject obj,
        int sd);

/**
 * 阻塞并接收来自socket的数据放到缓冲区
 * Block and receive data from the socket into the buffer.
 *
 * @param env JNIEnv interface.
 * @param obj object instance.
 * @param sd socket descriptor.
 * @param buffer data buffer.
 * @param bufferSize buffer size.
 * @return receive size.
 * @throws IOException
 */
static ssize_t ReceiveFromSocket(
        JNIEnv *env,
        jobject obj,
        int sd,
        char *buffer,
        size_t bufferSize);


/**
 * 将数据缓冲区发送到socket
 * Send data buffer to the socket.
 *
 * @param env JNIEnv interface.
 * @param obj object instance.
 * @param sd socket descriptor.
 * @param buffer data buffer.
 * @param bufferSize buffer size.
 * @return sent size.
 * @throws IOException
 */
static ssize_t SendToSocket(
        JNIEnv *env,
        jobject obj,
        int sd,
        const char *buffer,
        size_t bufferSize);


/**
 * 连接到给定的IP地址和给定的端口号
 * Connects to given IP address and given port.
 *
 * @param env JNIEnv interface.
 * @param obj object instance.
 * @param sd socket descriptor.
 * @param ip IP address.
 * @param port port number.
 * @throws IOException
 */
static void ConnectToAddress(
        JNIEnv *env,
        jobject obj,
        int sd,
        const char *ip,
        unsigned short port);

extern "C" JNIEXPORT void
Java_com_shenby_pacwth_echo_EchoServerActivity_nativeStartTcpServer(
        JNIEnv *env,
        jobject obj,
        jint port) {
    //构造新的Tcp Socket
    int serverSocket = NewTcpSocket(env, obj);
    if (env->ExceptionOccurred() == nullptr) {
        //将socket绑定到某端口号
        BindSocketToPort(env, obj, serverSocket, (unsigned short) port);
        if (env->ExceptionOccurred() != nullptr) goto exit;
        //如果请求了随机端口号
        if (0 == port) {
            //获取当前socket绑定的端口号
            GetSocketPort(env, obj, serverSocket);
            if (env->ExceptionOccurred() != nullptr) goto exit;
        }
        //监听有4个等待连接的backlog的socket
        ListenOnSocket(env, obj, serverSocket, 4);
        if (env->ExceptionOccurred() != nullptr) goto exit;
        //接受socket的一个客户连接
        int clientSocket = AcceptOnSocket(env, obj, serverSocket);
        if (env->ExceptionOccurred() != nullptr) goto exit;

        char buffer[MAX_BUFFER_SIZE];
        ssize_t recvSize;
        ssize_t sentSize;
        //接收并发送数据
        while (1) {
            //从socket中接收
            recvSize = ReceiveFromSocket(env, obj, clientSocket, buffer, MAX_BUFFER_SIZE);
            if (0 == recvSize || env->ExceptionOccurred() != nullptr) {
                break;
            }
            //发送给socket
            sentSize = SendToSocket(env, obj, clientSocket, buffer, (size_t) recvSize);
            if (sentSize == 0 || env->ExceptionOccurred() != nullptr) {
                break;
            }
        }
        //关闭客户端socket
        close(clientSocket);

    }

    exit:
    {
        if (serverSocket > 0) {
            //关闭服务端socket
            close(serverSocket);
        }
    };


}
extern "C" JNIEXPORT void JNICALL
Java_com_shenby_pacwth_echo_EchoServerActivity_nativeStartUdpServer(
        JNIEnv *env,
        jobject obj,
        jint port) {
    //todo
}

extern "C" JNIEXPORT void JNICALL
Java_com_shenby_pacwth_echo_EchoClientActivity_nativeStartTcpClient(
        JNIEnv *env,
        jobject obj,
        jstring ip,
        jint port,
        jstring message) {
    int clientSocket = NewTcpSocket(env, obj);
    if (nullptr == env->ExceptionOccurred()) {
        //以C字符串获取IP地址
        const char *ipAddress = env->GetStringUTFChars(ip, nullptr);
        if (env->ExceptionOccurred() != nullptr) goto exit;

        //连接到IP地址和端口
        ConnectToAddress(env, obj, clientSocket, ipAddress, (unsigned short) port);
        //释放IP地址
        env->ReleaseStringUTFChars(ip, ipAddress);
        if (env->ExceptionOccurred() != nullptr) goto exit;
        //以C字符串获取消息
        const char *messageText = env->GetStringUTFChars(message, nullptr);
        if (env->ExceptionOccurred() != nullptr) goto exit;
        //获取消息大小
        jsize messageSize = env->GetStringUTFLength(message);
        //发送消息给Socket
        SendToSocket(env, obj, clientSocket, messageText, messageSize);
        //释放文本
        env->ReleaseStringUTFChars(message, messageText);
        //如果发送失败
        if (env->ExceptionOccurred() != nullptr) goto exit;
        char buffer[MAX_BUFFER_SIZE];
        //从socket中接收数据
        ReceiveFromSocket(env, obj, clientSocket, buffer, MAX_BUFFER_SIZE);

    }
    exit:
    {
        if (clientSocket > -1) {
            close(clientSocket);
        }
    };

}


static void LogMessage(JNIEnv *env,
                       jobject obj,
                       const char *format, ...) {
    //缓存日志方法IO
    static jmethodID methodID = nullptr;
    if (nullptr == methodID) {
        //从对象获取类
        jclass pJclass = env->GetObjectClass(obj);
        //从给定方法中获取方法ID
        methodID = env->GetMethodID(pJclass, "logMessage", "(Ljava/lang/String;)V");
        //释放类引用
        env->DeleteLocalRef(pJclass);
    }
    //如果找到方法
    if (nullptr != methodID) {
        //格式化日志消息
        char buffer[MAX_LOG_MESSAGE_LENGTH];
        //todo 保存可变参数的对象
        va_list ap;
        //这是一个宏：从format开始处理可变参数
        va_start(ap, format);
        //todo 用于向字符串中打印数据,用户自定义数据格式
        ////vsnprintf 将可变个参数按照format格式化输出成字符串：写入到缓冲区
        vsnprintf(buffer, MAX_LOG_MESSAGE_LENGTH, format, ap);
        /** 这也是一个宏  结束：销毁可变参数 */
        va_end(ap);

        /** 将缓冲区转换为Java字符串 */
        jstring message = env->NewStringUTF(buffer);
        if (nullptr != message) {
            ////如果字符串构造成功
            //记录消息
            env->CallVoidMethod(obj, methodID, message);
            //释放消息引用
            env->DeleteLocalRef(message);
        }
    }
}

static void ThrowException(JNIEnv *env,
                           const char *className,
                           const char *message) {
    jclass pJclass = env->FindClass(className);
    if (pJclass != nullptr) {
        env->ThrowNew(pJclass, message);
        env->DeleteLocalRef(pJclass);
    }
}

static void ThrowErrnoException(JNIEnv *env,
                                const char *className,
                                int errNum) {
    char buffer[MAX_LOG_MESSAGE_LENGTH];
    //获取错误号消息
    //todo strerror_r
    if (-1 == strerror_r(errNum, buffer, MAX_LOG_MESSAGE_LENGTH)) {
        //todo errno
        strerror_r(errno, buffer, MAX_LOG_MESSAGE_LENGTH);
    }
    ThrowException(env, className, buffer);
}

static int NewTcpSocket(JNIEnv *env, jobject obj) {
    //构造socket
    LogMessage(env, obj, "create a new TCP Socket ...");
    // todo DOMAIN:通信的socket域，也是指协议簇，Android支持以下2种：
    //      PF_INET:ipv4,可以与网络上其他地方运行的应用程序通信。
    //      PF_LOCAL:主机内部通信协议簇，仅能与同一个主机上的应用程序通信

    // todo Type:通信的语义，socket的类型，tcp 和 udp
    //      SOCK_STREAM:使用TCP协议的、面向连接的通信Stream socket类型
    //      SOCK_STREAM:使用TCP协议的、面向连接的通信Stream socket类型
    //todo Protocol 用到的协议，0是默认

    //返回-1为失败，且全局的errno被相应地设置成错误值；否则返回socket描述符
    int tcpSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (tcpSocket == -1) {
        //抛出带错误号的异常
        ThrowErrnoException(env, "java/io/IOException", errno);
    }
    return tcpSocket;
}

static void BindSocketToPort(JNIEnv *env,
                             jobject obj,
                             int sd,
                             unsigned short port) {
    struct sockaddr_in address;
    //绑定socket的地址
    memset(&address, 0, sizeof(address));
    address.sin_family = PF_INET;
    //绑定到所有地址
    //htonl:将unsigned integer 从主机字节排序转换到网络字节排序
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    //将端口转换为网络字节顺序
    //htons:将unsigned short 从主机字节排序转换到网络字节排序
    address.sin_port = htons(port);
    //绑定socket
    LogMessage(env, obj, "Binding to port %hu.", port);
    //socket创建之后还需要分配协议地址：使用 bind,三个参数分别是
    //  socket 描述符
    //  address:指定socket被绑定的协议地址
    //  address length: 协议地址数据结构的大小

    //返回0：绑定成功
    //返回-1为失败，且全局的errno被相应地设置成错误值；
    int result = bind(sd, (struct sockaddr *) &address, sizeof(address));
    if (-1 == result) {
        ThrowErrnoException(env, "java/io/IOException", errno);
    }
}

static unsigned short GetSocketPort(
        JNIEnv *env,
        jobject obj,
        int sd) {
    unsigned short port = 0;

    struct sockaddr_in address;
    socklen_t addressLength = sizeof(address);

    // Get the socket address
    // 获取socket地址
    if (-1 == getsockname(sd, (struct sockaddr *) &address, &addressLength)) {
        // Throw an exception with error number
        ThrowErrnoException(env, "java/io/IOException", errno);
    } else {
        // Convert port to host byte order
        // ntohs:与htons相反，将unsigned short 从网络字节排序转换到主机字节排序
        port = ntohs(address.sin_port);

        LogMessage(env, obj, "Binded to random port %hu.", port);
    }

    return port;
}

static void ListenOnSocket(
        JNIEnv *env,
        jobject obj,
        int sd,
        int backlog) {
    // Listen on socket with the given backlog
    // 监听给定的backlog的socket
    LogMessage(env, obj,
               "Listening on socket with a backlog of %d pending connections.",
               backlog);
    //listen:监听socket
    //listen(int __fd, int __backlog):__fd:socket描述符；__backlog：队列的最大大小，超过时拒绝连接
    // 成功返回0；失败 返回-1 ，且全局的errno被相应地设置成错误值；
    if (-1 == listen(sd, backlog)) {
        // Throw an exception with error number
        ThrowErrnoException(env, "java/io/IOException", errno);
    }
}

static void LogAddress(
        JNIEnv *env,
        jobject obj,
        const char *message,
        const struct sockaddr_in *address) {
    char ip[INET_ADDRSTRLEN];

    // Convert the IP address to string
    //将ip地址转换成字符串
    if (nullptr == inet_ntop(PF_INET,
                             &(address->sin_addr),
                             ip,
                             INET_ADDRSTRLEN)) {
        // Throw an exception with error number
        ThrowErrnoException(env, "java/io/IOException", errno);
    } else {
        // Convert port to host byte order
        // 将端口装换成主机字节顺序
        unsigned short port = ntohs(address->sin_port);

        // Log address
        LogMessage(env, obj, "%s %s:%hu.", message, ip, port);
    }
}

static int AcceptOnSocket(
        JNIEnv *env,
        jobject obj,
        int sd) {
    struct sockaddr_in address;
    socklen_t addressLength = sizeof(address);

    // Blocks and waits for an incoming client connection
    // and accepts it
    LogMessage(env, obj, "Waiting for a client connection...");

    //阻塞和等待进来的客户连接，并且接受它
    int clientSocket = accept(sd,
                              (struct sockaddr *) &address,
                              &addressLength);

    //0:success;-1:fail
    // If client socket is not valid
    if (-1 == clientSocket) {
        // Throw an exception with error number
        ThrowErrnoException(env, "java/io/IOException", errno);
    } else {
        // Log address
        LogAddress(env, obj, "Client connection from ", &address);
    }

    return clientSocket;
}


static ssize_t ReceiveFromSocket(
        JNIEnv *env,
        jobject obj,
        int sd,
        char *buffer,
        size_t bufferSize) {
    // Block and receive data from the socket into the buffer
    // 阻塞并接收来自socket的数据放到缓冲区
    LogMessage(env, obj, "Receiving from the socket...");
    //-1:fail;other:receive data length
    ssize_t recvSize = recv(sd, buffer, bufferSize - 1, 0);

    LogMessage(env, obj, "recvSize = %d", recvSize);
    // If receive is failed
    if (-1 == recvSize) {
        // Throw an exception with error number
        ThrowErrnoException(env, "java/io/IOException", errno);
    } else {
        // NULL terminate the buffer to make it a string
        // 以'\0'结尾缓冲区行程一个字符串：原文是以NULL结尾
        buffer[recvSize] = '\0';

        // If data is received
        if (recvSize > 0) {
            LogMessage(env, obj, "Received %d bytes: %s", recvSize, buffer);
        } else {
            LogMessage(env, obj, "Client disconnected.");
        }
    }

    return recvSize;
}

static ssize_t SendToSocket(
        JNIEnv *env,
        jobject obj,
        int sd,
        const char *buffer,
        size_t bufferSize) {
    // Send data buffer to the socket
    // 将数据缓冲区发送到socket
    LogMessage(env, obj, "Sending to the socket...");
    ssize_t sentSize = send(sd, buffer, bufferSize, 0);

    //-1:发送失败；
    //0:socket 连接失败
    // If send is failed
    if (-1 == sentSize) {
        // Throw an exception with error number
        ThrowErrnoException(env, "java/io/IOException", errno);
    } else if (sentSize == 0) {
        LogMessage(env, obj, "Client disconnected.");
    } else {
        LogMessage(env, obj, "Sent %d bytes: %s", sentSize, buffer);
    }
    return sentSize;
}

static void ConnectToAddress(
        JNIEnv *env,
        jobject obj,
        int sd,
        const char *ip,
        unsigned short port) {
    // Connecting to given IP address and given port
    //连接到给定的IP地址和给定的端口号
    LogMessage(env, obj, "Connecting to %s:%uh ...", ip, port);

    struct sockaddr_in address;

    memset(&address, 0, sizeof(address));
    address.sin_family = PF_INET;

    // Convert IP address string to Internet address
    //将ip地址字符串装换成网络地址
    if (0 == inet_aton(ip, &(address.sin_addr))) {
        // Throw an exception with error number
        ThrowErrnoException(env, "java/io/IOException", errno);
    } else {
        // Convert port to network byte order
        //将端口号转换为网络字节顺序
        address.sin_port = htons(port);

        // Connect to address
        //connect：连接到指定地址
        //socket描述符，协议地址，协议地址数据结构的长度
        if (-1 == connect(sd, (const sockaddr *) &address, sizeof(address))) {
            // Throw an exception with error number
            ThrowErrnoException(env, "java/io/IOException", errno);
        } else {
            LogMessage(env, obj, "Connected.");
        }
    }
}