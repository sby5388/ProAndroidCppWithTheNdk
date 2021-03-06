/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.shenby.swig;

public class PointCpp {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected PointCpp(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(PointCpp obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        CppStructJNI.delete_PointCpp(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public void setX(int value) {
    CppStructJNI.PointCpp_x_set(swigCPtr, this, value);
  }

  public int getX() {
    return CppStructJNI.PointCpp_x_get(swigCPtr, this);
  }

  public void setY(int value) {
    CppStructJNI.PointCpp_y_set(swigCPtr, this, value);
  }

  public int getY() {
    return CppStructJNI.PointCpp_y_get(swigCPtr, this);
  }

  public PointCpp() {
    this(CppStructJNI.new_PointCpp(), true);
  }

}
