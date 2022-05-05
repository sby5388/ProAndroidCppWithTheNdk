package com.shenby.pacwtn.chap02;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;
import com.shenby.swig.Unix;
import com.example.hellojni.HelloJni;
import com.shenby.pacwtn.chap02.databinding.ActivityChap02MainBinding;

import java.util.Locale;

public class Chap02MainActivity extends AppCompatActivity {
    public static final String TAG = "chap02-Cmake";
    private final HelloJni mHelloJni = new HelloJni();
    private ActivityChap02MainBinding mBinding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mBinding = ActivityChap02MainBinding.inflate(getLayoutInflater());
        setContentView(mBinding.getRoot());

        mBinding.text.setText(mHelloJni.stringFromJNI());

        mBinding.textUid.setText(String.format(Locale.CHINESE, "uid:%d", Unix.getuid()));

    }
}