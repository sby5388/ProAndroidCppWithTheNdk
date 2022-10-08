package com.shenby.socket;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.nio.charset.StandardCharsets;

public class UdpClient {
    public static void main(String[] args) {

        int port = 1235;
        if (args != null && args.length > 0) {
            try {
                port = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                e.printStackTrace();
            }
        }

        System.out.println("port = " + port);
        String text = "";
        if (args != null && args.length > 1) {
            text = args[1];
        }
        System.out.println("text = " + text);

        final String hostName = "localhost";
        try (DatagramSocket datagramSocket = new DatagramSocket(0)) {
            //4秒超时
            datagramSocket.setSoTimeout(4000);
            final InetAddress host = InetAddress.getByName(hostName);
            int length = text.length();
            //请求报文
            final byte[] bytes = text.getBytes(StandardCharsets.UTF_8);
            final DatagramPacket request = new DatagramPacket(bytes, bytes.length, host, port);

            //响应报文
            final DatagramPacket response = new DatagramPacket(new byte[1024], 1024);
            //发送请求
            datagramSocket.send(request);
            //接收响应
            datagramSocket.receive(response);
            //处理响应报文

            final byte[] data = response.getData();
            final String result = new String(data, 0, response.getLength(), StandardCharsets.UTF_8);
            System.out.println("result = " + result);


        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
