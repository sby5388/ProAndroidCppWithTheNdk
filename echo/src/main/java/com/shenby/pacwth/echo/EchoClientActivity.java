package com.shenby.pacwth.echo;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;

import com.shenby.pacwth.echo.databinding.ActivityEchoClientBinding;

public class EchoClientActivity extends AbstractEchoActivity {
    public static final String TAG = "chap08EchoClient";
    private ActivityEchoClientBinding mBinding;

    public static Intent newIntent(Context context) {
        return new Intent(context, EchoClientActivity.class);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mBinding = ActivityEchoClientBinding.inflate(getLayoutInflater());
        setContentView(mBinding.getRoot());
        mBinding.startButton.setOnClickListener(v -> startClient());
    }


    @Override
    public Integer getPort() {
        final String s = mBinding.portEdit.getText().toString();
        int port;
        try {
            port = Integer.parseInt(s);
        } catch (NumberFormatException e) {
            port = -1;
        }
        return port;
    }

    @Override
    protected void logMessage(String message) {
        runOnUiThread(() -> logMessageDirect(message));
    }

    @Override
    protected void logMessageDirect(String message) {
        mBinding.logView.append(message);
        mBinding.logView.append("\n");
        mBinding.logScroll.fullScroll(View.FOCUS_DOWN);
        Log.d(TAG, "logMessageDirect: " + message);
    }

    private void startClient() {
        startTcpClient();
    }

    private void startTcpClient() {
        Log.d(TAG, "startTcpClient: ");
        final String message = mBinding.messageEdit.getText().toString().trim();
        final Integer port = getPort();
        final String ip = mBinding.ipEdit.getText().toString().trim();
        if (TextUtils.isEmpty(ip) || TextUtils.isEmpty(message) || port == -1) {
            Log.e(TAG, "startTcpClient: stop!! ip = %s,port = %d,message = %s");
            return;
        }
        final ClientTask task = new ClientTask(ip, port, message);
        task.start();

    }

    /**
     * 根据给定服务器IP地址和端口号启动TCP客户端，并且发送给定的消息
     *
     * @param ip      服务端ip地址
     * @param port    服务端端口号
     * @param message 发送的文本信息
     * @throws Exception
     */
    private native void nativeStartTcpClient(String ip, int port, String message) throws Exception;

    /**
     * 客户端任务
     */
    private class ClientTask extends AbstractEchoTask {
        private final String mIp;
        private final int mPort;
        private final String mMessage;

        public ClientTask(String ip, int port, String message) {
            mIp = ip;
            mPort = port;
            mMessage = message;
        }


        @Override
        protected void onBackground() {
            logMessage("Starting client");
            try {
                nativeStartTcpClient(mIp, mPort, mMessage);
            } catch (Exception e) {
                logMessage(e.getMessage());
            }
            logMessage("client terminated");
        }


    }


}