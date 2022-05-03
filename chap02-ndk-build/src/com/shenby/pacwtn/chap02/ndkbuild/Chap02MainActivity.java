package com.shenby.pacwtn.chap02.ndkbuild;

import android.os.Bundle;
import android.util.Log;

import androidx.appcompat.app.AppCompatActivity;

import com.example.hellojni.HelloJni;
import com.shenby.pacwtn.chap02.ndkbuild.databinding.ActivityChap02MainBinding;
import com.shenby.swig.CppStruct;
import com.shenby.swig.MyEnumConstants;
import com.shenby.swig.Numbers;
import com.shenby.swig.Point;
import com.shenby.swig.PointCpp;
import com.shenby.swig.Student;
import com.shenby.swig.Unix;
import com.shenby.swig.UnixConstants;
import com.shenby.swig.UnsafeNumbers;
import com.shenby.swig.Week;

import java.util.Locale;

public class Chap02MainActivity extends AppCompatActivity {
    public static final String TAG = "chap02NdkBuild";

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
        testEnums();
        testStruct();
        testCppStruct();
        testCppStructParam();
        testDefaultParam();

        testFunctionOverloading();

        testCppClass();
    }

    /**
     * 测试c++的类
     */
    private void testCppClass() {
        final Student student = new Student(20, 100.0);
        student.show();
        student.setId(50);
        student.show();
    }

    /**
     * 测试函数重载
     */
    private void testFunctionOverloading() {
        CppStruct.add(20);
        CppStruct.add(50.666);
    }

    /**
     * 测试带默认参数的函数
     */
    private void testDefaultParam() {
        CppStruct.func();
        CppStruct.func(20);
        CppStruct.func(20, 30);
        CppStruct.func(20, 30, 50);
    }

    /**
     * 测试cpp传递参数的指针，引用，值
     */
    private void testCppStructParam() {
        Log.d(TAG, "testCppStructParam: start");
        final PointCpp pointCpp = new PointCpp();
        pointCpp.setX(100);
        pointCpp.setY(120);
        CppStruct.drawByPointer(pointCpp);
        CppStruct.drawByReference(pointCpp);
        CppStruct.drawByValue(pointCpp);
        Log.d(TAG, "testCppStructParam: end");

    }

    /**
     * 测试C++结构体
     */
    private void testCppStruct() {
        final PointCpp pointCpp = new PointCpp();
        showPointCpp(pointCpp);
        pointCpp.setX(20);
        pointCpp.setY(40);
        showPointCpp(pointCpp);
    }

    private void showPointCpp(PointCpp point) {
        final int x = point.getX();
        final int y = point.getY();

        Log.d(TAG, "showPointCpp: x = " + x);
        Log.d(TAG, "showPointCpp: y = " + y);
    }

    /**
     * 测试结构体
     */
    private void testStruct() {
        final Point point = new Point();
        showPoint(point);
        point.setX(100);
        point.setY(200);
        showPoint(point);

    }

    private void showPoint(Point point) {
        final int x = point.getX();
        final int y = point.getY();

        Log.d(TAG, "showPoint: x = " + x);
        Log.d(TAG, "showPoint: y = " + y);
    }

    /**
     * 测试枚举类
     */
    private void testEnums() {
        Log.d(TAG, "testEnums: 测试匿名枚举");
        Log.d(TAG, "testEnums: ONE = " + MyEnumConstants.ONE);
        Log.d(TAG, "testEnums: TWO = " + MyEnumConstants.TWO);
        Log.d(TAG, "testEnums: THREE = " + MyEnumConstants.THREE);
        Log.d(TAG, "testEnums: FOUR = " + MyEnumConstants.FOUR);

        Log.d(TAG, "testEnums: 测试命名枚举");
        Log.d(TAG, String.format(Locale.CHINESE, "testEnums: %s:%d ", Numbers.A, Numbers.A.swigValue()));
        Log.d(TAG, String.format(Locale.CHINESE, "testEnums: %s:%d ", Numbers.B, Numbers.B.swigValue()));
        Log.d(TAG, String.format(Locale.CHINESE, "testEnums: %s:%d ", Numbers.C, Numbers.C.swigValue()));
        Log.d(TAG, String.format(Locale.CHINESE, "testEnums: %s:%d ", Numbers.D, Numbers.D.swigValue()));

        Log.d(TAG, "testEnums: 测试被标记为不安全的命名枚举");
        Log.d(TAG, "testEnums: UnsafeNumbers.U1 = " + UnsafeNumbers.U1);
        Log.d(TAG, "testEnums: UnsafeNumbers.U2 = " + UnsafeNumbers.U2);
        Log.d(TAG, "testEnums: UnsafeNumbers.U3 = " + UnsafeNumbers.U3);
        Log.d(TAG, "testEnums: UnsafeNumbers.U4 = " + UnsafeNumbers.U4);

        Log.d(TAG, "testEnums: 测试Java枚举类");
        Log.d(TAG, "testEnums: Week.SUNDAY =  " + Week.SUNDAY);
        Log.d(TAG, "testEnums: Week.MONDAY " + Week.MONDAY);
        Log.d(TAG, "testEnums: Week.TUESDAY =" + Week.TUESDAY);
        Log.d(TAG, "testEnums: Week.WEDNESDAY = " + Week.WEDNESDAY);
        Log.d(TAG, "testEnums: Week.THURSDAY = " + Week.THURSDAY);
        Log.d(TAG, "testEnums: Week.FRIDAY " + Week.FRIDAY);
        Log.d(TAG, "testEnums: Week.SATURDAY = " + Week.SATURDAY);

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