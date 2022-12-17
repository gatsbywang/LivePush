package com.example.livepush;

public class LivePush {
    static {

        System.loadLibrary("live-push");
    }

    private String mUrl;
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
        if(mConnectlistener !=null){
            mConnectlistener.connectError(errCode,errMsg);
        }

    }
    // called form jni
    private void onConnectSuccess(){
        if(mConnectlistener !=null){
            mConnectlistener.connectSuccess();
        }
    }

}
