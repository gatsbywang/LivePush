package com.example.livepush;

import android.os.Handler;
import android.os.Looper;

import java.util.logging.LogRecord;

public class LivePush {
    static {

        System.loadLibrary("live-push");
    }

    private String mUrl;

    private static Handler MAIN_HANDLER= new Handler(Looper.getMainLooper());

    public LivePush(String url){
        this.mUrl = url;
    }

    public void initConnect(){

        nInitConnect(mUrl);
    }

    private OnConnectListener mConnectlistener;

    public void setConnectlistener(OnConnectListener listener) {
        this.mConnectlistener = listener;
    }

    public interface OnConnectListener{
        void connectError(int errCode,String errMsg);
        void connectSuccess();
    }

    private native void nInitConnect(String url);

    //监听回调

    // called form jni
    private void onConnectError(int errCode,String errMsg){

        stop();
        if(mConnectlistener !=null){
            mConnectlistener.connectError(errCode,errMsg);
        }

    }

    public void stop() {

        MAIN_HANDLER.post(new Runnable() {
            @Override
            public void run() {

                nStop();
            }
        });
    }

    private native void nStop();

    // called form jni
    private void onConnectSuccess(){
        if(mConnectlistener !=null){
            mConnectlistener.connectSuccess();
        }
    }

}
