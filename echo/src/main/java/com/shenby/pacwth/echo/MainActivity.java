package com.shenby.pacwth.echo;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

import com.shenby.pacwth.echo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        final ActivityMainBinding binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        binding.buttonTcpClient.setOnClickListener(v -> toTcpClient());
        binding.buttonTcpServer.setOnClickListener(v -> toTcpServer());

    }

    private void toTcpClient() {
        startActivity(EchoClientActivity.newIntent(this));
    }

    private void toTcpServer() {
        startActivity(EchoServerActivity.newIntent(this));
    }


}