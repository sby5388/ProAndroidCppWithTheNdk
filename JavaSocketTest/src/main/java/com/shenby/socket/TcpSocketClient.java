package com.shenby.socket;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class TcpSocketClient {

    public static void main(String[] args) throws IOException {
//        final String hostName = "192.168.0.101";
        final String hostName = "localhost";
        final int port = 1234;
        startTcpSocketServer(hostName, port);
    }

    private static void startTcpSocketServer(String hostName, int port) throws IOException {
        final Socket socket = new Socket(hostName, port);
        try (
             final InputStream inputStream = socket.getInputStream();
             final OutputStream outputStream = socket.getOutputStream();
        ) {
            outputStream.write("come from client".getBytes(StandardCharsets.UTF_8));
            outputStream.write("uuu end".getBytes(StandardCharsets.UTF_8));
            outputStream.flush();
            final int length = 80;
            final byte[] buffer = new byte[length];
            final int read = inputStream.read(buffer);
            if (read != -1) {
                final String result = new String(buffer, 0, read, StandardCharsets.UTF_8);
                System.out.println("result = " + result);
            }
        }
    }

}
