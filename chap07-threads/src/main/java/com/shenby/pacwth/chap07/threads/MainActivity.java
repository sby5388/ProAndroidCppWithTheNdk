package com.shenby.pacwth.chap07.threads;

import android.os.Bundle;
import android.util.Log;
import android.widget.EditText;

import androidx.annotation.Keep;
import androidx.appcompat.app.AppCompatActivity;

import com.shenby.pacwth.chap07.threads.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    public static final String TAG = "chap07-threads";

    static {
        System.loadLibrary("threads");
    }

    private com.shenby.pacwth.chap07.threads.databinding.ActivityMainBinding mBinding;

    /**
     * 获取文本编辑框的数字，出错时返回默认值
     *
     * @param editText
     * @param defaultValue
     * @return
     */
    private static int getNumber(EditText editText, int defaultValue) {
        int value;
        try {
            value = Integer.parseInt(editText.getText().toString());
        } catch (NumberFormatException e) {
            value = defaultValue;
        }
        return value;

    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mBinding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(mBinding.getRoot());
        mBinding.startButton.setOnClickListener((v) -> {
            final int threads = getNumber(mBinding.threadsEdit, 0);
            final int iterations = getNumber(mBinding.iterationsEdit, 0);
            if (threads > 0 && iterations > 0) {
                startThreads(threads, iterations);
            }
        });

        nativeInit();

    }

    @Override
    protected void onDestroy() {
        nativeFree();
        super.onDestroy();
    }

    /**
     * 原生代码通过反射回调的方法
     *
     * @param message
     */
    @Keep
    private void onNativeMessage(final String message) {
        Log.d(TAG, "onNativeMessage: thread = " + Thread.currentThread().getName() + ",message = " + message);
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                mBinding.logView.append(message);
                mBinding.logView.append("\n");
            }
        });

    }

    /**
     * 启动给定数量的线程进行迭代
     *
     * @param threads
     * @param iterations
     */
    private void startThreads(int threads, int iterations) {
        //javaThreads(threads, iterations);
        posixThreads(threads, iterations);
    }

    /**
     * 使用JAVA线程
     *
     * @param threads
     * @param iterations
     */
    private void javaThreads(final int threads, final int iterations) {
        //为每一个Worker创建一个基于java的线程
        for (int i = 0; i < threads; i++) {
            final int id = i;
            new Thread(new Runnable() {
                @Override
                public void run() {
                    nativeWorker(id, iterations);
                }
            }).start();
        }

    }

    /**
     * 初始化原生代码
     */
    private native void nativeInit();

    /**
     * 释放原生资源
     */
    private native void nativeFree();

    /**
     * 原生worker，模拟执行时间长的任务，
     *
     * @param id
     * @param iterations
     */
    private native void nativeWorker(int id, int iterations);

    /**
     * 使用POSIX线程
     *
     * @param threads
     * @param iterations
     */
    private native void posixThreads(int threads, int iterations);
}