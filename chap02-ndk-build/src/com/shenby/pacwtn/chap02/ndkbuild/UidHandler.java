package com.shenby.pacwtn.chap02.ndkbuild;

import static com.shenby.pacwtn.chap02.ndkbuild.Chap02MainActivity.TAG;

import android.util.Log;
import android.widget.TextView;

import com.shenby.swig.AsyncUidProvider;

import java.util.Locale;

public class UidHandler extends AsyncUidProvider {
    
    private final TextView mTextView;

    public UidHandler(TextView textView) {
        mTextView = textView;
    }

    @Override
    public void onUid(long uid) {
        super.onUid(uid);
        Log.d(TAG, "onUid: uid = " + uid);
        mTextView.setText(String.format(Locale.CHINESE, "async uid = %d", uid));
    }
}
