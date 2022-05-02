package com.shenby.pacwtn.chap02.ndkbuild;

import android.os.Bundle;
import android.util.Log;

import androidx.appcompat.app.AppCompatActivity;

import com.example.hellojni.HelloJni;
import com.shenby.pacwtn.chap02.ndkbuild.databinding.ActivityChap02MainBinding;
import com.shenby.swig.Unix;
import com.shenby.swig.UnixConstants;

import java.util.Locale;

public class Chap02MainActivity extends AppCompatActivity {
    public static final String TAG = "Chap02NdkBuild";

    private final HelloJni mHelloJni = new HelloJni();
    private ActivityChap02MainBinding mBinding;
    private int mValue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mBinding = ActivityChap02MainBinding.inflate(getLayoutInflater());
        setContentView(mBinding.getRoot());

        mBinding.text.setText(mHelloJni.stringFromJNI());

        mBinding.textUid.setText(String.format(Locale.CHINESE, "uid:%d", Unix.getuid()));

        mBinding.buttonGetValue.setOnClickListener(v -> updateNumber());
        mBinding.buttonValueIncrease.setOnClickListener(v -> increaseValue());
        mBinding.buttonValueReduce.setOnClickListener(v -> reduceValue());

        updateNumber();
        testConstantValue();

    }

    /**
     * 测试常量
     */
    private void testConstantValue() {
        Log.d(TAG, "testConstantValue: maxWidth = " + UnixConstants.MAX_WIDTH);
        Log.d(TAG, "testConstantValue: maxHeight = " + UnixConstants.MAX_HEIGHT);
        Log.d(TAG, "testConstantValue: minWidth = " + UnixConstants.MIN_WIDTH);
        Log.d(TAG, "testConstantValue: minHeight = " + UnixConstants.MIN_HEIGHT);

        Log.d(TAG, "testConstantValue: readOnly = " + Unix.getReadOnly());
        Log.d(TAG, "testConstantValue: readWrite = " + Unix.getReadWrite());
        Log.d(TAG, "testConstantValue: set readWrite = -10");
        Unix.setReadWrite(-10);
        Log.d(TAG, "testConstantValue: readWrite = " + Unix.getReadWrite());
    }

    private void reduceValue() {
        mValue--;
        Unix.setCounter(mValue);
    }

    private void increaseValue() {
        mValue++;
        Unix.setCounter(mValue);
    }

    private void updateNumber() {
        mValue = Unix.getCounter();
        mBinding.textNumberValue.setText(String.format(Locale.CHINESE, "value = %d", mValue));
    }

}