package com.shenby.pacwtn.chap02.ndkbuild;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

import com.example.hellojni.HelloJni;
import com.shenby.pacwtn.chap02.ndkbuild.databinding.ActivityChap02MainBinding;
import com.shenby.swig.Unix;

import java.util.Locale;

public class Chap02MainActivity extends AppCompatActivity {

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