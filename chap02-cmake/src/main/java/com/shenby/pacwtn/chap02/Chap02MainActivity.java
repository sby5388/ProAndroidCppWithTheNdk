package com.shenby.pacwtn.chap02;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

import com.example.hellojni.HelloJni;
import com.shenby.pacwtn.chap02.databinding.ActivityChap02MainBinding;

public class Chap02MainActivity extends AppCompatActivity {

    private final HelloJni mHelloJni = new HelloJni();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        final ActivityChap02MainBinding binding = ActivityChap02MainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        binding.text.setText(mHelloJni.stringFromJNI());

    }
}