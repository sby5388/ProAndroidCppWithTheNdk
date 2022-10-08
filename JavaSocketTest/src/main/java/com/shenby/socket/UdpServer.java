package com.shenby.socket;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.nio.charset.StandardCharsets;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

public class UdpServer {
    public static final String KEY_EXIT = "exit";
    private static final Logger audit = Logger.getLogger("requests");
    private static final Logger errors = Logger.getLogger("errors");

    public static void main(String[] args) {
        final int port = 1026;
        startUdpServer(port);

    }

    /**
     * 启动一个udp服务:返回当前的时间
     *
     * @param port 端口，一般要大于1024,小于1024的端口需要使用 sudo
     */
    private static void startUdpServer(final int port) {
        final int length = 1024;
        try (final DatagramSocket socket = new DatagramSocket(port)) {
            while (true) {
                try {
                    final DatagramPacket request = new DatagramPacket(new byte[length], length);
                    socket.receive(request);

                    //打印响应报文
                    final byte[] requestData = request.getData();
                    final String requestString = new String(requestData, 0,
                            //todo 下一个参数不是 requestData.length
                            request.getLength(),
                            StandardCharsets.UTF_8);
                    System.out.println("requestString = " + requestString);


                    //返回报文内容
                    final String time = new Date().toString();
                    final byte[] data = time.getBytes(StandardCharsets.UTF_8);
                    final DatagramPacket response = new DatagramPacket(data,
                            data.length, request.getAddress(), request.getPort());

                    socket.send(response);

                    audit.info(time + " " + request.getAddress());

                    if (KEY_EXIT.equals(requestString)) {
                        System.err.println("客户端请求断开udp");
                        break;
                    }
                } catch (IOException | RuntimeException e) {
                    errors.log(Level.SEVERE, e.getMessage(), e);
                }

            }

        } catch (Exception e) {
            e.printStackTrace();
            errors.log(Level.SEVERE, e.getMessage(), e);
        }
    }
}
