package com.shenby.pacwth.echo;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

import com.shenby.pacwth.echo.databinding.ActivityEchoServerBinding;

/**
 * 启动一个native-tcp-服务端
 */
public class EchoServerActivity extends AbstractEchoActivity {
    public static final String TAG = "chap08EchoServer";

    private ActivityEchoServerBinding mBinding;

    public static Intent newIntent(Context context) {
        return new Intent(context, EchoServerActivity.class);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mBinding = ActivityEchoServerBinding.inflate(getLayoutInflater());
        setContentView(mBinding.getRoot());
        mBinding.startButton.setOnClickListener(v -> startServer());
    }

    @Override
    public Integer getPort() {
        final String portString = mBinding.portEdit.getText().toString();
        try {
            return Integer.valueOf(portString);
        } catch (NumberFormatException e) {
            e.printStackTrace();
        }
        return -1;
    }

    @Override
    protected void logMessage(String message) {
        runOnUiThread(() -> logMessageDirect(message));
    }

    @Override
    protected void logMessageDirect(String message) {
        mBinding.logView.append(message);
        mBinding.logView.append("\n");
        // TODO: 2022/5/14
        mBinding.logScroll.fullScroll(View.FOCUS_DOWN);
    }

    private void startServer() {
        startTcpServer();
    }

    private void startTcpServer() {
        final Integer port = getPort();
        if (port != null && port != -1) {
            Log.d(TAG, "startTcpServer: port = " + port);
            final ServerTask task = new ServerTask(port);
            task.start();
        } else {
            Log.e(TAG, "startTcpServer: port = " + port);
        }
    }

    /**
     * 根据给定的端口号启动TCP服务
     *
     * @param port 端口号
     * @throws Exception
     */
    public native void nativeStartTcpServer(int port) throws Exception;

    /**
     * 根据给定的端口号启动UDP服务
     *
     * @param port 端口号
     * @throws Exception
     */
    public native void nativeStartUdpServer(int port) throws Exception;

    /**
     * 服务端任务
     */
    private class ServerTask extends AbstractEchoTask {
        /**
         * 端口号
         */
        private final int mPort;

        public ServerTask(int port) {
            mPort = port;
        }

        @Override
        protected void onBackground() {
            logMessage("Starting server");
            try {
                nativeStartTcpServer(mPort);
            } catch (Exception e) {
                logMessage(e.getMessage());
            }
            logMessage("Server terminated");
        }
    }
}