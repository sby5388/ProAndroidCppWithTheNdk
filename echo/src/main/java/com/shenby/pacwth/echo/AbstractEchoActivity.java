package com.shenby.pacwth.echo;

import android.os.AsyncTask;
import android.os.Handler;
import android.os.Looper;

import androidx.annotation.Keep;
import androidx.appcompat.app.AppCompatActivity;


public abstract class AbstractEchoActivity extends AppCompatActivity {
    static {
        System.loadLibrary("Echo");
    }


    public abstract Integer getPort();

    /**
     * 记录给定的消息
     * 给native代码反射的
     *
     * @param message 日志消息
     */
    @Keep
    protected abstract void logMessage(final String message);

    /**
     * 直接记录给定的消息
     * 给native代码反射的
     *
     * @param message 日志消息
     */
    @Keep
    protected abstract void logMessageDirect(final String message);


    /**
     * 抽象异步Echo对象
     */
    protected abstract class AbstractEchoTask extends Thread {
        private final Handler mHandler;

        public AbstractEchoTask() {
            mHandler = new Handler(Looper.getMainLooper());
        }

        @Override
        public synchronized void start() {
            onPreExecute();
            super.start();
        }


        @Override
        public void run() {
            onBackground();
            super.run();
            mHandler.post(this::onPostExecute);
        }

        /**
         * 在调用线程中先执行回调
         * {@link AsyncTask#onPreExecute()}
         */
        protected void onPreExecute() {

        }

        /**
         * 新线程中的后台回调
         */
        protected abstract void onBackground();

        /**
         * 在调用线程中后执行回调
         * {@link AsyncTask#onPostExecute(Object)} ()}
         */
        protected void onPostExecute() {

        }

    }


}
