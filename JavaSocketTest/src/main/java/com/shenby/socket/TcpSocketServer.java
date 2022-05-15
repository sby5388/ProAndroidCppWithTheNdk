package com.shenby.socket;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

/**
 * 本地开启一个Tcp Socket Server
 */
public class TcpSocketServer {


    public static void main(String[] args) throws IOException {
        final int port = 1234;
        startTcpSocketServer(port);
    }

    /**
     * 开启socket服务
     *
     * @param port 端口号
     */
    private static void startTcpSocketServer(int port) throws IOException {
        final ServerSocket serverSocket = new ServerSocket(port);
        System.out.println(serverSocket.getLocalPort());
        System.out.println(serverSocket.getLocalSocketAddress());
        while (true) {
            final Socket client = serverSocket.accept();
            // TODO: 2022/5/15 这里可以使用线程池处理
            new Thread(new Runnable() {
                @Override
                public void run() {
                    final InetAddress inetAddress = client.getInetAddress();
                    System.out.println("client address = " + client.getLocalAddress());
                    System.out.println("client inetAddress = " + inetAddress);

                    final int bufferLength = 80;
                    byte[] buffer = new byte[bufferLength];

                    try {
                        final InputStream inputStream = client.getInputStream();
                        final int readLength = inputStream.read(buffer);
                        String result;
                        if (readLength != -1) {
                            result = "come from SocketServer:" + new String(buffer, 0, readLength, StandardCharsets.UTF_8);
                        } else {
                            result = "come from SocketServer:null";
                        }

                        try {
                            final OutputStream outputStream = client.getOutputStream();
                            outputStream.write(result.getBytes(StandardCharsets.UTF_8));
                            outputStream.flush();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
    }


}
