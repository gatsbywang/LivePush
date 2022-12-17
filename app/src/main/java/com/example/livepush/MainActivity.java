package com.example.livepush;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {


    private LivePush mLivePush;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mLivePush = new LivePush("");
        mLivePush.setConnectlistener(new LivePush.OnConnectListener() {
            @Override
            public void connectError(int errCode, String errMsg) {

            }

            @Override
            public void connectSuccess() {

            }
        });
        mLivePush.initConnect();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mLivePush.stop();
    }
}